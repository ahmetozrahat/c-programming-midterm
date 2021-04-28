//
//  main.c
//  Odev
//
//  Created by Ahmet Ozrahat on 24.12.2020.
//

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

typedef enum{
	YUKARI=0,
	ASAGI=1,
	SOL=2,
	SAG=3
};

int kuyrukX[300],kuyrukY[300];
int kafax=40,kafay=12,yonx=1,yony=0,kuyruk=4,sayac=0,gecikme=1000,yon=SAG;
int lost=0;

void oyna(void);

void ekrani_cizdir(void);

void yon_degistir(void);

void bitir(void);

void gotoxy(int x, int y);

int main(void) {
	ekrani_cizdir();
	oyna();
	return 0;
}

void oyna(void){
	int i;
	
	for(i=0; i<4; i++){
		kuyrukY[i+1]=kafax-i;
		kuyrukX[i+1]=kafay;
	}
	
	do{
		kafax=kafax+yonx;
		kafay=kafay+yony;
		
		if(kafax>78) kafax=2;
		if(kafax<2) kafax=78;
		if(kafay>22) kafay=2;
		if(kafay<2) kafay=22;
			
		kuyrukY[0]=kafax;
		kuyrukX[0]=kafay;
		
		for(i=1;i<=kuyruk;i++){
            if((kafax==kuyrukY[i] && kafay==kuyrukX[i])){
            	lost=1;
            	bitir();
            }
    	}	
		
		gotoxy(kafax,kafay);printf("*");
		for(i=0; i<=kuyruk; i++){
			gotoxy(kuyrukY[i],kuyrukX[i]);printf("*");
		}
		
		Sleep(gecikme);
		sayac++;
		if(sayac==5){
			kuyruk++;
			sayac=0;
			yon_degistir();
		}
		gotoxy(kafax,kafay);printf(" ");
		for(i=0; i<=kuyruk; i++){
			gotoxy(kuyrukY[i],kuyrukX[i]);printf(" ");
		}
		
		for(i=kuyruk; i>0; i--){
			kuyrukY[i]=kuyrukY[i-1];
			kuyrukX[i]=kuyrukX[i-1];
		}
		
	}while(lost==0);
}

void ekrani_cizdir(void){
    int i,j;
    for(i=0;i<79;i++){
    	gotoxy(i+1,1);printf("%c",176);
    	gotoxy(i+1,23);printf("%c",176);
    }
    for(j=0;j<23;j++){
    	gotoxy(1,j+1);printf("%c",176);
    	gotoxy(79,j+1);printf("%c",176);
	}
}

void yon_degistir(void){
	srand(time(NULL));
	if(kafax>78 && yon==SAG){
		if(kafay<2){
			yon=ASAGI;
			yonx=0;yony=1;
		}
		else if(kafay>22){
			yon=YUKARI;
			yonx=0;yony=-1;
		}else {
			int random = rand() % 2;
			switch(random){
				case 0:
					yon=YUKARI;
					yonx=0;yony=1;
					break;
				case 1:
					yon=ASAGI;
					yonx=0;yony=-1;
					break;
			}
		}
	}
	else if(kafax<2 && yon==SOL){
		if(kafay<2){
			yon=ASAGI;
			yonx=0;yony=1;
		}else if(kafay>22){
			yon=YUKARI;
			yonx=0;yony=-1;
		}else{
			int random = rand() % 2;
			switch(random){
				case 0:
					yon=YUKARI;
					yonx=0;yony=1;
					break;
				case 1:
					yon=ASAGI;
					yonx=0;yony=-1;
					break;
			}
		}
	}
	else if(kafay>22 && yon==ASAGI){
		if(kafax<2){
			yon=SAG;
			yonx=1;yony=0;
		}else if(kafax>78){
			yon=SOL;
			yonx=-1;yony=0;
		}else{
			int random = rand() % 2;
			switch(random){
				case 0:
					yon=SAG;
					yonx=1;yony=0;
					break;
				case 1:
					yon=SOL;
					yonx=-1;yony=0;
					break;
			}
		}	
	}
	else if(kafay<2 && yon==YUKARI){
		if(kafax<2){
			yon=SAG;
			yonx=1;yony=0;
		}else if(kafax>78){
			yon=SOL;
			yonx=-1;yony=0;
		}else{
			int random = rand() % 2;
			switch(random){
				case 0:
					yon=SAG;
					yonx=1;yony=0;
					break;
				case 1:
					yon=SOL;
					yonx=-1;yony=0;
					break;
			}
		}	
	}
	else{
		int random = rand() % 3;
		switch(yon){
			case YUKARI:
				switch(random){
					case 0:
						yon=YUKARI;
						yonx=0;yony=1;
						break;
					case 1:
						yon=SAG;
						yonx=1;yony=0;
						break;
					case 2:
						yon=SOL;
						yonx=-1;yony=0;
						break;	
				}	
				break;
			case ASAGI:
					switch(random){
					case 1:
						yon=ASAGI;
						yonx=0;yony=-1;
						break;
					case 2:
						yon=SAG;
						yonx=1;yony=0;
						break;
					case 3:
						yon=SOL;
						yonx=-1;yony=0;
						break;	
				}
				break;
			case SOL:
				switch(random){
					case 1:
						yon=YUKARI;
						yonx=0;yony=1;
						break;
					case 2:
						yon=ASAGI;
						yonx=0;yony=-1;
						break;
					case 3:
						yon=SOL;
						yonx=-1;yony=0;
						break;	
				}
				break;
			case SAG:
				switch(random){
					case 1:
						yon=YUKARI;
						yonx=0;yony=1;
						break;
					case 2:
						yon=ASAGI;
						yonx=0;yony=-1;
						break;
					case 3:
						yon=SOL;
						yonx=-1;yony=0;
						break;	
				}
				break;
		}
	}
}

void bitir(void){
	system("cls");
	gotoxy(0,0);
	printf("Yandiniz, simulasyon sona erdi.");
}

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
