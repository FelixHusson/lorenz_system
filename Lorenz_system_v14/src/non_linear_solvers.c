#include "MASTER.h"

// point fixe
double point_fixe(int kmax,double x0, double(* f)(double), double eps )
{
    int compteur = 0;
    double x = x0;
    double fx;
    double erreur = eps+1;
    while ((compteur<kmax)&&(erreur>eps))
    {
        compteur++;
        fx= (*f)(x);
        erreur = fabs((x-fx)/(fabs(fx)+1));
        x= fx;
    }

    printf("nombre iteration de la methode du point fixe %d\n", compteur);
    if(compteur>=kmax){printf("probleme de convergence de la methode du point fixe\n"); return(EXIT_FAILURE);}
    else{
        return fx;
    }
    
}

double newton(int kmax,double x0, double(* f)(double), double (* df)(double), double eps )
{
    double erreur = eps+1;
    double x,xp;
    int compteur = 0;
    x=x0;
    while ((compteur<kmax)&&(erreur>eps))
    {
        compteur ++;
        xp=x;
        x = xp- (*f)(xp)/(*df)(xp);
        erreur = fabs((xp-x)/(fabs(x)+1));
        
    }

    if(compteur>=kmax){printf("probleme de convergence de la methode de newton\n"); exit(EXIT_FAILURE);}
    else{
        return x;
    }
    
}


//newton 
