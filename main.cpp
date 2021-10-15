
#include <cstdlib>
#include <iostream>
#include <thread>
#include <future>

using namespace std;


const long m=1000000;
const int n = 8;
const int cantidad_por_hebra = m/n;

double f(int num_hebra){
	double suma = 0.0;
	
	for(int i=0+cantidad_por_hebra*num_hebra; i < cantidad_por_hebra + cantidad_por_hebra*num_hebra; i++){

		const double xj = double(i+0.5)/m;
		suma += 4.0/(1+xj*xj);
	}

	return suma/m;
}

int main()
{
	double suma;

	future<double> futuros[n];

	for(int i=0; i<n; i++){

		futuros[i] = async(launch::async, f,i);
	}

	for(int j=0; j<n; j++)
		suma += futuros[j].get();
	
	cout << suma << endl;
	


}