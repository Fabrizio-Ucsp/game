#include <windef.h>
void gotox(int x,int y){
	HANDLE name;
	name=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD ubi;
	ubi.X=x;ubi.Y=y;
	SetConsoleCursorPosition(name,ubi);
}
void hidecursor(){
	HANDLE name;
	name=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize=10;
	cursor.bVisible=false;
	SetConsoleCursorInfo(name,&cursor);
}
void limites(){
	for(int i=2;i<100;i++){
		gotox(i,3);cout<<char(205);
		gotox(i,35);cout<<char(205);
	}
	for(int i=4;i<35;i++){
		gotox(1,i);cout<<char(186);
		gotox(100,i);cout<<char(186);
	}
	gotox(1,3);cout<<char(201);
	gotox(1,35);cout<<char(200);
	gotox(100,3);cout<<char(187);
	gotox(100,35);cout<<char(188);
}
void gameendtxt(int score){
	gotox(5,5);cout<<"      _____          __  __ ______    ______      ________ _____  _       "<<endl;
	gotox(5,6);cout<<"     / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\| |      "<<endl;
	gotox(5,7);cout<<"    | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) | |      "<<endl;
	gotox(5,8);cout<<"    | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /| |      "<<endl;
	gotox(5,9);cout<<"    | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\|_|      "<<endl;
	gotox(5,10);cout<<"     \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_(_)      "<<endl;
	gotox(0,0);cout<<"                 ";
	gotox(35,13);cout<<"SCORE  :"<<score;
}

void printname(){
	gotox(15,2);cout<<"  _____                                    _                 _                  "<<endl;
	gotox(15,3);cout<<" / ____|                          /\\      | |               | |                 "<<endl;
	gotox(15,4);cout<<"| (___  _ __   __ _  ___ ___     /  \\   __| |_   _____ _ __ | |_ _   _ _ __ ___ "<<endl;
	gotox(15,5);cout<<" \\___ \\|  _ \\ / _  |/ __/ _ \\   / /\\ \\ / _` \\ \\ / / _ \\  _ \\| __| | | |  __/ _ \\'"<<endl;
	gotox(15,6);cout<<" ____) | |_) | (_| | (_|  __/  / ____ \\ (_| |\\ V /  __/ | | | |_| |_| | | |  __/"<<endl;
	gotox(15,7);cout<<"|_____/| .__/ \\__,_|\\___\\___| /_/    \\_\\__,_| \\_/ \\___|_| |_|\\__|\\__,_|_|  \\___|"<<endl;
	gotox(15,8);cout<<"       | |                                                                      "<<endl;
	gotox(15,9);cout<<"       |_|                                                                      "<<endl;
}
void instrucciones(){
	gotox(15,2);cout<<"	 _____           _                       _                       "<<endl;
	gotox(15,3);cout<<"	|_   _|         | |                     (_)                      "<<endl;
	gotox(15,4);cout<<"	  | |  _ __  ___| |_ _ __ _   _  ___ ___ _  ___  _ __   ___  ___ "<<endl;
	gotox(15,5);cout<<"	  | | |  _ \\/ __| __|  __| | | |/ __/ __| |/ _ \\|  _ \\ / _ \\/ __|"<<endl;
	gotox(15,6);cout<<"	 _| |_| | | \\__ \\ |_| |  | |_| | (_| (__| | (_) | | | |  __/\\__ \\'"<<endl;
	gotox(15,7);cout<<"	|_____|_| |_|___/\\__|_|   \\__,_|\\___\\___|_|\\___/|_| |_|\\___||___/"<<endl;
	gotox(15,11);cout<<"1.- El objetivo es sobrevivir el mayor tiempo posible al espacio"<<endl;
	gotox(15,12);cout<<"2.- Puede mover la nave usando las teclas 'w' , 'a' , 's' , 'd'"<<endl;
	gotox(15,13);cout<<"3.- La nave puede disparar usando la tecla 'j' "<<endl;
	
}
void gracias(){
	gotox(15,2);cout<<" _____                _                                  ___                        "<<endl;
	gotox(15,3);cout<<"|  __ \\              (_)                                |_  |                       "<<endl;
	gotox(15,4);cout<<"| |  \\/_ __ __ _  ___ _  __ _ ___   _ __   ___  _ __      | |_   _  __ _  __ _ _ __ "<<endl;
	gotox(15,5);cout<<"| | __| '__/ _` |/ __| |/ _` / __| | '_ \\ / _ \\| '__|     | | | | |/ _` |/ _` | '__|"<<endl;
	gotox(15,6);cout<<"| |_\\ \\ | | (_| | (__| | (_| \\__ \\ | |_) | (_) | |    /\\__/ / |_| | (_| | (_| | | "  <<endl;
	gotox(15,7);cout<<" \\____/_|  \\__,_|\\___|_|\\__,_|___/ | .__/ \\___/|_|    \\____/ \\__,_|\\__, |\\__,_|_|   "<<endl;
	gotox(15,8);cout<<"                                   | |                              __/ |           "<<endl;
	gotox(15,9);cout<<"                                   |_|                             |___/            "<<endl;
	gotox(15,15);cout<<"Hecho por :"<<endl;
	gotox(15,17);cout<<"- Rodrigo Sanchez Pinto"<<endl;
	gotox(15,18);cout<<"- Fabrizio Flores Pari"<<endl;
	gotox(15,23);cout<<" "<<endl;
}
