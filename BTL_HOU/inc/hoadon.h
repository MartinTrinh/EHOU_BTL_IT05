#ifndef __HOADON
#define __HOADON
#include <iostream>
#include <vector>
#include "common.h"

using namespace std;

class HoaDon{
public:
    HoaDon();
    ~HoaDon();

    void xuat();

    void setMaHD(string maHD);
    string getMaHD() const;

    void addDienThoai(tt_dienthoai dt);

    void setNgayLapHD(string ngayLapHD);
    string getNgayLapHD() const;

    bool checkMaDT(string madt);
    void updateDt(tt_dienthoai dt);

    int geListDtSize() const;

    std::vector<tt_dienthoai> getListDT() const;
    
private:
    string m_maHD;
    string m_ngayLapHD;
    std::vector<tt_dienthoai> listDT;     
};


#endif