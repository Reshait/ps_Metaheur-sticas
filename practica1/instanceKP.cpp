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
	int i = 0;

	ifstream bbddEntrada(nombreFichero.c_str());

	if(!bbddEntrada)
		return false;

	else{
		getline(bbddEntrada, linea);

		stringstream lineaCompleta(linea);

		for(int j = 0; j < 3; j++)
			getline(lineaCompleta, desechable, '_');

		setNumEle( atoi(desechable.c_str()) ); // capturo el número de elementos en la línea 1, desde el segundo al tercer _

		for(int j = 1; j < 5; j++){
			getline(bbddEntrada, linea);

			if(j == 2){
				stringstream lineaCompleta(linea);

				getline(lineaCompleta, desechable, ' ');
				getline(lineaCompleta, desechable, '\n');

				setPesoMax( atoi(desechable.c_str()) ); // capturo el peso Máximo en la línea 3, desde el espacio en blanco hasta el \n
			}
		}

		while(i < getNumEle()){
			getline(bbddEntrada, linea);

			stringstream lineaCompleta(linea);

			getline(lineaCompleta, posicion, ',');
			getline(lineaCompleta, beneficio, ',');
			getline(lineaCompleta, peso, ',');
			getline(lineaCompleta, enMochila, '\n');

			O.setPosicion(atoi(posicion.c_str()));
			O.setBeneficio(atoi(beneficio.c_str()));
			O.setPeso(atoi(peso.c_str()));
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
	cout << "Número de elementos\t ..: " << getNumEle() << endl;
	cout << "Peso máx. en mochila\t ..: " << getPesoMax() << endl;
}

bool InstanceKP::estaVacio(){
	if(vector_.empty())
		return true;
	return false;
}

