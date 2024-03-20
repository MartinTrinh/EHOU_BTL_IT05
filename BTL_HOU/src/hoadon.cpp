#include "hoadon.h"
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <string.h>

HoaDon::HoaDon()
{
    m_maHD = "";
    m_ngayLapHD = "";
}

HoaDon::~HoaDon()
{

}


void HoaDon::xuat()
{   cout << "====================\n";
    cout << "Ma hoa don: " << m_maHD <<'\n';
    cout << "Ngay lap hoa don: " << m_ngayLapHD << '\n'; 
    for(int i = 0; i < listDT.size(); i++){
        cout << "Dien thoai thu: " << i + 1 << '\n';
        cout << "Ma dt:" << listDT[i].maDt << '\n';
        cout << "SoLuong: " << listDT[i].sl << '\n';
    }
}

void HoaDon::setMaHD(string maHD)
{
    m_maHD =maHD;
}

string HoaDon::getMaHD() const
{
    return m_maHD;
}

void HoaDon::addDienThoai(tt_dienthoai dt)
{
    listDT.push_back(dt);
}

void HoaDon::setNgayLapHD(string ngayLapHD)
{
    m_ngayLapHD = ngayLapHD;
}

string HoaDon::getNgayLapHD() const
{
    return m_ngayLapHD;
}

bool HoaDon::checkMaDT(string madt)
{
    auto it = std::find(listDT.begin(), listDT.end(), madt);
    for(int  i = 0; i < listDT.size(); i++){
        if(strcmp(listDT[i].maDt.c_str(),madt.c_str()) == 0){
            return true;
        }
    }
    return false;
}

void HoaDon::updateDt(tt_dienthoai dt)
{
    for(int  i = 0; i < listDT.size(); i++){
        if(strcmp(listDT[i].maDt.c_str(),dt.maDt.c_str()) == 0){
            listDT[i].sl += dt.sl;
            break;
        }
    }
}

int HoaDon::geListDtSize() const
{
    return listDT.size();
}

std::vector<tt_dienthoai> HoaDon::getListDT() const
{
    return listDT;
}
