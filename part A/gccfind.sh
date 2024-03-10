#!/bin/bash
#Ye'ela Granot 209133107
if [[ $# -ne 2 ]] && [[ $# -ne 3 ]]
then
  echo "Not enough parameters"
  exit 1
fi

path=$1
word=$2
cd -P -- "$path" || exit
if [ "$#" -eq 2 ]
then
	rm -f -- *.out
	for file in *.c
	do
		if grep -Eqwi "(\W)*""$word""(\W)*" "$file"
		then 
			output=$(basename "${file%.c}").out
			gcc -w "$file" -o "$output"
		fi
	done
fi
if [[ ($# -eq 3) && ("$3" == "-r") ]]
then
	find . -name "*.out" -type f -delete
	word=$2
	currdir=$(pwd)

	find "$currdir" -type f -name "*.c" -exec grep -Eqwi "(\W)*""$word""(\W)*" {} \; -exec sh -c 'gcc -o "${0%.c}.out" "$0"' {} \;
fi

