#ifndef __SOLGENERATORKP_HPP__
#define __SOLGENERATORKP_HPP__

#include <iostream>
#include <list>
#include <cstdlib>
#include "solutionKP.hpp"
#include "instanceKP.hpp"
#include "objeto.hpp"

using std::vector;
using std::list;
using std::to_string;
using std::sort;

class SolGeneratorKP{
	private:
		list<SolutionKP> lista_;
		SolutionKP mejorSol_;

	public:
		SolGeneratorKP(){
			mejorSol_.setPesoTotal(0);
			mejorSol_.setBeneficioTotal(0);
		}

		inline void aniadeElementoLista(SolutionKP S){ lista_.push_back(S); }
		inline void generaSolucion(InstanceKP I){
			SolutionKP S;
			int iteracion = 0;
			vector<Objeto>::iterator i;
			
			while(S.getPesoTotal() <  I.getPesoMax() && iteracion < 200){
				int aleatorio = rand() % 200;

				//cout << "Num. Aleatorio (tiene que ir cambiando)\t ..: " << aleatorio << endl; //Si no cambia, se quedará en bucle infinito.
				for(i = I.vector_.begin(); i < I.vector_.end(); i++){
					if(i->getPosicion() == aleatorio){
						if(!i->getEnMochila() && iteracion < 200){
							iteracion++; // Para que si se queda cercano al pesoMaximo y no hay ningún objeto con ese peso, no se quede en bucle infinito
							if(S.getPesoTotal() + i->getPeso() <= I.getPesoMax()){
								i->setEnMochila(1);
								S.setPesoTotal(S.getPesoTotal() + i->getPeso());
								S.setBeneficioTotal(S.getBeneficioTotal() + i->getBeneficio());	
								S.aniadePosSolucion(aleatorio);
							}
							break;
						}
					}

				}
		
			}
			cout << "Beneficio obtenido\t ..: " << S.getBeneficioTotal() << endl;
			cout << "Peso Total obtenido\t ..: " << S.getPesoTotal() << endl;
			cout << "Peso Máximo permitido\t ..: " << I.getPesoMax() << endl;
			sort(S.vSol_.begin(), S.vSol_.end());
			S.imprimePosSolucion();

			aniadeElementoLista(S);
		}

		inline void imprimeMejorSolucion(){
			list<SolutionKP>::iterator it;

			for(it = lista_.begin(); it != lista_.end(); it++){
				if(it->getBeneficioTotal() > mejorSol_.getPesoTotal()){
					mejorSol_.setPesoTotal(it->getPesoTotal());
					mejorSol_.setBeneficioTotal(it->getBeneficioTotal());
					mejorSol_.setVector(it->getVector());
				}
			}
			cout << "====================================" << endl;
			cout << "Mejor Beneficio\t\t ..: " << mejorSol_.getBeneficioTotal() << endl;
			cout << "Peso correspondiente\t ..: " << mejorSol_.getPesoTotal() << endl;
			cout << "Vector de posiciones usadas : " << endl;
			mejorSol_.imprimePosSolucion();
		}
};

#endif