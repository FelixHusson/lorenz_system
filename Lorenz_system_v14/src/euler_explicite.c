#include "MASTER.h"

matrix_t* euler_explicite(matrix_t* x0, double T, double N, double sigma, double beta, double rho)
{
    int i;
    double dt = T/N; 
    double x, y, z;
    double x1, y1, z1;
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

    for(i = 1; i<=N; i++)
    {
        tn+=dt;
        x1 = x + dt*sigma*(y-x);
        y1 = y + dt*(x*(rho-z) - y);
        z1 = z + dt*(x*y - beta*z);
        
        x= x1;
        y= y1;
        z= z1;

        set_elem(data, i, 0,tn);
        set_elem(data, i, 1, x);
        set_elem(data, i, 2, y);
        set_elem(data, i, 3, z);
        
    }


    return data;
}
