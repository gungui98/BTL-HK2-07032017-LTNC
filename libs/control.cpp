#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>
#include<cstdlib>
#include"hash.h"
#include"control.h"
#include"data.h"
#include"view.h"
using std::string;
using namespace std;
Session checkuser(string username,string password)
{
    ifstream file;
    file.open((logindir+hashing(username)+".csv").c_str(),ios::in);
    string hashedpass;
    Session session;
    file>>hashedpass>>session.permission;
    if(hashing(password)==hashedpass)
    {
        session.ID=username;
        return session;
    }
    else
    {
        session.permission=0;
        return session;
    }

};
void logout(int* permission)
{
    *permission=0;
};
void checkout()
{
    system("cls");
    greet();

    Borrow tempbr;
    string temp,line="";
    int numofcopy;
    char c[10];

    cout << "nhap ID sach da muon :";
    cin >> tempbr.borrowID;

    fstream file;
    file.open(("data/etc/borrow/"+tempbr.borrowID+".csv").c_str(),std::ios_base::in);
    getline(file,tempbr.bookID,',');
    getline(file,tempbr.employeeID,',');
    getline(file,tempbr.startDate,',');
    getline(file,tempbr.dueDate,',');
    getline(file,tempbr.borrowstatus,',');
    cout << "nhap ngay tra sach:";
    cin >> tempbr.realDate;
    tempbr.borrowstatus="returned";
    file.close();

    file.open(("data/etc/borrow/"+tempbr.borrowID+".csv").c_str(),std::ios_base::out);
    file<<tempbr.bookID<<','<<tempbr.employeeID<<','<<tempbr.startDate<<','<<tempbr.dueDate<<','<<tempbr.realDate<<tempbr.borrowstatus;
    file.close();

    file.open((bookdir+tempbr.bookID+".csv").c_str(),std::ios_base::in);
    for(int i=0;i<4;i++)
    {
        getline(file,temp,',');
        line+=temp;
        line+=',';
    }
    file>>numofcopy;
    numofcopy++;
    itoa(numofcopy,c,10);
    line+=c;
    file.close();

    file.open((bookdir+tempbr.bookID+".csv").c_str(),std::ios_base::out);
    file<<line;
    file.close();

    notifi("tra sach thanh cong");

}
void checkin()
{
    system("cls");
    greet();
    Borrow tempbr;
    char c[10];
    string line,temp;
    int numofcopy;

    cout << "moi nhap ID muon sach:";
    cin >> tempbr.borrowID;
    cout << "moi nhap ID sach:";
    cin >> tempbr.bookID;
    cout << "moi nhap ID nguoi muon:";
    cin >> tempbr.employeeID;
    cout << "moi nhap ngay muon:";
    cin >> tempbr.startDate;
    cout << "moi nhap han tra:";
    cin >> tempbr.dueDate;
    tempbr.borrowstatus="borrow";
    fstream file;

    file.open((bookdir+tempbr.bookID+".csv").c_str(),std::ios_base::in);
    if(!file.good())
    {
        notifi("khong ton tai sach");
        return;
    };
    for(int i=0;i<4;i++)
    {
        getline(file,temp,',');
        line+=temp;
        line+=',';
    }
     file>>numofcopy;
    if(numofcopy<1)
    {
        notifi("khong con sach trong kho");
        return;
    }
    file.close();

    numofcopy--;
    itoa(numofcopy,c,10);
    line+=c;
    file.open((bookdir+tempbr.bookID+".csv").c_str(),std::ios_base::out);
    file<<line;
    file.close();

    file.open((employeedir+tempbr.employeeID+".csv").c_str(),std::ios_base::app);
    file<<tempbr.borrowID<<',';
    file.close();

    file.open(("data/etc/borrow/"+tempbr.borrowID+".csv").c_str(),std::ios_base::out);
    file<<tempbr.bookID<<','<<tempbr.employeeID<<','<<tempbr.startDate<<','<<tempbr.dueDate<<','<<tempbr.borrowstatus;
    file.close();

    notifi("da dat muon sach thanh cong");
}
