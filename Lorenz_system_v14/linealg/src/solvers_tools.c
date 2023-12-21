#include "MASTER.h"

// verif RSL -> concordance des tailles, b vecteur, A matrice carree 
void verif_RSL(matrix_t* A, matrix_t* b)
{
    if(est_vecteur(b)!=1)
    {
        printf("erreur dans la concordance des tailles de RSL : le second membre doit etre un vecteur nx1\n");
        exit(EXIT_FAILURE); 
    }
    if(get_colonne(A)!=get_ligne(b))
    {
        printf("erreur dans la concordance des tailles de RSL : la matrice A et son second membre b doivent avoir le même nombre de ligne\n");
        exit(EXIT_FAILURE);
    }
    if(est_carree(A)!=1)
    {
        printf("erreur dans la concordance des tailles de RSL : la matrice A doit etre carree\n");
        exit(EXIT_FAILURE);
    }
}

// RSL DIAG
void RSL_DIAG(matrix_t* result, matrix_t* A, matrix_t* b)
{
    verif_RSL(A, b);
    int taille = get_colonne(A);
    int i;
    if(est_diagonale(A)!=1){printf("erreur : la matrice de RSL_DIAG n'est pas diagonale.\n"); exit(EXIT_FAILURE);}
    
    // verification matrice diagonale inversible  
    for(i =0; i<taille; i++)
    {
        if (get_elem(A, i, i)==0)
        {
            printf("erreur in RSL_DIAG : la matrice n'est pas inversible.\n");
            exit(EXIT_FAILURE);
        }
    }
    alloue_matrix(result, taille, 1);
    for(i = 0; i<taille; i++)
    {
        set_elem(result, i, 0, get_elem(b, i, 0)/get_elem(A, i, i));
    }
}

// RSL TRI INF
void RSL_TRI_INF(matrix_t* result, matrix_t* A, matrix_t* b)
{
    verif_RSL(A, b);
    double somme= 0;
    int taille = get_colonne(A);
    int i,j;
    if(est_triangulaire_inf(A)!=1){printf("erreur : la matrice de RSL_TRI_INF n'est pas triangulaire inferieure.\n"); exit(EXIT_FAILURE);}
    
    // verification matrice triangulaire inversible  
    for(i =0; i<taille; i++)
    {
        if (get_elem(A, i, i)==0)
        {
            printf("erreur in RSL_TRI_INF : la matrice n'est pas inversible.\n");
            exit(EXIT_FAILURE);
        }
    }
    alloue_matrix(result, taille, 1);

    for (i = 0; i<taille; i++)
    {
        somme = 0;
        for (j= 0; j<i; j++)
        {
            somme+=get_elem(A, i,j)*get_elem(result,j,0);
        }
        set_elem(result, i, 0, (get_elem(b, i, 0)-somme)/get_elem(A,i,i));
    }
}

// RSL TRI SUP
void RSL_TRI_SUP(matrix_t* result, matrix_t* A, matrix_t* b)
{
    verif_RSL(A, b);
    double somme= 0;
    int taille = get_colonne(A);
    int i,j;
    if(est_triangulaire_sup(A)!=1){printf("erreur : la matrice de RSL_TRI_SUP n'est pas triangulaire superieure.\n"); exit(EXIT_FAILURE);}
    
    // verification matrice triangulaire inversible  
    for(i =0; i<taille; i++)
    {
        if (get_elem(A, i, i)==0)
        {
            printf("erreur in RSL_TRI_SUP : la matrice n'est pas inversible.\n");
            exit(EXIT_FAILURE);
        }
    }
    alloue_matrix(result, taille, 1);

    for (i = taille-1; i>=0; i--)
    {
        somme = 0;
        for (j= i+1; j<taille; j++)
        {
            somme+=get_elem(A, i,j)*get_elem(result,j,0);
        }
        set_elem(result, i, 0, (get_elem(b, i, 0)-somme)/get_elem(A,i,i));
    }

}


// ********************************* Manipulation Lineaire Matricielle *******************************

// Cherche indice pivot
int cherche_ind_pivot (matrix_t* A, int num_colonne)
{
    int i;
    int indice_result; 
    double pivot = fabs(get_elem(A, num_colonne, num_colonne));
    indice_result = num_colonne;
    for (i = num_colonne+1; i<get_ligne(A); i++)
    {
        if (fabs(get_elem(A, i, num_colonne))>pivot)
        {
            indice_result = i;
            pivot= fabs(get_elem(A, i, num_colonne));
        }
    }
    return indice_result;
}


// Permutation de ligne 
void permutation_ligne(matrix_t* A, int ligne_i, int ligne_k)
{
    int n = get_colonne(A);
    int j; 
    double intermediaire;
    for (j = 0; j<n; j++)
    {
        intermediaire = get_elem(A, ligne_i, j);
        set_elem(A, ligne_i, j, get_elem(A, ligne_k, j));
        set_elem(A, ligne_k, j, intermediaire);
    }
}

// Permutation ligne systeme
void permutation_ligne_sys(matrix_t* A, matrix_t* b, int ligne_i, int ligne_k)
{
    permutation_ligne(A, ligne_i,ligne_k);
    permutation_ligne(b, ligne_i, ligne_k);
}

// Combinaison lineaire de ligne
void combinaison_lineaire_ligne(matrix_t* A, int i, int j, double coeff)
{
    int n = get_colonne(A);
    int k;
    for (k = 0; k<n; k++)
    {
        set_elem(A, i,k, get_elem(A,i,k)+coeff*get_elem(A,j,k));
    }
}

// Combinaison lineaire du systeme
void comb_linear_ligne_sys(matrix_t* A, matrix_t* b, int i, int j, double coeff)
{
    combinaison_lineaire_ligne(A, i, j, coeff);
    combinaison_lineaire_ligne(b, i, j, coeff);
}


// *********************************** Factorisation *******************************************

// RSL facto LU
void RSL_FACT_LU(matrix_t* result, matrix_t* A, matrix_t* b)
{
    matrix_t* L= define_matrix();
    matrix_t* U = define_matrix();
    stockage_matrix_t* fact_LU = define_stockage_matrix();
    matrix_t* y = define_matrix();

    fact_LU= FACT_LU(A);
    L = get_matrix_in_list(fact_LU, 0);
    U = get_matrix_in_list(fact_LU, 1);

    RSL_TRI_INF(y, L, b);
    RSL_TRI_SUP(result, U, y);
    
    // liberation memoire
    free_matrix(y);
    free_matrix(L); 
    free_matrix(U);
    free_stockage_matrice(fact_LU);

}

// Factorisation LU
stockage_matrix_t* FACT_LU(matrix_t* A)
{
    stockage_matrix_t* fact_LU = define_stockage_matrix();
    matrix_t* L = define_matrix();
    matrix_t* U = define_matrix(); 
    alloue_stockage_matrice(fact_LU, 2);
    
    int taille = get_colonne(A);
    int i, j, k;
    double Sum1, Sum2;

    zeros(U, taille, taille);
    identity(L, taille);

    for (i = 0; i<taille; i++)
    {
        // Calcul de la ligne i de U
        for (j=0; j<taille; j++)
        {
            Sum1 = 0;
            for (k= 0; k<i; k++)
            {
                Sum1 += get_elem(L, i, k)* get_elem(U, k, j);
            }
            set_elem(U,i,j, get_elem(A, i,j)- Sum1);
        }

        // Calcul de la colonne i de L
        for (j= i+1; j< taille; j++)
        {
            Sum2 = 0;
            for (k = 0; k<i; k++)
            {
                Sum2 += get_elem(L,j,k)*get_elem(U,k,i);
            }
            set_elem(L, j,i, (get_elem(A, j,i)- Sum2)/get_elem(U, i,i));
        }
    }
    
    set_matrix_in_list(fact_LU, L, 0);
    set_matrix_in_list(fact_LU, U, 1);
    return fact_LU;
}


// RSL Cholesky

    // Cholesky
    //MatAdjointe

// Fact QR

    // Householder


// RSL Meth Iterative