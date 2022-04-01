#include <iostream>
#include <cmath>

int i=0;
float x[] = {2, 4, 6, 8};
float y[] = {81, 93, 91, 97};

float avg_array(float array[]){
	float sum = 0;
	for(i = 0; i < 4; i++){
		sum += array[i];
	}
	return (sum/4);
};

float gradient_line(float array_x[], float array_y[], float avg_x, float avg_y){
	float divisor = 0;
	float dividend = 0;
	
	for(i = 0; i < 4; i++)
	{
		divisor += pow((array_x[i] - avg_x),2);
		dividend += (array_x[i] - avg_x) * (array_y[i] - avg_y);
		printf("%f, %f  |\t",array_x[i],array_y[i]);
		printf("%f %f\n", divisor, dividend);
	}
	return dividend/divisor;
}

float yyy(float avg_x, float avg_y, float gradient){
	return avg_y-(avg_x * gradient);
}



int main() {

	float avg_x = avg_array(x);
	float avg_y = avg_array(y);
	float gradient= gradient_line(x, y, avg_x, avg_y);
	float yy = yyy(avg_x, avg_y, gradient);
	
	printf("average(x) : %f    average(y) : %f\n", avg_x, avg_y);
	printf("y = %fx+ %f\n", gradient, yy);
	
		return 0;
}
