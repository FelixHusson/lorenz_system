set xlabel "X"
set ylabel "Y"
set zlabel "Z"
set autoscale

set title "explicite (e-3,e-3,e-3) pour sigma = 10, beta = 8/3, rho= 28"
splot "explicite.txt" using 2:3:4  title "schema" w l
replot "explicite_v2.txt" using 2:3:4 title "decale de eps" w l