#include "objeto.hpp"
#include "instanceKP.hpp"
#include "solutionKP.hpp"

using namespace std;

int main(){
	InstanceKP Mochila;
	string nombreFichero;

	do{
		cout << "Introduzca el nombre del fichero a cargar ..: ";
		cin >> nombreFichero;
		Mochila.rellenaVector(nombreFichero);
	}while(!Mochila.rellenaVector(nombreFichero));
	
	Mochila.imprimeVector();
	
	return 0;
}