#!/bin/bash
#
#	Samuel Barata
#	01/05/2019
#

show_help() {
	echo "Usage: $0 <main-file> <src-file2>.c ..."
	echo "Example: $0 -y ex01 aux01.c aux02.c"
	echo "-h | --help		-	mostra este menu"
	echo "-c | --compila		-	compila o ficheiro"
	echo "-y | --testa		-	corre os testes no ficheiro"
	echo "-n | --corre		-	corre o ficheiro"
	echo "-v | --valgrind		-	corre os testes com valgrind"
	echo "-N|-Y|-C 	-	compila com menos flags"
}

RED='\033[0;31m'
GREEN='\033[0;92m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
BLINK='\e[5m'
NB='\e[25m'
NC='\033[0m'

DIFF="diff --ignore-space-change --ignore-blank-lines"
CC="gcc -ansi -Wall -Wextra -pedantic"
MORE=" -g -fsanitize=address"
COMMANDO=""

codigo_geral(){
	clear
	if [[ $# -lt 1 ]] ; then
		show_help
		exit 1
	fi

	prog_name="${1}"
	cfile="${1}".c
	shift

	if  ! ( which `cut <<<valgrind -f1 -d\ ` >/dev/null 2>&1 ) ; then		#se falhar aqui provavelmente não tem valgrind, provavelmente está num mac e apaga tralha desnecessária
		BLINK=''
		NB=''
	fi

	if [ ! -f "${cfile}" ]; then										#vê se o ficheiro existe
		echo -e "${RED}ERROR: file ${cfile} not found!${NC}"
		exit 1
	fi

	if [ ${COMMANDO} == "v" ]; then
		${CC} -o ${prog_name} ${cfile} $* 2> ${prog_name}.warnings		#se correr valgrind n compila com as flags extra
		rv_compile=$?
	else
		${CC} -o ${prog_name} ${cfile} $* ${MORE} 2> ${prog_name}.warnings
		rv_compile=$?
	fi

	if [ ${rv_compile} != 0 ]; then										#verifica se compila
		cat ${prog_name}.warnings
		echo -e "${RED}ERROR: Compilation failed!${NC}"
		rm -f ${prog_name}.warnings
		exit 1

	elif [ -s ${prog_name}.warnings ]; then
		echo -e "${YELLOW}Program ${NC}${GREEN}${prog_name}${NC}${YELLOW} compiled with warnings${NC}"
	else
		echo -e "${BLUE}Program ${prog_name} successfully compiled${NC}"
	fi
}

funcao_c() {
	cat ${prog_name}.warnings
	rm -f ${prog_name} ${prog_name}.warnings
	exit 0
}

funcao_y() {
	##TESTAR
	for test_in in tests/${prog_name}_*.in ; do
		echo "Test:" "${test_in}"
		test_out="${test_in%.in}.out"
		stamp="${RANDOM}${RANDOM}"
		student_out=/tmp/in_${stamp}
		./${prog_name} <${test_in} | sed -e 's/\r$//' >${student_out}
		rv_student=$?

		if [ ! -f "${student_out}" ]; then
			echo -e "${RED}ERROR:${NC} The output of the exercise was not created (file ${student_out})!"
			exit 1
		fi

		if [ ${rv_student} != 0 ]; then
			echo -e "${YELLOW}Program ran and return ${NC}${RED}${rv_student}${NC}"
			rm -f ${student_out}
			exit 1
		else
			echo "Program successfully ran..."
		fi

		${DIFF} ${student_out} ${test_out}
		rv_diff=$?
		rm -f ${student_out}

		if [ ${rv_diff} == 0 ]; then
			echo -e "Test ${test_in} ${GREEN}PASSED!${NC}"
		else
			echo -e "Test ${test_in} ${RED}FAILURE!${NC}"
			exit 1
		fi
	done
	echo -e "${GREEN}${BLINK}Program successfully ran${NB}${NC}"
	cat ${prog_name}.warnings
	exit 0
}

funcao_v() {
	##VALGRIND
	if  ! ( which `cut <<<valgrind -f1 -d\ ` >/dev/null 2>&1 ) ; then
		echo "Looks like valgrind can't be run. Make sure it's installed."
		exit 2
	fi


	for test_in in tests/${prog_name}_*.in ; do
		echo "Test:" "${test_in}"
		test_out="${test_in%.in}.out"
		stamp="${RANDOM}${RANDOM}"
		student_out=/tmp/in_${stamp}
		vg_out=/tmp/vg_${stamp}
		valgrind ./${prog_name} <${test_in} 2>${vg_out} >${student_out}
		rv_student=$?

		if [ ! -f "${student_out}" ]; then
			echo -e "${RED}ERROR:${NC} The output of the exercise was not created (file ${student_out})!"
			exit 1
		fi

		if [ ${rv_student} != 0 ]; then
			echo -e "${YELLOW}Program ran and return ${NC}${RED}${rv_student}${NC}"
			rm -f ${student_out}
			exit 1
		else
			echo "Program successfully ran..."
		fi

		${DIFF} ${student_out} ${test_out}
		rv_diff=$?

		#valgrind
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

		if grep -q '^valgrind: No such file or directory' ${vg_out}; then nofile=1;
		else nofile=0; fi

		obs=''
		if [[ $killed == 1 ]]; then obs="killed ${obs}"; fi
		if [[ $noerrs == 0 ]]; then obs="ERRS ${obs}"; fi
		if [[ $noleaks == 0 ]]; then obs="LEAKS ${obs}"; fi
		if [[ $nofile == 1 ]]; then obs="nofile ${obs}"; fi

		if [ ${rv_diff} == 0 ]; then
			echo -e "Test ${test_in} ${GREEN}PASSED!${NC}"
		else
			echo -e "Test ${test_in} ${RED}FAILURE!${NC}"
			exit 1
		fi

		if [ ${score} != 1 ]; then
			clear
			echo -e "${RED}STOP:${NC} Looks like there's an issue reported by valgrind!"
			echo -e "${YELLOW}ISSUE:${NC} ${obs}"
			rv=1
			break
		fi
		rm -f ${student_out} ${vg_out}
	done
	rm -f ${student_out} ${vg_out}

	cat ${prog_name}.warnings
	rm -f ${prog_name} ${prog_name}.warnings
	exit 0
}

funcao_n(){
	##EXPERIMENTAR MANUALMENTE
	cat ${prog_name}.warnings
	echo -e "${BLUE}running:${NC}"

	./${prog_name}
	output=$?
	if [ ${output} != 0 ]; then
		echo -e "${YELLOW}Program ran and return ${NC}${RED}${output}${NC}"
	else
		echo -e "${GREEN}${BLINK}Program successfully ran${NB}${NC}"
	fi

	rm -f ${prog_name} ${prog_name}.warnings
	exit ${output}
}

case "$1" in
	-h|--help|-H)
		#HELP
		show_help
		COMMANDO='v'
		exit 0
		;;
	-c|--compila)
		#COMPILA
		COMMANDO='v'
		shift
		codigo_geral $*
		funcao_c $*
		;;
	-C)
		#COMPILA
		COMMANDO='n'
		shift
		codigo_geral $*
		funcao_c $*
		;;
	-y|--testa)
		#TESTA
		COMMANDO='v'
		shift
		codigo_geral $*
		funcao_y $*
		;;
	-Y)
		#TESTA
		COMMANDO='n'
		shift
		codigo_geral $*
		funcao_y $*
		;;
	-v|--valgrind|-V)
		#VALGRIND
		COMMANDO='v'
		shift
		codigo_geral $*
		funcao_v $*
		;;
	-n|--corre)
		#CORRE
		COMMANDO='v'
		shift
		codigo_geral $*
		funcao_n $*
		;;
	-N)
		#CORRE
		COMMANDO='n'
		shift
		codigo_geral $*
		funcao_n $*
		;;
	*)
		COMMANDO='v'
		codigo_geral $*
		funcao_n $*
esac
