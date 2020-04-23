.PHONY: test

OUT_DIR=build
CFLAGS=-L$(OUT_DIR)

test: $(OUT_DIR)/test_dynamic_library\
	  $(OUT_DIR)/test_adjacent_string_literals_are_concatenated\
	  $(OUT_DIR)/test_nested_scope\
	  $(OUT_DIR)/test_function_scope\
	  $(OUT_DIR)/test_function_prototype_scope\
	  $(OUT_DIR)/test_point_of_declaration\


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
