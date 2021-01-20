#include <stdlib.h>


// ENGINCAN DANABAS - 19010011032

struct araba_ozellikler{
	
	char araba_renk[20];
	float araba_yil;
	float araba_km;
	float alis_fiyat;
	float satis_fiyat;
	float araba_kar;
	float motor_hacmi; // �rn: 1.4---1.6---2.0---3.0
	int yakit_tipi; // 1se benzin 2 ise benzin ve lpg 3 ise dizel
	int kasa_tipi; //1se hatchback 2 ise sedan
	
};

typedef struct{
	char araba_uretici[20];
	int araba_adet;
	char araba_model[20];
	
	struct araba_ozellikler *araba_ozellik;
	
}araba;
int flag=0;
araba *araba_ptr=NULL;
void ekle(){
	system("COLOR C7");
	system("cls");
	printf("Araba Bilgilerini Giriniz....\n\n\n\n");
	if(araba_ptr==NULL){
		flag+=1;
		araba_ptr = (araba *)calloc(sizeof(araba),1); //araba tipinde 1 adet yer ay�r...
		printf("Araba Marka: ");
		scanf("%s", &araba_ptr->araba_uretici);
		printf("Araba Model: ");
		scanf("%s", &araba_ptr->araba_model);
		printf("Araba Adet: ");
		scanf("%d", &araba_ptr->araba_adet);
		araba_ptr->araba_ozellik = calloc(sizeof(*araba_ptr->araba_ozellik),araba_ptr->araba_adet); //araba adet kadar yer a�.
		int i;
		for(i=0;i<araba_ptr->araba_adet;i++){
			printf("\n%d. Araba Bilgileri\n\n",i+1);
			printf("Araba Rengi: ");
			scanf("%s", &(araba_ptr->araba_ozellik+i)->araba_renk);
			printf("Araba Uretim Yili: ");
			scanf("%f", &(araba_ptr->araba_ozellik+i)->araba_yil);
			printf("Araba Km: ");
			scanf("%f", &(araba_ptr->araba_ozellik+i)->araba_km);
			printf("Araba Alis Fiyat: ");
			scanf("%f", &(araba_ptr->araba_ozellik+i)->alis_fiyat);
			printf("Araba Satis Fiyat: ");
			scanf("%f", &(araba_ptr->araba_ozellik+i)->satis_fiyat);
			printf("Araba Motor Hacmi(1.4-1.6-2.0): ");
			scanf("%f", &(araba_ptr->araba_ozellik+i)->motor_hacmi);
			printf("Araba Yakit Tipi(1-Benzin,2-Benzin & Lpg,3-)Diesel): ");
			scanf("%d", &(araba_ptr->araba_ozellik+i)->yakit_tipi);
			printf("Araba Kasa Tipi(1-Hatchback,2-Sedan): ");
			scanf("%d", &(araba_ptr->araba_ozellik+i)->kasa_tipi);
		}
	}
	else{
		flag+=1;
		araba_ptr = (araba *)realloc(araba_ptr, flag * sizeof(araba)); //bellek alan�nda geni�letme
		printf("Araba Uretici: ");
		scanf("%s", &(araba_ptr+flag-1)->araba_uretici);
		printf("Araba Model: ");
		scanf("%s", &(araba_ptr+flag-1)->araba_model);
		printf("Araba Adet: ");
		scanf("%d", &(araba_ptr+flag-1)->araba_adet);
		(araba_ptr+flag-1)->araba_ozellik = calloc(sizeof(*araba_ptr->araba_ozellik),(araba_ptr+flag-1)->araba_adet);
		int i;
		for(i=0;i<(araba_ptr+flag-1)->araba_adet;i++){

			printf("\n%d. Araba Bilgileri\n\n",i+1);
			printf("Araba Rengi: ");
			scanf("%s", &((araba_ptr+flag-1)->araba_ozellik+i)->araba_renk);
			printf("Araba Uretim Yili: ");
			scanf("%f", &((araba_ptr+flag-1)->araba_ozellik+i)->araba_yil);
			printf("Araba Km: ");
			scanf("%f", &((araba_ptr+flag-1)->araba_ozellik+i)->araba_km);
			printf("Araba Alis Fiyat: ");
			scanf("%f", &((araba_ptr+flag-1)->araba_ozellik+i)->alis_fiyat);
			printf("Araba Satis Fiyat: ");
			scanf("%f", &((araba_ptr+flag-1)->araba_ozellik+i)->satis_fiyat);
			printf("Araba Motor Hacmi(1.4-1.6-2.0): ");
			scanf("%f", &((araba_ptr+flag-1)->araba_ozellik+i)->motor_hacmi);
			printf("Araba Yakit Tipi(1-Benzin,2-Benzin & Lpg,3-)Diesel): ");
			scanf("%d", &((araba_ptr+flag-1)->araba_ozellik+i)->yakit_tipi);
			printf("Araba Kasa Tipi(1-Hatchback,2-Sedan): ");
			scanf("%d", &((araba_ptr+flag-1)->araba_ozellik+i)->kasa_tipi);
		}
	}
}

void goruntule(){
	char devam;
	system("cls");
	system("COLOR F5");
	int i,j;
	printf("\nARABA GORUNTULEME EKRANI");
	for(i=0;i<flag;i++){
		if(strcmp((araba_ptr+i)->araba_model,"\0")==0){
			continue;
		}
		printf("\n\n**********************************************");
		printf("\nAraba Marka: %s", (araba_ptr+i)->araba_uretici);
		printf("\nAraba Model: %s", (araba_ptr+i)->araba_model);
		for(j=0;j<(araba_ptr+i)->araba_adet;j++){
			printf("\n------------------------------------");
			printf("\n\n%s Marka %s Model %d. Arac Ozellikleri",(araba_ptr+i)->araba_uretici,(araba_ptr+i)->araba_model,j+1);
			printf("\nAraba Renk: %s", ((araba_ptr+i)->araba_ozellik+j)->araba_renk);
			printf("\nAraba Uretim Yil: %.0f", ((araba_ptr+i)->araba_ozellik+j)->araba_yil);
			printf("\nAraba Km: %.3f",((araba_ptr+i)->araba_ozellik+j)->araba_km);
			printf("\nAraba Alis Fiyati: %.3f",((araba_ptr+i)->araba_ozellik+j)->alis_fiyat);
			printf("\nAraba Satis Fiyati: %.3f",((araba_ptr+i)->araba_ozellik+j)->satis_fiyat);
			printf("\nAraba Motor Hacmi: %.4f",((araba_ptr+i)->araba_ozellik+j)->motor_hacmi);
			if(araba_ptr->araba_ozellik->yakit_tipi==1){
				printf("\nAraba Yakit Tipi: Benzin");
			}
			else if(araba_ptr->araba_ozellik->yakit_tipi==2){
				printf("\nAraba Yakit Tipi: Benzin & LPG");
			}
			else{
				printf("\nAraba Yakit Tipi: Diesel");
			}
			if(araba_ptr->araba_ozellik->kasa_tipi==1){
				printf("\nAraba Kasa Tipi: Hatchback");
			}
			else if(araba_ptr->araba_ozellik->kasa_tipi==2){
				printf("\nAraba Kasa Tipi: Sedan");
			}
			
	}
	}
	printf("\n\nDevam Etmek Icin Herhangi Bir Harf Giriniz ->");
	scanf("%s",&devam);
	
}

void kar_goruntule(){
	
	int i,j;
	float alis,satis;
	char devam;
	system("COLOR F5");
	for(i=0;i<flag;i++){
		printf("\n\n**********************************************");
		printf("\nAraba Marka: %s", (araba_ptr+i)->araba_uretici);
		printf("\nAraba Model: %s", (araba_ptr+i)->araba_model);
		for(j=0;j<(araba_ptr+i)->araba_adet;j++){
			printf("\n------------------------------------");
			printf("\n\n%s Marka %s Model %d. Arac Kar Bilgisi",(araba_ptr+i)->araba_uretici,(araba_ptr+i)->araba_model,j+1);
			alis=((araba_ptr+i)->araba_ozellik+j)->alis_fiyat;
			satis=((araba_ptr+i)->araba_ozellik+j)->satis_fiyat;
			printf("\n Aracin Kari: %.3f Turk Lirasi",(satis-alis));
			
		}
		
	}
	printf("\n\nDevam Etmek Icin Herhangi Bir Harf Giriniz ->");
		scanf("%s",&devam);
}

void sil(){
	system("cls");
	char devam,silinecek_araba_model[20];
	printf("\nARABA SILME EKRANI");
	printf("-------------------------------------");
	printf("\nSilinecek Araba/Arabalarin Modelini Yaziniz :");
	scanf("%s", &silinecek_araba_model);
	int i,j;
	for(i=0;i<flag;i++){
		//araba sayisi kadar don
		if(strcmp((araba_ptr+i)->araba_model,silinecek_araba_model)==0)
		{
			strcpy((araba_ptr+i)->araba_model,"\0");
			printf("\nArac Basariyla Silindi.");
			printf("\n\nDevam Etmek Icin Herhangi Bir Harf Giriniz ->");
			scanf("%s",&devam);
		}
	}
}

void ara(){

	system("cls");
	int i,j;
	char devam,aranacak_araba[20];
	printf("\nARABA ARAMA EKRANI");
	printf("\nAranacak Arabayi Giriniz : ");
	scanf("%s", &aranacak_araba);
	for(i=0;i<flag;i++){
		if(strcmp((araba_ptr+i)->araba_model,aranacak_araba)==0){
			printf("\n\n**********************************************");
			printf("\nAraba Marka: %s", (araba_ptr+i)->araba_uretici);
			printf("\nAraba Model: %s", (araba_ptr+i)->araba_model);
			for(j=0;j<(araba_ptr+i)->araba_adet;j++){
				printf("\n------------------------------------");
				printf("\n\n%s Marka %s Model %d. Arac Ozellikleri",(araba_ptr+i)->araba_uretici,(araba_ptr+i)->araba_model,j+1);
				printf("\nAraba Renk: %s", ((araba_ptr+i)->araba_ozellik+j)->araba_renk);
				printf("\nAraba Uretim Yil: %.0f", ((araba_ptr+i)->araba_ozellik+j)->araba_yil);
				printf("\nAraba Km: %.3f",((araba_ptr+i)->araba_ozellik+j)->araba_km);
				printf("\nAraba Alis Fiyati: %.3f",((araba_ptr+i)->araba_ozellik+j)->alis_fiyat);
				printf("\nAraba Satis Fiyati: %.3f",((araba_ptr+i)->araba_ozellik+j)->satis_fiyat);
				printf("\nAraba Motor Hacmi: %.4f",((araba_ptr+i)->araba_ozellik+j)->motor_hacmi);
				if(araba_ptr->araba_ozellik->yakit_tipi==1){
					printf("\nAraba Yakit Tipi: Benzin");
				}
				else if(araba_ptr->araba_ozellik->yakit_tipi==2){
					printf("\nAraba Yakit Tipi: Benzin & LPG");
				}
				else{
					printf("\nAraba Yakit Tipi: Diesel");
				}
				if(araba_ptr->araba_ozellik->kasa_tipi==1){
					printf("\nAraba Kasa Tipi: Hatchback");
				}
				else if(araba_ptr->araba_ozellik->kasa_tipi==2){
					printf("\nAraba Kasa Tipi: Sedan");
			}
		}
		
			
	}
	}
	printf("\n\nDevam Etmek Icin Herhangi Bir Harf Giriniz ->");
	scanf("%s",&devam);
	
}


void guncelle(){
	system("cls");
	int i,j,index;
	char araba_mod[20],devam;
	printf("\nARABA GUNCELLEME EKRANI");
	printf("\nGuncellencek Arabanin Modeli: ");
	scanf("%s",&araba_mod);
	printf("\nGuncelleneck Aracin Sira Sayisi: ");
	scanf("%d",&index);
	index--;
	for(i=0;i<flag;i++){
		//araba sayisi kadar don
		if(strcmp((araba_ptr+i)->araba_model,araba_mod)==0)
		{
			printf("\nGuncel Km: ");
			scanf("%f",&((araba_ptr+i)->araba_ozellik+index)->araba_km);
			printf("Guncel Alis Fiyat: ");
			scanf("%f",&((araba_ptr+i)->araba_ozellik+index)->alis_fiyat);
			printf("Guncel Satis Fiyat: ");
			scanf("%f",&((araba_ptr+i)->araba_ozellik+index)->satis_fiyat);
			
			printf("\n\nDevam Etmek Icin Herhangi Bir Harf Giriniz ->");
			scanf("%s",&devam);
		}
	}
	}
int main(int argc, char *argv[]) {
	int secim,i;
	while(1){
		system("COLOR F2");
		system("cls");
		printf("\nGALERI YONETIM OTOMASYONUNA HOSGEDLINIZ..");
		printf("\n1-)Araba Ekle");
		printf("\n2-)Araba Bilgileri Guncelle");
		printf("\n3-)Araba Sil");
		printf("\n4-)Arabalari Listele");
		printf("\n5-)Araba Kar Goruntule");
		printf("\n6-)Araba Ara");
		printf("\n\nSecim->");
		scanf("%d",&secim);
		switch(secim){
			case 1:
				ekle();
				
				break;
			case 2:
				guncelle();
				break;
			case 3:
				sil();
				break;
			case 4:
				goruntule();
				break;
			case 5:
				kar_goruntule();
				break;
			case 6:
				ara();
				break;
			
		}
	}
	

	
	
	
	return 0;
}

