#include "plantilla.h"
void plantilla::imp(char _char){
	gotox(x,y);cout<<_char;
}
void plantilla::mover(char _char){
	gotox(x,y);cout<<" ";
	x--;
	if(x<2){
		y=rand()%30+4;
		x=99;
	}
	imp(_char);
}
int plantilla::X(){return x;}
int plantilla::Y(){return y;}
