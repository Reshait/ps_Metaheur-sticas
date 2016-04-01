#ifndef __INSTANCEKP_HPP__
#define __INSTANCEKP_HPP__
#include <iostream>
#include <vector>
#include <cstdlib> //para el atoi
#include <string>
#include <fstream>
#include <sstream> //para cazar las líneas del fichero
#include "objeto.hpp"
#include "SolutionKP.hpp"

using std::vector;
using std::string;
using std::ifstream;
using std::stringstream;
using std::endl;
using std::cout;
using std::cin;

class InstanceKP{
	private:
		vector<Objeto> vector_;
		int pesoMax_;
		int numElementos_;

	public:
		InstanceKP(){};
		const vector<Objeto> getVector();
		inline int getPesoMax(){ return pesoMax_; }
		inline int getNumEle(){ return numElementos_; }

		void setVector(const vector<Objeto> &vector);
		void setPesoMax(const int peso);
		inline void setNumEle(int numEle){ numElementos_ = numEle; }
		void aniadeElemento(const Objeto &O);
		bool rellenaVector(const string &nombreFichero);
		void imprimeVector();
		bool estaVacio();
		friend class SolGeneratorKP;

//		int getValorAp(SolutionKP vBinarioSol);

};

#endif