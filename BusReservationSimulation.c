
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void ANA_MENU();
void FIRMA_GIRISI();
void MUSTERI_GIRISI();
void Otobus_Ekle();
void Sefer_Bilgisi();
void Koltuk_Bilgisi();
void Sefer_No();
void Kapasite();
void Otobus_No();
void bilgi();
struct
{
char baslangic_sehri[20],varis_sehri[20];
int kalkis_saat,sonuc,islem;
char rando[5];
int hasilat,kisi_basi_ucret;}sefer[35];

int sayac=-1,kat=0;

struct
{

int sayi;
int apasite;
int Personel;
char Otobus_Modeli[10];
}otobus[30];

int main(){

 ANA_MENU();

return 0;
}

void ANA_MENU(){
    system("cls");
	int x,i=0;
    tekrar:
    printf("ANA MENU\n1.FIRMA GIRISI\n2.MUSTERI GIRISI\n3.CIKIS\n\n");
    printf("Lutfen seciminizi yapiniz:");
    scanf("%d",&x);
    if (x<4){
	    if (x==1){
	        FIRMA_GIRISI();
	    }
        else if(x==2){
    	    MUSTERI_GIRISI();
	    }
	    else if(x==3){
		    printf("cikis yapiliyor");
		    exit(1);
        }
    }

    else{
        printf("\nGecersiz giris yaptiniz.\n");
	    goto tekrar;
    }

}

void FIRMA_GIRISI(){

	int x;
	tekrar:
	printf("\n1-Otobus Ekle\n2-Sefer Bilgisi Ekle\n3-Sefer/Koltuk Bilgisi\n4-Bir Ust Menuye Don\n");
    printf("Lutfen seciminizi yapiniz:");
    scanf("%d",&x);
    if (x<5){
    	if (x==1){
		    Otobus_Ekle();
	    }
        else if (x==2){
	        Sefer_Bilgisi();
	    }
	    else if (x==3){
		    Koltuk_Bilgisi();
	    }
	    else if (x==4){
		    ANA_MENU();
	    }
    }
    else
    {
        printf("Gecersiz giris tekrar deneyin\n");
	     goto tekrar;
    }
}
void Otobus_Ekle(){
     sayac++;


	printf("\nOtobus_Modeli:");
	scanf("%s",otobus[sayac].Otobus_Modeli);

	Otobus_No();
}

void Otobus_No(){

	printf("otobus no:%d\n",sayac);

    Kapasite();
}
void Kapasite(){

	printf("Kapasite:");
	tekrar:
	scanf("%d",&otobus[sayac].apasite);
	if (otobus[sayac].apasite>30){
		printf("Personel sayisi:3\n\n");
		otobus[sayac].Personel=3;
	}
    else if(otobus[sayac].apasite<30 && otobus[sayac].apasite>0){
        printf("Personel sayisi:2\n\n");
        otobus[sayac].Personel=2;

	}
	else{
		printf("Hatali islem girdiniz tekrar giriniz:");

		goto tekrar;
	}


	FIRMA_GIRISI();
}

void Sefer_Bilgisi(){
	int Otobus_No;


	printf("Otobus numarasini giriniz:");
	scanf("%d",&Otobus_No);


    int saat,varis_saat;
    geridon:
    printf("saati giriniz:");
    scanf("%d",&saat);
    sefer[sayac].kalkis_saat=saat*100+55;



    if(saat<24 && saat>=0){
        printf("kalkissaati:%d\n" ,sefer[sayac].kalkis_saat);
    }
    else{
        printf("Hatali deger girdiniz.");
        goto geridon;
        }

    printf("varis saatini:");
    scanf("%d",&varis_saat);
    replay:

    sefer[sayac].sonuc=varis_saat*100;
    sefer[sayac].islem=sefer[sayac].sonuc-sefer[sayac].kalkis_saat-40;
    if(otobus[sayac].apasite>30 && otobus[sayac].Personel==3){
        printf("yolculuk suresi:%d",abs(sefer[sayac].islem));
    }
    else if(otobus[sayac].apasite<30 && otobus[sayac].Personel==2){
        if(sefer[sayac].islem>400){
            printf("hatali kullanim tekrar deneyiniz:");
            goto replay;
        }
        else;
            printf("yolculuk suresi:%d",abs(sefer[sayac].islem));
    }


    Sefer_No();
  }

void Sefer_No(){
    char hex[] = {"0123456789ABCDEF"};
    char ses[]={"5"};
	int i=0,m=0;


    srand(time(NULL));
    for(m;m<2;m++){
    	sefer[sayac].rando[m]=ses[(rand()%1)];
	}
	for( i; i<4;i++){
        sefer[sayac].rando[i+2]=hex[(rand()%16)];
    }





    printf("\nSefer numaraniz :%s\n",&sefer[sayac].rando);

    printf("\nSeferin baslayacagi sehri giriniz:" );
    scanf("%s" ,&sefer[sayac].baslangic_sehri);
    printf("\nSeferin bitecegi sehri giriniz:" );
    scanf("%s" ,&sefer[sayac].varis_sehri);

    printf("\nBu yolculuk sonunda toplanmasi gereken hasilat degerini giriniz:");
    scanf("%d" ,&sefer[sayac].hasilat);

    sefer[sayac].kisi_basi_ucret = sefer[sayac].hasilat /otobus[sayac].apasite;

    printf("\nKisi basi odenmesi gereken ucret:%d" ,sefer[sayac].kisi_basi_ucret);




    FIRMA_GIRISI();
	}
void Koltuk_Bilgisi(){

	char Sefer_No[35];
    int secim;
    	printf("1-Bos koltuklar\n2-Sefer bilgisi\n");
	printf("Lutfen seciminizi yapiniz:");

	scanf("%d",&secim);

	if(secim==1){




        printf("aratmak istediginiz otobusun no:");
            int i,j,istek;
            scanf("%d",&istek);


                for(i=1;i<=(otobus[istek].apasite/4);i++){
                    printf(" %2.d\t",i);
                    for(j=1;j<=4;j++){
                        printf(" [ ]");
                    }
                printf("\n");
                    }
                if((otobus[istek].apasite%4)!=0)
                    printf("%2d\t",(otobus[istek].apasite/4)+1);
                for(i=1;(i<=otobus[istek].apasite%4);i++){
                    printf("[ ]");
                }


        FIRMA_GIRISI();

    }
	else if(secim==2){
	    bilgi();

}
}
void bilgi(){
	char Sefer_No[35];
	int i;
    for(i=0;i<sayac+1;i++){
    	printf("sefer no:%s",sefer[i].rando);
	}

    printf("\nSefer_No:");
    scanf("%s",Sefer_No);
    for(i=0;i<sayac+1;i++){
    	if(strcmp(sefer[i].rando,Sefer_No)==0){
    		printf("baslangic_sehri:%s\tvaris_sehri:%s\tsefer no:%s\thasilat:%d\tsure:%d\tkalkis saat:%d\tbilet fiyati:%d\tvaris saat:%d\totobus no:%d\n",sefer[i].baslangic_sehri,sefer[i].varis_sehri,sefer[i].rando,sefer[i].hasilat,sefer[i].islem,sefer[i].kalkis_saat,sefer[i].kisi_basi_ucret,sefer[i].sonuc,sayac);
		}
	}

    FIRMA_GIRISI();


}
void MUSTERI_GIRISI(){

	int tercih,koltuk_no,onay;

	struct
	{
	char ad[20],soyad[20];
	char NUMARA[7];
	}kisi[20];
     char rez_no[7];


	printf("\n1-Seferleri Listele\n2-Sefer Rezervasyon Yap\n3-Bir ust Menuye Don\n4-Rezervasyon Goster\n");
	printf("Lutfen seciminizi yapiniz\n");
	scanf("%d",&tercih);
    do{
    	if(tercih==1){

            char Sefer_No[35];
	        int i;
            for(i=0;i<sayac+1;i++){
    	        printf("sefer no:%s",sefer[i].rando);
	        }
            printf("\nSefer_No:");
            scanf("%s",Sefer_No);
            for(i=0;i<sayac+1;i++){
    	        if(strcmp(sefer[i].rando,Sefer_No)==0){
    		        printf("baslangic_sehri:%s\tvaris_sehri:%s\tsefer no:%s\thasilat:%d\tsure:%d\tkalkis saat:%d\tbilet fiyati:%d\tvaris saat:%d\totobus no:%d",sefer[i].baslangic_sehri,sefer[i].varis_sehri,sefer[i].rando,sefer[i].hasilat,sefer[i].islem,sefer[i].kalkis_saat,sefer[i].kisi_basi_ucret,sefer[i].sonuc,sayac);
		        }
	       }
            MUSTERI_GIRISI();
        }
        else if(tercih==2){
        	char Sefer_No[35];
	        int i;
            for(i=0;i<sayac+1;i++){
    	        printf("sefer no:%s",sefer[i].rando);
	        }
            printf("\nSefer_No:");
            scanf("%s",Sefer_No);
            for(i=0;i<sayac+1;i++){
    	        if(strcmp(sefer[i].rando,Sefer_No)==0){
    		        printf("baslangic_sehri:%s\tvaris_sehri:%s\tsefer no:%s\thasilat:%d\tsure:%d\tkalkis saat:%d\tbilet fiyati:%d\tvaris saat:%d\totobus no:%d",sefer[i].baslangic_sehri,sefer[i].varis_sehri,sefer[i].rando,sefer[i].hasilat,sefer[i].islem,sefer[i].kalkis_saat,sefer[i].kisi_basi_ucret,sefer[i].sonuc,sayac);
		        }
	       }

        printf("aratmak istediginiz otobusun no:");
            int m,j,istek;
            scanf("%d",&istek);


                for(m=1;m<=(otobus[istek].apasite/4);m++){
                    printf(" %2.d\t",m);
                    for(j=1;j<=4;j++){
                        printf(" [ ]");
                    }
                printf("\n");
                    }
                if((otobus[istek].apasite%4)!=0)
                    printf("%2d\t",(otobus[istek].apasite/4)+1);
                for(m=1;m<=otobus[istek].apasite%4;m++){
                    printf("[ ]");
                }


		printf("\nAd:");scanf("%s",&kisi[kat].ad);
        printf("soyad:");scanf("%s",&kisi[kat].soyad);
        printf("koltuk no:");scanf("%d",&koltuk_no);
        printf("\nonayliyormusunuz?(evet='1'    hayir='2')");
        scanf("%d",&onay);
        if(onay==1){
            char number[] = {"0123456789ABCDEF"};
            int n=0;
            srand(time(NULL));
            for( n; n<8;n++){
                kisi[kat].NUMARA[n]=number[(rand()%16)];

            }
            printf("rezervasyon numara:%s", kisi[kat].NUMARA);

            kat++;
            MUSTERI_GIRISI();
		}
	    }
		else if(onay==2){
			printf("iptal edildi...");
			ANA_MENU();
		}


        else if(tercih==3){
        	ANA_MENU();
        }
        else if(tercih==4){
        	int a=0;
			printf("rezervasyon numarasini giriniz:");scanf("%s",&rez_no);
        	for(a;a<21;a++){
			    if(strcmp(kisi[a].NUMARA,rez_no)==0)
        	{
        		printf("%s %s %s",kisi[a].ad,kisi[a].soyad,kisi[a].NUMARA);
        	}
			}
             MUSTERI_GIRISI();
		}
	}while(tercih!=5);

}
