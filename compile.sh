#!/bin/bash
clear
if [[ $# -lt 1 ]] ; then
	echo "Usage: $0 <main-file> <src-file2>.c ..."
	exit 1
fi

prog_name="${1}"
cfile="${1}".c
shift
DIFF="diff --ignore-space-change --ignore-blank-lines"
CC="gcc -ansi -Wall -Wextra -pedantic"
MORE=" -fcolor-diagnostics -g -fdebug-info-for-profiling  -fsanitize=address"

if [ ! -f "${cfile}" ]; then
	echo -e "${RED}ERROR: file ${cfile} not found!${NC}"
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
    echo -e "${YELLOW}Program ${prog_name} compiled with warnings${NC}"
    cat ${prog_name}.warnings
	echo "running:"

else
	echo -e "${GREEN}Program ${prog_name} successfully compiled and running:${NC}"
fi

./${prog_name}
output=$?

echo -e "${GREEN}Program successfully ran and return ${NC}${RED}${output}${NC}"

rm -f ${prog_name}.warnings
exit 1
