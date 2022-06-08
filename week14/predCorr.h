#include<vector>
typedef std::vector<double> Vec;

Vec trap_pred_corrector(double t_f, double t_intitial, double y_initial, double n, double (*func)(double, double));
