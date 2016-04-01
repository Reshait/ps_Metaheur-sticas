#ifndef __OBJETO_HPP__
#define __OBJETO_HPP__

class Objeto{
	private:
		int peso_;
		int beneficio_;
		int posicion_;
		bool enMochila_;

	public:
		Objeto(){}
		inline int getPeso(){ return peso_; }
		inline int getBeneficio(){ return beneficio_; }
		inline int getPosicion(){ return posicion_; }
		inline bool getEnMochila(){ return enMochila_; }

		inline void setPeso(int peso){ peso_ = peso; }
		inline void setBeneficio(int beneficio){ beneficio_ = beneficio; }
		inline void setPosicion(int posicion){ posicion_ = posicion; }
		inline void setEnMochila(bool enMochila){ enMochila_ = enMochila; }
};

#endif