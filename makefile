all: compile link

compile:
	nasm -f elf64 -o build/${OBJ}.o ${OBJ}.asm

link:
	ld -o build/${OBJ} build/${OBJ}.o

testlibio: clean
	cp libio/libio.inc build/ && cd build/ && python ../libio/test.py

clean:
	rm -rf build/*
