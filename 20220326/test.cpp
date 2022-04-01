#include <iostream>
#include <vector>
#include <cmath>
#include <string>

float datax[20];
float datay[20];

float dis(float x, float y, float a, float b)
{
    return abs(a * x - y + b) / sqrt(a * a + 1); 
}

float  f(float a, float b) {
	float sum = 0.0;
	for (int i = 0; i < 20; i++) {
		sum += dis(datax[i], datay[i], a, b) / 20;
	}
	return sum;
}

float dfabda(float a, float b, float da) 
{
    return (f(a + da, b) - f(a, b)) / da;
}

float dfabdb(float a, float b, float db)  
{
    return (f(a, b+db) - f(a, b)) / db;
}
 
int main(){
    	for(int i=0; i<20; i++){
			datax[i] = i+0.5;
			datay[i] = i-0.5;
			printf("%f   |  %f\n", datax[i], datay[i]);
		}
	float a0 = 0;
	float b0 = 0;
	
	int iteration = 0;
	
	float eta = 0.0001;
	float psi = 0.005;
	
	float da = 0.01;
	float db = 0.01;
	
	float a1 = 2;
	float b1 = 2;
	while (dis(a0, b0, a1, b1) > eta && iteration < 1000000) {
		a0 = a1;
		b0 = b1;
		a1 -=   psi * dfabda(a0, b0, da);
		b1 -=   psi * dfabdb(a0, b0, db);
		iteration++;
	}
	printf("y = %f  x + %f\n",a1,b1);
	printf("iteration = %d  E = %f\n",iteration,dis(a0, b0, a1, b1));
	return 0;
}
