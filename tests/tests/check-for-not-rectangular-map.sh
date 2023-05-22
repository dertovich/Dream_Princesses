#!/bin/bash

  CYAN="\033[0;36m"
 GREEN="\033[0;32m"
   RED="\033[0;31m"
 RESET="\033[0m"
  MAP1="maps/invalid/map-not-rectangular-1.ber"
  MAP2="maps/invalid/map-not-rectangular-2.ber"
  MAP3="maps/invalid/map-not-rectangular-3.ber"
  MAP4="maps/invalid/map-not-rectangular-4.ber"
ERROR1=$(./../dream_princesses $MAP1 | grep "Error" | wc -l)
ERROR2=$(./../dream_princesses $MAP2 | grep "Error" | wc -l)
ERROR3=$(./../dream_princesses $MAP3 | grep "Error" | wc -l)
ERROR4=$(./../dream_princesses $MAP4 | grep "Error" | wc -l)

if [ ${ERROR1} -ge 1 ]
then
	echo -e -n "${CYAN}Check Map not Rectangular:    $GREEN  [KO] $RESET"
else
	echo -e -n "${CYAN}Check Map not Rectangular:    $RED  [KO] $RESET"
fi

if [ ${ERROR2} -ge 1 ]
then
	echo -e -n "$GREEN[OK] $RESET"
else
	echo -e -n "$RED[KO] $RESET"
fi

if [ ${ERROR3} -ge 1 ]
then
	echo -e -n "$GREEN[OK] $RESET"
else
	echo -e -n "$RED[KO] $RESET"
fi

if [ ${ERROR4} -ge 1 ]
then
	echo -e "$GREEN[OK] $RESET"
else
	echo -e "$RED[KO] $RESET"
fi
