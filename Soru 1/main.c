//
//  main.c
//  Odev
//
//  Created by Ahmet Ozrahat on 24.12.2020.
//

#include <stdio.h>

void islem_yap(void);

int main(void) {
    islem_yap();
    return 0;
}

void islem_yap(void){
    int matris1satir=0, matris1sutun=0, matris2satir=0, matris2sutun=0,i,j,k,l;
    
    // Kullaniciya program hakkinda bilgi veriyoruz.
    printf("Bu program mxn mertebeden A ile pxq mertebeden B matrisleri arasinda A#B islemlerini yapmaktadir.\n\n");
    
    // Kullanicidan matris mertebesini almak istiyoruz.
    // Ayni zamanda matris mertebeleri negatif olamayacagi icin kontrolleri yapiyoruz.
    // scanf'den donen deger sayi degilse fflush() metodu ile hafizadaki hatalari karakteri temizliyoruz.
    // Bu sayede program sonsuz donguden korunmus oluyor.
    while(matris1satir <= 0){
        int deger;
        printf("Lutfen birinci matrisin satir sayisini giriniz -> ");
        int result = scanf("%d", &deger);
        
        if(result == 0) fflush(stdin);
        else matris1satir = deger;
    }
    while(matris1sutun <= 0){
        int deger;
        printf("Lutfen birinci matrisin sutun sayisini giriniz -> ");
        int result = scanf("%d", &deger);
        
        if(result == 0) fflush(stdin);
        else matris1sutun = deger;
    }
    while(matris2satir <= 0){
        int deger;
        printf("Lutfen ikinci matrisin satir sayisini giriniz -> ");
        int result = scanf("%d", &deger);
        
        if(result == 0) fflush(stdin);
        else matris2satir = deger;
    }
    while(matris2sutun <= 0){
        int deger;
        printf("Lutfen ikinci matrisin sutun sayisini giriniz -> ");
        int result = scanf("%d", &deger);
        
        if(result == 0) fflush(stdin);
        else matris2sutun = deger;
    }
    
    // Elde ettigimiz matrislerin mertebelerini kullanarak A#B islemini gerceklestirecegimiz yeni matrisi olusturuyoruz.
    int matris1[matris1satir][matris1sutun], matris2[matris2satir][matris2sutun];
    
    for(i=0; i<matris1satir; i++){
        printf("Lutfen birinci matrisin %d. satirini giriniz (Enter) -> \n", i+1);
        
        for(j=0; j<matris1sutun; j++){
            int deger;
            scanf("%d", &deger);
            matris1[i][j] = deger;
        }
    }
    
    for(k=0; k<matris2satir; k++){
        printf("Lutfen ikinci matrisin %d. satirini giriniz (Enter) -> \n", k+1);
        
        for(l=0; l<matris2sutun; l++){
            int deger;
            scanf("%d", &deger);
            matris2[k][l] = deger;
        }
    }
    
    int yeniMatris[matris1satir*matris2satir][matris1sutun*matris2sutun];
    
    for(i=0; i<matris1satir; i++){
        for(j=0; j<matris1sutun; j++){
            for(k=0; k<matris2satir; k++){
                for(l=0; l<matris2sutun; l++){
                    yeniMatris[i*matris2satir+k][j*matris2sutun+l] = matris1[i][j] * matris2[k][l];
                }
            }
        }
    }

    printf("\nA#B matrisi:\n\n");

    for(k=0; k<matris1satir*matris2satir; k++){
        for(l=0; l<matris1sutun*matris2sutun; l++){
            printf("%d  ", yeniMatris[k][l]);
        }
        printf("\n");
    }
}
