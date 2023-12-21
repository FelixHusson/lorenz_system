#include "MASTER.h"

void RSL_GAUSS(matrix_t* result, matrix_t* A, matrix_t*b)
{
    matrix_t* copy_A= define_matrix();
    matrix_t* copy_b= define_matrix();

    copy_matrix(copy_A, A);
    copy_matrix(copy_b, b);

    verif_RSL(copy_A, copy_b);
    int j;
    int i; 
    int indice_pivot=0;
    for (j=0; j<get_colonne(copy_A)-1; j++)
    {
        indice_pivot = cherche_ind_pivot(copy_A, j);
        permutation_ligne_sys(copy_A, copy_b, j, indice_pivot); 

        for (i = j+1; i< get_colonne(copy_A); i++)
        {
            comb_linear_ligne_sys(copy_A, copy_b, i,j, -get_elem(copy_A,i,j)/get_elem(copy_A, j,j));
        }
    }
    RSL_TRI_SUP(result, copy_A, copy_b);

    free_matrix(copy_A);
    free_matrix(copy_b);
}