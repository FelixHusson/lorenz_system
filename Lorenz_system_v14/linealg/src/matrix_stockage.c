#include "MASTER.h"

// definition de la liste de matrice
stockage_matrix_t* define_stockage_matrix()
{
    stockage_matrix_t* list = NULL;
    list = malloc(sizeof(stockage_matrix_t));
    if (list == NULL){printf("error in define_stockage_matrix : echec d'allocation memoire de stockage_matrice_t"); exit(EXIT_FAILURE);}
    // ligne a verifier si marche pas
    list->matrix_list=NULL;

    return list;
}

// alloue la memoire pour stocker la liste de matrice
void alloue_stockage_matrice (stockage_matrix_t* list, int number_of_matrix)
{
    matrix_t** list_of_matrix = NULL;
    list->number_of_matrix = number_of_matrix;
    list_of_matrix = malloc(number_of_matrix*sizeof(matrix_t*));
    for(int i = 0; i<number_of_matrix; i++)
    {
        list_of_matrix[i]= define_matrix();
    }
    list->matrix_list = list_of_matrix;
}

// libere la memoire de la liste de matrice
void free_stockage_matrice(stockage_matrix_t* list)
{
    list->number_of_matrix = 0;
    free(list->matrix_list);
    (list->matrix_list) = NULL;
    free(list);
    list = NULL;
}


// avoir le nombre de matrice dans une population 

int get_number_of_matrix(stockage_matrix_t* list)
{
    return list->number_of_matrix; 
}

// affecter une matrice dans la liste 

void set_matrix_in_list(stockage_matrix_t* list, matrix_t* A, int i)
{
    list->matrix_list[i] = A;
}



// obtenir une matrice en particulier

matrix_t*  get_matrix_in_list (stockage_matrix_t* list, int i)
{
    return list->matrix_list[i];
}

// lire plusieurs matrices d'un fichier  

void read_list_of_matrix(stockage_matrix_t* list_of_matrix, char* input_filename)
{
    // convention :
    // - nombre de matrice dans le fichier d'entree __ nom des matrices A.txt B.txt ect
    
    char matrix_name[LINESIZE]= "";    
    FILE* pF_matrix = NULL;
    FILE* pF_input = NULL; 
    int i;
       
    pF_input = fopen(input_filename, "r");
    if (pF_input==NULL){printf("error in read_list_of_matrix in matrix_stockage : echec d'acces au fichier entree"); exit(EXIT_FAILURE);}
    int number_of_matrix; 
    fscanf(pF_input, "%d", &number_of_matrix);
    alloue_stockage_matrice(list_of_matrix, number_of_matrix);

    for(i = 0; i<number_of_matrix; i++)
    {
        fscanf(pF_input,"%s", matrix_name);
        pF_matrix= fopen(matrix_name, "r");
        if(pF_matrix==NULL){printf("error in read_list_of_matrix : echec d'ouverture du fichier matrice\n"); exit(EXIT_FAILURE);}
        read_matrix(get_matrix_in_list(list_of_matrix,i), pF_matrix);
        fclose(pF_matrix);
        pF_matrix = NULL;
    }
    
    fclose(pF_input); 
    pF_input = NULL;

}


// afficher une matrice de la liste de matrices

void afficher_matrix_in_list(stockage_matrix_t* list_of_matrix, int i, FILE * pF_output)
{
    afficher_matrix(get_matrix_in_list(list_of_matrix, i), pF_output);
}
