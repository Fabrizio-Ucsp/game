#include <bits/stdc++.h>
#include <conio.h>
#include "nave.cpp"
#include "extralife.cpp"
#include "funciones.cpp"
#include "bala.cpp"
class juego{
private:
    navep *n1;
    int score,masdif;
    vector<asteroide*> astgroup;
    vector<bala*> B;
    bool game_over;
public:
	juego();
	void jugar();
};
