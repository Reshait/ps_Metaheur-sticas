#include "instance.hpp"

bool Instance::estaVacio(){
	if(vector_.empty())
		return true;
	return false;
}

void Instance::setVector(const vector<Objeto> &vector){
	vector_ = vector;
}

const vector<Objeto> Instance::Instance::getVector(){
	return vector_;
}

void Instance::aniadeElemento(const Objeto &O){
	vector_.push_back(O);
}

bool Instance::rellenaVector(const string &nombreFichero){
	Objeto O;
	string linea, beneficio, peso, posicion, enMochila;

	ifstream bbddEntrada(nombreFichero.c_str());

	if(!bbddEntrada)
		return false;

	else{
		while(getline(bbddEntrada, linea)){
			stringstream lineaCompleta(linea);

			getline(lineaCompleta, posicion, ',');
			getline(lineaCompleta, beneficio, ',');
			getline(lineaCompleta, peso, ',');
			getline(lineaCompleta, enMochila, '\n');

			O.setPosicion(atoi(posicion.c_str()));
			O.setBeneficio(atoi(beneficio.c_str()));
			O.setPeso(atoi(peso.c_str()));
			O.setEnMochila(atoi(enMochila.c_str()));

			aniadeElemento(O);
		}
		bbddEntrada.close();

	}
	return true;
}

void Instance::imprimeVector(){
	vector<Objeto>:: iterator i;
	for(i = vector_.begin(); i != vector_.end(); i++){
		cout << "Beneficio\t.: " << i->getBeneficio() << endl;
	}
}