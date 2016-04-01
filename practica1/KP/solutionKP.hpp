#ifndef __SOLUTIONKP_HPP__
#define __SOLUTIONKP_HPP__

#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class SolutionKP{
	private:
		vector<int> vSol_;
		int bTotal_;
		int pTotal_;

	public:
		SolutionKP(){
			setBeneficioTotal(0);
			setPesoTotal(0);
		}

		inline int getBeneficioTotal(){ return bTotal_; }
		inline int getPesoTotal(){ return pTotal_; }
		inline vector<int> getVector(){ return vSol_; }

		inline void setBeneficioTotal(int beneficioTotal){ bTotal_ = beneficioTotal; }
		inline void setPesoTotal(int pesoTotal){ pTotal_ = pesoTotal; }
		inline void setVector(vector<int> vector){ vSol_ = vector; }

		inline void aniadePosSolucion(int posicion){
			vSol_.push_back(posicion);
		}

		inline void imprimePosSolucion(){
			vector<int>::iterator i;
			int contador = 0;
			
			cout << "[ ";
			for(i = vSol_.begin(); i < vSol_.end(); i++){
				contador++;
				if(contador != vSol_.size())
					cout << *i << " | ";
				else
					cout << *i << " ]" << endl;
			}
		}

		friend class SolGeneratorKP;	
};

#endif