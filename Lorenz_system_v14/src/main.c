#include "MASTER.h"
#include "euler_explicite.h"
#include "euler_implicite.h"
#include"RK4.h"
#include "comparaison.h"

int main(int argc, char* argv[])
{
    // *********************************** LECTURE ARGC ARGV **********************************************
    if(argc!=5){printf("error in main : le programme doit recevoir 4 arguments : fichier entree et 3 fichiers sortie"); exit(EXIT_FAILURE);}
    char* intput_filename = argv[1];
    char* output_filename_explicite = argv[2];
    char* output_filename_implicite = argv[3];
    char* output_filename_RK4 = argv[4]; 

    // *************************************** VARIABLES  *************************************************
    // Variables en fichier entree
    double T;
    int N; 
    double sigma;
    double beta;
    double rho;
    matrix_t* x0 = define_matrix();

    // Variables programme

    matrix_t*  euler_explicite_matrix = define_matrix();
    matrix_t*  euler_implicite_matrix = define_matrix();
    matrix_t*  RK4_matrix = define_matrix();



    // *********************************** LECTURE FICHIER ENTREE ******************************************
    FILE* pF_input = NULL;
    FILE* pF_x0 = NULL; 
    pF_input = fopen(intput_filename, "r");
    pF_x0 = fopen("x0.txt", "r");
    if(pF_input==NULL){printf("error in main : echec d'ouverture du fichier entree"); exit(EXIT_FAILURE);}
    if(pF_x0==NULL){printf("error in main : echec d'ouverture du fichier entree de x0"); exit(EXIT_FAILURE);}

    fscanf(pF_input, "%lf %d %lf %lf %lf", &T, &N, &sigma, &beta, &rho);
    read_matrix(x0, pF_x0);

    fclose(pF_input);
    fclose(pF_x0);
    pF_input=NULL;
    pF_x0 = NULL;

    printf("Confirmation des valeurs d'entree:\n Valeur de T vaut %lf\n Valeur de N vaut %d\n Valeur de sigma vaut %lf\n Valeur de beta vaut %lf\n Valeur de rho vaut %lf\n", T, N, sigma, beta, rho );

    // ********************************** ACCES FICHIER ECRITURE ******************************************
    FILE* pF_output_explicite = NULL;
    FILE* pF_output_implicite = NULL;
    FILE* pF_output_RK4 = NULL;


    pF_output_explicite = fopen(output_filename_explicite, "w");
    pF_output_implicite = fopen(output_filename_implicite, "w");
    pF_output_RK4 = fopen(output_filename_RK4, "w");

    if(pF_output_explicite==NULL){printf("error in main : echec d'acces au fichier sortie"); exit(EXIT_FAILURE);}
    if(pF_output_implicite==NULL){printf("error in main : echec d'acces au fichier sortie"); exit(EXIT_FAILURE);}
    if(pF_output_RK4==NULL){printf("error in main : echec d'acces au fichier sortie"); exit(EXIT_FAILURE);}


    // *************************************** PROGRAMME *************************************************** 

    alloue_matrix(euler_explicite_matrix, N+1,4);
    alloue_matrix(euler_implicite_matrix, N+1,4);
    alloue_matrix(RK4_matrix, N+1,4);


    euler_explicite_matrix = euler_explicite(x0, T, N, sigma, beta, rho);
    euler_implicite_matrix = euler_implicite(x0, T, N, sigma, beta, rho);


    RK4_matrix = RK4(x0, T, N, sigma, beta, rho);
    
    afficher_matrix(euler_explicite_matrix, pF_output_explicite);
    afficher_matrix(euler_implicite_matrix, pF_output_implicite);
    afficher_matrix(RK4_matrix, pF_output_RK4);



    // ****************************** Deuxieme graphe de stabilite pour implicite **************



    // **********************Comparaison des resultats *******************************************************
    
    //                                  stabilite
    //double epsilon = 0.02;
    //comparaison_explicite(T, N, sigma, beta, rho, x0, epsilon);
    //comparaison_implicite(T, N, sigma, beta, rho, x0, epsilon);
    //comparaison_RK4(T, N, sigma, beta, rho, x0, epsilon);

    // ***** Deuxieme graphe de stabilite pour implicite ****
    //stabilite_implicite(x0, T, N, sigma, beta, rho, epsilon);

    // ***** Deuxieme graphe de stabilite pour explicite ****
    //stabilite_explicite(x0, T, N, sigma, beta, rho, epsilon);

    // ***** Deuxieme graphe de stabilite pour RK4 ****
    //stabilite_RK4(x0, T, N, sigma, beta, rho, epsilon);

    

    //                              Vitesse de convergence
    //vitesse_convergence_explicite(euler_explicite_matrix, N, beta, rho);
    //vitesse_convergence_implicite(euler_implicite_matrix, N, beta, rho);
    //vitesse_convergence_RK4(RK4_matrix, N, beta, rho);

    // *********************************** LIBERATION MEMOIRE ***********************************************
    fclose(pF_output_explicite); pF_output_explicite=NULL;
    fclose(pF_output_implicite); pF_output_implicite=NULL;    
    fclose(pF_output_RK4); pF_output_RK4=NULL;    
    free_matrix(x0);
    free_matrix(euler_explicite_matrix);
    free_matrix(euler_implicite_matrix);
    free_matrix(RK4_matrix); 






    return EXIT_SUCCESS;
}