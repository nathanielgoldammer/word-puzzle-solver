#!/bin/bash 

#Prompt the user to input a dictionary file
echo 'Enter a dictionary file: '
read dictionaryFile

#Prompt the user to input a grid file
echo 'Enter a grid file: '
read gridFile

#Obtain the runtime of 5 different executables, using the same parameters for each
RUNTIME1=`./a.out "$dictionaryFile" "$gridFile" | tail -1` 
RUNTIME2=`./a.out "$dictionaryFile" "$gridFile" | tail -1` 
RUNTIME3=`./a.out "$dictionaryFile" "$gridFile" | tail -1` 
RUNTIME4=`./a.out "$dictionaryFile" "$gridFile" | tail -1` 
RUNTIME5=`./a.out "$dictionaryFile" "$gridFile" | tail -1` 

#Print the average runtime of the 5 different executables
echo 'Average runtime:' $(( (RUNTIME1 + RUNTIME2 + RUNTIME3 + RUNTIME4 + RUNTIME5) / 5 )) 'milliseconds'