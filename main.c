#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct node {
	int daireNo;
	char name[15];
	char surname[15];
	int odenenMiktar;
	struct node* next;
};
struct node* start;
struct node* sonEleman;
struct node* Yenidugum(int daire, char isim[15], char soyisim[15], int odenen) {
	struct node* eklenecek = (struct node*)malloc(sizeof(struct node));
	eklenecek->daireNo = daire;
	strcpy_s(eklenecek->name, isim);
	strcpy_s(eklenecek->surname, soyisim);
	eklenecek->odenenMiktar = odenen;
	eklenecek->next = NULL;
	return eklenecek;
}
void siraliEkle(int daire, char isim[15], char soyisim[15], int odenen) {
	struct node* eklenecek = (struct node*)malloc(sizeof(struct node));
	eklenecek->daireNo = daire;
	strcpy_s(eklenecek->name, isim);
	strcpy_s(eklenecek->surname, soyisim);
	eklenecek->odenenMiktar = odenen;
	eklenecek->next = NULL;
	if (start == NULL) {
		start = eklenecek;
	}
	else if (start->next == NULL) {
		if (start->daireNo > eklenecek->daireNo) {
			eklenecek->next = start;
			start = eklenecek;
		}
		else {
			start->next = eklenecek;
		}
	}
	else {
		struct node* temp = start;
		while (temp->next != NULL && temp->next->daireNo < eklenecek->daireNo) {
			temp = temp->next;
		}
		if (temp->next == NULL) {
			temp->next = eklenecek;
		}
		else if (temp == start) {
			eklenecek->next = start;
			start = eklenecek;
		}
		else {
			eklenecek->next = temp->next;
			temp->next = eklenecek;
		}
	}
}
void traverseList() {
	struct node* temp = start;
	while (temp != NULL) {
		cout << temp->daireNo << " " << temp->name << " " << temp->surname << " " << temp->odenenMiktar << endl;
		temp = temp->next;
	}
}
bool isNumeric(string s) {
	int flag = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		if (isdigit(s[i]) == 0) {
			flag = 1;
		}
	}
	if (flag == 1) {
		return false;
	}
	else {
		return true;
	}
}
int main()
{
	int controller;
	while (1) {
		int daire, odenen;
		char isim[15];
		char soyisim[15];
		string belirleyici;
		cout << "Aidat odemesi girmek icin (1) tiklayiniz." << endl;
		cout << "Mevcut odemeleri gormek icin (2) tiklayiniz." << endl;
		cout << "Guncelleme Yapmak icin (3) tiklayiniz." << endl;
		cin >> controller;
		if (controller == 1) {
			ofstream yazmaDosyasi;
			bool hataliGiris = 1;
			cout << "Kac Numarali Daire"<<endl;
			cin >> belirleyici;
			if (isNumeric(belirleyici) == false) {
				while (hataliGiris) {
					cout << "Hatali giris yaptiniz tekrar girin:"<<endl;
					cin >> belirleyici;
					if (isNumeric(belirleyici) == true) {
						hataliGiris = 0;
					}
				}
				
			}
			daire = stoi(belirleyici);
			cout << "Odeyen Ismi?"<<endl;
			cin >> isim;
			cout << "Odeyen Soyismi"<<endl;
			cin >> soyisim;
			cout << "Odenen Miktari Giriniz:"<<endl;
			cin >> belirleyici;
			hataliGiris = 1;
			if (isNumeric(belirleyici) == false) {
				while (hataliGiris) {
					cout << "Hatali giris yaptiniz tekrar giriniz:"<<endl;
					cin >> belirleyici;
					if (isNumeric(belirleyici) == true) {
						hataliGiris = 0;
					}
				}
			}
			odenen = stoi(belirleyici);
			siraliEkle(daire, isim, soyisim, odenen);
			struct node* temp = start;
			yazmaDosyasi.open("aidatlar.txt");
			while (temp != NULL) {
				yazmaDosyasi << temp->daireNo << " " << temp->name << " " << temp->surname << " " << temp->odenenMiktar << endl;
				temp = temp->next;
			}
			yazmaDosyasi.close();
		}
		else if (controller == 2) {
			
			struct node* temp = start;
			while (temp != NULL) {
				cout << temp->daireNo << " " << temp->name << " " << temp->surname << " " << temp->odenenMiktar << endl;
				temp = temp->next;
			}
		}
		else if (controller == 3) {
			ofstream yazmaDosyasi;

			int arananDaire;
			int guncelOdenen;
			cout << "Guncellemek istediginiz daireyi giriniz:" << endl;
			cin >> arananDaire;
			cout << "Odemek istediginiz tutari giriniz:" << endl;
			cin >> guncelOdenen;
			struct node* temp = start;
			while (temp->daireNo != arananDaire) {
				temp = temp->next;
			}
			temp->odenenMiktar = guncelOdenen;
			struct node* temp2 = start;
			yazmaDosyasi.open("aidatlar.txt");
			while (temp2 != NULL) {
				yazmaDosyasi << temp2->daireNo << " " << temp2->name << " " << temp2->surname << " " << temp2->odenenMiktar << endl;
				temp2 = temp2->next;
			}
			yazmaDosyasi.close();
		}
			
		
		
		

	}
	
	
	

	
}

