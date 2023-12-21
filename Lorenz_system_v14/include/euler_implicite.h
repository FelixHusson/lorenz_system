#ifndef _EULER_IMPLICITE_H_
#define _EULER_IMPLICITE_H_

double newton_lorenz(double x_ini, double y_ini, double z_ini,double T, double N, double sigma, double beta, double rho );

matrix_t* euler_implicite(matrix_t* x0, double T, double N, double sigma, double beta, double rho);


#endif