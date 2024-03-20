#ifndef CONTAINER
#define CONTAINER

#include <iostream>
#include <sstream>
#include "dienthoai.h"
#include "hoadon.h"

using namespace std;

int compareDates(const std::string& date1, const std::string& date2);

template<class T>
struct Node { 
    T data; 
    Node* next; 
  
    // Default constructor 
    Node() 
    { 
        next = NULL; 
    }
  
    // Parameterised Constructor 
    Node(T data) 
    { 
        this->data = data;
        this->next = NULL; 
    } 
}; 
  

class LinkedlistDT { 
    Node<DienThoai>* head; 
    int m_counter;  
public: 
    // constructor 
    LinkedlistDT();

    // destructor
    ~LinkedlistDT();
    
    // insert to the end of  list. 
    void insertNode(DienThoai data); 
    // Function to delete the 
    void deleteNode(string madt); 
    void updateNode(DienThoai data);

    bool checkNodeExist(string id);

    void findNode(int type, string data);
    void showData(int type);

    int getSize() const;

    void writeDataToFile();
}; 

class LinkedlistHD { 
    Node<HoaDon>* head;  
    int m_size; 
public: 
    // constructor 
    LinkedlistHD();

    // destructor
    ~LinkedlistHD();
    
    // insert to the end of  list. 
    void insertNode(HoaDon data); 
    // Function to delete the 
    void deleteNode(string mahd); 
    void updateNode(HoaDon data);

    bool checkNodeExist(string id);

    void findNode(int type, string data);
    void showData(int type);
    void writeDataToFile();

    int getSize() const;

};

#endif