set xlabel "X"
set ylabel "Y"
set zlabel "Z"
set autoscale

set title "implicite (10,10,20) pour sigma = 10, beta = 8/3, rho= 17"
splot "implicite.txt" using 2:3:4  title "schema" w l
replot "implicite_v2.txt" using 2:3:4 title "decale de eps" w l 