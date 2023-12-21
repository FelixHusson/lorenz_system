#ifndef _NON_LINEAR_SOLVERS_H_
#define _NON_LINEAR_SOLVERS_H_



double point_fixe(int kmax,double x0, double(* f)(double), double eps );

double newton(int kmax,double x0, double(* f)(double), double (* df)(double), double eps );







#endif