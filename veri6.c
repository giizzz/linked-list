#include <stdio.h>//linked list ekleme,silme, ters �evirme i�lemleri
#include <stdlib.h>

struct node{
	
	int data;
	struct node * next;
	
};

struct node* start = NULL;
struct node* temp = NULL;
struct node* q = NULL;

void sonaekle(int veri){
	
	struct node* eklenecek = (struct node*)malloc(sizeof(struct node));
	eklenecek->data = veri;
	eklenecek->next = NULL;
	
	if(start == NULL){
		start = eklenecek;
	}
	else{
		q= start;
		while(q->next != NULL){
			q = q->next; //bu dongu sondaki eleman� buldurur
		}
		q->next =eklenecek;
	}//else blo�u i�inde traverse i�lemi yap�l�yor
}

void arayaekle(int x,int y){//x hangi say�n�n onune eklenece�ini belirtiyor y de hangi say�n�n eklenece�ini belirten parametre
	
	struct node* arayaeklenecek = (struct node*)malloc(sizeof(struct node));//araya eklenecek d���m i�in alan olu�turdum
	arayaeklenecek->data = y;
	q = start;
	while(q->next->data != x){ //bu traverse i�lemi 3=>5=>7=>9=>10 �rn 9 un �n�ne eklemek istiyorsak 7 yi bulur 
		q = q->next;//yani q de�eri 7 yi tutar
	}
	struct node* onune = (struct node*)malloc(sizeof(struct node));//9 u tutan d���m� elimde tutmam laz�m
	onune = q->next;
	q->next = arayaeklenecek;
	arayaeklenecek->next = onune;
}

void basaekle(int veri){
	struct node* basagelecek =(struct node*)malloc(sizeof(struct node));
	basagelecek->data = veri;
	basagelecek->next = start;
	start = basagelecek;
	
}

void sondansil(){  //sondan eleman silme
		q = start;
	while(q->next->next != NULL){//bu d�ng� sondan bir �nceki eleman� bulacak
		q = q->next;//q sondan bir �nceki q next son eleman 
	}
	free(q->next);
	q->next = NULL;
	
}

void bastansil(){
	
	struct node* ikinci=NULL;
	ikinci = start->next;
	free(start);
	start = ikinci;
	
}

void aradansil(int x){
	if(start->data == x){
		bastansil();
	}
	struct node* onceki = NULL;
	struct node* sonraki = NULL;
	q=start;
	while(q->next->data != x){//traverse i�lemi
		q = q->next;//q silinecek d���mden bir �nceki d���md�r
	}
	if(q->next==NULL){
		sondansil();
	}
	onceki = q;
	sonraki = q->next->next;
	free(q->next);
	onceki->next = sonraki;
}

void terscevir(){// ba�l� listeyi ters �evirme i�lemi 
	struct node* temp;
	struct node* prev = NULL;
	q = start;
	while(q != NULL){//d�ng� s�resince hi�bir d���m bo� olmayacak
		temp = q->next;
		q->next = prev;
		prev = q;
		q=temp;
		
	}
	start = prev;
}

void yazdir(){
	q = start;
	while(q->next!= NULL){
		printf("%d  ",q->data);//buradaki d�g�de son de�eri yazd�rmaz
		q= q->next;
	}
	printf("%d",q->data);// o yuzden burada en son eleman� yazd�r�r�z
}

int main(){
	int x,y;
	int secim,sona,basa;
	while(1==1){
		printf("\n1-Sona ekle ");
		printf("\n2-Basa ekle ");
		printf("\n3-Araya ekle ");
		printf("\n4-Sondan eleman silme");
		printf("\n5-Bastan eleman silme");
		printf("\n6-Aradan eleman silme");
		printf("\n7-Ters dondurme islemi");
		printf("\n Yapmak istediginiz islemi seciniz: ");
		scanf("%d",&secim);
		switch(secim){
		
		case 1:
			printf("\n Sona eklemek istediginiz eleman� giriniz:");
			scanf("%d",&sona);
			sonaekle(sona);
			yazdir();
			break;
		case 2:
			printf("\n Basa eklemek istediginiz eleman� giriniz:");
			scanf("%d",&basa);
			basaekle(basa);
			yazdir();
			break;
		case 3:
			printf("\n Hangi sayinin onune ekleme yapacaksiniz:");
			scanf("%d",&x);
			printf("\n Hangi sayiyi ekleyeceksiniz:");
			scanf("%d",&y);
			arayaekle(x,y);
			yazdir();
			break;
		case 4:
			sondansil();
			yazdir();
			break;
		case 5:	
			bastansil();
			yazdir();
			break;
		case 6:
			printf("\n Silinmesini istediginiz sayi:");
			scanf("%d",&secim);
			aradansil(secim);
			yazdir();
			break;
		case 7:
			terscevir();
			yazdir();
			break;
			
	}
}
	
	return 0;
}
