#include "juego.h"
juego::juego(){
    n1=new navep(2,4,3,3);
    score=0;
    masdif=200;
	for(int i=0;i<10;i++){astgroup.push_back(new asteroide(rand()%39+60,rand()%31+4));}
	bool game_over=false;
}
void juego::jugar(){
    extralife lifeplus(rand()%39+60,rand()%31+4);
    printname();
    system("pause");
	system("cls");
	hidecursor();
	limites();
	n1->impnav();
	n1->corazones();
	while(!game_over){
		gotox(0,0);cout<<"Score  :"<<score;score++;
		if(kbhit()){
			char tecla=getch();
			n1->mover(tecla);
			if(tecla=='j'){B.push_back(new bala(n1->X()+7,n1->Y()+4));}
		}
		for(int it=0;it<B.size();it++){
			(*B[it]).mover();
			if((*B[it]).fuera()){
				gotox((*B[it]).X(),(*B[it]).Y());cout<<" ";
				delete(B[it]);
				B.erase(B.begin()+it);
			}
		}
		for(int it=0;it<astgroup.size();it++){
			(*astgroup[it]).mover(char(184));
			(*astgroup[it]).colision(*n1);
		}
		for(int itast=0;itast<astgroup.size();itast++){
			for(int itbal=0;itbal<B.size();itbal++){
				if((*astgroup[itast]).Y()==(*B[itbal]).Y()){
					if((*astgroup[itast]).X()==(*B[itbal]).X() or (*astgroup[itast]).X()==(*B[itbal]).X()+1){
						gotox((*B[itbal]).X(),(*B[itbal]).Y());cout<<" ";
						delete(B[itbal]);
						B.erase(B.begin()+itbal);
						gotox((*astgroup[itast]).X(),(*astgroup[itast]).Y());cout<<" ";
						(*astgroup[itast]).reload();
						score+=10;
					}
				}
			}
		}
		if(lifeplus.enpantalla){
            lifeplus.mover(char(64));
            lifeplus.colision(*n1);
		}
		if(score>masdif){
            astgroup.push_back(new asteroide(99,rand()%31+4));
            lifeplus.enpantalla=true;
            masdif+=200;
            }
		n1->muerte();
		if(n1->gameend()){game_over=true;}
		Sleep(30);
	}
	Sleep(500);
	system("cls");
	gameendtxt(score);
	gotox(12,32);system("pause");
	system("cls");
	gracias();
	system("pause");
}
