#!/bin/bash

echo Lista: 4 67 3 87 23 8
ARG="4 67 3 87 23 8"; ./push_swap $ARG | ./checker_Mac $ARG
# ./push_swap 4 67 3 87 23 > output
echo

echo Lista: 18 2 28 33 16
ARG="18 2 28 33 16"; ./push_swap $ARG | ./checker_Mac $ARG
# ./push_swap "18 2 28 33 16" > output
echo

echo Lista: 19 20 23 17 3
ARG="19 20 23 17 3"; ./push_swap $ARG | ./checker_Mac $ARG
# ./push_swap 19 20 23 17 3 > output
echo

echo Lista: -359 -969 -744 -824 -218
ARG="-359 -969 -744 -824 -218"; ./push_swap $ARG | ./checker_Mac $ARG
# ./push_swap -359 -969 -744 -824 -218 > output # 10 números, los dos inputs anteriores.
echo
