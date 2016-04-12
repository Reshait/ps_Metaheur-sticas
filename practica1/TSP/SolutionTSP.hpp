#ifndef __SOLUTIONTSP__
#define __SOLUTIONTSP__

#include <iostream>
#include <cmath>
#include <vector>
#include "punto.hpp"

using std::cout;
using std::endl;
using std::vector;

class SolutionTSP{
	private:
		vector<Punto> vectorSol_;
		float suma_;

	public:
		SolutionTSP(){
			setSuma(0);
		}

		//Getters
		inline vector<Punto> getVectorSol(){ return vectorSol_; }
		inline float getSuma(){ return suma_; }

		//Setters
		inline void setVectorSol(vector<Punto> vector){ vectorSol_ = vector; }
		inline void setSuma(float suma){ suma_ = suma; }

		//Others
		inline float calculaDistancia(Punto P1, Punto P2){ 
			float distancia;
			distancia = sqrt( pow( P2.getX()-P1.getX(), 2 ) + pow( P2.getY() - P1.getY(), 2 ));
			return distancia;
		}

		inline void aniadeDistancia(float distancia){ suma_ += distancia; }

		inline void eliminaDistancia(float distancia){ suma_ -= distancia; }

		inline void imprimeSolucion(){
			cout << "[ ";
			
			for(int i = 0; i < getVectorSol().size(); i++){
				cout << vectorSol_.at(i).getNumNodo() << " ";
			}

			cout << "]" << endl;
			cout << "Minima Suma total de distancia\t..: " << getSuma() << endl;
		}

		inline void obtenSuma(){
			for(int i = 0; i < getVectorSol().size()-1; i++){
				if(i < getVectorSol().size()-1)
					aniadeDistancia( calculaDistancia(getVectorSol().at(i), getVectorSol().at(i+1)) );
				else
					aniadeDistancia( calculaDistancia(getVectorSol().at(i), getVectorSol().at(0)) );
			}
		}

		inline void cambiaPosiciones(){
			Punto Aux;
			int aleatorio;

			for(int i = 0; i < getVectorSol().size(); i++){
				aleatorio = rand() % (getVectorSol().size()-1) + 1;
				Aux = vectorSol_.at(i);
				vectorSol_.at(i) = vectorSol_.at(aleatorio);
				vectorSol_.at(aleatorio) = Aux;
			}
/*			int pos1 = rand() % (getVectorSol().size()-1) + 1;
			int pos2 = pos1;

			while(pos2 == pos1) 
				pos2 = rand() % (getVectorSol().size()-1) + 1;

			Punto Aux = vectorSol_.at(pos1);
			vectorSol_.at(pos1) = vectorSol_.at(pos2);
			vectorSol_.at(pos2) = Aux;
*/
		}
};
#endif