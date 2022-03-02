#include<iostream>
using namespace std;
int main(){
	string nama, npm;
	cout<<"IDENTITAS MAHASISWA"<< endl;
	cout<<"Nama: ";
	cin>> nama;
	cout<<"NPM: "; 
	getline (cin, npm);
	cin>> npm;
	cout<<"================================"<< endl;
	string username;
	string password;
	int i;
	cout<<"silahkan Masukkan Username dan Password Anda"<< endl;
	cout<<"username: ";
	cin>> username;
	cout<<"Password: ";
	cin>> password;
	while (username!="statistika" || password!="2021"){
		cout<<"username dan password anda salah"<<endl;
		cout<<"Masukkan Username dan Password Anda"<< endl<<endl;
		cout<<"username: ";
		cin>> username;
		cout<<"password: ";
		cin>> password;
	}
	cout<<"eldo"<<endl;
	int Pilihan; 
    while (Pilihan>=0) {
        cout <<endl<<"Selamat Datang di Program GANJIL GENAP"<<endl;
        cout <<"Pilih Program dibawah ini "<<endl;
        cout << " 1. GANJIL "<<endl;
        cout << " 2. GENAP "<<endl;
        cout << "Pilihan Anda (1 / 2) :";
        cin >>Pilihan;
        if (Pilihan ==1) {
            int x, ganjil;
            cout <<endl<< "Masukkan Angka Ganjil awal (1-10) :";
            cin >>ganjil;
            for(x=1; x<=20; x=x+2){
                cout << x <<"  ";
            }
        }
        else if (Pilihan ==2) {
            int y, Genap;
            cout <<endl<< "Masukkan Angka Genap Awal (1-10) :";
            cin >>Genap;
            for(y=2; y<=20; y=y+2){
                cout << y <<"  ";
            }
        }
        cout <<endl<<"Terima Kasih Sudah Menggunakan Program Ini"<<endl;
    }
    return 0;
}