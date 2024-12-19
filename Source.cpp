#include"Header.h"


int main() {
	double a{};
	double b{};
	size_t n{};
	auto lambda0 = [](double x)->double {
		return 1;
	};
	auto lambda1 = [](double x)->double {
		return x;
	};
	auto lambda2 = [](double x)->double {
		return 1.0/2.0*(3*std::pow(x,2)-1);
	};
	auto lambda3 = [](double x) ->double {
		return 1.0/2.0*(5*std::pow(x,3)-3*x);
	};
	auto lambda4 = [](double x) ->double {
		return 1.0/8.0*(35*std::pow(x,4)-30*std::pow(x,2)+3);
	};
	std::cout << "give a and b for the interval [a,b]\n";
	std::cout << "give a:\n";
	std::cin >> a;
	std::cout << "give b:\n";
	std::cin >> b;
	std::cout << "give n:\n";
	std::cin >> n;
	double h = 0.001;
	std::vector<std::vector<double>>A(n);
	std::vector<double>F(n);
	std::vector<std::function<double(double)>> pi;
		if ((n-1) == 0) {
			A[0].push_back(simpson(a,b,lambda0,lambda0,h));
			
			F[0] = simpson(a, b, f, lambda0,h);
			pi.push_back(lambda0);
			
	    }
		else if ((n-1) == 1) {
			A[0].push_back(simpson(a, b, lambda0, lambda0, h));
			A[0].push_back(simpson(a, b, lambda0, lambda1, h));
			A[1].push_back(simpson(a, b, lambda1, lambda0, h));
			A[1].push_back(simpson(a, b, lambda1, lambda1, h));
			F[0] = simpson(a, b, f, lambda0, h);
		    F[1] = simpson(a, b, f, lambda1, h);
			pi.push_back(lambda0);
			pi.push_back(lambda1);
		}
		else if ((n-1) == 2) {
			A[0].push_back(simpson(a, b, lambda0, lambda0, h));
			A[0].push_back(simpson(a, b, lambda0, lambda1, h));
			A[0].push_back(simpson(a, b, lambda0, lambda2, h));
			A[1].push_back(simpson(a, b, lambda1, lambda0, h));
			A[1].push_back(simpson(a, b, lambda1, lambda1, h));
			A[1].push_back(simpson(a, b, lambda1, lambda2, h));
			A[2].push_back(simpson(a, b, lambda2, lambda0, h));
			A[2].push_back(simpson(a, b, lambda2, lambda1, h));
			A[2].push_back(simpson(a, b, lambda2, lambda2, h));
			F[0] = simpson(a, b, f, lambda0, h);
			F[1] = simpson(a, b, f, lambda1, h);
			F[2] = simpson(a, b, f, lambda2, h);
			pi.push_back(lambda0);
			pi.push_back(lambda1);
			pi.push_back(lambda2);
		}
		else if ((n-1) == 3) {
			A[0].push_back(simpson(a, b, lambda0, lambda0, h));
			A[0].push_back(simpson(a, b, lambda0, lambda1, h));
			A[0].push_back(simpson(a, b, lambda0, lambda2, h));
			A[0].push_back(simpson(a, b, lambda0, lambda3, h));
			A[1].push_back(simpson(a, b, lambda1, lambda0, h));
			A[1].push_back(simpson(a, b, lambda1, lambda1, h));
			A[1].push_back(simpson(a, b, lambda1, lambda2, h));
			A[1].push_back(simpson(a, b, lambda1, lambda3, h));
			A[2].push_back(simpson(a, b, lambda2, lambda0, h));
			A[2].push_back(simpson(a, b, lambda2, lambda1, h));
			A[2].push_back(simpson(a, b, lambda2, lambda2, h));
			A[2].push_back(simpson(a, b, lambda2, lambda3, h));
			A[3].push_back(simpson(a, b, lambda3, lambda0, h));
			A[3].push_back(simpson(a, b, lambda3, lambda1, h));
			A[3].push_back(simpson(a, b, lambda3, lambda2, h));
			A[3].push_back(simpson(a, b, lambda3, lambda3, h));
			F[0] = simpson(a, b, f, lambda0, h);
			F[1] = simpson(a, b, f, lambda1, h);
			F[2] = simpson(a, b, f, lambda2, h);
			F[3] = simpson(a, b, f, lambda3, h);
			pi.push_back(lambda0);
			pi.push_back(lambda1);
			pi.push_back(lambda2);
			pi.push_back(lambda3);
		}
		else {
			A[0].push_back(simpson(a, b, lambda0, lambda0, h));
			A[0].push_back(simpson(a, b, lambda0, lambda1, h));
			A[0].push_back(simpson(a, b, lambda0, lambda2, h));
			A[0].push_back(simpson(a, b, lambda0, lambda3, h));
			A[0].push_back(simpson(a, b, lambda0, lambda4, h));
			A[1].push_back(simpson(a, b, lambda1, lambda0, h));
			A[1].push_back(simpson(a, b, lambda1, lambda1, h));
			A[1].push_back(simpson(a, b, lambda1, lambda2, h));
			A[1].push_back(simpson(a, b, lambda1, lambda3, h));
			A[1].push_back(simpson(a, b, lambda1, lambda4, h));
			A[2].push_back(simpson(a, b, lambda2, lambda0, h));
			A[2].push_back(simpson(a, b, lambda2, lambda1, h));
			A[2].push_back(simpson(a, b, lambda2, lambda2, h));
			A[2].push_back(simpson(a, b, lambda2, lambda3, h));
			A[2].push_back(simpson(a, b, lambda2, lambda4, h));
			A[3].push_back(simpson(a, b, lambda3, lambda0, h));
			A[3].push_back(simpson(a, b, lambda3, lambda1, h));
			A[3].push_back(simpson(a, b, lambda3, lambda2, h));
			A[3].push_back(simpson(a, b, lambda3, lambda3, h));
			A[3].push_back(simpson(a, b, lambda3, lambda4, h));
			A[4].push_back(simpson(a, b, lambda4, lambda0, h));
			A[4].push_back(simpson(a, b, lambda4, lambda1, h));
			A[4].push_back(simpson(a, b, lambda4, lambda2, h));
			A[4].push_back(simpson(a, b, lambda4, lambda3, h));
			A[4].push_back(simpson(a, b, lambda4, lambda4, h));
			F[0] = simpson(a, b, f, lambda0, h);
			F[1] = simpson(a, b, f, lambda1, h);
			F[2] = simpson(a, b, f, lambda2, h);
			F[3] = simpson(a, b, f, lambda3, h);
			F[4] = simpson(a, b, f, lambda4, h);
			pi.push_back(lambda0);
			pi.push_back(lambda1);
			pi.push_back(lambda2);
			pi.push_back(lambda3);
			pi.push_back(lambda4);
		}
	
		
		std::vector<double>C;
		
	
			
			
		
	    C=gauss_elimination(A, F);
		
		//std::cout << C.size()<<"\n\n";
		double sum = 0;
		double xi = a;
		size_t iterations = static_cast<size_t>((b - a) / h);
		for (size_t i = 0; i < iterations; i++) {
			double isimp=(std::pow(f(xi) - pf(C, pi, xi),2)+
			4* std::pow(f((xi + xi + h) / 2) - pf(C, pi, (xi + xi + h) / 2), 2)+
			std::pow(f(xi+h) - pf(C, pi, xi+h), 2))*h/6;
			xi += h;
			sum += isimp;
		}
		std::cout << sum << '\n';


}