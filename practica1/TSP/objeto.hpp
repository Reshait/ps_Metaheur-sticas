#ifndef __OBJETO_HPP__
#define __OBJETO_HPP__

class Objeto{
	private:
		float peso_;
		float beneficio_;
		int posicion_;
//		bool enMochila_;

	public:
		Objeto(){}
		inline float getPeso(){ return peso_; }
		inline float getBeneficio(){ return beneficio_; }
		inline int getPosicion(){ return posicion_; }
		inline bool getEnMochila(){ return enMochila_; }

		inline void setPeso(float peso){ peso_ = peso; }
		inline void setBeneficio(float beneficio){ beneficio_ = beneficio; }
		inline void setPosicion(int posicion){ posicion_ = posicion; }
		inline void setEnMochila(bool enMochila){ enMochila_ = enMochila; }
};

#endif