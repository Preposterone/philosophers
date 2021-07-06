#!/bin/bash

# Declare an array of string with type
declare -a StringArray=("5" "5 5 5" "a a a a" "5 5 5 -5" "5 5 5 5 -5" "a 100 100 100" )

make
EXEC_NAME="philo"

# Iterate the string array using for loop
for val in "${StringArray[@]}"; do
   echo "Running: ./$EXEC_NAME" $val
  ./$EXEC_NAME val &>/dev/null; EXIT_CODE=$?
  if (( EXIT_CODE != 1 ))
	then
		echo "$(tput setaf 1)[KO - EXIT_CODE]$(tput sgr0)"
		exit 1
  fi
done
    echo "$(tput setaf 2)[OK]$(tput sgr0)"
