#include "objeto.hpp"
#include "instanceKP.hpp"
#include "solutionKP.hpp"
#include "solGenerator.hpp"

using namespace std;

int main(){
	InstanceKP I;
	SolGeneratorKP S;
	string nombreFichero;

	do{
		cout << "Introduzca el nombre del fichero a cargar ..: ";
		cin >> nombreFichero;
		I.rellenaVector(nombreFichero);
	}while(!I.rellenaVector(nombreFichero));
	
//	I.imprimeVector();
	for(int i = 0; i < 10; i++){
		S.generaSolucion(I);
	}
	
	return 0;
}