#include"control.h"
#include"view.h"
#include"data.h"
#include<cstdio>
#include<string.h>
#include<conio.h>
#include<limits.h>
#include<iostream>
#include<windows.h>

using std::string;
using namespace std;

void notifi(string messenge)
{
    system("CLS");
    greet();
    cout<<"           "+messenge+"             \n";
    system("pause");
}
void greet()
{
    system("cls");
    cout<<"-------------------------------------------------"<<endl;
    cout<<"----------chuong trinh quan ly thu vien----------"<<endl;
    cout<<"-------------------------------------------------"<<endl;
}
Session loginscreen()
{
    greet();
    string username,password="";
    cout<<"           moi nhap ten tai khoan:            \n                   ";
    cin>>username;
    cout<<"            moi nhap mat khau:                \n                   ";
    password=inputpassword();
    return checkuser(username,password);
}
string inputpassword()
{
    string password;
    char ch;
    ch = _getch();
    while(ch != 13){//character 13 is enter
      password.push_back(ch);
      cout << '*';
      ch = _getch();
    }
    cout<<endl;
    return password;
};
void adminscreen(Session session)
{
   int mode;
    //hiện thị ID chức danh
    //giao diện cho admin,cho tùy chọn tìm sách
    system("cls");
    greet();
    cout << "                WELCOME ADMIN" << endl;
    cout << "               ==============" << endl;
    cout << "Moi ban lua chon tinh nang can xu ly: "<< endl;

    cout << "1,xem sach"<<endl;
    cout << "2,them,sua sach"<<endl;
    cout << "3,tim sach"<<endl;
    cout << "4,xoa sach\n"<<endl;

    cout << "5,xem thong tin nguoi muon"<<endl;
    cout << "6,tim thong tin nguoi muon"<<endl;
    cout << "7,them,sua thong tin nguoi muon"<<endl;
    cout << "8,xoa thong tin nguoi muon\n"<<endl;

    cout << "9,xem thong tin nhan vien"<<endl;
    cout << "10,tim thong tin nhan vien"<<endl;
    cout << "11,them,sua thong tin nhan vien"<<endl;
    cout << "12,xoa thong tin nhan vien\n"<<endl;

    cout << "13,dang xuat"<<endl;
    cin.clear();
    cin.ignore(6400,'\n');
    cin >> mode;
    switch(mode)
    {
        case 1: bookprocess("view");break;
        case 2: bookprocess("edit");break;
        case 3: bookprocess("search");break;
        case 4: bookprocess("delete");break;

        case 5: employeeprocess("view","");break;
        case 6: employeeprocess("search","");break;
        case 7: employeeprocess("add","");break;
        case 8: employeeprocess("delete","");break;

        case 9: userprocess("view","");break;
        case 10: userprocess("search","");break;
        case 11: userprocess("add","");break;
        case 12: userprocess("delete","");break;

        case 13: return;
        default: notifi("nhap sai chuc nang,moi ban nhap lai");break;
    };
    adminscreen(session);
}
void userscreen(Session session)
{
    int mode;
    //giao diện cho user,cho tùy chọn tìm sách
    system("cls");
    greet();
    cout << "                WELCOME USER" << endl;
    cout << "               ==============" << endl;
    cout << "Moi ban lua chon tinh nang can xu ly: "<< endl;
    cout << "1,xem sach"<<endl;
    cout << "2,them,sua sach"<<endl;
    cout << "3,tim sach"<<endl;
    cout << "4,xoa sach\n"<<endl;

    cout << "5,nhan tra sach"<<endl;
    cout << "6,cho muon sach\n"<<endl;

    cout << "7,tim thong tin nguoi muon"<<endl;
    cout << "8,xem thong tin nguoi muon"<<endl;
    cout << "9,them,sua thong tin nguoi muon"<<endl;
    cout << "10,xoa thong tin nguoi muon\n"<<endl;

    cout << "11,dang xuat"<<endl;
    cin.clear();
    cin.ignore(6400,'\n');
    cin >> mode;
    switch(mode)
    {
        case 1: bookprocess("view");break;
        case 2: bookprocess("edit");break;
        case 3: bookprocess("search");break;
        case 4: bookprocess("delete");break;

        case 5: checkout();break;
        case 6: checkin();break;

        case 7: employeeprocess("search","");break;
        case 8: employeeprocess("view","");break;
        case 9: employeeprocess("edit","");break;
        case 10: employeeprocess("delete","");break;
        case 11: return;
        default : notifi("nhap sai chuc nang,moi ban nhap lai");break;
    };
    userscreen(session);
}
void employeescreen(Session session)
{
	int mode;
    //hiện thị ID chức danh
    //giao diện cho employee,cho tùy chọn chức năng
    system("cls");
    greet();
    cout << "                WELCOME EMPLOYEE" << endl;
    cout << "               ==================" << endl;
    cout << "Moi ban lua chon tinh nang can xu ly: "<<endl;
    cout << "1,xem sach"<<endl;
    cout << "2,tim sach"<<endl;
    cout << "3,xem thong tin ca nhan"<<endl;

    cout << "5,dang xuat"<<endl;
    cin.clear();
    cin.ignore(6400,'\n');
    cin >> mode;
    switch(mode)
    {
        case 1:bookprocess("view");break;
        case 2:bookprocess("search");break;
        case 3:employeeprocess("view",session.ID);break;
        case 5:return;break;
        default: notifi("ban da nhap sai chuc nang");break;
    };
    employeescreen(session);
}
