#!/bin/python

import os
import subprocess
import sys

avg_100 = 0
avg_500 = 0
max_100 = 0
max_500 = 0
command_100 = "ARG=\"$(./gen.py 100)\"; ./push_swap $ARG | wc -l"
command_500 = "ARG=\"$(./gen.py 500)\"; ./push_swap $ARG | wc -l"

for i in range(int(sys.argv[1])):
    result_100 = int(subprocess.check_output(command_100, shell=True, text=True))
    avg_100 += result_100
    result_500 = int(subprocess.check_output(command_500, shell=True, text=True))
    avg_500 += result_500

    if (result_100 > max_100):
        max_100 = result_100

    if (result_500 > max_500):
        max_500 = result_500

avg_100 /= int(sys.argv[1])
avg_500 /= int(sys.argv[1])

print(f"Executing push_swap {int(sys.argv[1])} times with random stacks of length 100 and 500, we get the following :")
print(f"For stacks of length 100 : {avg_100} operations avg, {max_100} operations max")
print(f"For stacks of length 500 : {avg_500} operations avg, {max_500} operations max")