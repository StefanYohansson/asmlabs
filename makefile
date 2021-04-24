all: compile link

compile:
	nasm -f elf64 -o build/${OBJ}.o ${OBJ}.asm

link:
	ld -o build/${OBJ} build/${OBJ}.o

compile_c_exercises_dotproduct:
	gcc -Werror \
		exercises_c/dotproduct.c \
 		exercises_c/dotproduct_runner.c \
 		-o exercises_c/build/dotproduct

compile_c_exercises_tests:
	gcc -Werror \
		-I./exercises_c/munit \
 		exercises_c/munit/munit.c \
 		exercises_c/dotproduct.c \
 		exercises_c/dotproduct_test.c \
 		exercises_c/runner.c \
 		-o exercises_c/build/test_runner

testlibio: clean
	cp libio/libio.inc.asm build/ && cd build/ && python ../libio/test.py

clean:
	rm -rf build/*
	rm -rf exercises_c/build/*
