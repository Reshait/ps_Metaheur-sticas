#include "InstanceKP.hpp"

const vector<Objeto> InstanceKP::getVector(){
	return vector_;
}

void InstanceKP::setVector(const vector<Objeto> &vector){
	vector_ = vector;
}

void InstanceKP::setPesoMax(const int peso){
	pesoMax_ = peso;
}

void InstanceKP::aniadeElemento(const Objeto &O){
	vector_.push_back(O);
}

bool InstanceKP::rellenaVector(const string &nombreFichero){
	Objeto O;
	string linea, beneficio, peso, posicion, enMochila, desechable;
	int numDatos, i = 0;

	ifstream bbddEntrada(nombreFichero.c_str());

	if(!bbddEntrada)
		return false;

	else{
		getline(bbddEntrada, linea);

		stringstream lineaCompleta(linea);

		for(int j = 0; j < 3; j++)
			getline(lineaCompleta, desechable, '_');

		numDatos = atoi(desechable.c_str());

		for(int j = 1; j < 5; j++)
			getline(bbddEntrada, linea);

		while(i < numDatos){
			getline(bbddEntrada, linea);

			stringstream lineaCompleta(linea);

			getline(lineaCompleta, posicion, ',');
			getline(lineaCompleta, beneficio, ',');
			getline(lineaCompleta, peso, ',');
			getline(lineaCompleta, enMochila, '\n');

			O.setPosicion(atoi(posicion.c_str()));
			O.setBeneficio(atoi(beneficio.c_str()));
			O.setPeso(atoi(peso.c_str()));
			//O.setEnMochila(atoi(enMochila.c_str()));
			O.setEnMochila(false);

			aniadeElemento(O);
			i++;
		}
		
		bbddEntrada.close();

	}

	return true;
}

void InstanceKP::imprimeVector(){
	vector<Objeto>:: iterator i;
	for(i = vector_.begin(); i != vector_.end(); i++){
		cout << "Posición\t ..: " << i->getPosicion() << "    \t" << "Beneficio\t.: " << i->getBeneficio() << endl;
	}
}

bool InstanceKP::estaVacio(){
	if(vector_.empty())
		return true;
	return false;
}
