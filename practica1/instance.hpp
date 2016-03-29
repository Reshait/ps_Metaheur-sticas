#ifndef __INSTANCE_HPP__
#define __INSTANCE_HPP__
#include <iostream>
#include <cstdio>
#include <vector>
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
		Instance(){}
		
		bool estaVacio(){
			if(vector_.empty())
				return true;
			return false;
		}

		void setVector(vector<Objeto> vector){
			vector_ = vector;
		}

		vector<Objeto> getVector(){
			return vector_;
		}

		bool rellenaVector(string nombreFichero){
			Objeto O;
			string linea, beneficio, peso, posicion, enMochila;

			ifstream bbddEntrada(nombreFichero.c_str());

			if(!bbddEntrada)
				return false;

			else{
				while(getline(bbddEntrada, linea)){
					std::stringstream lineaCompleta(linea);

					getline(lineaCompleta, posicion, ',');
					getline(lineaCompleta, beneficio, ',');
					getline(lineaCompleta, peso, ',');
					getline(lineaCompleta, enMochila, '\n');

					O.setPosicion(atoi(posicion));

				}
				bbddEntrada.close();

			}
		}




};


#endif