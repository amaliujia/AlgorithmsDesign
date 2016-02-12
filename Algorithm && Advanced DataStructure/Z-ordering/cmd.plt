set terminal png
set title " z-curve - HW2-Q2"
set xtics 1
set ytics 1
unset xtics
unset ytics
unset key
# unset border
set pointsize 1
set style line 1 lt 2 lc rgb "blue" lw 3

set output "zcurve.png"
set xr[0:63]
set yr[0:63]
plot "zpoint.dat" using 1:2 with linespoints pointtype 0
