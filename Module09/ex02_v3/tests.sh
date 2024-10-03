#!/bin/bash

# Clean the output file
> outfile

# Make the program
make

# Loop from 1 to 1000
for ((i=1; i<=1000; i++)); do
    # Generate a random number between 1 and 3000
    N=$((RANDOM % 300 + 1))
    
    # Execute the command with the generated number
    ./PmergeMe $(shuf -i 1-$N -n $N | tr "\n" " ") >> outfile
done
