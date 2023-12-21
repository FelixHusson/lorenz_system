#include "MASTER.h"
#include "euler_implicite.h"
#include "euler_explicite.h"
#include "RK4.h"
#include "comparaison.h"



int stabilite_implicite(matrix_t* x0, double T, int N, double sigma, double beta, double rho, double epsilon)
{
    matrix_t* implicite2 = define_matrix();
    matrix_t* x0_copy = define_matrix();
    copy_matrix(x0_copy, x0);
    FILE* pF_output_2 = NULL;
    pF_output_2 = fopen("implicite_v2.txt","w");
    if(pF_output_2==NULL){printf("error in stabilite_implicite : echec d'acces au fichier sortie"); exit(EXIT_FAILURE);}

    alloue_matrix(implicite2, N+1, 4);    
    set_elem(x0_copy, 0, 0, get_elem(x0, 0, 0)+ epsilon);
    set_elem(x0_copy, 1, 0, get_elem(x0, 1, 0)+ epsilon);
    set_elem(x0_copy, 2, 0, get_elem(x0, 2, 0)+ epsilon);
    implicite2 = euler_implicite(x0_copy, T, N, sigma, beta, rho);
    afficher_matrix(implicite2, pF_output_2);
    
    fclose(pF_output_2); pF_output_2 = NULL;
    free_matrix(implicite2);
    free_matrix(x0_copy);

    return EXIT_SUCCESS;
}


int stabilite_explicite(matrix_t* x0, double T, int N, double sigma, double beta, double rho, double epsilon)
{
    matrix_t* explicite2 = define_matrix();
    matrix_t* x0_copy = define_matrix();
    copy_matrix(x0_copy, x0);
    FILE* pF_output_2 = NULL;
    pF_output_2 = fopen("explicite_v2.txt","w");
    if(pF_output_2==NULL){printf("error in stabilite_explicite : echec d'acces au fichier sortie"); exit(EXIT_FAILURE);}

    alloue_matrix(explicite2, N+1, 4);    
    set_elem(x0_copy, 0, 0, get_elem(x0, 0, 0)+ epsilon);
    set_elem(x0_copy, 1, 0, get_elem(x0, 1, 0)+ epsilon);
    set_elem(x0_copy, 2, 0, get_elem(x0, 2, 0)+ epsilon);
    explicite2 = euler_explicite(x0_copy, T, N, sigma, beta, rho);
    afficher_matrix(explicite2, pF_output_2);
    
    fclose(pF_output_2); pF_output_2 = NULL;
    free_matrix(explicite2);
    free_matrix(x0_copy);

    return EXIT_SUCCESS;
}

int stabilite_RK4(matrix_t* x0, double T, int N, double sigma, double beta, double rho, double epsilon)
{
    matrix_t* RK4_2 = define_matrix();
    matrix_t* x0_copy = define_matrix();
    copy_matrix(x0_copy, x0);
    FILE* pF_output_2 = NULL;
    pF_output_2 = fopen("RK4_v2.txt","w");
    if(pF_output_2==NULL){printf("error in stabilite_RK4 : echec d'acces au fichier sortie"); exit(EXIT_FAILURE);}

    alloue_matrix(RK4_2, N+1, 4);    
    set_elem(x0_copy, 0, 0, get_elem(x0, 0, 0)+ epsilon);
    set_elem(x0_copy, 1, 0, get_elem(x0, 1, 0)+ epsilon);
    set_elem(x0_copy, 2, 0, get_elem(x0, 2, 0)+ epsilon);
    RK4_2 = RK4(x0_copy, T, N, sigma, beta, rho);
    afficher_matrix(RK4_2, pF_output_2);
    
    fclose(pF_output_2); pF_output_2 = NULL;
    free_matrix(RK4_2);
    free_matrix(x0_copy);

    return EXIT_SUCCESS;
}