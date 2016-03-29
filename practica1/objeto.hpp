#ifndef __OBJETO_HPP__
#define __OBJETO_HPP__

class Objeto{
	private:
		int peso_;
		int beneficio_;
		int posicion_;
		bool enMochila_;

	public:
		Objeto();
		int getPeso(){ return peso_; }
		int getBeneficio(){ return beneficio_; }
		int getPosicion(){ return posicion_; }
		bool getEnMochila(){ return enMochila_; }

		void setPeso(int peso){ peso_ = peso; }
		void setBeneficio(int beneficio){ beneficio_ = beneficio; }
		void setPosicion(int posicion){ posicion_ = posicion; }
		void setEnMochila(){enMochila_ = true; }
};

#endif