#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	Kp_ = Kp;
	Ki_ = Ki;
	Kd_ = Kd;
	is_error_init = false;
}

void PID::UpdateError(double cte) {
	if (!is_error_init){
		p_error = cte;
		d_error = 0.0;
		i_error = cte;
		is_error_init = true;
	}
	d_error = cte - p_error;
	i_error += cte;
	p_error = cte;

}

double PID::CalculateSteering() {
	return -Kp_*p_error - Kd_*d_error - Ki_*i_error;
}

