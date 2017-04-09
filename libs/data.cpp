#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<windows.h>
#include"data.h"
#include"control.h"
#include"view.h"
#include"hash.h"
#include<cstdio>
using std::string;
using namespace std;

void bookprocess(string mode)
{
	book tempbook;
	greet();

	if (mode == "add" || mode == "edit")
	{
		getline(std::cin, tempbook.Title);//xóa buffer của std::in
		cout << ("moi nhap ten sach:");
		getline(std::cin, tempbook.Title);
		cout << ("moi nhap ten tac gia:");
		getline(std::cin, tempbook.author);
		cout << ("moi nhap ID sach:");
		getline(std::cin, tempbook.bookID);
		cout << ("moi nhap ma ISBN sach:");
		getline(std::cin, tempbook.ISBN);
		cout << ("moi nhap ten nha xuat ban:");
		getline(std::cin, tempbook.publisher);
		cout << ("moi nhap so sach:");
		cin >> tempbook.numOfcopies;
		if (tempbook.numOfcopies > 0)
			tempbook.status = "available";
		ofstream file;
		file.open((bookdir + tempbook.bookID + ".csv").c_str());
		file << tempbook.Title << "," << tempbook.author << "," << tempbook.ISBN << "," << tempbook.publisher << "," << tempbook.numOfcopies;
		file.close();
		file.open("data/book/index.csv",std::ios_base::app);
		file << tempbook.Title << ',' << tempbook.bookID<<endl;
		file.close();
		notifi("da thao tac thanh cong!");
	}

	if (mode == "delete")
	{
		string bookID;
		cout << ("moi nhap ma sach can xoa:");
		cin >> bookID;
		if (remove((bookdir + bookID + ".csv").c_str()) == 0)
			notifi("da xoa thanh cong sach");
		else
			notifi("khong the xoa sach,xin vui long thu lai!");
	}

	if (mode == "view")
	{
		string bookID;
		cout << ("moi nhap ma sach can xem: ");
		cin >> bookID;
		ifstream file;
		file.open((bookdir + bookID + ".csv").c_str(), ios::in);
		string data, messenges[] = { "\nten sach:","ten tac gia:","ID sach:","ma ISBN sach:","nha xuat ban:","\nso sach trong kho:" };
		for (int i = 0;i < 6;i++)
		{
			getline(file, data, ',');
			cout << messenges[i] ;
			cout << "   " << data << endl;
		}
		cout<<'\n';
		system("pause");
	}

	if (mode=="search")
    {
        string booktitle,temp,ID;
        cout << "nhap ten sach can tim" <<endl;
        cin.ignore();
        getline(std::cin,booktitle);
        ifstream file;
        file.open("data/book/index.csv");
        while(file.good())
        {
            getline(file,temp,',');
            if(temp==booktitle)
            {
                getline(file,ID);
                ifstream file2;
                file2.open((bookdir +ID + ".csv").c_str(), ios::in);
                string data, messenges[] = { "\nten sach:","ten tac gia:","ID sach:","ma ISBN sach:","nha xuat ban:","\nso sach trong kho:" };
                for (int i = 0;i < 6;i++)
                {
                    getline(file2, data, ',');
                    cout << messenges[i] ;
                    cout << "   " << data << endl;
                }
                cout<<'\n';
                file2.close();
                system("pause");
                return;
            }
            else
            {
                getline(file,temp);
            };
        }
        notifi("khong tim thay sach!");
    }
}


void userprocess(string mode,string sessionID)
{
	user tempUser;
	greet();

	if (mode == "add" || mode == "edit")
	{
		getline(std::cin, tempUser.ID);//xóa buffer của std::in
		cout << ("moi nhap ID nhan vien:");
		getline(std::cin, tempUser.ID);
		cout << ("moi nhap ten nhan vien:");
		getline(std::cin, tempUser.name);
		cout << ("moi nhap mat khau nhan vien:");
		tempUser.password=inputpassword();
		cout << ("moi nhap email nhan vien:");
		getline(std::cin, tempUser.email);
		cout << ("moi nhap ngay sinh nhan vien:");
		getline(std::cin, tempUser.dateofbirth);
		cout << ("moi nhap so dien thoai nhan vien:");
		cin >> tempUser.phoneNum;

		ofstream file,login;
		file.open((userdir + tempUser.ID + ".csv").c_str());
		file << tempUser.ID << "," << tempUser.name << "," << tempUser.email << "," << tempUser.dateofbirth << "," << tempUser.phoneNum;
		file.close();
		login.open((logindir+hashing(tempUser.ID)+".csv").c_str());
		login << hashing(tempUser.password) << " 2";
		login.close();
		file.open("data/user/index.csv",std::ios_base::app);
		file << tempUser.name << ',' << tempUser.ID<<endl;
		file.close();

		notifi("da thao tac thanh cong!");
	}

	if (mode == "delete")
	{
		string userID;
		cout << ("moi nhap ID nhan vien can xoa:");
		cin >> userID;
		if (remove((logindir + hashing(userID) + ".csv").c_str())*remove((userdir + userID + ".csv").c_str()) == 0)

			notifi("da xoa thanh cong nhan vien");
		else
			notifi("khong the xoa nhan vien,xin vui long thu lai!");
	}

	if (mode == "view")
	{
		string userID;
		cout << ("moi nhap ma nhan vien can xem!");
		cin >> userID;
		ifstream file;
		file.open((userdir + userID + ".csv").c_str(), ios::in);
		string data, messenges[] = { "ID nhan vien:","ten nhan vien:","email nhan vien:","ngay sinh nhan vien:","so dien thoai nhan vien:" };
		for (int i = 0;i < 5;i++)
		{
			getline(file, data, ',');
			cout << messenges[i];
			cout << "    " << data << endl;
		}
		system("pause");
	}

    if (mode=="search")
    {
        string user,temp,ID;
        cout << "nhap ten nguoi muon can xem" <<endl;
        cin.ignore();
        getline(std::cin,user);
        ifstream file;
        file.open("data/user/index.csv");
        while(file.good())
        {
            getline(file,temp,',');
            if(temp==user)
            {
                getline(file,ID);
                ifstream file2;
                file2.open((userdir + ID + ".csv").c_str(), ios::in);
                string data, messenges[] = { "ID nhan vien:","ten nhan vien:","email nhan vien:","ngay sinh nhan vien:","so dien thoai nhan vien:" };
                for (int i = 0;i < 5;i++)
                {
                    getline(file2, data, ',');
                    cout<<messenges[i];
                    cout <<"    "<< data << endl;
                }
                file2.close();
                system("pause");
                return;
            }
            else
            {
                getline(file,temp);
            };
        }
        file.close();
        notifi("khong tim thay nhan vien!");
    }
}

void employeeprocess(string mode,string sessionID)
{
	employee tempE;
	greet();
	if (mode == "add" || mode == "edit")
	{
		getline(std::cin, tempE.employeeID);//xóa buffer của std::in
		cout << ("moi nhap ID nguoi muon :");
		getline(std::cin, tempE.employeeID);
		cout << ("moi nhap mat khau: ");
		tempE.password=inputpassword();
		cout << ("moi nhap ten nguoi muon: ");
		getline(std::cin, tempE.Name);
		cout << ("moi nhap bo phan lam viec nguoi muon :");
		getline(std::cin, tempE.Department);
		cout << ("moi nhap email nguoi muon: ");
		getline(std::cin, tempE.email);
		cout << ("moi nhap ngay sinh nguoi muon: ");
		getline(std::cin, tempE.dateofbirth);
		cout << ("moi nhap dia chi nguoi muon: ");
		getline(std::cin, tempE.address);
		cout << ("moi nhap so dien thoai nguoi muon: ");
		getline(std::cin, tempE.phoneNum);
		cout << ("moi nhap gioi tinh nguoi muon: ");
		getline(std::cin, tempE.gender);

		ofstream file,login;
		file.open((employeedir + tempE.employeeID + ".csv").c_str());
		file << tempE.employeeID << "," << tempE.Name << "," << tempE.Department << "," << tempE.email << "," << tempE.dateofbirth << "," << tempE.address << "," << tempE.phoneNum << "," << tempE.gender;
		login.open((logindir+hashing(tempE.employeeID)+".csv").c_str());
		login << hashing(tempE.password) << " 3";
		login.close();
		file.close();
		file.open("data/employee/index.csv",std::ios_base::app);
		file << tempE.Name << ',' << tempE.employeeID<<endl;
		file.close();
		notifi("da thao tac thanh cong!");
	}

	if (mode == "delete")
	{
		string employID;
		cout << ("moi nhap ID nguoi muon can xoa:");
		cin >> employID;
		if (remove((employeedir + employID + ".csv").c_str()) == 0&&remove((logindir + hashing(employID) + ".csv").c_str()) == 0)
			notifi("da xoa thanh cong nguoi muon");
		else
			notifi("khong the xoa nguoi muon,xin vui long thu lai!");
	}

	if (mode == "view")
	{
		string employID;
		if(sessionID=="")
        {
            cout << ("moi nhap ID nguoi muon can xem!");
            cin >> employID;
        }
        else
        {
            employID=sessionID;
        }
		ifstream file;
		file.open((employeedir + employID + ".csv").c_str(), ios::in);
		string data, messenges[] = { "ID nguoi muon:","ten nguoi muon:","bo phan lam viec:","email nguoi muon:","ngay sinh nguoi muon:","dia chi nguoi muon:","so dien thoai nguoi muon:","gioi tinh:" };
		for (int i = 0;i < 8;i++)
		{
			getline(file, data, ',');
			cout<<messenges[i];
			cout <<"    "<< data << endl;
		}
		system("pause");
	}

    if (mode=="search")
    {
        string employee,temp,ID;
        cout << "nhap ten nguoi muon can xem" <<endl;
        cin.ignore();
        getline(std::cin,employee);
        ifstream file;
        file.open("data/employee/index.csv");
        while(file.good())
        {
            getline(file,temp,',');
            if(temp==employee)
            {
                getline(file,ID);
                ifstream file2;
                file2.open((employeedir + ID + ".csv").c_str(), ios::in);
                string data, messenges[] = { "ID nguoi muon:","ten nguoi muon:","bo phan lam viec:","email nguoi muon:","ngay sinh nguoi muon:","dia chi nguoi muon:","so dien thoai nguoi muon:","gioi tinh:" };
                for (int i = 0;i < 8;i++)
                {
                    getline(file2, data, ',');
                    cout<<messenges[i];
                    cout <<"    "<< data << endl;
                }
                file2.close();
                system("pause");
                return;
            }
            else
            {
                getline(file,temp);
            };
        }
        file.close();
        notifi("khong tim thay nguoi muon!");
    }
}
