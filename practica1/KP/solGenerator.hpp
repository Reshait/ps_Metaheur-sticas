#ifndef __SOLGENERATORKP_HPP__
#define __SOLGENERATORKP_HPP__

#include <iostream>
#include <string>
#include <list>
#include <algorithm> //para el sort en linux
#include <cstdlib>
#include "solutionKP.hpp"
#include "instanceKP.hpp"
#include "objeto.hpp"

using std::vector;
using std::list;
using std::string;
using std::sort;

class SolGeneratorKP{
	private:
		list<SolutionKP> lista_;
		SolutionKP *mejorSol_;
		int numElem;

	public:
		SolGeneratorKP(int numElem){
			this->numElem = numElem;
			mejorSol_ = new SolutionKP(numElem);
		}

		~SolGeneratorKP(){
			delete mejorSol_;
		}

		inline void aniadeElementoLista(SolutionKP S){ lista_.push_back(S); }
		inline void generaSolucion(InstanceKP I){
			SolutionKP S(numElem);
//			float ale = rand()%100;
//			ale/=100;
///// Añadido por Carlos para admitir soluciones no válidas y después aplicarle un fitness;			
			for (int i = 0; i < I.getNumEle(); i++){
				if ((((double)rand()) / RAND_MAX) < 0.5){
					S.setPesoTotal(S.getPesoTotal() + I.vector_.at(i).getPeso());
					S.setBeneficioTotal(S.getBeneficioTotal() + I.vector_.at(i).getBeneficio());	
					S.vSol_.at(i) = true; 
//					cout << "Hola" << endl;
				}
			}

			cout << "Beneficio obtenido\t ..: " << S.getBeneficioTotal() << endl;
			cout << "Peso Total obtenido\t ..: " << S.getPesoTotal() << endl;
			cout << "Peso Máximo permitido\t ..: " << I.getPesoMax() << endl;

			S.imprimeVectorSolucion();

			if(S.getBeneficioTotal() > mejorSol_->getBeneficioTotal()){
				mejorSol_->setPesoTotal(S.getPesoTotal());
				mejorSol_->setBeneficioTotal(S.getBeneficioTotal());
				mejorSol_->setVector(S.getVector());				
			}			
		}

		inline void imprimeMejorSolucion(){
			cout << "====================================" << endl;
			cout << "Mejor Beneficio\t\t ..: " << mejorSol_->getBeneficioTotal() << endl;
			cout << "Peso correspondiente\t ..: " << mejorSol_->getPesoTotal() << endl;
			cout << "Vector de posiciones usadas : " << endl;
			mejorSol_->imprimeVectorSolucion();
		}
};

#endif
