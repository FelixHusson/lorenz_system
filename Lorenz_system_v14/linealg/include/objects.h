#ifndef _OBJECTS_H_
#define _OBJECTS_H_

#define CONST_INT 1
#define CONST_DOUBLE 1.0
#define LINESIZE 1024

typedef struct matrix_t matrix_t;
struct matrix_t
{
    int ligne;
    int colonne; 
    double* data;
};

typedef struct stockage_matrix_t stockage_matrix_t;
struct stockage_matrix_t
{
    int number_of_matrix;
    matrix_t** matrix_list; // liste de pointeurs sur differentes matrices 
};


typedef struct matrix_sparse_t matrix_sparse_t;
struct matrix_sparse_t
{
    int ligne;
    int colonne; 
    int * elem_non_nul;
    int * indice_non_nul;
    double * data_non_nul;
};



#endif