#ifndef __APPCONTROLLER
#define __APPCONTROLLER
#include <iostream>
#include "common.h"
#include "container.h"
#include "dienthoai.h"
#include "hoadon.h"

using namespace std;

class Controller{
public:
    Controller();
    ~Controller();

    void nhapDienThoai(); 
    void nhapHoaDon();

    void suaDienThoai();
    void suaHoaDon();

    void xoaDT();
    void xoaHoaDon();

    void xuatTimKiemDT(int type, string data);
    void xuatTimeKiemHD(int type, string data);

    void xuatDanhSachDT(int type);
    void xuatDanhSachHD(int type);

    void readDataFromFile();

private:
    // creat 2 linker list
    LinkedlistDT listDienThoai;
    LinkedlistHD listHoaDon;
};

#endif