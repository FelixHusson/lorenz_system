#include "MASTER.h"

// ********************************* Gestion generale de la structure *******************************
// definition de la matrice
matrix_t* define_matrix()
{
    matrix_t* A = NULL;
    A = malloc(sizeof(matrix_t));
    if(A==NULL){printf("error in matrix tools -> alloue matrice : echec d'allocation memoire de la matrice A\n"); exit(EXIT_FAILURE);}
    A->data = NULL;
    return A;
}

// allocation memoire de la matrice
void alloue_matrix(matrix_t* A, int ligne, int colonne)
{
    // ecrase la memoire de la matrice portant le même  nom
    free(A->data); 
    A->data = NULL;

    A->ligne = ligne;
    A->colonne = colonne;
    double * data = NULL;
    data = malloc(ligne*colonne*sizeof(double));
    if(data==NULL){printf("error in matrix tools -> alloue matrice : echec d'allocation memoire de data\n"); exit(EXIT_FAILURE);}
    A-> data = data;
}

// libere matrice

void free_matrix(matrix_t *A)
{
    A->ligne = 0;
    A->colonne= 0;
    free(A->data);
    A->data = NULL;
    free(A);
    A = NULL;
}

// prend la dimension des lignes

int get_ligne(matrix_t* A)
{
    return A-> ligne;
}

// prend la dimension des colonnes 

int get_colonne(matrix_t* A)
{
    int colonne = A->colonne;
    return colonne;
}

// lit un element de la matrice
double get_elem(matrix_t* A, int i, int j)
{
    if(i<0){printf("get_elem error : la ligne %d n'est pas presente dans la matrice\n", i); exit(EXIT_FAILURE);}
    if(i>= get_ligne(A)){printf("get_elem error : la ligne %d n'est pas presente dans la matrice\n",i); exit(EXIT_FAILURE);}
    if(j<0){printf("get_elem error : la colonne %d n'est pas presente dans la matrice\n", j); exit(EXIT_FAILURE);}
    if(j>= get_colonne(A)){printf("get_elem error : colonne %d n'est pas presente dans la matrice\n", j); exit(EXIT_FAILURE);}
    int p = get_colonne(A);
    return (A->data)[p*i+j];
}

// change element dans la matrice
void set_elem(matrix_t* A, int i, int j, double data)
{
    if(i<0){printf("set_elem error : la ligne %d n'est pas presente dans la matrice\n", i); exit(EXIT_FAILURE);}
    if(i>= get_ligne(A)){printf("set_elem error : la ligne %d n'est pas presente dans la matrice\n",i); exit(EXIT_FAILURE);}
    if(j<0){printf("set_elem error : la colonne %d n'est pas presente dans la matrice\n", j); exit(EXIT_FAILURE);}
    if(j>= get_colonne(A)){printf("set_elem error : la colonne %d n'est pas presente dans la matrice\n", j); exit(EXIT_FAILURE);}
    (A->data)[get_colonne(A)*i+j]= data;
}

// copie matrice
void copy_matrix(matrix_t* copy, matrix_t* origine)
{
    int ligne = get_ligne(origine);
    int colonne = get_colonne(origine);
    alloue_matrix(copy, ligne, colonne);
    for(int i = 0; i<ligne; i++ )
    {
        for(int j =0; j<colonne; j++)
        {
            set_elem(copy, i,j, get_elem(origine,i,j));
        }
    }
}

// *************************************** Interactions fichiers **************************************

// affiche matrice
void afficher_matrix(matrix_t* A, FILE* pF_output)
{
    int i, j;
    int ligne = get_ligne(A);
    int colonne = get_colonne(A);
    for(i = 0; i<ligne; i++)
    {
        for(j=0; j<colonne; j++)
        {
            fprintf(pF_output, "%g ", get_elem(A,i,j));
        }
        fprintf(pF_output, "\n");
    }
    fprintf(pF_output, "\n");
}

// lire matrice
void read_matrix (matrix_t* A, FILE* pF_input)
{
    // convention : 
    //-> ligne 1 ligne colonne 
    //-> lignes suivantes data 
    int i, j;
    double d;
    int ligne, colonne; 
    fscanf(pF_input, "%d %d", &ligne, &colonne);
    alloue_matrix(A, ligne, colonne); 
    for (i = 0; i<ligne; i++)
    {
        for(j= 0; j<colonne; j++)
        {
            fscanf(pF_input,"%lf", &d);
            set_elem(A, i, j, d);
        }
    }
}



// **************************************** Matrices utiles ******************************************* 
// matrice nulle 
void zeros(matrix_t* A, int ligne, int colonne)
{
    int i, j;
    alloue_matrix(A, ligne, colonne);
    for (i = 0; i< ligne; i++)
    {
        for(j=0; j<colonne; j++)
        {
            set_elem(A, i, j, 0);
        }
    }
    
}

// matrice identite 
void identity(matrix_t* I, int ligne)
{
    zeros(I, ligne, ligne);
    for (int i = 0; i<ligne; i++)
    {
        set_elem(I, i, i, 1.0);
    }
}



// **************************************** Verif utiles ********************************************
// verif vecteur 1: oui, 0:non
int est_vecteur(matrix_t* v)
{
    int boleen = 1;
    if(get_colonne(v)!=1)
    {
        printf("attention : la matrice d'entree n'est pas un vecteur (colonne) \n");
        boleen= 0;        
    }
    return boleen;
}

// verif carre 1: oui, 0:non
int est_carree(matrix_t* A)
{
    int boleen = 1;
    if(get_colonne(A)!=get_ligne(A))
    {
        printf("attention : la matrice d'entree n'est pas carree \n");
        boleen= 0;        
    }
    return boleen;
}

// verif diagonale
int est_diagonale(matrix_t* A)
{
    int boleen=1;
    int i, j; 
    for (i =0; i<get_ligne(A); i++)
    {
        for(j=0; j<get_colonne(A); j++)
        {
            if (i!=j)  
            {  
                if(get_elem(A, i, j)!=0)
                {
                    boleen = 0;
                    printf("attention : la matrice n'est pas diagonale\n");
                    break;
                }
            }
        }
    }
    return boleen;
}

// verif tri inf
int est_triangulaire_inf(matrix_t* A)
{
    int boleen = 1;
    int i, j; 
    for (i =0; i<get_ligne(A); i++)
    {
        for(j=i+1; j<get_colonne(A); j++)
        {        
            if(get_elem(A, i, j)!=0)
            {
                boleen = 0;
                printf("attention : la matrice n'est pas triangulaire inferieure\n");
                break;
            }
        }
    }
    return boleen;
}

// verif tri sup 
int est_triangulaire_sup(matrix_t* A)
{
    int boleen = 1;
    int i, j;
    for (i =0; i<get_ligne(A); i++)
    {
        for(j=0; j<i; j++)
        { 
            if(get_elem(A, i, j)!=0)
            {
                boleen = 0;
                printf("attention : la matrice n'est pas triangulaire superieure\n");
                break;
            }
        }
    }
    return boleen;
}

// ******************* Operations matricielles ****************************************************** 
// transposer matrice 
void transpose_matrix(matrix_t* Resultat, matrix_t* A)
{
    if(get_colonne(Resultat)!= get_ligne(A)){printf("erreur de dimension pour la transposee"); exit(EXIT_FAILURE);}
    if(get_ligne(Resultat)!=get_colonne(A)){printf("erreur de dimension pour la transposee"); exit(EXIT_FAILURE);}
    for (int i = 0; i<get_ligne(A); i++ )
    {
        for(int j = 0; j<get_colonne(A); j++)
        {
            set_elem(Resultat, j,i, get_elem(A, i,j));
        }   
    }
}

// Somme matricielle
void sum_matrix(matrix_t* Resultat, matrix_t* A, matrix_t* B, double alpha, double beta)
{
    if(get_colonne(A)!=get_colonne(B)){printf("erreur dans la dimension colonne de la somme matricielle"); exit(EXIT_FAILURE);}
    if(get_ligne(A)!= get_ligne(B)){printf("erreur dans la dimension ligne de la somme matricielle"); exit(EXIT_FAILURE);}
    if(get_colonne(A)!=get_colonne(Resultat)){printf("erreur dans la dimension colonne de la somme matricielle"); exit(EXIT_FAILURE);}
    if(get_ligne(A)!= get_ligne(Resultat)){printf("erreur dans la dimension ligne de la somme matricielle"); exit(EXIT_FAILURE);}


    for(int i = 0; i< get_ligne(A); i++)
    {
        for(int j=0; j<get_colonne(A); j++)
        {
            set_elem(Resultat, i, j, alpha*get_elem(A,i,j)+ beta*get_elem(B,i,j));
        }
    }

}

// Produit matriciel 
void product_matrix(matrix_t* Resultat, matrix_t* A, matrix_t* B)
{
    if(get_colonne(A)!=get_ligne(B)){printf("erreur dans la dimension du produit matriciel"); exit(EXIT_FAILURE);}
    if(get_ligne(A)!=get_ligne(Resultat)){printf("erreur dans la dimension de la matrice resultat du produit matriciel"); exit(EXIT_FAILURE);};
    if(get_colonne(B)!=get_colonne(Resultat)){printf("erreur dans la dimension de la matrice resultat du produit matriciel"); exit(EXIT_FAILURE);}
    
    matrix_t* matrice_intermediare = define_matrix();
    double somme=0.0;
    int i, j, k;
    alloue_matrix(matrice_intermediare, get_ligne(Resultat), get_colonne(Resultat));

    for(i= 0; i<get_ligne(A); i++)
    {
        for(j = 0; j<get_colonne(B); j++)
        {
            for (k = 0; k<get_colonne(A);k++ )
            {
                somme+=get_elem(A,i, k)*get_elem(B, k, j);
            }
            set_elem(matrice_intermediare, i,j,somme);
            somme =0.0;
        }
    }

    copy_matrix(Resultat, matrice_intermediare);
    free_matrix(matrice_intermediare);
}


// *************************** Normes ************************************************
// Norme 1 
double norm_1(matrix_t * A)
{
    double somme =0;
    int i;
    int j;
    int ligne = get_ligne(A);
    int colonne = get_colonne(A);
    for (i = 0; i<ligne; i++)
    {
        for (j= 0; j<colonne; j++)
        {
            somme+= fabs(get_elem(A, i, j));
        }
    }

    return somme;
}

// Norme euclidienne 
double norm_euclidienne(matrix_t* A)
{
    double somme = 0;
    int ligne = get_ligne(A);
    int colonne = get_colonne(A);
    int i;
    int j; 
    for (i =0; i<ligne; i++)
    {
        for (j= 0; j<colonne; j++)
        {
            somme+= pow(get_elem(A, i, j),2);
        }
    }
    
    somme = sqrt(somme);
    return somme;
}

// Norme infinie
double norm_sup(matrix_t* A)
{
    int ligne = get_ligne(A);
    int colonne = get_colonne(A);
    double somme= 0.0; 
    double max=0.0;
    int i, j;

    for (i = 0; i<ligne; i++)
    {
        somme =0;
        for(j= 0; j<colonne; j++)
        {
            somme+=fabs(get_elem(A, i, j));
        }
        if(somme>max)
        {
            max= somme;
        }
    }
    
    return max;
}