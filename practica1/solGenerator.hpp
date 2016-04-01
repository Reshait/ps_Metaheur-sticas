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

class SolGeneratorKP{
	private:
		list<SolutionKP> lista_;

	public:
		SolGeneratorKP(){};
		inline void aniadeElementoLista(SolutionKP S){ lista_.push_back(S); }

		inline void generaSolucion(InstanceKP I){
			SolutionKP S;
			int iteracion = 0;
			//int i;
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
								//S.vSol_[i] = 1; --> falta por hacer.
							}
							break;
						}
					}

				}
		
			}
			cout << "Beneficio obtenido\t ..: " << S.getBeneficioTotal() << endl;
			cout << "Peso Total obtenido\t ..: " << S.getPesoTotal() << endl;
			cout << "Peso Máximo permitido\t ..: " << I.getPesoMax() << endl;

			aniadeElementoLista(S);
		}
};

#endif