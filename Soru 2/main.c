//
//  main.c
//  Odev
//
//  Created by Ahmet Ozrahat on 24.12.2020.
//

#include <stdio.h>

void islem_yap(void);

void degistir(int* xp, int* yp);

void sirala(int arr[], int n);

void uc_sayili(int sayi1, int sayi2, int sayi3);

void iki_sayili(int sayi1, int sayi2);

void tek_sayili(int sayi);

int main() {
    islem_yap();
    return 0;
}

void islem_yap(void) {
	int i;
    // Kullaniciya program hakking bilgi veriyoruz.
    printf("1,2,3 sayilarindan sadece 3 tanesini secerek bu programi calistirabilirsiniz. Eger sayi girmek istemiyorsaniz sadece Enter tusuna basiniz.\n\n");
    
    int carpan=0;
    int sayilar[3];
    
    while(carpan < 1 || carpan > 3){
        int deger;
        printf("Kac adet sayi girmek istiyorsunuz -> ");
        int result = scanf("%d", &deger);
        
        if(result==0) fflush(stdin);
        else carpan = deger;
    }
    printf("\n");
    
    for(i=0; i<carpan; i++){
        int sayi=0;
        while(sayi < 1 || sayi > 3){
            int deger;
            printf("Lutfen %d.sayiyi giriniz -> ", i+1);
            int result = scanf("%d", &deger);

            if(result==0) fflush(stdin);
            else {
                sayi = deger;
                sayilar[i] = sayi;
            }
        }
    }

    printf("\n");
    
    sirala(sayilar, sizeof(sayilar) / sizeof(sayilar[0]));

    switch (carpan) {
        case 1:
            tek_sayili(sayilar[2]);
            break;
        case 2:
            iki_sayili(sayilar[1], sayilar[2]);
            break;
        case 3:
            uc_sayili(sayilar[0], sayilar[1], sayilar[2]);
            break;
        default:
            break;
    }
}

void degistir(int* xp, int* yp){
    int gecici = *xp;
    *xp = *yp;
    *yp = gecici;
}

void sirala(int arr[], int n){
    int i,j,min_idx;
  
    for (i=0; i<n-1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        degistir(&arr[min_idx], &arr[i]);
    }
}

void uc_sayili(int sayi1, int sayi2, int sayi3){
    int x=0,y=0,z=0,i,j,k;
    for(i=0; i<sayi1; i++){
        x++;
        for(j=0; j<sayi2; j++){
            y++;
            for(k=0; k<sayi3; k++){
                z++;
                printf("%d %d %d\n", x, y, z);
            }
            z=0;
        }
        y=0;
    }
}

void iki_sayili(int sayi1, int sayi2){
    int x=0,y=0,i,j;
    for(i=0; i<sayi1; i++){
        x++;
        for(j=0; j<sayi2; j++){
            y++;
            printf("%d %d\n", x, y);
        }
        y=0;
    }
}

void tek_sayili(int sayi){
    int x=0,i;
    for(i=0; i<sayi; i++){
        x++;
        printf("%d\n", x);
    }
}
