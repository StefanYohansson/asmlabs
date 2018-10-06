all: compile link

compile:
	nasm -f elf64 -o build/${OBJ}.o ${OBJ}.asm

link:
	ld -o build/${OBJ} build/${OBJ}.o

clean:
	rm -rf build/*
