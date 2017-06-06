#ifndef PID_H
#define PID_H

#include <iostream>
#include <stdlib.h>

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */
  double Kp;
  double Ki;
  double Kd;

  /*
   * Twiddle
   */
  double dp;
  double di;
  double dd;
  double best_err;

 /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  /*
  * Parameter Optimization
  */
  double Sigmoid(double value, double min, double max);

};

#endif /* PID_H */
