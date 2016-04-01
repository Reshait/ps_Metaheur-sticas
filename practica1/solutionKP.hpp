#ifndef __SOLUTIONKP_HPP__
#define __SOLUTIONKP_HPP__

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class SolutionKP{
	private:
		vector<bool> vSol_;
		int bTotal_;
		int pTotal_;

	public:
		SolutionKP(){
			setBeneficioTotal(0);
			setPesoTotal(0);
		}
		inline vector<bool> getVectorSolucion(){ return vSol_; }
		inline int getBeneficioTotal(){ return bTotal_; }
		inline int getPesoTotal(){ return pTotal_; }

		inline void setBeneficioTotal(int beneficioTotal){ bTotal_ = beneficioTotal; }
		inline void setPesoTotal(int pesoTotal){ pTotal_ = pesoTotal; }

		inline void aniadeElemento(const bool &B){ vSol_.push_back(B); }
		inline void imprimeVectorSolucion(){
			vector<bool>::iterator i;

			cout << "[";
			//for(i = vSol_.begin(); i < vSol_.end(); i++)
			for(int i = 0; i < vSol_.size(); i++)
				cout << " " << i << ",";
			cout << " ]" << endl;
		}

		friend class SolGeneratorKP;	
};

#endif