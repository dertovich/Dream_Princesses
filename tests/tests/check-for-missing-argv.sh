#!/bin/bash


 CYAN="\033[0;36m"
GREEN="\033[0;32m"
  RED="\033[0;31m"
RESET="\033[0m"
  VAL=$(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes ./../so_long | grep "Error" > check)
ERROR=$(grep "Error" check | wc -l)

${VAL}

if [ ${ERROR} -ge 1 ]
then
	echo -e "${CYAN}Check for missing argv: $GREEN	[OK] $RESET"
else
	echo -e "${CYAN}Check for missing argv: $RED	[KO] $RESET"
fi
