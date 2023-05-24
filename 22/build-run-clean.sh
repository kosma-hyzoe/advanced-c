#!/bin/bash

gcc client1.c -o cli1
gcc client2.c -o cli2
gcc server.c -o server

./server & ./cli1 && fg 2> /dev/null
./cli2

rm cli1 cli2 server
