#!/bin/bash
clear
if [[ $# -lt 1 ]] ; then
	echo "Usage: $0 <main-file> <src-file2> ..."
	exit 1
fi

prog_name="${1}"
cfile="${1}".c
shift
DIFF="diff --ignore-space-change --ignore-blank-lines"
CC="gcc -ansi -Wall -Wextra -pedantic"
MORE=" -fcolor-diagnostics -g -fdebug-info-for-profiling  -fsanitize=address"

if [ ! -f "${cfile}" ]; then
	echo "ERROR: file ${cfile} not found!"
	exit 1
fi

${CC} -o ${prog_name} ${cfile} $* ${MORE} 2> ${prog_name}.warnings
rv_compile=$?
if [ ${rv_compile} != 0 ]; then
	echo -e "${RED}ERROR: Compilation failed!${NC}"
	cat ${prog_name}.warnings
	rm -f ${prog_name}.warnings
	exit 1

elif [ -s ${prog_name}.warnings ]; then
    echo -e "${YELLOW}Program ${prog_name} compiled with warnings and running:${NC}"
    cat ${prog_name}.warnings

else
	echo -e "${GREEN}Program ${prog_name} successfully compiled and running:${NC}"
fi

./${prog_name}
output=$?
if [ ${output} != 0 ]; then
	echo "ERROR: Program did not return 0!"
else
	echo "Program successfully ran"
fi
rm -f ${prog_name}.warnings
exit 1
