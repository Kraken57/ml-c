#!/bin/sh

set -xe

clang -Wall -Wextra -o or or.c -lm
clang -Wall -Wextra -o xor xor.c -lm