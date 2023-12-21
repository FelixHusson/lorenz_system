#ifndef _MATRIX_TOOLS_H_
#define _MATRIX_TOOLS_H_

// ********************************* Gestion generale de la structure *******************************
//definition d'une matrice
matrix_t* define_matrix();

// alloue matrice nulle
void alloue_matrix(matrix_t* A, int ligne, int colonne);

// libere matrice
void free_matrix(matrix_t *A);

// prend la dimension des lignes
int get_ligne(matrix_t* A);

// prend la dimension des colonnes 
int get_colonne(matrix_t* A);

// lit un element de la matrice
double get_elem(matrix_t* A, int i, int j);

// change element dans la matrice
void set_elem(matrix_t* A, int i, int j, double data);

// copie matrice
void copy_matrix(matrix_t* copy, matrix_t* origine);

// *************************************** Interactions fichiers **************************************

// affiche matrice
void afficher_matrix(matrix_t* A, FILE* pF_output);

// lire matrice
void read_matrix (matrix_t* A, FILE* pF_input);

// **************************************** Matrices utiles ******************************************* 
// matrice identite 
void identity(matrix_t* I, int ligne);

// matrice nulle 
void zeros(matrix_t* A, int ligne, int colonne);


// **************************************** Verif utiles ********************************************
// verif vecteur 1: oui, 0: non
int est_vecteur(matrix_t* v);

// verif carre 1: oui, 0: non
int est_carree(matrix_t* A);

// verif diagonale
int est_diagonale(matrix_t* A);

// verif tri inf
int est_triangulaire_inf(matrix_t* A);

// verif tri sup 
int est_triangulaire_sup(matrix_t* A);

// ******************* Operations matricielles ****************************************************** 
// transposer matrice 
void transpose_matrix(matrix_t* Resultat, matrix_t* A);

// Somme matricielle
void sum_matrix(matrix_t* Resultat, matrix_t* A, matrix_t* B, double alpha, double beta);

// Produit matriciel 
void product_matrix(matrix_t* Resultat, matrix_t* A, matrix_t* B);


// *************************** Normes ************************************************
//Norme 1
double norm_1(matrix_t* A);

// Norme euclidienne 
double norm_euclidienne(matrix_t* A);

// Norme infinie
double norm_sup(matrix_t* A);

#endif