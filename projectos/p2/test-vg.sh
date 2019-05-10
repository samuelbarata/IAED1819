#!/bin/bash
#
# File:  test.sh
# Author:  mikolas
# Created on:  Sun Feb 17 13:31:59 STD 2019
# Copyright (C) 2019, Mikolas Janota
#
if [ $# -lt 2 ] ; then
    echo "Usage: $0 <test-dir> <src-file1> <src-file2> ..."
    echo "Example: ${0} testes_enunciado *.c"
    exit 1
fi

if  ! ( which `cut <<<valgrind -f1 -d\ ` >/dev/null 2>&1 ) ; then
    echo "Looks like valgrind can't be run. Make sure it's installed."
    exit 2
fi

test_dir="${1}"
shift
prog_name=foo_${RANDOM}
DIFF="diff"
CC="gcc -g -ansi -Wall -Wextra -pedantic"

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

rv=0
for test_in in `ls -rS ${test_dir}/*.in`; do
    echo "Test:" "${test_in}"
    test_out="${test_in%.in}.out"
    stamp="${RANDOM}${RANDOM}"
    student_out=/tmp/out_${stamp}
    vg_out=/tmp/vg_${stamp}
    valgrind ./${prog_name} <${test_in} 2>${vg_out} >${student_out}
    rv_student=$?

    if [ ! -f "${student_out}" ]; then
        echo -e "${RED}ERROR${NC}: The output of the exercise was not created (file ${student_out})!"
        exit 1
    fi

    if [ ${rv_student} != 0 ]; then
        echo -e "${RED}ERROR${NC}: Program return ${YELLOW}${rv_student}${NC}!"
        rm -f ${student_out}
        valgrind --tool=memcheck --leak-check=full ./${prog_name} < ${test_in}
        rm -f ${prog_name}
        exit 1
    else
        echo "Program successfully ran..."
    fi

    ${DIFF} ${student_out} ${test_out}
    rv_diff=$?

    noerrs='X'
    noleaks='X'
    killed='X'
    pref='^==[0-9]*==\s\+'

    if grep -q "${pref}"'ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)' ${vg_out}; then
        noerrs=1
    elif grep -q  "${pref}"'ERROR SUMMARY: [1-9][0-9]* errors from [0-9]* contexts' ${vg_out}; then
        noerrs=0
    elif grep -q  "${pref}"'Invalid write of size [1-9][0-9]*$' ${vg_out}; then
        noerrs=0
    elif grep -q  "${pref}"'Invalid read of size [1-9][0-9]*$' ${vg_out}; then
        noerrs=0
    fi

    if grep -q "${pref}"'All heap blocks were freed -- no leaks are possible' ${vg_out}; then
        noleaks=1
    elif grep -q "${pref}"'definitely lost: [1-9].* bytes in' ${vg_out}; then
        noleaks=0
    elif grep -q "${pref}"'still reachable: [1-9].* bytes in [1-9].* blocks$' ${vg_out}; then
        noleaks=0
    fi
    if grep -q 's.*\sKilled\s.*valgrind' ${vg_out}; then
        killed=1
    elif grep -q '^Time Limit Exceeded$' ${vg_out}; then
        killed=1
    fi

    score='?'
    if [[ $noerrs == 1 && $noleaks == 1 ]]; then score=1
    elif [[ $noerrs == 1 && $noleaks == 0 ]]; then score=0.5
    elif [[ $noerrs == 0 ]]; then score=0
    elif [[ $killed == 1 ]]; then score=0
    fi

    if grep -q '^valgrind: ./proj2: No such file or directory' ${vg_out}; then nofile=1;
    else nofile=0; fi

    obs=''
    if [[ $killed == 1 ]]; then obs="${RED}killed${NC} ${obs}"; fi
    if [[ $noerrs == 0 ]]; then obs="${RED}ERRS${NC} ${obs}"; fi
    if [[ $noleaks == 0 ]]; then obs="${RED}LEAKS${NC} ${obs}"; fi
    if [[ $nofile == 1 ]]; then obs="${RED}nofile${NC} ${obs}"; fi

    if [ ${rv_diff} == 0 ]; then
        echo -e "Test ${test_in} ${GREEN}PASSED${NC}!"
    else
        echo -e "Test ${test_in} ${RED}FAILURE!${NC}"
        rv=1
        break
    fi

    if [ ${score} != 1 ]; then
        clear
        echo -e "${BLINK}${RED}STOP${NC}${NB}: Looks like there's an issue reported by valgrind!"
        echo -e "${YELLOW}ISSUE${NC}:${obs} ${YELLOW}File${NC}:${test_in}" 
        rv=1
        valgrind --tool=memcheck --leak-check=full ./${prog_name} < ${test_in}
        echo "File:${test_in}"
        exit $rv
        break
    fi
    rm -f ${student_out} ${vg_out}
done
rm -f ${student_out} ${vg_out}
if [ ${rv} == 0 ]; then
    echo -e "${YELLOW}╔═══════════════════════╗"
    echo -e "║   ${GREEN}${BLINK}All Tests PASSED!${NB}${YELLOW}   ║"
    echo -e "╚═══════════════════════╝${NC}"
else
    echo -e "${YELLOW}╔══════════════════════╗"
    echo -e "║   ${RED}${BLINK}GIGANTIC FAILURE${NB}${YELLOW}   ║"
    echo -e "╚══════════════════════╝${NC}"
fi
exit $rv
