#!/bin/bash

echo Lista: -3
ARG="-3"; ./push_swap $ARG | ./checker_Mac $ARG
./push_swap -3
./push_swap "-3"
echo

echo Lista: 2 3
ARG="2        3"; ./push_swap $ARG | ./checker_Mac $ARG
./push_swap 2 3
./push_swap "2 3"
echo

echo Lista: 2 0 3
ARG="2 0 3"; ./push_swap $ARG | ./checker_Mac $ARG
./push_swap 2 0 3
./push_swap "2 0 3"
echo

echo Lista: 2 -3 0
ARG="2 -3 0"; ./push_swap $ARG | ./checker_Mac $ARG
./push_swap 2 -3 0
./push_swap "2 -3 0"
echo

# echo Lista: -3 2 0
# ARG="-3 2 0"; ./push_swap $ARG | ./checker_Mac $ARG
# # ./push_swap -3 2 0
# echo

# echo Lista: 0 -3 2
# ARG="0 -3 2"; ./push_swap $ARG | ./checker_Mac $ARG
# # ./push_swap 0 -3 2
# echo

# echo Lista: 0 2 -3
# ARG="0 2 -3"; ./push_swap $ARG | ./checker_Mac $ARG
# # ./push_swap 0 2 -3

echo Lista: -3 0 2
ARG="-3 0 2"; ./push_swap $ARG | ./checker_Mac $ARG
./push_swap -3 0 2
./push_swap "-3 0 2"
echo
