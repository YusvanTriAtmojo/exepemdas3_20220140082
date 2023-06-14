#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Pengarang;
class Buku;
class Penerbit {
public:
	string namaPenerbit;
	vector<Pengarang*> daftar_pengarang;
	Penerbit(string PnamaPenerbit) : namaPenerbit(PnamaPenerbit) {
		//cout << "Penerbit\"" << namaPenerbit << "\"ada\n";
	}
	~Penerbit() {
		//cout << "Penerbit\"" << namaPenerbit << "\" tidak ada\n";
	}
	void tambahPengarang(Pengarang*);
	void cetakPengarang();
};

class Pengarang {
public:
	string namaPengarang;
	vector<Penerbit*> daftar_penerbit;
	vector<Buku*> daftar_buku;
	Pengarang(string PnamaPengarang) : namaPengarang(PnamaPengarang) {
		//cout << "Pengarang\"" << namaPengarang << "\"ada\n";
	}
	~Pengarang() {
		//cout << "Pengarang\"" << namaPengarang << "\" tidak ada\n";
	}
	void tambahPenerbit(Penerbit*);
	void cetakPenerbit();
	void tambahBuku(Buku*);
	void cetakBuku();
};

class Buku {
public:
	string judulBuku;
	Buku(string judulbuku) :judulBuku(judulbuku) {
		//cout << "Buku\"" << judulBuku << "\" ada \n";
	}
	~Buku() {
		//cout << "Buku\"" << judulBuku << "\" tidak ada\n";
	}
};

void Pengarang::tambahPenerbit(Penerbit* penerbit) {
	daftar_penerbit.push_back(penerbit);
}

void Pengarang::cetakPenerbit() {
	cout << "Daftar Penerbit yang diikuti pengarang \"" << this->namaPengarang << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->namaPenerbit << "\n";
	}
	cout << endl;
}

void Pengarang::tambahBuku(Buku* buku) {
	daftar_buku.push_back(buku);
}

void Pengarang::cetakBuku() {
	cout << "Daftar Buku yang dikarang\"" << this->namaPengarang << "\":\n";
	for (auto& a : daftar_buku) {
		cout << a->judulBuku << "\n";
	}
	cout << endl;
}
void Penerbit::tambahPengarang(Pengarang* pengarang) {
	daftar_pengarang.push_back(pengarang);
	pengarang->tambahPenerbit(this);
}

void Penerbit::cetakPengarang() {
	cout << "Daftar Pengarang pada penerbit \" " << this->namaPenerbit << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->namaPengarang << "\n";
	}
	cout << endl;
}

int main()
{
	Penerbit* varPenerbit1 = new Penerbit("Gama Press");
	Penerbit* varPenerbit2 = new Penerbit("Intan Pariwara");

	Pengarang* varPengarang1 = new Pengarang("Joko");
	Pengarang* varPengarang2 = new Pengarang("Lia");
	Pengarang* varPengarang3 = new Pengarang("Giga");
	Pengarang* varPengarang4 = new Pengarang("Asroni");

	Buku* varBuku1 = new Buku("Fisika");
	Buku* varBuku2 = new Buku("Algoritma");
	Buku* varBuku3 = new Buku("Basisdata");
	Buku* varBuku4 = new Buku("Dasar Pemograman");
	Buku* varBuku5 = new Buku("Matematika");
	Buku* varBuku6 = new Buku("Multimedia 1");

	varPenerbit1->tambahPengarang(varPengarang1);
	varPenerbit1->tambahPengarang(varPengarang2);
	varPenerbit1->tambahPengarang(varPengarang3);

	varPenerbit2->tambahPengarang(varPengarang4);
	varPenerbit2->tambahPengarang(varPengarang3);

	varPengarang3->tambahPenerbit(varPenerbit1);
	varPengarang3->tambahPenerbit(varPenerbit2);

	varPengarang1->tambahBuku(varBuku1);
	varPengarang1->tambahBuku(varBuku2);

	varPengarang2->tambahBuku(varBuku3);

	varPengarang4->tambahBuku(varBuku4);

	varPengarang3->tambahBuku(varBuku5);
	varPengarang3->tambahBuku(varBuku6);

	varPenerbit1->cetakPengarang();
	varPenerbit2->cetakPengarang();
	varPengarang1->cetakPenerbit();
	varPengarang2->cetakPenerbit();
	varPengarang3->cetakPenerbit();
	varPengarang4->cetakPenerbit();
	varPengarang1->cetakBuku();
	varPengarang2->cetakBuku();
	varPengarang3->cetakBuku();
	varPengarang4->cetakBuku();

	delete varPenerbit1;
	delete varPenerbit2;
	delete varPengarang1;
	delete varPengarang2;
	delete varPengarang3;
	delete varPengarang4;
	delete varBuku1;
	delete varBuku2;
	delete varBuku3;
	delete varBuku4;
	delete varBuku5;
	delete varBuku6;
	return 0;
}