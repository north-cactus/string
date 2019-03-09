#!/bin/bash

./bin/Debug/string <in >./gnuplot/animation.dat
cd gnuplot
gnuplot animator.gp
gifsicle -i animation.gif -O3 -o optim.gif
