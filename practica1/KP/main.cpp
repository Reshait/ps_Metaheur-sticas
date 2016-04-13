//compilar con:
//g++ main.cpp instanceKP.cpp objeto.cpp

#include <string>
#include <ctime>
#include "objeto.hpp"
#include "instanceKP.hpp"
#include "solutionKP.hpp"
#include "solGenerator.hpp"


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
	I.rellenaVector("k200.csv"); //cambiar por lo anterior cuando esté terminado.
	SolGeneratorKP S(I.getNumEle());

	for(int i = 0; i < 1000; i++){
		S.generaSolucion(I);
		S.imprimeMejorSolucion();

	}

//	S.imprimeMejorSolucion();
	
	return 0;
}
