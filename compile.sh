#!/bin/bash
clear
if [[ $# != 1 ]] ; then
	echo "Usage: $0 <file>"
	return 1
fi

prog_name="${1}"
cfile="${1}".c
DIFF="diff --ignore-space-change --ignore-blank-lines"
CC="gcc -ansi -Wall -Wextra -pedantic"

if [ ! -f "${cfile}" ]; then
	echo "ERROR: file ${cfile} not found!"
	return 1
fi

${CC} -o ${prog_name} ${cfile}
rv_compile=$?
if [${rv_compile} != 0];then
	echo "ERROR: Compilation failed!"
	return 1
else
	echo "Program successfully compiled..."
	return 0
fi
