#include <stdio.h>//linked list ekleme,silme, ters çevirme iþlemleri
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
			q = q->next; //bu dongu sondaki elemaný buldurur
		}
		q->next =eklenecek;
	}//else bloðu içinde traverse iþlemi yapýlýyor
}

void arayaekle(int x,int y){//x hangi sayýnýn onune ekleneceðini belirtiyor y de hangi sayýnýn ekleneceðini belirten parametre
	
	struct node* arayaeklenecek = (struct node*)malloc(sizeof(struct node));//araya eklenecek düðüm için alan oluþturdum
	arayaeklenecek->data = y;
	q = start;
	while(q->next->data != x){ //bu traverse iþlemi 3=>5=>7=>9=>10 örn 9 un önüne eklemek istiyorsak 7 yi bulur 
		q = q->next;//yani q deðeri 7 yi tutar
	}
	struct node* onune = (struct node*)malloc(sizeof(struct node));//9 u tutan düðümü elimde tutmam lazým
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
	while(q->next->next != NULL){//bu döngü sondan bir önceki elemaný bulacak
		q = q->next;//q sondan bir önceki q next son eleman 
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
	while(q->next->data != x){//traverse iþlemi
		q = q->next;//q silinecek düðümden bir önceki düðümdür
	}
	if(q->next==NULL){
		sondansil();
	}
	onceki = q;
	sonraki = q->next->next;
	free(q->next);
	onceki->next = sonraki;
}

void terscevir(){// baðlý listeyi ters çevirme iþlemi 
	struct node* temp;
	struct node* prev = NULL;
	q = start;
	while(q != NULL){//döngü süresince hiçbir düðüm boþ olmayacak
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
		printf("%d  ",q->data);//buradaki dögüde son deðeri yazdýrmaz
		q= q->next;
	}
	printf("%d",q->data);// o yuzden burada en son elemaný yazdýrýrýz
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
			printf("\n Sona eklemek istediginiz elemaný giriniz:");
			scanf("%d",&sona);
			sonaekle(sona);
			yazdir();
			break;
		case 2:
			printf("\n Basa eklemek istediginiz elemaný giriniz:");
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
