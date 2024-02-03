#!/bin/bash

problem="abacus"
grader_name="grader"

g++ --std=c++17 -O2 -Wall  -o "${problem}" "${grader_name}.cpp" "${problem}.cpp"

