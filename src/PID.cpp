#include "PID.h"
#include <math.h>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;
    p_error = d_error = i_error = 0;
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    p_error = cte;
    i_error = i_error + cte;
}

double PID::TotalError() {
    return -(p_error * Kp) - (i_error * Ki) - (d_error * Kd);
}

double PID::Sigmoid(double value, double min, double max) {
    return (max - min)/(1 + exp(-value)) + min;
}