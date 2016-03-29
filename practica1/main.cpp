#include "objeto.hpp"
#include "instance.hpp"

using namespace std;

int main(){
	Instance Mochila;
	string nombreFichero;

	do{
		cout << "Introduzca el nombre del fichero a cargar ..: ";
		cin >> nombreFichero;
		Mochila.rellenaVector(nombreFichero);
	}while(!Mochila.rellenaVector(nombreFichero));
	
	Mochila.imprimeVector();
	
	return 0;
}