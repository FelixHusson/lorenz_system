#include "MASTER.h"
#include "euler_implicite.h"


int comparaison_implicite(double T, int N, double sigma, double beta, double rho, matrix_t* x0, double epsilon )
{
    // Variables programme

    double eps = epsilon; 
    int i;

    matrix_t* X = define_matrix();
    matrix_t* Y = define_matrix();
    matrix_t* Z = define_matrix();
    matrix_t* resultats = define_matrix();
    matrix_t* resultats_eps = define_matrix();


    // ********************************** ACCES FICHIER ECRITURE ******************************************
    FILE* pF_output_X =NULL;
    FILE* pF_output_Y =NULL;
    FILE* pF_output_Z =NULL;

    pF_output_X = fopen("stabilite/implicite/comparaison_implicite_X.txt", "w");
    pF_output_Y = fopen("stabilite/implicite/comparaison_implicite_Y.txt", "w");
    pF_output_Z = fopen("stabilite/implicite/comparaison_implicite_Z.txt", "w");

    if(pF_output_X==NULL){printf("error in main : echec d'acces au fichier sortie"); exit(EXIT_FAILURE);}
    if(pF_output_Y==NULL){printf("error in main : echec d'acces au fichier sortie"); exit(EXIT_FAILURE);}
    if(pF_output_Z==NULL){printf("error in main : echec d'acces au fichier sortie"); exit(EXIT_FAILURE);}


    alloue_matrix(X, N+1, 3);
    alloue_matrix(Y, N+1, 3);
    alloue_matrix(Z, N+1, 3);
    alloue_matrix(resultats, N+1, 4);
    alloue_matrix(resultats_eps, N+1, 4);

    resultats = euler_implicite(x0,T, N, sigma, beta, rho);
    set_elem(x0, 0, 0, get_elem(x0, 0,0)+eps);
    resultats_eps = euler_implicite(x0,T, N, sigma, beta, rho);

    // enregistremement des données dans la matrice de comparaison

    for (i = 0; i<=N; i++)
    {
        set_elem(X, i, 0, get_elem(resultats, i,0));
        set_elem(X, i, 1, get_elem(resultats, i,1));
        set_elem(X, i, 2, get_elem(resultats_eps, i,1));

        set_elem(Y, i, 0, get_elem(resultats, i,0));
        set_elem(Y, i, 1, get_elem(resultats, i,2));
        set_elem(Y, i, 2, get_elem(resultats_eps, i,2));

        set_elem(Z, i, 0, get_elem(resultats, i,0));
        set_elem(Z, i, 1, get_elem(resultats, i,3));
        set_elem(Z, i, 2, get_elem(resultats_eps, i,3));


    }

    afficher_matrix(X, pF_output_X);
    afficher_matrix(Y, pF_output_Y);
    afficher_matrix(Z, pF_output_Z);   


    // *********************************** LIBERATION MEMOIRE ***********************************************
    fclose(pF_output_X); pF_output_X= NULL;
    fclose(pF_output_Y); pF_output_Y = NULL;
    fclose(pF_output_Z); pF_output_Z = NULL;
    
    free_matrix(X);
    free_matrix(Y);
    free_matrix(Z);
    free_matrix(resultats);
    free_matrix(resultats_eps);

    return EXIT_SUCCESS;
}

