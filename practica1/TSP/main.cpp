//compilar con:
//g++ main.cpp instanceKP.cpp objeto.cpp

#include <string>
#include <ctime>
#include "objeto.hpp"
#include "instanceTSP.hpp"
//#include "solutionKP.hpp"
//#include "solGenerator.hpp"


using namespace std;

int main(){
	InstanceKP I;
	string nombreFichero;

	system("clear");
	srand(time(NULL));

/*	do{
		cout << "Introduzca el nombre del fichero a cargar ..: ";
		cin >> nombreFichero;
		I.rellenaVector(nombreFichero);
	}while(!I.rellenaVector(nombreFichero));
*/
	I.rellenaVector("berlin52.tsp"); //cambiar por lo anterior cuando esté terminado.

	cout << "Nombre BBDD\t ..: " << I.getNombreBBDD() << endl;
	cout << "Número de Ele\t ..: " << I.getNumEle() << endl;



/*
	SolGeneratorKP S(I.getNumEle());

	for(int i = 0; i < 1000; i++)
		S.generaSolucion(I);

	S.imprimeMejorSolucion();
*/	
	return 0;
}