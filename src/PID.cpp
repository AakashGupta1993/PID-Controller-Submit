#include "PID.h"
#include "math.h"
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
	Kp = 0;
	Ki = 0;
	Kd = 0;
  p_error = 0;
  i_error = 0;
  d_error = 0;
  count = 0;
  errorSum=0;
  dp = [1,1,1];
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
}

void PID::UpdateError(double cte) {
	
  d_error = cte - p_error;	      
  p_error = cte;                  
  i_error += cte;                 
  errorSum = errorSum + fabs(cte);
}

double PID::TotalError() {
	double steer = -Kp*p_error - Kd*d_error - Ki*i_error;
  return steer;
}

void PID::UpdateCount(){
    count++;
}

int PID::GetCount(){
	return count;
}

double long PID::GetSum(){
	return errorSum;
}

void PID::SetCount(){
    count = 0;
	errorSum = 0;
}