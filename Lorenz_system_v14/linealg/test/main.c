#include "MASTER.h"

int main(int argc, char* argv[])
{
    // *********************************** LECTURE ARGC ARGV **********************************************
    if(argc!=3){printf("error in main : le programme doit recevoir 2 arguments : fichier entree et fichier sortie\n"); exit(EXIT_FAILURE);}
    char* input_filename = argv[1]; 
    char* output_filename = argv[2];
    

    // *************************************** VARIABLES  *************************************************
    // Variables en fichier entree
    stockage_matrix_t* list_of_matrix = define_stockage_matrix(); 

    // Variables programme
    matrix_t* A = define_matrix();
    matrix_t* b = define_matrix();
    matrix_t* result = define_matrix();
    matrix_t* verification = define_matrix();


    // *********************************** LECTURE FICHIER ENTREE ******************************************
    read_list_of_matrix(list_of_matrix, input_filename);
   

    // ********************************** ACCES FICHIER ECRITURE ******************************************
    FILE* pF_output = NULL;
    pF_output = fopen(output_filename, "w");
    if(pF_output==NULL){printf("error in main : echec d'acces au fichier sortie"); exit(EXIT_FAILURE);}


    // *************************************** PROGRAMME *************************************************** 
    A = get_matrix_in_list(list_of_matrix, 0);
    b = get_matrix_in_list(list_of_matrix, 1);
    zeros(verification, 3, 1);
    
    afficher_matrix(A, pF_output);
    afficher_matrix(b, pF_output);



    RSL_GAUSS(result, A, b);
    afficher_matrix(result, pF_output);    

    product_matrix(verification, A, result); 
    afficher_matrix(verification, pF_output);

    
    
    
    // TODO **************************************
    // coder les solvers lineaires             *** 
    
    // -> verifier la factorisation LU         ***

    // coder newton multidimentionnel          ***

    //idem pour les matrices creuses           ***
    //********************************************





    // *********************************** LIBERATION MEMOIRE ***********************************************
    // pointeur matrices
    //free_matrix(A);
    //free_matrix(B);

    //pointeur liste de matrice
    free_stockage_matrice(list_of_matrix);

    // pointeur fichier
    fclose(pF_output); pF_output=NULL;


    return EXIT_SUCCESS;
}