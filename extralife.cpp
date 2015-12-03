#include "extralife.h"
extralife::extralife(int _x,int _y){y=_y;x=_x;enpantalla=false;}
void extralife::colision(navep &naveaux){
	if(y>=naveaux.y and y<=naveaux.y+4 and x>=naveaux.x and x<=naveaux.x+11){
		naveaux.corazon++;
		naveaux.impnav();
		naveaux.corazones();
		enpantalla=false;
		gotox(x,y);cout<<" ";
		y=rand()%30+4;
		x=99;
	}
}
void extralife::reload(){x=rand()%9+90;y=rand()%31+4;}
