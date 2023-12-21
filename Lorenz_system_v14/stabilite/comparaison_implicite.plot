set multiplot layout 1,3


set xlabel "temps"
set autoscale
set ylabel "X"
set title "Stabilite euler implicite X"

plot for[i=2:3] "implicite/comparaison_implicite_X.txt" using 1:i w l title "Donnee X"




unset ylabel
unset title
set xlabel "temps"
set ylabel "Y"
set title "Stabilite euler implicite Y"

plot for[i=2:3]"implicite/comparaison_implicite_Y.txt" using 1:i w l title "Donnee Y"



unset ylabel
unset title
set xlabel "temps"
set ylabel "Z"
set title "Stabilite euler implicite Z"

plot for[i=2:3] "implicite/comparaison_implicite_Z.txt" using 1:i w l title "Donnee Z"



unset multiplot