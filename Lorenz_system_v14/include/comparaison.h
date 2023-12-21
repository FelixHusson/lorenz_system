#ifndef _COMPARAISON_H_
#define _COMPARAISON_H_

int comparaison_explicite(double T, int N, double sigma, double beta, double rho, matrix_t* x0, double epsilon );

int comparaison_implicite(double T, int N, double sigma, double beta, double rho, matrix_t* x0, double epsilon );

int comparaison_RK4(double T, int N, double sigma, double beta, double rho, matrix_t* x0, double epsilon );

int stabilite_implicite(matrix_t* x0, double T, int N, double sigma, double beta, double rho, double epsilon);

int stabilite_explicite(matrix_t* x0, double T, int N, double sigma, double beta, double rho, double epsilon);

int stabilite_RK4(matrix_t* x0, double T, int N, double sigma, double beta, double rho, double epsilon);

int vitesse_convergence_explicite(matrix_t* explicite, int N, double beta, double rho);

int vitesse_convergence_implicite(matrix_t* implicite, int N, double beta, double rho);

int vitesse_convergence_RK4(matrix_t* RK4, int N, double beta, double rho);

#endif





