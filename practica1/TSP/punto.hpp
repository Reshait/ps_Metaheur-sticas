#ifndef __PUNTO_HPP__
#define __PUNTO_HPP__

class Punto{
	private:
		float x_;
		float y_;
		int nNodo_;

	public:
		Punto(){}
		inline float getX(){ return x_; }
		inline float getY(){ return y_; }
		inline int getNumNodo(){ return nNodo_; }

		inline void setX(float x){ x_ = x; }
		inline void setY(float y){ y_ = y; }
		inline void setNumNodo(int nNodo){ nNodo_ = nNodo; }
};

#endif