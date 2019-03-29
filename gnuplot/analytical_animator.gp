#set terminal animate gif crop delay 100 optimize
set term gif animate delay 10
set output 'analytical_animation.gif'

set yrange [-10:10]

do for [i=1:100]{
	plot 'analytical_animation.dat' index i:i:2 with lines notitle
}
