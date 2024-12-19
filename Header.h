#pragma once
#include<iostream>
#include<cmath>
#include<numbers>
#include<vector>
#include<functional>
double f(double x) {
	return  x * std::sin(4 * std::numbers::pi * x) ;
}
template<typename t,typename u>
double simpson(double a,double b,t callable1,u callable2,double h) {//callables
	double sum = 0;
	double xi = a;
	size_t iterations = static_cast<size_t>((b - a) / h);
	for (size_t i = 0; i < iterations; i++) {
		double isimp = (callable1(xi) * callable2(xi) + 4 * callable1((xi + xi + h) / 2) * callable2((xi + xi + h) / 2) + callable1(xi + h) * callable2(xi + h)) * h / 6;
		sum += isimp;
		xi += h;

	}   
	return sum;
}
std::vector<double>gauss_elimination(std::vector<std::vector<double>>a,std::vector<double>b) {

	for (size_t k = 0; k < a.size(); k++) {
		size_t row1 = k;
		size_t row2 = k;
		double max = std::abs(a[k][k]);

		for (size_t i = k + 1; i < a.size(); i++) {
			if (std::abs(a[i][k]) > max) {
				max = std::abs(a[i][k]);
				row2 = i;
			}
		}
		if (max == 0) {
			std::cout << "error\n";
			std::exit(EXIT_FAILURE);

		}


		std::vector<double>c = a[row1];
		a[row1] = a[row2];
		a[row2] = c;
		double temp = b[row1];
		b[row1] = b[row2];
		b[row2] = temp;

		for (size_t i = k + 1; i < a.size(); i++) {
			double kati = a[i][k] / a[k][k];

			for (size_t j = k; j < a.size(); j++) {

				a[i][j] = a[i][j] - kati * a[k][j];

			}
			b[i] = b[i] - kati * b[k];
		}

	}

	if (a[a.size() - 1][a.size() - 1] == 0) {
		std::cout << "error\n";
		std::exit(EXIT_FAILURE);
	}
	//backwards substitution:
	std::vector <double>x(a.size());
	for (size_t k = a.size() - 1; k > 0; k--) {

		x[k] = b[k];
		for (size_t j = k + 1; j < a.size(); j++) {
			x[k] = (x[k] - a[k][j] * x[j]);
		}
		x[k] = x[k] / a[k][k];


	}
	size_t k = 0;
	while (k == 0) {
		x[k] = b[k];
		for (size_t j = k + 1; j < a.size(); j++) {
			x[k] = (x[k] - a[k][j] * x[j]);
		}
		x[k] = x[k] / a[k][k];
		break;
	}
	
	return x;
}

double pf(std::vector<double>c, std::vector<std::function<double(double)>> pi,double xi) {
	double sum = 0;
	
	for (size_t i = 0; i <c.size(); i++) {
		sum += c[i] *pi[i](xi);
	}
	return sum;
}

