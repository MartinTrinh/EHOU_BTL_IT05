#include "dienthoai.h"
#include <stdexcept>
#include <limits>

DienThoai::DienThoai(string madt, string tendt, string mausac, string hangsx, string ngaysx, int donGia, int soLuong)
{
    m_madt = madt;
    m_tendt = tendt;
    m_mausac = mausac;
    m_hangsx = hangsx;
    m_ngaysx = ngaysx;
    m_dongia = donGia;
    m_soLuong = soLuong;
}

DienThoai::DienThoai()
{
}

DienThoai::~DienThoai()
{

}

void DienThoai::xuat()
{
    cout << "====================\n"<<"Ma dt:" << m_madt << "\nTen dtL:" << m_tendt << "\nmau sac:" 
    << m_mausac << "\nHang sx:" << m_hangsx << "\nNgaysx:" << m_ngaysx 
    << "\nDon gia:" << m_dongia << "\nSo luong:" << m_soLuong  << '\n';
}

void DienThoai::setMadt(string madt)
{
    m_madt = madt;
}

string DienThoai::getMadt() const
{
    return m_madt;
}

void DienThoai::setTenDt(string tendt)
{
    m_tendt = tendt;
}

string DienThoai::getTenDt() const
{
    return m_tendt;
}

void DienThoai::setMausac(string mausac)
{
    m_mausac = mausac;
}

string DienThoai::getMausac() const
{
    return m_mausac;
}

void DienThoai::setHangSX(string hangsx)
{
    m_hangsx = hangsx;
}

string DienThoai::getHangsx() const
{
    return m_hangsx;
}

void DienThoai::setNgaySx(string ngaysx)
{
    m_ngaysx = ngaysx;
}

string DienThoai::getNgaySx() const
{
    return m_ngaysx;
}

void DienThoai::setDongia(int dongia)
{
    m_dongia = dongia;
}

int DienThoai::getDongia() const
{
    return m_dongia;
}

void DienThoai::setSoLuong(int soLuong)
{
    m_soLuong = soLuong;
}

int DienThoai::getSoluong() const
{
    return m_soLuong;
}