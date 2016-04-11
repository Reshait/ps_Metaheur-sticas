#ifndef __SOLGENERATOR_TSP__
#define __SOLGENERATOR_TSP__

#include <list>
#include "solutionTSP.hpp"
#include "punto.hpp"

using std::list;

class SolGeneratorTSP
{
	private:
		list<SolutionTSP> lista_;
		SolutionTSP mejorSol_;

	public:
/*		SolGeneratorTSP(SolutionTSP Inicial){
			mejorSol_ = Inicial;
			lista_.push_back(Inicial);
		};
*/
		SolGeneratorTSP(){}
		//Getters
		inline list<SolutionTSP> getList(){ return lista_; }
		inline SolutionTSP getMejorSol(){ return mejorSol_; }

		//Setters
		inline void setList(list<SolutionTSP> lista) { lista_ = lista; }
		inline void setMejorSol(SolutionTSP mejorSol) { mejorSol_ = mejorSol; }

		//Others
		inline void aniadeSolucion(SolutionTSP Solucion){
			if(lista_.empty())
				setMejorSol(Solucion);
			
			if(Solucion.getSuma() < mejorSol_.getSuma())
				setMejorSol(Solucion);

			lista_.push_back(Solucion);
		}



	
};

#endif