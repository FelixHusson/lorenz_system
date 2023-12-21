#include "MASTER.h"
#include"non_linear_solvers.h"



double newton_lorenz(double x_ini, double y_ini, double z_ini,double T, double N, double sigma, double beta, double rho )
{
    int kmax = 20; 
    double y0 = y_ini+10;
    double eps = 1e-15;
    double y_resultat= 0;

    double h= T/N;
    double A= 1+h*sigma;
    double B = 1+h;
    double C= 1+beta*h;

    double f(double y)
    {
        return pow(A,2)*C*y_ini+ A*C*h*rho*x_ini - A*h*z_ini*x_ini + y*(A*C*pow(h,2)*rho*sigma - A*pow(h,2)*sigma*z_ini - pow(x_ini*h,2) -A*A*B*C)-y*y*2*x_ini * sigma*pow(h,3)-pow(y,3)*pow(h*h*sigma, 2);
    }

    double df(double y)
    {
        return (A*C*pow(h,2)*rho*sigma - A*pow(h,2)*sigma*z_ini - pow(x_ini*h,2) -A*A*B*C)-4*x_ini*sigma*pow(h,3)*y- 3 * pow(y*h*h,2)*sigma*sigma;
    }
    
    y_resultat = newton(kmax, y0, f, df, eps);
    return y_resultat;
}



matrix_t* euler_implicite(matrix_t* x0, double T, double N, double sigma, double beta, double rho)
{
    int i;
    double h = T/N; 
    double A= 1+h*sigma;
    double C= 1+beta*h;
    double x, y, z;
    double tn = 0;
    matrix_t * data = define_matrix();
    
    alloue_matrix(data, N+1, 4);
    x= get_elem(x0, 0, 0);
    y= get_elem(x0, 1, 0);
    z= get_elem(x0, 2, 0);

    set_elem(data, 0, 0, tn);
    set_elem(data, 0, 1, x);
    set_elem(data, 0, 2, y);
    set_elem(data, 0, 3, z);

    for (i = 1; i<=N; i++)
    {
        tn+=h;
        y= newton_lorenz(x,y,z, T, N, sigma, beta, rho);

        x= (x + h*sigma*y)/A;
        z= (z + h*x*y)/C;

        set_elem(data, i, 0,tn);
        set_elem(data, i, 1, x);
        set_elem(data, i, 2, y);
        set_elem(data, i, 3, z);

    }

    return data;
}
