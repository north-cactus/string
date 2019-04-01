#!/bin/bash

There_are_all_needed_programs=true
if [[ -z `which gnuplot` ]]
then
	echo 'You need to install gnuplot to create animation'
	There_are_all_needed_programs=false
fi
if [[ -z `which gifsicle` ]]
then
	echo 'You need to install gifsicle to optim animation'
	There_are_all_needed_programs=false
fi
if (( ${There_are_all_needed_programs} == 'true' )) 
then
	./bin/Debug/string -a <analytical_in >./gnuplot/analytical_animation.dat
	cd gnuplot
	gnuplot analytical_animator.gp
	gifsicle -i analytical_animation.gif -O3 -o analytical_optim.gif
	eog analytical_optim.gif
fi
