set multiplot layout 1,3


set xlabel "temps"
set autoscale
set ylabel "X"
set title "Stabilite euler explicite X"

plot for[i=2:3] "explicite/comparaison_explicite_X.txt" using 1:i w l title "Donnee X"




unset ylabel
unset title
set xlabel "temps"
set ylabel "Y"
set title "Stabilite euler explicite Y"

plot for[i=2:3]"explicite/comparaison_explicite_Y.txt" using 1:i w l title "Donnee Y"



unset ylabel
unset title
set xlabel "temps"
set ylabel "Z"
set title "Stabilite euler explicite Z"

plot for[i=2:3] "explicite/comparaison_explicite_Z.txt" using 1:i w l title "Donnee Z"



unset multiplot