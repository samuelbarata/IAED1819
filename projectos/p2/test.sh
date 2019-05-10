#!/bin/bash
#
# File:  test.sh
# Author:  mikolas
# Created on:  Sun Feb 17 13:31:59 STD 2019
# Copyright (C) 2019, Mikolas Janota
#
if [ $# -lt 2 ] ; then
    echo "Usage: $0 <test-dir> <src-file1> <src-file2> <flags>"
    echo "Example: ${0} testes_enunciado *.c"
    exit 1
fi

test_dir="${1}"
shift
prog_name=foo_${RANDOM}
DIFF="diff"
CC="gcc -ansi -Wall -Wextra -pedantic"

RED='\033[0;31m'
GREEN='\033[0;92m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
BLINK='\e[5m'
NB='\e[25m'
NC='\033[0m'



${CC} -o ${prog_name} $*
rv_compile=$?
if [ ${rv_compile} != 0 ]; then
    echo -e "${RED}ERROR${NC}: Compilation failed!"
    exit 1
else
    echo -e "${BLUE}Program successfully compiled...${NC}"
fi

if  [ -f /usr/bin/time ] ; then
    time_cmd='/usr/bin/time'
    time_args=(-f "Resources: real:%es mem:%MKB")
else
    time_cmd="time"
    time_args=""
fi

okay=1
for test_in in `ls -rS ${test_dir}/*.in`; do
    #echo "Test:" "${test_in}"
    test_out="${test_in%.in}.out"
    stamp="${RANDOM}${RANDOM}"
    student_out=/tmp/in_${stamp}
    ( ${time_cmd} "${time_args[@]}" ./${prog_name} <${test_in} >${student_out} )
    rv_student=$?

    if [ ! -f "${student_out}" ]; then
        echo "ERROR: The output of the exercise was not created (file ${student_out})!"
        okay=0
        break
    fi

    if [ ${rv_student} != 0 ]; then
        echo -e "${RED}ERROR${NC}: Program return ${YELLOW}${rv_student}${NC}!"
        rm -f ${student_out}
        okay=0
        break
    else
        echo "Program successfully ran..."
    fi

    ${DIFF} ${student_out} ${test_out}
    rv_diff=$?
    rm -f ${student_out}

    if [ ${rv_diff} == 0 ]; then
        echo -e "Test ${test_in} ${GREEN}PASSED${NC}!"
    else
        echo "Test ${test_in} FAILURE!"
        okay=0
        break
    fi
done
if [ ${okay} == 1 ]; then
    echo "+++++++++++++++++++"
    echo "+All Tests PASSED!+"
    echo "+++++++++++++++++++"
fi

rm -f ${student_out}
rm -f ${prog_name}
