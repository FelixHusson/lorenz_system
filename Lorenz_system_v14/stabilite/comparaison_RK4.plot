set multiplot layout 1,3


set xlabel "temps"
set autoscale
set ylabel "X"
set title "Stabilite euler RK4 X"

plot for[i=2:3] "RK4/comparaison_RK4_X.txt" using 1:i w l title "Donnee X"




unset ylabel
unset title
set xlabel "temps"
set ylabel "Y"
set title "Stabilite euler RK4 Y"

plot for[i=2:3]"RK4/comparaison_RK4_Y.txt" using 1:i w l title "Donnee Y"



unset ylabel
unset title
set xlabel "temps"
set ylabel "Z"
set title "Stabilite euler RK4 Z"

plot for[i=2:3] "RK4/comparaison_RK4_Z.txt" using 1:i w l title "Donnee Z"



unset multiplot