#!/bin/python
import random
import sys

numbers = []
for i in range(int(sys.argv[1])):
    v = random.randint(0, 1000)
    while v in numbers:
        v = random.randint(0, 1000)
    numbers.append(v)

res = ""
for n in numbers:
    res += f"{n} "

print(res)