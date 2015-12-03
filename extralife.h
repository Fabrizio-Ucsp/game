#include "asteroide.cpp"
class extralife : public plantilla {
public:
    bool enpantalla;
	extralife(int,int);
	void colision(navep&);
	void reload();
};
