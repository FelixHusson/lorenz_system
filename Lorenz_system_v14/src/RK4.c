#include "MASTER.h"

matrix_t* RK4 (matrix_t* x0, double T, double N, double sigma, double beta, double rho)
{
    int i;
    double h = T/N;
    double k12, k22, k32, k42, k11, k21, k31, k41;

    double k13, k23, k33, k43;

    double yn1, yn;
    double xn1, xn;
    double zn1, zn;
    double tn = 0;

    matrix_t * data = define_matrix();
    alloue_matrix(data, N+1,4);

    xn= get_elem(x0, 0, 0);
    yn= get_elem(x0, 1, 0);
    zn= get_elem(x0, 2, 0);

    set_elem(data, 0, 0, tn);
    set_elem(data, 0, 1, xn);
    set_elem(data, 0, 2, yn);
    set_elem(data, 0, 3, zn);

    for(i=1;i<=N;i++)
    {   
        tn+=h;
        k11=sigma*(yn-xn);
        k21=sigma*(yn-(xn+h*k11/2));
        k31=sigma*(yn-(xn+h*k21/2));
        k41=sigma*(yn-(xn+h*k31));
        xn1=xn+h*(k11+2*k21+2*k31+k41)/6;

        k12=rho*xn-yn-xn*zn;
        k22=rho*xn-(yn+h*k12/2)-xn*zn;
        k32=rho*xn-(yn+h*k22/2)-xn*zn;
        k42=rho*xn-(yn+h*k32)-xn*zn;
        yn1=yn+h*(k12+2*k22+2*k32+k42)/6;
 
        k13=xn*yn-beta*zn;
        k23=xn*yn-beta*(zn+h*k13/2);
        k33=xn*yn-beta*(zn+h*k23/2);
        k43=xn*yn-beta*(zn+h*k33);
        zn1=zn+h*(k13+2*k23+2*k33+k43)/6;

        set_elem(data, i, 0, tn);
        set_elem(data, i, 1, xn1);
        set_elem(data, i, 2, yn1);
        set_elem(data, i, 3, zn1);  
        yn=yn1;
        xn=xn1;
        zn=zn1;     
        
    }
return(data);

}