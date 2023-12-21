#ifndef _SOLVERS_TOOLS_H_
#define _SOLVERS_TOOLS_H_

// verif RSL -> concordance des tailles, b vecteur etc 
void verif_RSL(matrix_t* A, matrix_t* b);

// RSL DIAG
void RSL_DIAG(matrix_t* result, matrix_t* A, matrix_t* b);

// RSL TRI INF
void RSL_TRI_INF(matrix_t* result, matrix_t* A, matrix_t* b);

// RSL TRI SUP
void RSL_TRI_SUP(matrix_t* result, matrix_t* A, matrix_t* b);


// ********************************* Manipulation Lineaire Matricielle *******************************

// Cherche indice pivot
int cherche_ind_pivot(matrix_t* A, int num_colonne);


// Permutation de ligne 
void permutation_ligne(matrix_t* A, int ligne_i, int(ligne_k));

// Permutation ligne systeme
void permutation_ligne_sys(matrix_t* A, matrix_t* b, int ligne_i, int(ligne_k));


// Combinaison lineaire de ligne
void combinaison_lineaire_ligne(matrix_t* A, int i, int j, double coeff);

// Combinaison lineaire du systeme
void comb_linear_ligne_sys(matrix_t* A, matrix_t* b, int i, int j, double coeff);


// ************************************ Factorisation **********************************************

// RSL facto LU
void RSL_FACT_LU(matrix_t* result, matrix_t* A, matrix_t* b);

// Factorisation LU
stockage_matrix_t* FACT_LU(matrix_t* A);



// RSL Cholesky

    // Cholesky
    //MatAdjointe

// Fact QR

    // Householder


// RSL Meth Iterative

#endif