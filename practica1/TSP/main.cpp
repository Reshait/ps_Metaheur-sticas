//compilar con:
//g++ main.cpp instanceTSP.cpp punto.cpp -lm

#include <ctime>
#include "punto.hpp"
#include "instanceTSP.hpp"
#include "solutionTSP.hpp"
#include "solGeneratorTSP.hpp"


using namespace std;

int main(){
	InstanceKP I;
	string nombreFichero;
	SolutionTSP S;
	SolGeneratorTSP Final;

	system("clear");
	srand(time(NULL));

	I.rellenaVector("berlin52.tsp"); //Rellenando Vector

	cout << "Nombre BBDD\t ..: " << I.getNombreBBDD() << endl;
	cout << "Número de Ele\t ..: " << I.getNumEle() << endl;

	for(int i = 0; i < 1000; i++){
		S.setVectorSol(I.getVector());
		S.cambiaPosiciones();
		S.obtenSuma();
//		S.imprimeSolucion();
		Final.aniadeSolucion(S);
		S.setSuma(0);
		if(i == 99 || i == 199 || i == 299 || i == 399 || i == 499 || i == 599 || i == 699 || i == 799 || i == 899)
			Final.getMejorSol().imprimeSolucion();

	}

	Final.getMejorSol().imprimeSolucion();

	return 0;
}