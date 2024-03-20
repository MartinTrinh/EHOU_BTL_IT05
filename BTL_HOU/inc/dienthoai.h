#ifndef __DIENTHOAI
#define __DIENTHOAI
#include <iostream>

using namespace std;

class DienThoai{
public:
    DienThoai(string madt, string tendt, string mausac, string hangsx, string ngaysx, int donGia, int soLuong);
    DienThoai();
    ~DienThoai();
    void xuat();

    void setMadt(string madt);
    string getMadt() const;

    void setTenDt(string tendt);
    string getTenDt() const;

    void setMausac(string mausac);
    string getMausac() const;

    void setHangSX(string hangsx);
    string getHangsx() const;

    void setNgaySx(string ngaysx);
    string getNgaySx() const;

    void setDongia(int dongia);
    int getDongia() const;

    void setSoLuong(int soLuong);
    int getSoluong() const;
    
private:
    string m_madt;
    string m_tendt;
    string m_mausac;
    string m_hangsx;
    string m_ngaysx;
    int m_dongia;
    int m_soLuong;
};

#endif