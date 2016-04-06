#include "instanceTSP.hpp"

const vector<Objeto> InstanceKP::getVector(){
	return vector_;
}

void InstanceKP::setVector(const vector<Objeto> &vector){
	vector_ = vector;
}

void InstanceKP::aniadeElemento(const Objeto &O){
	vector_.push_back(O);
}

bool InstanceKP::rellenaVector(const string &nombreFichero){
	Objeto O;
	string linea, beneficio, peso, posicion, enMochila, desechable;
	int i = 0;

	ifstream bbddEntrada(nombreFichero.c_str());

	if(!bbddEntrada)
		return false;

	else{

		for(int j = 0; j < 6; j++){  // For para pasar la cabecera leyendo el nombre y la cantidad de elementos
			getline(bbddEntrada, linea);

			if(j == 0 || j == 3){
				stringstream lineaCompleta(linea);
				getline(lineaCompleta, desechable, ' ');
				getline(lineaCompleta, desechable, '\n');

				if(j == 0) //Leo nombre de BBDD
					setNombreBBDD(desechable);

				if(j == 3) //Leo el número de elementos
					setNumEle( atoi(desechable.c_str()) );
			}

		}

		while(i < getNumEle()){
			getline(bbddEntrada, linea);

			stringstream lineaCompleta(linea);

			getline(lineaCompleta, posicion, ' ');
			getline(lineaCompleta, beneficio, ' ');
			getline(lineaCompleta, peso, ' ');

			O.setPosicion(atoi(posicion.c_str()));
			O.setBeneficio(atof(beneficio.c_str()));
			O.setPeso(atof(peso.c_str()));

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
	cout << "Número de elementos\t ..: " << getNumEle() << endl;
}

bool InstanceKP::estaVacio(){
	if(vector_.empty())
		return true;
	return false;
}

