#!/usr/bin/env gnuplot

set terminal png
set output "10000.png"
set xrange[0:499]
set yrange[0:499] reverse
plot "10000" binary array=(500,500) format="%lf" with image

