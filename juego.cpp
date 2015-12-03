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
	instrucciones();
	gotox(15,15);system("pause");
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
		for(int i=0;i<B.size();i++){
			(*B[i]).mover();
			if((*B[i]).fuera()){
				gotox((*B[i]).X(),(*B[i]).Y());cout<<" ";
				delete(B[i]);
				B.erase(B.begin()+i);
			}
		}
		for(int i=0;i<astgroup.size();i++){
			(*astgroup[i]).mover(char(184));
			(*astgroup[i]).colision(*n1);
		}
		for(int i=0;i<astgroup.size();i++){
			for(int j=0;j<B.size();j++){
				if((*astgroup[i]).Y()==(*B[j]).Y()){
					if((*astgroup[i]).X()==(*B[j]).X() or (*astgroup[i]).X()==(*B[j]).X()+1){
						gotox((*B[j]).X(),(*B[j]).Y());cout<<" ";
						delete(B[j]);
						B.erase(B.begin()+j);
						gotox((*astgroup[i]).X(),(*astgroup[i]).Y());cout<<" ";
						(*astgroup[i]).reload();
						score+=10;
					}
				}
			}
		}
		if(lifeplus.enpantalla){
            lifeplus.mover(char(3));
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
