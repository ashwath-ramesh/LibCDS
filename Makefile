# -*- MakeFile -*-

#target: dependencies
#	action

examples/array_example: examples/array_example.o src/libcds_array.o
	clang examples/array_example.o src/libcds_array.o -o examples/array_example -l m

examples/array_example.o: examples/array_example.c
	clang -Iinclude -c examples/array_example.c -o examples/array_example.o

src/libcds_array.o: src/libcds_array.c
	clang -Iinclude -c src/libcds_array.c -o src/libcds_array.o

clean:
	rm -f examples/array_example examples/*.o src/*.o