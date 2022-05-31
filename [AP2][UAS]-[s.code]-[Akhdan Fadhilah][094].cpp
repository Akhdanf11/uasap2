#include <string.h>
#include <ctime>
#include "extend.h"

int level,status,plh1,plhtkt,tbhtiket,jlhtkt,totawal,totsem,totakhir,userpay,kembalian,x;
char userlogin[10],passlogin[10];
int statuslogin = 0;
char *nama;
int nokode = rand();
time_t now = time(0);
char* tgl = ctime(&now);

int login(int level){
	system("cls");
	if (level == 1){
		cout << "Kamu masuk sebagai admin"<<endl;
		status = 1; 
		
	}else if (level == 2){
		cout << "Kamu masuk sebagai kasir"<<endl;
		status = 2;
	}
	return status;
}

int bayar(int userpay){
	kembalian = userpay-totakhir;
	return kembalian;
}

int loginnew(){
	system("cls");
	//default username & password
	string userdef1= "admin";
	string passdef1= "ADMIN";
	string userdef2= "kasir";
	string passdef2= "KASIR";
	cout << "Login"<<endl; 
	cout << "Masukkan Username : ";
	cin>> userlogin;
	cout << "Masukkan Password : ";
	cin>> passlogin;
	strlwr(userlogin);
	if(status == 1){
		if((userlogin == userdef1) && (passlogin == passdef1)){
			cout << "Berhasil Login"<<endl;
			statuslogin+=1;
			system("pause");
			system("cls");
			nama = "admin";
		}else {
			cout << "Gagal login"<<endl;
			statuslogin = 0;
			system("pause");
			system("cls");
		}	
	}else if (status == 2){
		if((userlogin == userdef2) && (passlogin == passdef2)){
			cout << "Berhasil Login"<<endl;
			statuslogin+=1;
			system("pause");
			system("cls");
			nama = "kasir";
		}else {
			cout << "Gagal login"<<endl;
			statuslogin = 0;
			system("pause");
			system("cls");
		}
	}
	return statuslogin;
}

main (){
	data_tiket ticket[3];
    char ulangi = 'y';
	ticket[0].nama = "Reguler";
	ticket[0].harga = 30000;
    // perulangan while
    while(ulangi == 'y' || ulangi == 'Y'){
    	system("cls");
		index();
		cout << "Masuk sebagai : ";cin>>level;
		login(level);
		if(status == 1){
			while (statuslogin == 0){
						loginnew();
			}
			cout << "Kamu masuk sebagai "<<nama<<endl;
			batas();
			cout<<"1. Tambah tiket"<<endl;
			cout<<"2. keluar"<<endl;
			cout << "pilih : ";
			cin >> plh1;
			if(plh1 == 1){
				input_tiket(ticket[1]);
				system("cls");
				batas();
				cout<<"List tiket cinema"<<endl;
					for (int x=0; x<=1; x++){
					output_tiket(ticket[x]);
					}
			}else{
				exit;				
			}
			statuslogin = 0;
		}else if(status ==2){
			while (statuslogin == 0){
						loginnew();
			}
				cout << "Kamu masuk sebagai "<<nama<<endl;
				batas();
				cout<<"List tiket cinema"<<endl;
			batas();
				for (int x=0; x<=1; x++){
					if (ticket[x].harga == 1){
						break;
					}else {
						output_tiket(ticket[x]);
					}
				}
				cout<<"Pilih tiket : ";
				cin>>plhtkt;
				cout<<"Jumlah tiket : ";
				cin>>jlhtkt;
				system("cls");
				cout << "Struk Kasir"<<endl;
			batas();
					if (plhtkt == 1){
						x= 0;						
					}else if (plhtkt == 2){
						x=1;
					}
				totawal = ticket[x].harga * jlhtkt;
				totsem = 0.05 * totawal;
				totakhir = 	totawal+totsem;
				cout<< "Nomor kode " << nokode << endl;
				cout << "Nama Tiket  = " << ticket[x].nama << endl;
				cout << "Harga Tiket = Rp. " << ticket[x].harga << endl;	
				cout << "Total Awal  = Rp. " << totawal << endl;
				cout << "Pajak 5%    = Rp. " << totsem << endl;
				cout << "Total Akhir = Rp. " << totakhir << endl;
				cout << "Bayar       = Rp. "; 
				cin >> userpay;
				bayar(userpay);
				cout << "Kembalian   = Rp. " << kembalian << endl;
				cout << "Tanggal     = " << tgl << endl;
				system("pause");
			statuslogin = 0;
		}
        printf("Apakah kamu mau ke index?\n");
        printf("Jawab (y/t): ");
    	cin >> ulangi;
    }
    system("cls");
    batas();
    printf("See u again\n");
    return 0;
}
