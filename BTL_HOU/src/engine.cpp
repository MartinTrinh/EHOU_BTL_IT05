#include "engine.h"
#include <stdexcept>
#include <limits>

Engine::Engine(){
    LOG("App START\n");
}

Engine::~Engine(){
    LOG("-----> App EXIT\n");
}

void Engine::start_application(){
    LOG("");
    while(true){
        cout << "=========MH1=========\n";
        cout << "1: Nhap\n";
        cout << "2: Xuat\n";
        cout << "3: Chinh Sua\n";
        cout << "4: Exit\n";
        cout << "Moi nhap lua chon: ";
        int chose;
        cin >> chose;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        int is_return = false;
        switch(chose){
        case MENU_1::NHAP:{
            while(true){
                //PAUSE;
                CLEAR_SCREEN;
                cout << "=========MH2=========\n";
                cout << "1: DIEN THOAI\n";
                cout << "2: HOA DON\n";
                cout << "3: BACK\n";
                cout << "Moi nhap lua chon: ";
                cin >> chose;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                switch(chose){
                case MENU_2::NHAP_DT:{
                    // man hinh nhap tt dt
                    //PAUSE;
                    CLEAR_SCREEN;
                    ctl.nhapDienThoai();
                    break;
                }
                case MENU_2::NHAP_HOADON:{
                    // man hinh nhap thong tin hoa don
                    //PAUSE;
                    CLEAR_SCREEN;
                    ctl.nhapHoaDon();
                    break;
                }
                case MENU_2::MN2_RETURN_HOME:{
                    is_return = true;
                    break;
                }
                default:
                    break;
                }

                if(is_return){
                    // back to HOME
                    is_return = false; 
                    break;
                }
            }
            break;
        }
        case MENU_1::XUAT:{
            while(true){
                //PAUSE;
                CLEAR_SCREEN;
                cout << "=========MH3=========\n";
                cout << "1: XUAT DIEN THOAI\n";
                cout << "2: XUAT HOA DON\n";
                cout << "3: BACK\n";
                cout << "Moi nhap lua chon: ";
                cin >> chose;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                switch(chose){
                case MENU_3::XUAT_DS_DT:{
                    while(true){
                        // MENU_3_A
                        //PAUSE;
                        CLEAR_SCREEN;
                        cout << "=========MH3=========\n";
                        cout << "1: TIM KIEM\n";
                        cout << "2: XUAT HET DS\n";
                        cout << "3: BACK\n";
                        cout << "Moi nhap lua chon: ";
                        cin >> chose;
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        switch(chose){
                        case MENU_3_A::MENU_3_A_TIMKIEM:{
                            // MENU_3_A1
                            //PAUSE;
                            CLEAR_SCREEN;
                            cout << "=========MH3=========\n";
                            cout << "1: Tim kiem theo ten dien thoai\n";
                            cout << "2: Tim kiem theo hang san xuat\n";
                            cout << "Moi nhap lua chon: ";
                            cin >> chose;
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            switch (chose)
                            {
                            case MENU_3_A1::MENU_3_A1_THEO_TEN_DT:{
                                CLEAR_SCREEN;
                                cout << "=========MH3=========\n";
                                cout << "Nhap ten dien thoai: ";
                                string userInput;
                                cin >> userInput;
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                ctl.xuatTimKiemDT(MENU_3_A1::MENU_3_A1_THEO_TEN_DT,userInput);
                                break;
                            }case MENU_3_A1:: MENU_3_A1_THEO_HANGSX:{
                                CLEAR_SCREEN;
                                cout << "=========MH3=========\n";
                                cout << "Nhap ten hang san xuat dien thoai: ";
                                string userInput;
                                cin >> userInput;
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                ctl.xuatTimKiemDT(MENU_3_A1::MENU_3_A1_THEO_HANGSX,userInput);
                                break;
                            }
                            default:
                                break;
                            }
                            std::cout << "Press Enter to continue...";
                            while (std::cin.get() != '\n');

                            break;
                        }
                        case MENU_3_A::MENU_3_A_XUAT_HET_DS:{
                            // MENU_3_A1_SX
                            //PAUSE;
                            CLEAR_SCREEN;
                            cout << "=========MH3=========\n";
                            cout << "1: Sap xep tang dan theo ten dien thoai\n";
                            cout << "2: Sap xep tang dan theo don gia\n";
                            cout << "Moi nhap lua chon: ";
                            cin >> chose;
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            switch(chose){
                            case MENU_3_A1_SX::SX_THEO_TEN_DT:{
                                // show theo ten dt
                                CLEAR_SCREEN;
                                ctl.xuatDanhSachDT(MENU_3_A1_SX::SX_THEO_TEN_DT);
                                break;
                            }
                            case MENU_3_A1_SX::SX_THEO_DON_GIA:{
                                // show don gia
                                CLEAR_SCREEN;
                                ctl.xuatDanhSachDT(MENU_3_A1_SX::SX_THEO_DON_GIA);
                                break;
                            }
                            default:
                                break;
                            }

                            std::cout << "Press Enter to continue...";
                            while (std::cin.get() != '\n');
                            break;
                        }
                        case MENU_3_A::MENU_3_A_BACk:{
                            is_return = true;
                            break;
                        }
                        default:
                            break;
                        }

                        if(is_return){
                        // back to previos
                            is_return = false; 
                            break;
                        }
                    }
                    
                    break;
                }
                case MENU_3::XUAT_DS_HD:{
                    while(true){
                    // MENU_3_A
                        //PAUSE;
                        CLEAR_SCREEN;
                        cout << "=========MH3=========\n";
                        cout << "1: TIM KIEM\n";
                        cout << "2: XUAT HET DS\n";
                        cout << "3: BACK\n";
                        cout << "Moi nhap lua chon: ";
                        cin >> chose;
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        switch(chose){
                        case MENU_3_A::MENU_3_A_TIMKIEM:{
                            //MENU_3_A4
                            //PAUSE;
                            CLEAR_SCREEN;
                            cout << "=========MH3=========\n";
                            cout << "1: Tim kiem theo ma hoa don\n";
                            cout << "2: Tim kiem theo ngay lap hoa don\n";
                            cout << "Moi nhap lua chon: ";
                            cin >> chose;
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            switch (chose)
                            {
                            case MENU_3_A4::MENU_3_A4_THEO_MaHD:{
                                CLEAR_SCREEN;
                                cout << "=========MH3=========\n";
                                cout << "Nhap ma hoa don: ";
                                string userInput;
                                cin >> userInput;
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                ctl.xuatTimeKiemHD(MENU_3_A4::MENU_3_A4_THEO_MaHD,userInput);
                                break;
                            }case MENU_3_A4::MENU_3_A4_THEO_NGAY_LAP:{
                                CLEAR_SCREEN;
                                cout << "=========MH3=========\n";
                                cout << "Nhap ngay lap[yyyy/mm/dd]: ";
                                string userInput;
                                cin >> userInput;
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                ctl.xuatTimeKiemHD(MENU_3_A4::MENU_3_A4_THEO_NGAY_LAP,userInput);
                                break;
                            }
                            default:
                                break;
                            }
                            std::cout << "Press Enter to continue...";
                            while (std::cin.get() != '\n');

                            break;
                            break;
                        }
                        case MENU_3_A::MENU_3_A_XUAT_HET_DS:{
                            //MENU 3_A4_SX
                            //PAUSE;
                            CLEAR_SCREEN;
                            cout << "=========MH3=========\n";
                            cout << "1: Sap xep tang dan theo ten ma hoa don \n";
                            cout << "2: Sap xep tang dan theo ngay lap\n";
                            cout << "Moi nhap lua chon: ";
                            cin >> chose;
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            switch(chose){
                            case MENU_3_A4_SX::SX_THEO_MaHD:{
                                // show theo ma hd
                                CLEAR_SCREEN;
                                ctl.xuatDanhSachHD(MENU_3_A4_SX::SX_THEO_MaHD);
                                break;
                            }
                            case MENU_3_A4_SX::SX_THEO_NGAY_LAP:{
                                // theo ngay lap 
                                CLEAR_SCREEN;
                                ctl.xuatDanhSachHD(MENU_3_A4_SX::SX_THEO_NGAY_LAP);
                                break;
                            }
                            default:
                                break;
                            }

                            std::cout << "Press Enter to continue...";
                            while (std::cin.get() != '\n');
                            break;
                        }
                        case MENU_3_A::MENU_3_A_BACk:{
                            is_return = true;
                            break;
                        }
                        default:
                            break;
                        }

                        if(is_return){
                        // back to previos
                            is_return = false; 
                            break;
                        }
                    }
                    break;
                }
                case MENU_3::MN3_RETURN_HOME:{
                    is_return = true;
                    break;
                }
                default:
                    break;
                }

                if(is_return){
                    // back to HOME
                    is_return = false; 
                    break;
                }
            }
            break;
        }
        case MENU_1::CHINH_SUA:{
            //PAUSE;
            while(true){
                CLEAR_SCREEN;
                cout << "=========MH4=========\n";
                cout << "1: Sua thong tin dien thoai\n";
                cout << "2: Sua thong tin hoa don\n";
                cout << "3: Xoa thong tin dien thoai\n";
                cout << "4: Xoa thong tin hoa don\n";
                cout << "5: Back\n";
                cout << "Moi nhap lua chon: ";
                cin >> chose;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                switch (chose)
                {
                case MENU_4::SUA_DT:{
                    CLEAR_SCREEN;
                    ctl.suaDienThoai();
                    break;
                }case MENU_4::SUA_HD:{
                    CLEAR_SCREEN;
                    ctl.suaHoaDon();
                    break;
                }case MENU_4::XOA_TT_DT:{
                    CLEAR_SCREEN;
                    ctl.xoaDT();
                    break;
                }case MENU_4::XOA_TT_HD:{
                    CLEAR_SCREEN;
                    ctl.xoaHoaDon();
                    break;
                }case MENU_4::MENU_4_RETURN:{
                    is_return = true;
                    break;
                } default:
                    break;
                }

                if(is_return){
                    // back to HOME
                    is_return = false; 
                    break;
                }
            }

            break;
        }
        case MENU_1::EXIT:{
            exit(NULL);
            break;
        }
        default:
            break;
        }  
        //PAUSE;
        CLEAR_SCREEN;
    }
}