set autoscale
set xlabel "temps"
set ylabel "distance au point critique"
set title "comparaison des distances au point critique pour rho = 13"

unset logscale x
unset logscale y

plot "vitesse_explicite.txt" using 1:2 title "explicite" w l
replot "vitesse_implicite.txt" using 1:2 title "implicite" w l
replot "vitesse_RK4.txt" using 1:2 title "RK4" w l