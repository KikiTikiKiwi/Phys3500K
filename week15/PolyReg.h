#include<vector>
#include "vector_fwrd.h"

double sumation(Vec a);
void print_Vector(Vec vec);
void print_matrix(Mat mat);
double average(Vec a, int N_points);
void Guass_elim_Piv(Mat& A, Vec& b, int N_dim);
void back_sub(Mat A, Vec b, Vec& con, int N_dim);
double generate_S(int N_points, Vec x, Vec y, Vec u, int px, int py);
void generate_A_matrix(int N_points, Vec x, Vec y, Vec u, Mat& A, int N_dim);
void generate_b_vec(int N_points, Vec x, Vec y, Vec u, Vec& b, int N_dim);
double g_of_x(double x, Vec c, int N_dim);
double chiSquared(Vec c, Vec x, Vec y, Vec u, int N_dim);
double fit_goodness(Vec con, Vec x_data, Vec y_data, Vec u_data, int N_data, int N_dim);
