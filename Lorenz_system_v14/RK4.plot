set xlabel "X"
set ylabel "Y"
set zlabel "Z"
set autoscale

set title "RK4 (10,10,20) pour sigma = 10, beta = 8/3, rho= 13" 
splot "RK4.txt" using 2:3:4  title "schema" w l
replot "RK4_v2.txt" using 2:3:4 title "decale de eps" w l