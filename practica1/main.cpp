#include <ctime>
#include "objeto.hpp"
#include "instanceKP.hpp"
#include "solutionKP.hpp"
#include "solGenerator.hpp"

using namespace std;

int main(){
	InstanceKP I;
	SolGeneratorKP S;
	string nombreFichero;

	srand(time(NULL));

/*	do{
		cout << "Introduzca el nombre del fichero a cargar ..: ";
		cin >> nombreFichero;
		I.rellenaVector(nombreFichero);
	}while(!I.rellenaVector(nombreFichero));
*/
	I.rellenaVector("knaPi.csv"); //cambiar por lo anterior cuando esté terminado.


//	I.imprimeVector();
	for(int i = 0; i < 50; i++){
		S.generaSolucion(I);
	}

	S.imprimeMejorSolucion();
	
	return 0;
}