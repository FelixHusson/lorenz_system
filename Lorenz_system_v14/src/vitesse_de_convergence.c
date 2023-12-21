#include "MASTER.h"
#include "euler_implicite.h"
#include "euler_explicite.h"
#include "RK4.h"
#include "comparaison.h"



int vitesse_convergence_explicite(matrix_t* explicite, int N, double beta, double rho)
{
    FILE* pF_output = NULL;
    pF_output= fopen("vitesse_convergence/vitesse_explicite.txt","w");
    if(pF_output==NULL){printf("error in vitesse_convergence_explicite"); exit(EXIT_FAILURE);}

    int i; 
    double x, y, z, x1, y1, z1, x_theo, y_theo, z_theo;
    x_theo = sqrt(beta* (rho-1));
    y_theo = x_theo;
    z_theo = rho-1; 
    double distance; 
    double erreur; 
    matrix_t* vitesse_explicite = define_matrix();
    alloue_matrix(vitesse_explicite, N, 3);

    x= get_elem(explicite, 0,0);
    y= get_elem(explicite, 0, 1);
    z= get_elem(explicite, 0, 2); 

    set_elem(vitesse_explicite, 0, 0, 0);
    set_elem(vitesse_explicite, 0,1, 0);
    set_elem(vitesse_explicite, 0,2,0);


    for (i= 1; i<N; i++ )
    {

        set_elem(vitesse_explicite, i, 0, get_elem(explicite, i, 0)); // colonne 1 : mise en place de t 
        x1 = get_elem(explicite, i, 1);
        y1 = get_elem(explicite, i, 2);
        z1 = get_elem(explicite, i, 3);

        distance = sqrt ( pow(x1-x_theo,2)+ pow(y1-y_theo,2) + pow(z1-z_theo,2));
        set_elem(vitesse_explicite, i, 1, distance);

        erreur = sqrt ( pow(x1-x,2)+ pow(y1-y,2) + pow(z1-z,2));
        set_elem(vitesse_explicite, i, 2,erreur);

        x=x1;
        y=y1;
        z=z1;
    }


    // affichage
    afficher_matrix(vitesse_explicite, pF_output);
    
    // Liberation mémoire
    free_matrix(vitesse_explicite);
    free(pF_output);
    pF_output = NULL;

    return EXIT_SUCCESS;
}


int vitesse_convergence_implicite(matrix_t* implicite, int N, double beta, double rho)
{
    FILE* pF_output = NULL;
    pF_output= fopen("vitesse_convergence/vitesse_implicite.txt","w");
    if(pF_output==NULL){printf("error in vitesse_convergence_implicite"); exit(EXIT_FAILURE);}

    int i; 
    double x, y, z, x1, y1, z1, x_theo, y_theo, z_theo;
    x_theo = sqrt(beta* (rho-1));
    y_theo = x_theo;
    z_theo = rho-1; 
    double distance; 
    double erreur; 
    matrix_t* vitesse_implicite = define_matrix();
    alloue_matrix(vitesse_implicite, N, 3);

    x= get_elem(implicite, 0,0);
    y= get_elem(implicite, 0, 1);
    z= get_elem(implicite, 0, 2); 

    set_elem(vitesse_implicite, 0, 0, 0);
    set_elem(vitesse_implicite, 0,1, 0);
    set_elem(vitesse_implicite, 0,2,0);


    for (i= 1; i<N; i++ )
    {

        set_elem(vitesse_implicite, i, 0, get_elem(implicite, i, 0)); // colonne 1 : mise en place de t 
        x1 = get_elem(implicite, i, 1);
        y1 = get_elem(implicite, i, 2);
        z1 = get_elem(implicite, i, 3);

        distance = sqrt ( pow(x1-x_theo,2)+ pow(y1-y_theo,2) + pow(z1-z_theo,2));
        set_elem(vitesse_implicite, i, 1, distance);

        erreur = sqrt ( pow(x1-x,2)+ pow(y1-y,2) + pow(z1-z,2));
        set_elem(vitesse_implicite, i, 2,erreur);

        x=x1;
        y=y1;
        z=z1;
    }


    // affichage
    afficher_matrix(vitesse_implicite, pF_output);
    
    // Liberation mémoire
    free_matrix(vitesse_implicite);
    free(pF_output);
    pF_output = NULL;

    return EXIT_SUCCESS;
}

int vitesse_convergence_RK4(matrix_t* RK4, int N, double beta, double rho)
{
    FILE* pF_output = NULL;
    pF_output= fopen("vitesse_convergence/vitesse_RK4.txt","w");
    if(pF_output==NULL){printf("error in vitesse_convergence_RK4"); exit(EXIT_FAILURE);}

    int i; 
    double x, y, z, x1, y1, z1, x_theo, y_theo, z_theo;
    x_theo = sqrt(beta* (rho-1));
    y_theo = x_theo;
    z_theo = rho-1; 
    double distance; 
    double erreur; 
    matrix_t* vitesse_RK4 = define_matrix();
    alloue_matrix(vitesse_RK4, N, 3);

    x= get_elem(RK4, 0,0);
    y= get_elem(RK4, 0, 1);
    z= get_elem(RK4, 0, 2); 

    set_elem(vitesse_RK4, 0, 0, 0);
    set_elem(vitesse_RK4, 0,1, 0);
    set_elem(vitesse_RK4, 0,2,0);


    for (i= 1; i<N; i++ )
    {

        set_elem(vitesse_RK4, i, 0, get_elem(RK4, i, 0)); // colonne 1 : mise en place de t 
        x1 = get_elem(RK4, i, 1);
        y1 = get_elem(RK4, i, 2);
        z1 = get_elem(RK4, i, 3);

        distance = sqrt ( pow(x1-x_theo,2)+ pow(y1-y_theo,2) + pow(z1-z_theo,2));
        set_elem(vitesse_RK4, i, 1, distance);

        erreur = sqrt ( pow(x1-x,2)+ pow(y1-y,2) + pow(z1-z,2));
        set_elem(vitesse_RK4, i, 2,erreur);

        x=x1;
        y=y1;
        z=z1;
    }


    // affichage
    afficher_matrix(vitesse_RK4, pF_output);
    
    // Liberation mémoire
    free_matrix(vitesse_RK4);
    free(pF_output);
    pF_output = NULL;

    return EXIT_SUCCESS;
}