#ifndef __INSTANCETSP_HPP__
#define __INSTANCETSP_HPP__
#include <iostream>
#include <vector>
#include <cstdlib> //para el atoi
#include <string>
#include <fstream>
#include <sstream> //para cazar las líneas del fichero
#include "punto.hpp"
//#include "solutionKP.hpp"

using std::vector;
using std::string;
using std::ifstream;
using std::stringstream;
using std::endl;
using std::cout;
using std::cin;

class InstanceKP{
	private:
		vector<Punto> vector_;
		int numElementos_;
		string nombreBBDD_;

	public:
		InstanceKP(){};
		const vector<Punto> getVector();
		inline int getNumEle(){ return numElementos_; }
		inline string getNombreBBDD(){ return nombreBBDD_; }

		inline void setNombreBBDD(string nombre){ nombreBBDD_ = nombre; } 
		void setVector(const vector<Punto> &vector);
		inline void setNumEle(int numEle){ numElementos_ = numEle; }
		void aniadeElemento(const Punto &P);
		bool rellenaVector(const string &nombreFichero);
		void imprimeVector();
		bool estaVacio();

};

#endif