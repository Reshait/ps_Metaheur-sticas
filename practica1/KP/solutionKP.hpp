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
		//vector<int> vSol_;
		vector<bool> vSol_;
		int bTotal_;
		int pTotal_;
		double fitness_; //si el peso es superior a la capacidad, asignar capacidad menos pesoTotal
						 //si el peso es inferior o igual a la capacidad, asignar el beneficioTotal

	public:
		SolutionKP(int numElem){
			setBeneficioTotal(0);
			setPesoTotal(0);

			for (int i = 0; i < numElem; i++)
				vSol_.push_back(false);
		}

		inline int getBeneficioTotal(){ return bTotal_; }
		inline int getPesoTotal(){ return pTotal_; }
		//inline vector<int> getVector(){ return vSol_; }
		inline vector<bool> getVector(){ return vSol_; }

		inline void setBeneficioTotal(int beneficioTotal){ bTotal_ = beneficioTotal; }
		inline void setPesoTotal(int pesoTotal){ pTotal_ = pesoTotal; }
		//inline void setVector(vector<int> vector){ vSol_ = vector; }
		inline void setVector(vector<bool> vector){ vSol_ = vector; }

		inline void aniadePosSolucion(int posicion){
			vSol_.push_back(posicion);
		}

		inline void imprimeVectorSolucion(){
			vector<bool>::iterator i;
			int contador = 0; //Para cuestiones estéticas al imprimir el vector
			
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