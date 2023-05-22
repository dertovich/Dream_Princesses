#!/bin/bash


 CYAN="\033[0;36m"
GREEN="\033[0;32m"
  RED="\033[0;31m"
RESET="\033[0m"
  MAP="maps/valid/map1.ber"
EXTRA1="maps/valid/map2.ber"
EXTRA2="maps/valid/map3.ber"
  VAL1=$(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes ./../dream_princesses $MAP $EXTRA1 | grep "Error" > check)
  VAL2=$(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes ./../dream_princesses $MAP $EXTRA1 $EXTRA2 | grep "Error" > check)
 ERROR=$(grep "Error" check | wc -l)

${VAL1}

if [ ${ERROR} -ge 1 ]
then
	echo -e -n "${CYAN}Check for multiple argv: $GREEN       [OK] $RESET"
else
	echo -e -n "${CYAN}Check for multiple argv: $RED       [KO] $RESET"
fi

${VAL2}

if [ ${ERROR} -ge 1 ]
then
	echo -e "$GREEN[OK] $RESET"
else
	echo -e "$RED[KO] $RESET"
fi
