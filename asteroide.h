#include "plantilla.cpp"
class asteroide: public plantilla{
public:
	asteroide(int,int);
	void colision(navep&);
	void reload();
};
