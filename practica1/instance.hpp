#ifndef __INSTANCE_HPP__
#define __INSTANCE_HPP__
#include <iostream>
#include <vector>
#include <cstdlib> //para el atoi
#include <string>
#include <fstream>
#include <sstream> //para cazar las líneas del fichero
#include "objeto.hpp"

using std::vector;
using std::string;
using std::ifstream;
using std::stringstream;
using std::endl;
using std::cout;

class Instance{
	private:
		vector<Objeto> vector_;
	public:
		Instance(){};
		bool estaVacio();
		void setVector(const vector<Objeto> &vector);
		const vector<Objeto> getVector();
		void aniadeElemento(const Objeto &O);
		bool rellenaVector(const string &nombreFichero);
		void imprimeVector();
};

#endif