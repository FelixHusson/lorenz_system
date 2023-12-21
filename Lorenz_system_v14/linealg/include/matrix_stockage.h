#ifndef _MATRICE_STOCKAGE_H_
#define _MATRICE_STOCKAGE_H_

// definition de la liste de matrice
stockage_matrix_t* define_stockage_matrix();


// alloue la memoire pour stocker la liste de matrice
void alloue_stockage_matrice (stockage_matrix_t* list, int number_of_matrix);

// libere la memoire de la liste de matrice
void free_stockage_matrice(stockage_matrix_t* list);

// avoir le nombre de matrice dans une population 

int get_number_of_matrix(stockage_matrix_t* list);

// ajouter une matrice dans la liste

void set_matrix_in_list(stockage_matrix_t* list, matrix_t* A, int i);


// obtenir une matrice en particulier

matrix_t*  get_matrix_in_list (stockage_matrix_t* list, int i);


// lire plusieurs matrices d'un fichier  

void read_list_of_matrix(stockage_matrix_t* list_of_matrix, char* input_filename);

// afficher une matrice de la liste de matrices

void afficher_matrix_in_list(stockage_matrix_t* list_of_matrix, int i, FILE * pF_output);

#endif 