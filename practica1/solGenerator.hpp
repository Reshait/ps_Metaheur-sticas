#ifndef __SOLGENERATORKP_HPP__
#define __SOLGENERATORKP_HPP__

#include <iostream>
#include <list>
#include <ctime>
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
			int i;

			srand(time(NULL));
			
			while(S.getPesoTotal() <  I.getPesoMax()){
				i = rand() % 200;

				if(!I.vector_[i].getEnMochila()){
					S.vSol_[i] = 1;
					I.vector_[i].setEnMochila(1);
					S.setBeneficioTotal(S.getBeneficioTotal() + I.vector_[i].getBeneficio());
					S.setPesoTotal(S.getPesoTotal() + I.vector_[i].getPeso());
				}
				
			}
			aniadeElementoLista(S);
		}
};

#endif