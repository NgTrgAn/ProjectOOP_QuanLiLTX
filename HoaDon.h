#pragma once
#include "Phong.h"
class HoaDon : public Phong
{
public:
    string mahoadon;
    int thang;
    int nam;
    int soDiendau;
    int soDiencuoi;
    int soNuocdau;
    int soNuoccuoi;
    int tongtien;
    HoaDon(){};
    ~HoaDon(){};
    void themhoadon(string mahoadon, int thang, int nam, int soDiendau, int soDiencuoi, int soNuocdau, int soNuoccuoi);
    void xoahoadon();
    void suahoadon(string mahoadon = "0", int thang = 0, int nam = 0, int soDiendau = 0, int soDiencuoi = 0, int soNuocdau = 0, int soNuoccuoi = 0);
    void xuathoadon();
    void tinhtong(int d, int n);
};
void HoaDon::tinhtong(int d, int n){
    this->tongtien = (this->soDiencuoi - this->soDiendau)*d + (this->soNuoccuoi - this->soNuocdau)*n;
}
void HoaDon::themhoadon(string mahoadon,int thang, int nam, int soDiendau, int soDiencuoi, int soNuocdau, int soNuoccuoi)
{
    this->mahoadon = mahoadon;
    this->thang = thang;
    this->nam = nam;
    this->soDiendau = soDiendau;
    this->soDiencuoi = soDiencuoi;
    this->soNuocdau = soNuocdau;
    this->soNuoccuoi = soNuoccuoi;
}
void HoaDon::suahoadon(string mahoadon, int thang, int nam, int soDiendau, int soDiencuoi, int soNuocdau, int soNuoccuoi){
    if
        (mahoadon != "0")
    {
        this->mahoadon = mahoadon;
    }
    if
        (thang != 0)
    {
        this->thang = thang;
    }
    if
        (nam != 0)
    {
        this->nam = nam;
    }
    if
        (soDiendau != 0)
    {
        this->soDiendau = soDiendau;
    }
}
void HoaDon::xoahoadon(){
    this->mahoadon = "0";
    this->thang = 0;
    this->nam = 0;
    this->soDiendau = 0;
    this->soDiencuoi = 0;
    this->soNuocdau = 0;
    this->soNuoccuoi = 0;
}
void HoaDon::xuathoadon(){
    cout << this->mahoadon << " " << this->thang << " " << this->nam << " " << this->soDiendau << " " << this->soDiencuoi << " " << this->soNuocdau << " " << this->soNuoccuoi << " " << this->tongtien << endl;
}
