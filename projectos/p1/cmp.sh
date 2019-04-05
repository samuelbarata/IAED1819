#!/bin/bash

name="$1"
CC="gcc -ansi -Wall -Wextra -pedantic -fsanitize=address -lm -g"
clear

if [ ! -f "${name}.c" ]; then
	echo "ERROR: file ${name}.c not found!"
	return 1
fi

${CC} ${name}.c -o proj1 #$name
rv_compile=$?
if [ ${rv_compile} != 0 ];then
	echo "ERROR: Compilation failed!"
else
	echo "Program successfully compiled..."
fi
