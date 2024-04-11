#include "Phong.h"
#include "SinhVien.h"
#include "HoaDon.h"
#include <iostream>
#include <string>
#include <cstring>
#include <regex> 


using namespace std;

void suaphong(Phong& phong);

void timVaSua(Phong* phong, int& n);

void taophong(Phong* phong, int& n);

void themphong(Phong* phong, int& n);

void xuatDSphong(Phong* phong, int n);

void themSinhVien(SinhVien* sv, const Phong* phong, const int& n);

SinhVien timSinhVien(const SinhVien* sv, string masv, const int& m);
void taohoadon(HoaDon* hd,Phong& phong);
void xuathd(HoaDon& hd);


int main() {

	Phong* phong = new Phong[1000];
	SinhVien* sv = new SinhVien[1000];
	HoaDon* hd = new HoaDon[1000];
	int n;
	int m;
	int dem=0;
	taophong(phong, n);
	int chon;
	do {
		cout << "\n\n******************************************\n";
		cout << "** Ban muon lam gi?\t\t\t**\n";
		cout << "** 1. Tim va sua phong\t\t\t**\n";
		cout << "** 2. Xuat danh sach phong\t\t**\n";
		cout << "** 3. Them phong\t\t\t**\n";
		cout << "** 4. Them sinh vien\t\t\t**\n";
		cout << "** 5. Them hoa don\t\t\t**\n";
		cout << "** 6. Xuat hoa don\t\t\t**\n";
		cout << "** 0. Thoat\t\t\t\t**\n";
		cout << "******************************************\n";
		cin >> chon;
		if (chon == 1) {
			timVaSua(phong, n);
		}
		else if (chon == 2) {
			xuatDSphong(phong, n);
		}
		else if (chon == 3) {
			themphong(phong, n);
		} else if(chon == 4) {
			cout<<"So luong sinh vien them vao:";
			cin>>m;
			themSinhVien(sv, phong, m);
			for(int i=0;i<n;i++){
				if(phong[i].tenphong == sv[i].tenphong){
					phong[i].songuoihientai++;
				}
			}
		}else if(chon == 5) {
			string tp;
			cout << "Nhap ma phong:";
			cin >> tp;
			for(int i=0;i<n;i++){
				if(tp	== phong[i].tenphong){
					taohoadon(hd,phong[i]);
					dem++;
				}
			}
		}
		else if (chon == 6) {
			for(int i=0;i<dem;i++){
				xuathd(hd[i]);
			}
		}
		else if (chon == 0) {
			break;
		}
		else
			cout << "Nhap sai, vui long nhap lai\n";
	} while (chon != 0);
	cout << "end";
	return 0;
}

//Functions
SinhVien timSinhVien(const SinhVien* sv, string masv, const int& m) {
	for (int i = 0; i < m; i++) {
		if (sv[i].mssv == masv) {
			return sv[i];
		}
	}
	return SinhVien();
}

bool xacminhemail(const string& email) {
	const regex pattern(
		"(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	return regex_match(email, pattern);
}

bool xacminhtenphong(const string& tenphong, const Phong* phong, const int& n) {
	for (int i = 0; i < n; i++) {
		if (phong[i].tenphong == tenphong) {
			return true;
		}
	}
	return false;
}

void themSinhVien(SinhVien* sv, const Phong* phong, const int& n) {
	for (int i = 0; i < n; i++) {
		string tensv;
		string masv;
		bool gioitinh;
		string quequan;
		string email;
		string tenphong;
		do {
			cout << "Nhap ten sinh vien: ";
			cin.ignore();
			getline(cin, tensv);
			//cin >> tensv;
		} while (tensv == "");
		do {
			cout << "Nhap ma sinh vien: ";
			cin >> masv;
		} while (masv == "");
		do {
			cout << "Nhap gioi tinh:(nam, nu) ";
			string gt;
			cin >> gt;
			gioitinh = gt == "nam" ? true : false;
		} while (gioitinh != true && gioitinh != false);
		do {
			cout << "Nhap que quan: ";
			cin >> quequan;
		} while (quequan == "");
		do {
			cout << "Nhap email: ";
			cin >> email;
		} while (!xacminhemail(email));
		do {
			cout << "Nhap ten phong: ";
			cin >> tenphong;
		} while (!xacminhtenphong(tenphong, phong, n));

		sv[i].themsv(masv, tensv, gioitinh, quequan, email);
		sv[i].suasv(masv, tensv, gioitinh, quequan, email, tenphong);
		// sv[i].xuatsinhvien();
	}
}

void xuatDSphong(Phong* phong, int n) {
	cout << "\nTen Phong\tLoai Phong\tSo Nguoi Toi Da\tSo Nguoi Hien Tai\n";
	for (int i = 0; i < n; i++) {
		phong[i].xuathongtinphong();
	}
}

void themphong(Phong* phong, int& n) {
	string tenphong;
	string loaiphong;
	int songuoitoida;
	int songuoihientai;
	cout << "Nhap ten phong: ";
	cin >> tenphong;
	cout << "Nhap loai phong: ";
	cin >> loaiphong;
	do {
		cout << "Nhap so nguoi toi da: ";
		cin >> songuoitoida;
	} while (songuoitoida < 0);
	do {
		cout << "Nhap so nguoi hien tai: ";
		cin >> songuoihientai;
	} while (songuoihientai < 0 || songuoihientai > songuoitoida);
	for (int i = 0; i <= n; i++) {
		if (phong[i].tenphong == "0") {
			phong[i].themphong(tenphong, loaiphong, songuoitoida);
			phong[i].suaphong(tenphong, loaiphong, songuoitoida, songuoihientai);
			n++;
			cout << "Da them phong thanh cong\n";
			break;
		}
		if (i == n) {
			cout << "Khong the them phong\n";
		}
	}

}

void timVaSua(Phong* phong, int& n) {
	string tenphong;
	cout << "Nhap ten phong can sua: ";
	cin >> tenphong;
	for (int i = 0; i < n; i++) {
		if (phong[i].tenphong == tenphong) {
			suaphong(phong[i]);
		}
	}
}

void taophong(Phong* phong, int& n) {
	int chon;
	do {
		cout << "\nBan muon tao bao nhieu phong?";
		cin >> n;
		if (n < 0) {
			cout << "Nhap sai, vui long nhap lai\n";
		}
	} while (n < 0);
	
	for (int i = 0; i < n; i++) {
		string tenphong;
		string loaiphong;
		int songuoitoida;
		int songuoihientai;
		cout << "Nhap ten phong: ";
		cin >> tenphong;
		cout << "Nhap loai phong: ";
		cin >> loaiphong;
		do {
			cout << "Nhap so nguoi toi da: ";
			cin >> songuoitoida;
		} while (songuoitoida < 0);
		do {
			cout << "Nhap so nguoi hien tai: ";
			cin >> songuoihientai;
		} while (songuoihientai < 0 || songuoihientai > songuoitoida);
		phong[i].themphong(tenphong, loaiphong, songuoitoida);
		phong[i].suaphong(tenphong, loaiphong, songuoitoida, songuoihientai);
	}
}

void suaphong(Phong& phong) {
	int chon = 10;
	do {
		cout << "\nBan muon sua gi? \n";
		cout << "1. Sua ten phong\n";
		cout << "2. Sua loai phong\n";
		cout << "3. Sua so nguoi toi da\n";
		cout << "4. Sua so nguoi hien tai\n";
		cout << "0. Thoat\n";
		cin >> chon;
		if (chon == 1) {
			string tenphong;
			cout << "Nhap ten phong: ";
			cin >> tenphong;
			phong.suaphong(tenphong, phong.loaiphong, phong.songuoitoida, phong.songuoihientai);
			cout << "Da sua ten phong thanh cong\n";
			cout << "\nTen Phong\tLoai Phong\tSo Nguoi Toi Da\tSo Nguoi Hien Tai\n";
			phong.xuathongtinphong();
		}
		else if (chon == 2) {
			string loaiphong;
			cout << "\nNhap loai phong: ";
			cin >> loaiphong;
			phong.suaphong(phong.tenphong, loaiphong, phong.songuoitoida, phong.songuoihientai);
			cout << "Da sua ten phong thanh cong\n";
			phong.xuathongtinphong();
		}
		else if (chon == 3) {
			int songuoitoida;
			do {
				cout << "\nNhap so nguoi toi da: ";
				cin >> songuoitoida;
			} while (songuoitoida < phong.songuoihientai);
			phong.suaphong(phong.tenphong, phong.loaiphong, songuoitoida, phong.songuoihientai);
			cout << "Da sua ten phong thanh cong\n";
			phong.xuathongtinphong();
		}
		else if (chon == 4) {
			int songuoihientai;
			do {
				cout << "\nnNhap so nguoi hien tai: ";
				cin >> songuoihientai;
			} while (songuoihientai > phong.songuoitoida);
			phong.suaphong(phong.tenphong, phong.loaiphong, phong.songuoitoida, songuoihientai);
			cout << "Da sua ten phong thanh cong\n";
			phong.xuathongtinphong();
		}
		else if (chon == 0) {
			break;
		}
		else
			cout << "Nhap sai, vui long nhap lai\n";
	} while (chon != 0);
}

void XoaSinhvien(SinhVien& sv) {
	sv.xoasv();
}

void taohoadon(HoaDon* hd,Phong& phong){
	string p;
	cout<<"Nhap vao ten phong them hoa don: ";
	cin>>p;
	if(p==phong.tenphong){
		cout<<"thang: ";
		cin>>hd->thang;
		cout<<"\nnam: ";
		cin>>hd->nam;
		hd->mahoadon=phong.tenphong+phong.loaiphong;
		cout<<"\nSo dien dau cua phong: ";
		cin>>hd->soDiendau;
		cout<<"\nSo nuoc dau cua phong: ";
		cin>>hd->soNuocdau;
		cout<<"\nSo dien cuoi cua phong: ";
		cin>>hd->soDiencuoi;
		cout<<"\nSo nuoc cuoi cua phong: ";
		cin>>hd->soNuoccuoi;
		int d;
		cout<<"tien dien cua phong: ";
		cin>>d;
		int n;
		cout<<"tien nuoc cua phong: ";
		cin>>n;
		hd->tinhtong(d,n);
		hd->xuathoadon();
	}else{
		cout<<"sai phong!";
	}
}

void xuathd(HoaDon& hd){
	if(hd.mahoadon=="0"){
		cout<<"khong co hoa don!";
	}else{
	hd.xuathoadon();
}
}