#ifndef COMMON
#define COMMON

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sstream>
#include <string>

#if defined(_WIN64) || defined(_WIN32)
#define CLEAR_SCREEN system("cls")
#define PAUSE system("pause")
#elif __linux__
#define CLEAR_SCREEN system("clear")
#define PAUSE  system("sleep 1")
#endif


#define DT_PATH "dienthoai.json"
#define HD_PATH "hoadon.json"

//#define DEBUG
#ifdef DEBUG
#define LOG(x) std::cout << __func__ << __LINE__ << " " << x 
#else
#define LOG(x)  while(0){}
#endif 

struct tt_dienthoai
{
    std::string maDt;
    int sl;
    bool operator==(const std::string madt) const {
        return this->maDt == maDt;
    }
};

// menu 1
enum MENU_1{
    NHAP = 1,
    XUAT,
    CHINH_SUA,
    EXIT
};


// menu 2
enum MENU_2{
    NHAP_DT = 1,
    NHAP_HOADON,
    MN2_RETURN_HOME
};


// menu 3
enum MENU_3{
    XUAT_DS_DT = 1,
    XUAT_DS_HD,
    MN3_RETURN_HOME
};

// menu 3_A
enum MENU_3_A{
    MENU_3_A_TIMKIEM = 1,
    MENU_3_A_XUAT_HET_DS,
    MENU_3_A_BACk
};

// menu 3_A1
enum MENU_3_A1{
    MENU_3_A1_THEO_TEN_DT = 1,
    MENU_3_A1_THEO_HANGSX,
    MENU_3_A1_BACK
};

//MENU_3_A1_SX
enum MENU_3_A1_SX{
    SX_THEO_TEN_DT = 1,
    SX_THEO_DON_GIA
};

// menu 3_A4
enum MENU_3_A4{
    MENU_3_A4_THEO_MaHD = 1,
    MENU_3_A4_THEO_NGAY_LAP,
    MENU_3_A4_BACK
};

// menu 3_A4_SX
enum MENU_3_A4_SX{
    SX_THEO_MaHD = 1,
    SX_THEO_NGAY_LAP
};

// menu 4
enum MENU_4{
    SUA_DT = 1,
    SUA_HD,
    XOA_TT_DT,
    XOA_TT_HD,
    MENU_4_RETURN
};


#endif
