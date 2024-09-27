int main(void){
  	assert(fabs(trapezoidal(f1, 5, 10, 0.00001, 2) - 291.667) <= 0.001);
	assert(fabs(trapezoidal(f2, PI / 2, 3, 0.00001, 5) - -0.858879) <= 0.000001);
	assert(fabs(trapezoidal(f3, 1, 4, 0.00001, 2) - 4.666) <= 0.001);
	
  	return 0;
}