set autoscale
set xlabel "temps"
set ylabel "erreur"
set title "comparaison des erreurs pour rho =13"
unset logscale x
set logscale y
plot "vitesse_explicite.txt" using 1:3 title "erreur de explicite" w l
replot "vitesse_implicite.txt" using 1:3 title "erreur de implicite" w l
replot "vitesse_RK4.txt" using 1:3 title "erreur de RK4" w l