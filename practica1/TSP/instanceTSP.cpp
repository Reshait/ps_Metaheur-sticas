#include "instanceTSP.hpp"

const vector<Punto> InstanceKP::getVector(){
	return vector_;
}

void InstanceKP::setVector(const vector<Punto> &vector){
	vector_ = vector;
}

void InstanceKP::aniadeElemento(const Punto &P){
	vector_.push_back(P);
}

bool InstanceKP::rellenaVector(const string &nombreFichero){
	Punto P;
	string linea, x, y, nNodo, desechable;
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

			getline(lineaCompleta, nNodo, ' ');
			getline(lineaCompleta, x, ' ');
			getline(lineaCompleta, y, ' ');

			P.setNumNodo(atoi(nNodo.c_str()));
			P.setX(atof(x.c_str()));
			P.setY(atof(y.c_str()));

			aniadeElemento(P);
			i++;
		}
		
		bbddEntrada.close();

	}

	return true;
}

void InstanceKP::imprimeVector(){
	vector<Punto>:: iterator i;
	for(i = vector_.begin(); i != vector_.end(); i++){
		cout << "Número de Nodo\t ..: " << i->getNumNodo() << "    \t" << "Coordenada X\t.: " << i->getX() << endl;
	}
	cout << "Número de elementos\t ..: " << getNumEle() << endl;
}

bool InstanceKP::estaVacio(){
	if(vector_.empty())
		return true;
	return false;
}

