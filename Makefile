.PHONY: test

OUT_DIR=build
CFLAGS=-L$(OUT_DIR)

test: reset\
	  $(OUT_DIR)/test_dynamic_library\
	  $(OUT_DIR)/test_adjacent_string_literals_are_concatenated\
	  $(OUT_DIR)/test_nested_scope $(OUT_DIR)/test_function_scope $(OUT_DIR)/test_function_prototype_scope $(OUT_DIR)/test_no_struct_scope\
	  $(OUT_DIR)/test_point_of_declaration\
	  $(OUT_DIR)/test_object_has_constant_address\
	  $(OUT_DIR)/test_same_identifier_in_diff_name_spaces\
	  $(OUT_DIR)/test_main_with_argc_only\
	  $(OUT_DIR)/test_basic_alignment $(OUT_DIR)/test_object_alignment $(OUT_DIR)/test_disable_padding\
	  $(OUT_DIR)/test_unevaluated_expressions\
	  $(OUT_DIR)/test_lvalue_as_operand_of_the_address_of_operator $(OUT_DIR)/test_lvalue_as_operand_of_increment_or_decrement_operator $(OUT_DIR)/test_lvalue_as_left_operand_of_member_access_operator $(OUT_DIR)/test_lvalue_as_left_operand_of_assignments\
	  $(OUT_DIR)/test_lvalue_of_compound_literals $(OUT_DIR)/test_lvalue_of_result_of_member_access_operator $(OUT_DIR)/test_lvalue_of_result_of_member_access_through_pointer_operator $(OUT_DIR)/test_lvalue_of_result_of_indirection_operator_applied_to_pointer $(OUT_DIR)/test_lvalue_of_result_of_indirection_operator_applied_to_pointer $(OUT_DIR)/test_lvalue_of_result_of_subscription_operator\

reset:
	-@tput reset

$(OUT_DIR):
	mkdir $(OUT_DIR)

$(OUT_DIR)/test_dynamic_library: $(OUT_DIR) $(OUT_DIR)/max.so
	@echo "INFO: compile program with dynamic link library" 
	$(CC) test/main.c ${CFLAGS} -lmax -o $@
	LD_LIBRARY_PATH=$(OUT_DIR) $@ 
	@echo "INFO: verify program linked with dynamic library"
	ldd $@ | grep libmax.so 

$(OUT_DIR)/%.so: $(OUT_DIR)/%.o
	@echo "INFO: create dynamic shared library $(OUT_DIR)/lib$*.so"
	$(CC) -o $(OUT_DIR)/lib$*.so -shared $(OUT_DIR)/$*.o

$(OUT_DIR)/%.o:
	@echo "INFO: compile test/$*.c into C object"
	$(CC) ${CFLAGS} -o $@ -c test/$*.c

$(OUT_DIR)/test_%: $(OUT_DIR)
	$(CC) ${CFLAGS} -o $@ test/$*.c
	$@ || (rm $@ && false)

clean:
	@rm $(OUT_DIR) -rf
