#include "container.h"
#include "common.h" 
#include <cstring>
#include <fstream>
#include <jsoncpp/json/json.h>
#include <stdio.h>
#include <memory>

int compareDates(const std::string& date1, const std::string& date2) {
    std::istringstream ss1(date1), ss2(date2);
    int year1, month1, day1, year2, month2, day2;
    char slash; // to consume the slash character '/'
    
    ss1 >> year1 >> slash >> month1 >> slash >> day1;
    ss2 >> year2 >> slash >> month2 >> slash >> day2;
    
    if (year1 != year2)
        return year1 - year2;
    if (month1 != month2)
        return month1 - month2;
    return day1 - day2;
}

LinkedlistDT::LinkedlistDT()
{ 
    head = NULL; 
    m_counter = 0;
} 

LinkedlistDT::~LinkedlistDT(){
    while (head != NULL)
    {            
        Node<DienThoai> * tmp = head;
        head = head->next;
        // delete node 
        delete tmp;
        m_counter = 0;
    }
}

void LinkedlistDT::deleteNode(string madt) 
{ 
    // mac dinh cac nu trong list la duy nhat
    Node<DienThoai> *current = head, *temp = NULL; 
    int ListLen = 0; 
  
    if (head == NULL) { 
        cout << "List empty." << endl; 
        return; 
    } 

    // Nếu nút cần xóa là nút đầu tiên
    if (strcmp(madt.c_str(),head->data.getMadt().c_str()) == 0) {
        temp = head;
        head = head->next;
        delete temp;
        m_counter -= 1;
        return;
    }

    while (current != NULL && (strcmp(current->data.getMadt().c_str(),madt.c_str()) == 0)) {
        temp = current;
        current = current->next;
    }

    // Nếu nút cần xóa không phải nút đầu tiên
    if (temp != NULL) {
        delete temp;
        m_counter -= 1;
    }
}

bool LinkedlistDT::checkNodeExist(string id)
{
    Node<DienThoai>* current = head;
    while (current != NULL) {
        if(strcmp(current->data.getMadt().c_str(),id.c_str()) == 0){
            return true;
        }
        current = current->next;
    }

    return false;
}


void LinkedlistDT::findNode(int type,string data)
{
    Node<DienThoai>* current = head;
    bool isExist = false;
    switch (type)
    {
    case MENU_3_A1::MENU_3_A1_THEO_TEN_DT:{
        while (current != NULL) {
            if(strcmp(current->data.getTenDt().c_str(),data.c_str()) == 0){
                isExist = true;
                current->data.xuat();
            }
            current = current->next;
        }

        if(!isExist){
            cout << "Dien thoai khong ton tai!!!\n";
        }
        break;
    }case MENU_3_A1::MENU_3_A1_THEO_HANGSX:{
        while (current != NULL) {
            if(strcmp(current->data.getHangsx().c_str(),data.c_str())){
                isExist = true;
                current->data.xuat();
            }
            current = current->next;
        }

        if(!isExist){
            cout << "Dien thoai khong ton tai!!!\n";
        }
        break;
    }default:
        break;
    }

}

void LinkedlistDT::showData(int type)
{
    Node<DienThoai>* current = head;
    // Check for empty list. 
    if (head == NULL) { 
        cout << "List empty" << endl; 
        return; 
    } 

    //increase by buble sort algorithm
    if(type == MENU_3_A1_SX::SX_THEO_TEN_DT){
    // Traverse the list. 
        while (current != NULL) { 
            Node<DienThoai> *pos = current->next;
            while (pos != NULL)
            {
                // using bubble soft algorithm
               if(strcmp(current->data.getTenDt().c_str(),pos->data.getTenDt().c_str()) > 0){
                    DienThoai tmpData = current->data;
                    current->data = pos->data;
                    pos->data = tmpData;
                }
                pos = pos->next;
            }
            current = current->next; 
        }
    }else if(type == MENU_3_A1_SX::SX_THEO_DON_GIA){
        // Traverse the list. 
        while (current != NULL) { 
            Node<DienThoai> *pos = current->next;
            while (pos != NULL)
            {
                // using bubble soft algorithm
               if(current->data.getDongia() > pos->data.getDongia()){
                    DienThoai tmpData = current->data;
                    current->data = pos->data;
                    pos->data = tmpData;
                }
                pos = pos->next;
            }
            current = current->next; 
        }
    }
    current = head;
    while (current != NULL) {
        current->data.xuat();
        current = current->next;
    }
}
int LinkedlistDT::getSize() const
{
    return m_counter;
}

void LinkedlistDT::writeDataToFile()
{
    ofstream output(DT_PATH,std::ios::trunc);
    if(!output){
        cout << "open file " << DT_PATH << " failed!!!";
        return;
    }

    Json::Value root;
    Json::Value vecdt(Json::arrayValue);
    Json::StreamWriterBuilder builder;
    const std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());

    Node<DienThoai>* current  = head;
    while (current != NULL) {
        // output data to file
        Json::Value temp;
        temp["madt"] = current->data.getMadt();
        temp["tendt"] = current->data.getTenDt();
        temp["mausac"] = current->data.getMausac();
        temp["hangsx"] = current->data.getHangsx();
        temp["ngaysx"] = current->data.getNgaySx();
        temp["dongia"] = current->data.getDongia();
        temp["soluong"] = current->data.getSoluong();
        vecdt.append(temp);
        current = current->next;
    }

    root["dienthoai"] = vecdt;
    writer->write(root, &output);
    output.close();
}

void LinkedlistDT::updateNode(DienThoai data)
{
    Node<DienThoai>* current = head;
    while (current != NULL) {
        if(strcmp(current->data.getMadt().c_str(), data.getMadt().c_str())){
            current->data = data;
            break;
        }
        current = current->next;
    }
}

// Function to insert a new node. 
void LinkedlistDT::insertNode(DienThoai data) 
{ 
    m_counter += 1;
    // Create the new Node. 
    Node<DienThoai>* newNode = new Node<DienThoai>(data); 
  
    // Assign to head 
    if (head == NULL) { 
        head = newNode; 
        return; 
    } 
  
    // Traverse till end of list 
    Node<DienThoai>* temp = head; 
    while (temp->next != NULL) { 
  
        // Update temp 
        temp = temp->next; 
    } 
  
    // Insert at the last. 
    temp->next = newNode; 
} 


//============================================= implement LinkedlistHD body============================= 
LinkedlistHD::LinkedlistHD()
{ 
    head = NULL; 
    m_size =0;
} 

LinkedlistHD::~LinkedlistHD(){
    while (head != NULL)
    {            
        Node<HoaDon> * tmp = head;
        head = head->next;
        // delete node 
        delete tmp;
    }
}

void LinkedlistHD::deleteNode(string mahd) 
{ 
    // mac dinh cac nu trong list la duy nhat
    Node<HoaDon> *current = head, *temp = NULL; 
    int ListLen = 0; 
  
    if (head == NULL) { 
        cout << "List empty." << endl; 
        return; 
    } 

    // Nếu nút cần xóa là nút đầu tiên
    if (strcmp(mahd.c_str(),head->data.getMaHD().c_str()) == 0) {
        temp = head;
        head = head->next;
        delete temp;
        m_size -= 1;
        return;
    }

    while (current != NULL && (strcmp(current->data.getMaHD().c_str(),mahd.c_str()) == 0)) {
        temp = current;
        current = current->next;
    }

    // Nếu nút cần xóa không phải nút đầu tiên
    if (temp != NULL) {
        delete temp;
        m_size -= 1;
    }
}

bool LinkedlistHD::checkNodeExist(string id)
{
    Node<HoaDon>* current = head;
    while (current != NULL) {
        if( strcmp(current->data.getMaHD().c_str(),id.c_str()) == 0){
            return true;
        }
        current = current->next;
    }

    return false;
}


void LinkedlistHD::findNode(int type,string data)
{
    Node<HoaDon>* current = head;
    bool isExist = false;
    switch (type)
    {
    case MENU_3_A4::MENU_3_A4_THEO_MaHD:{
        while (current != NULL) {
            if(strcmp(current->data.getMaHD().c_str(),data.c_str()) == 0){
                isExist = true;
                current->data.xuat();
                break;
            }
            current = current->next;
        }
        if(!isExist){
            cout << "Hoa don khong ton tai!!!\n";
        }
        break;
    }case MENU_3_A4::MENU_3_A4_THEO_NGAY_LAP:{
        while (current != NULL) {
            if(strcmp(current->data.getNgayLapHD().c_str(),data.c_str()) == 0){
                isExist = true;
                current->data.xuat();
            }
            current = current->next;
        }       
        if(!isExist){
            cout << "Hoa don khong ton tai!!!\n";
        }
        break;
    }
    default:
        break;
    }
}

void LinkedlistHD::showData(int type)
{
    Node<HoaDon>* current = head;
    // Check for empty list. 
    if (head == NULL) { 
        cout << "List empty" << endl; 
        return; 
    } 

    //increase by buble sort algorithm
    if(type == MENU_3_A4_SX::SX_THEO_MaHD){
    // Traverse the list. 
        while (current != NULL) { 
            Node<HoaDon> *pos = current->next;
            while (pos != NULL)
            {
                // using bubble soft algorithm
               if(strcmp(current->data.getMaHD().c_str(),pos->data.getMaHD().c_str()) > 0){
                    HoaDon tmpData = current->data;
                    current->data = pos->data;
                    pos->data = tmpData;
                }
                pos = pos->next;
            }
            current = current->next; 
        }
    }else if(type == MENU_3_A4_SX::SX_THEO_NGAY_LAP){
        // Traverse the list. 
        while (current != NULL) { 
            Node<HoaDon> *pos = current->next;
            while (pos != NULL)
            {
                // using bubble soft algorithm
               if(compareDates(current->data.getNgayLapHD(), pos->data.getNgayLapHD()) > 0){
                    HoaDon tmpData = current->data;
                    current->data = pos->data;
                    pos->data = tmpData;
                }
                pos = pos->next;
            }
            current = current->next; 
        }
    }

    current = head;
    while (current != NULL) {
        current->data.xuat();
        current = current->next;
    }
}

void LinkedlistHD::writeDataToFile()
{
    ofstream output(HD_PATH,std::ios::trunc);
    if(!output){
        cout << "open file " << DT_PATH << " failed!!!";
        return;
    }

    Json::Value root;
    Json::Value vechd(Json::arrayValue);
    Json::StreamWriterBuilder builder;
    const std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());

    Node<HoaDon>* current  = head;
    while (current != NULL) {
        // output data to file
        Json::Value temp;
        Json::Value vecdt(Json::arrayValue);
        temp["mahd"] = current->data.getMaHD();
        temp["ngaylap"] = current->data.getNgayLapHD();
        std::vector<tt_dienthoai> listDt = current->data.getListDT();
        for(int i = 0 ; i < listDt.size();i++){
            Json::Value tempDt;
            tempDt["madt"] = listDt[i].maDt;
            tempDt["soluong"] = listDt[i].sl;
            vecdt.append(tempDt);
        }
        temp["listDT"] = vecdt;
        vechd.append(temp);
        current = current->next;
    }

    root["hoadon"] = vechd;
    writer->write(root, &output);
    output.close(); 
}

int LinkedlistHD::getSize() const
{
    return m_size;
}

void LinkedlistHD::updateNode(HoaDon data)
{
    Node<HoaDon>* current = head;
    while (current != NULL) {
        if(strcmp(current->data.getMaHD().c_str(),data.getMaHD().c_str()) == 0){
            current->data = data;
            break;
        }
        current = current->next;
    }
    LOG("update done\n");
}

// Function to insert a new node. 
void LinkedlistHD::insertNode(HoaDon data) 
{ 
    // Create the new Node. 
    Node<HoaDon>* newNode = new Node<HoaDon>(data); 
  
    // Assign to head 
    if (head == NULL) { 
        head = newNode; 
        m_size += 1;
        return; 
    } 
  
    // Traverse till end of list 
    Node<HoaDon>* temp = head; 
    while (temp->next != NULL) { 
        // Update temp 
        temp = temp->next; 
    } 
  
    // Insert at the last. 
    temp->next = newNode; 
    m_size  += 1;
} 



