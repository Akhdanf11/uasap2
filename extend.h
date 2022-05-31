#include <iostream>
using namespace std;

void batas(){
	cout << "*******************************"<<endl;
}

void index(){
	batas();
	cout << "Selamat Datang di Night Cinemax"<< endl;
	batas();
	cout << "1. Admin " << endl;
	cout << "2. Kasir "<< endl;
	//input angka 1-2
}

struct data_tiket {
	string nama;
	int harga;
};

void input_tiket(data_tiket &tbhtkt){
		cout<< "Masukkan nama kategori tiket : ";
		cin>>tbhtkt.nama;
		cout<< "Masukkan harga : ";
		cin>>tbhtkt.harga;
}

void output_tiket(data_tiket &tbhtkt){
		cout<< "Nama kategori tiket : " << tbhtkt.nama<<endl;
		cout<< "Harga tiket: " << tbhtkt.harga<<endl;
		batas();
}


