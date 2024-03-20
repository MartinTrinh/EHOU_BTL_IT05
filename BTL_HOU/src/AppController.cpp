#include "AppController.h"
#include <stdexcept>
#include <limits>
#include <fstream>
#include <jsoncpp/json/json.h>


Controller::Controller()
{
    // init data
    readDataFromFile();
}

Controller::~Controller()
{
}

void Controller::nhapDienThoai()
{
    char chose;
    do{
        CLEAR_SCREEN;
        string madt;
        string tendt;
        string mausac;
        string hangsx;
        string ngaysx;
        int dongia;
        int soLuong;
        cout << "Nhap ma dien thoai: "; 
        cin >> madt;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // check dien thoai da ton tai chua
        // neu da ton tai ngung nhap, thoat ra man hinh chinh
        if(listDienThoai.checkNodeExist(madt)){
            cout << "Dien thoai da ton tai!!!! \nMoi ban ve muc Chinh Sua\n";
            PAUSE;
            return;
        }
        cout << "Nhap ten dien thoai: ";
        cin >> tendt;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Nhap mau sac: ";
        cin >> mausac;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Nhap Hang SX: ";
        cin >> hangsx;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Nhap ngay SX [yyyy/mm/dd]: ";
        cin >> ngaysx;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Nhap don gia (usd): ";
        cin >> dongia;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Nhap so luong: ";
        cin >> soLuong;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        DienThoai dt (madt,tendt,mausac,hangsx,ngaysx,dongia, soLuong);
        listDienThoai.insertNode(dt);
        cout << "Ban co muon nhap dien thoai tiep theo [y/n]: ";
        cin >> chose;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while (chose == 'y' || chose == 'Y');

    listDienThoai.writeDataToFile();
}

void Controller::nhapHoaDon()
{   char chose;
    do {
        CLEAR_SCREEN;
        string mahd;
        string ngaylap;
        HoaDon hd;
        int counter = 1;
        cout << "Nhap ma hoa don:";
        cin >> mahd;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // check ma hoa don da ton tai chua
        if(listHoaDon.checkNodeExist(mahd)){
            cout << "Hoa don da ton tai!!!! \nMoi ban ve muc Chinh Sua\n";
            PAUSE;
            return;
        }
        cout << "Nhap ngay lap hoa don:[yyyy/mm/dd]: ";
        cin >> ngaylap;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        hd.setMaHD(mahd);
        hd.setNgayLapHD(ngaylap);
        do{
            //if(counter > 1){
                CLEAR_SCREEN;
                cout << "Nhap ma hoa don:" << mahd << '\n';
                cout << "Nhap ngay lap hoa don:[yyyy/mm/dd]: " << ngaylap <<  '\n';
            //}
            tt_dienthoai dt;
            cout << "Nhap ma dt " << counter << ":";
            cin >> dt.maDt;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if(!listDienThoai.checkNodeExist(dt.maDt)){
                cout << "Dien thoai khong ton tai trong kho moi nhap lai!!!!\n";
                chose = 'y';
                PAUSE;
                continue;
            }
            cout << "Nhap so luong:" ;
            cin >> dt.sl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if(hd.checkMaDT(dt.maDt)){
                hd.updateDt(dt);
            }else{
                hd.addDienThoai(dt);
                counter++;
            }
            cout << "Ban co muon nhap them dt[y/n]:";
            cin >> chose;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }while(chose == 'y' || chose == 'Y');

        listHoaDon.insertNode(hd);
        cout << "Ban co muon nhap hoa don tiep theo[y/n]: ";
        cin >> chose;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while (chose == 'y' || chose == 'Y');

    listHoaDon.writeDataToFile();
}

void Controller::suaDienThoai()
{
    char chose;
    do{
        CLEAR_SCREEN;
        string madt;
        string tendt;
        string mausac;
        string hangsx;
        string ngaysx;
        int dongia;
        int soLuong;
        cout << "Nhap ma dien thoai: "; 
        cin >> madt;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // check dien thoai da ton tai chua
        // neu da ton tai ngung nhap, thoat ra man hinh chinh
        if(!listDienThoai.checkNodeExist(madt)){
            cout << "Dien thoai khong ton tai!!!!\n";
            chose = 'y';
            PAUSE;
            continue;
        }
        cout << "Nhap ten dien thoai: ";
        cin >> tendt;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Nhap mau sac: ";
        cin >> mausac;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Nhap Hang SX: ";
        cin >> hangsx;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Nhap ngay SX [yyyy/mm/dd]: ";
        cin >> ngaysx;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Nhap don gia (usd): ";
        cin >> dongia;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Nhap so luong: ";
        cin >> soLuong;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        DienThoai dt (madt,tendt,mausac,hangsx,ngaysx,dongia, soLuong);
        listDienThoai.updateNode(dt);
        cout << "Ban co muon nhap dien thoai tiep theo [y/n]: ";
        cin >> chose;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while (chose == 'y' || chose == 'Y');

    listDienThoai.writeDataToFile();
}

void Controller::suaHoaDon()
{
char chose;
    do {
        CLEAR_SCREEN;
        string mahd;
        string ngaylap;
        HoaDon hd;
        int counter = 1;
        cout << "Nhap ma hoa don:";
        cin >> mahd;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // check ma hoa don da ton tai chua
        if(!listHoaDon.checkNodeExist(mahd)){
            cout << "Hoa don khong ton tai!!!!\n";
            chose = 'y';
            PAUSE;
            continue;
        }
        cout << "Nhap ngay lap hoa don:[yyyy/mm/dd]: ";
        cin >> ngaylap;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        hd.setMaHD(mahd);
        hd.setNgayLapHD(ngaylap);
        do{
            CLEAR_SCREEN;
            cout << "Nhap ma hoa don:" << mahd << '\n';
            cout << "Nhap ngay lap hoa don:[yyyy/mm/dd]: " << ngaylap <<  '\n';
            
            tt_dienthoai dt;
            cout << "Nhap ma dt " << counter << ":";
            cin >> dt.maDt;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if(!listDienThoai.checkNodeExist(dt.maDt)){
                cout << "Dien thoai khong ton tai trong kho moi nhap lai!!!!\n";
                chose = 'y';
                PAUSE;
                continue;
            }
            cout << "Nhap so luong:" ;
            cin >> dt.sl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if(hd.checkMaDT(dt.maDt)){
                hd.updateDt(dt);
            }else{
                hd.addDienThoai(dt);
                counter++;
            }
            cout << "Ban co muon nhap them dt[y/n]:";
            cin >> chose;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }while(chose == 'y' || chose == 'Y');

        listHoaDon.updateNode(hd);
        cout << "Ban co muon nhap hoa don tiep theo[y/n]: ";
        cin >> chose;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while (chose == 'y' || chose == 'Y');

    listHoaDon.writeDataToFile();
}

void Controller::xoaDT()
{
    char chose;
    do{
        CLEAR_SCREEN;
        string madt;
        cout << "Nhap ma dien thoai muon xoa: ";
        cin >> madt;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.clear();
        if(!listDienThoai.checkNodeExist(madt)){
            cout << "Dien thoai khong ton tai!!!!\n";
            chose = 'y';
            PAUSE;
            continue;
        }
        cout << "CHECK: " << madt<< '\n';
        PAUSE;
        listDienThoai.deleteNode(madt);
        cout << "Da xoa dien thoai trong database!!!\n";
        cout << "Ban co muon xoa dien thoai tiep theo [y/n]: ";
        cin >> chose;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while (chose == 'y' || chose == 'Y');

    listDienThoai.writeDataToFile();
}

void Controller::xoaHoaDon()
{
    char chose;
    do{
        CLEAR_SCREEN;
        string mahd;
        cout << "Nhap ma hoa don muon xoa: ";
        cin >> mahd;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(!listHoaDon.checkNodeExist(mahd)){
            cout << "Hoa Don khong ton tai!!!!\n";
            chose = 'y';
            PAUSE;
            continue;
        }
        listHoaDon.deleteNode(mahd);
        cout << "Da xoa hoa don trong database!!!\n";
        cout << "Ban co muon xoa hoa don tiep theo [y/n]: ";
        cin >> chose;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while (chose == 'y' || chose == 'Y');

    listHoaDon.writeDataToFile();
}

void Controller::xuatTimKiemDT(int type, string data)
{
    listDienThoai.findNode(type, data);
}

void Controller::xuatTimeKiemHD(int type, string data)
{
    listHoaDon.findNode(type, data);
}

void Controller::xuatDanhSachDT(int type)
{
    listDienThoai.showData(type);
}

void Controller::xuatDanhSachHD(int type)
{
    listHoaDon.showData(type);
}

void Controller::readDataFromFile()
{
    Json::Reader reader;
    Json::Value dataDT;
    Json::Value dataHD;
    ifstream inputDt(DT_PATH);
    if(!inputDt){
        cout << "open file " << DT_PATH << " failed!!!";
        return;
    }
    
    reader.parse(inputDt, dataDT);
    Json::Value &dienthoai = dataDT["dienthoai"];
    if(!dienthoai.isArray()){
        cout << "data dienthoai object invalid!!!'\n";
        return;
    }

    for(int i = 0; i < dienthoai.size(); i++){
        DienThoai dt;
        dt.setMadt(dienthoai[i]["madt"].asString());
        dt.setTenDt(dienthoai[i]["tendt"].asString());
        dt.setMausac(dienthoai[i]["mausac"].asString());
        dt.setHangSX(dienthoai[i]["hangsx"].asString());
        dt.setNgaySx(dienthoai[i]["ngaysx"].asString());
        dt.setDongia(dienthoai[i]["dongia"].asInt());
        dt.setSoLuong(dienthoai[i]["soluong"].asInt());
        
        listDienThoai.insertNode(dt);
    }

    inputDt.close();

    ifstream inputHD(HD_PATH);
    if(!inputHD){
        cout << "open file " << HD_PATH << " failed!!!";
        return;
    }

    reader.parse(inputHD, dataHD);

    Json::Value &hoadon = dataHD["hoadon"];
    if(!hoadon.isArray()){
        cout << "data hoadon object invalid!!!'\n";
        return;
    }

    for(int i = 0; i < hoadon.size(); i++){
        HoaDon hd;
        hd.setMaHD(hoadon[i]["mahd"].asString());
        hd.setNgayLapHD(hoadon[i]["ngaylap"].asString());
        Json::Value &vecdt = hoadon[i]["listDT"];
        for(int j = 0; j < vecdt.size();j++){
            tt_dienthoai dt;
            dt.maDt = vecdt[j]["madt"].asString();
            dt.sl = vecdt[j]["soluong"].asInt();
            hd.addDienThoai(dt);
        }
        listHoaDon.insertNode(hd);
    }

    inputHD.close();
}
