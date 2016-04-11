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
	}

	Final.getMejorSol().imprimeSolucion();

	return 0;
}