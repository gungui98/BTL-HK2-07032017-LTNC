#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include"data.h"
#include"control.h"
#include"view.h"
#include<cstdio>
using std::string;
using namespace std;

void bookprocess(string mode)
{
	book tempbook;
	greet();
	if (mode == "add" || mode == "edit")
	{
	    getline(std::cin,tempbook.Title);//xóa buffer của std::in
		notifi("moi nhap ten sach:");
		getline(std::cin,tempbook.Title);
		notifi("moi nhap ten tac gia:");
		getline(std::cin,tempbook.author);
		notifi("moi nhap ID sach:");
		getline(std::cin,tempbook.bookID);
		notifi("moi nhap ma ISBN sach:");
		getline(std::cin,tempbook.ISBN);
		notifi("moi nhap ten nha xuat ban:");
		getline(std::cin,tempbook.publisher);
		notifi("moi nhap so sach:");
		cin >> tempbook.numOfcopies;
		if (tempbook.numOfcopies > 0)
			tempbook.status = "available";
		ofstream file;
		file.open((bookdir + tempbook.bookID + ".csv").c_str());
		file << tempbook.Title << "," << tempbook.author << "," << tempbook.ISBN << "," << tempbook.publisher << "," << tempbook.numOfcopies;
		file.close();
		notifi("da thao tac thanh cong!");
	}
	if (mode == "delete")
	{
		string bookID;
		notifi("moi nhap ma sach can xoa:");
		cin >> bookID;
		if (remove((bookdir + bookID + ".csv").c_str()) == 0)
			notifi("da xoa thanh cong sach");
		else
			notifi("khong the xoa sach,xin vui long thu lai!");
	}
	if (mode == "view")
	{
		string bookID;
		notifi("moi nhap ma sach can xem!");
		cin >> bookID;
		ifstream file;
		file.open((bookdir + bookID + ".csv").c_str(),ios::in);
		string data, messenges[] = { "ten sach:","ten tac gia:","ID sach:","ma ISBN sach:","nha xuat ban:","so sach trong kho:" };
		for (int i = 0;i < 6;i++)
		{
			getline(file, data, ',');
			notifi(messenges[i]);
			cout << data<<endl;
		}
		system("pause");
	}
}


void userprocess(string mode)
{
	user tempUser;
	greet();
	if (mode == "add" || mode == "edit")
	{
	    getline(std::cin,tempUser.ID);//xóa buffer của std::in
		notifi("moi nhap ID nguoi dung:");
		getline(std::cin,tempUser.ID);
		notifi("moi nhap ten nguoi dung:");
		getline(std::cin,tempUser.name);
		notifi("moi nhap mat khau nguoi dung:");
		getline(std::cin,tempUser.password);
		notifi("moi nhap email nguoi dung:");
		getline(std::cin,tempUser.email);
		notifi("moi nhap ngay sinh nguoi dung:");
		getline(std::cin,tempUser.dateofbirth);
		notifi("moi nhap so dien thoai nguoi dung:");
		cin >> tempUser.phoneNum;

		ofstream file;
		file.open((userdir + tempUser.ID + ".csv").c_str());
		file << tempUser.ID << "," << tempUser.name << "," << tempUser.password << "," << tempUser.email << "," << tempUser.dateofbirth << "," << tempUser.phoneNum;
		file.close();
		notifi("da thao tac thanh cong!");
	}
	if (mode == "delete")
	{
		string userID;
		notifi("moi nhap ID nguoi dung can xoa:");
		cin >> userID;
		if (remove((userdir + userID + ".csv").c_str()) == 0)
			notifi("da xoa thanh cong nguoi dung");
		else
			notifi("khong the xoa nguoi dung,xin vui long thu lai!");
	}
	if (mode == "view")
	{
		string userID;
		notifi("moi nhap ma nguoi dung can xem!");
		cin >> userID;
		ifstream file;
		file.open((userdir + userID + ".csv").c_str(),ios::in);
		string data, messenges[] = { "ID nguoi dung:","ten nguoi dung:","mat khau nguoi dung:","email nguoi dung:","ngay sinh nguoi dung:","so dien thoai nguoi dung:" };
		for (int i = 0;i < 6;i++)
		{
			getline(file, data, ',');
			notifi(messenges[i]);
			cout << data<<endl;
		}
		system("pause");
	}
}

void employeeprocess(string mode)
{
	employee tempE;
	greet();
	if (mode == "add" || mode == "edit")
	{
	    getline(std::cin,tempE.employeeID);//xóa buffer của std::in
		notifi("moi nhap ID nhan vien:");
		getline(std::cin,tempE.employeeID);
		notifi("moi nhap ten nhan vien:");
		getline(std::cin,tempE.Name);
		notifi("moi nhap bo phan lam viec nhan vien:");
		getline(std::cin,tempE.Department);
		notifi("moi nhap email nhan vien:");
		getline(std::cin,tempE.email);
		notifi("moi nhap ngay sinh nhan vien:");
		getline(std::cin,tempE.dateofbirth);
		notifi("moi nhap dia chi nhan vien:");
		getline(std::cin,tempE.address);
		notifi("moi nhap so dien thoai nhan vien:");
		getline(std::cin,tempE.phoneNum);
		notifi("moi nhap gioi tinh nhan vien:");
		getline(std::cin,tempE.gender);

		ofstream file;
		file.open((employeedir + tempE.employeeID + ".csv").c_str());
		file << tempE.employeeID << "," << tempE.Name << "," << tempE.Department << "," << tempE.email << "," << tempE.dateofbirth << "," << tempE.address << "," << tempE.phoneNum << "," << tempE.gender;
		file.close();
		notifi("da thao tac thanh cong!");
	}
	if (mode == "delete")
	{
		string employID;
		notifi("moi nhap ID nhan vien can xoa:");
		cin >> employID;
		if (remove((employeedir + employID + ".csv").c_str()) == 0)
			notifi("da xoa thanh cong nhan vien");
		else
			notifi("khong the xoa nhan vien,xin vui long thu lai!");
	}
	if (mode == "view")
	{
		string employID;
		notifi("moi nhap ID nhan vien can xem!");
		cin >> employID;
		ifstream file;
		file.open((employeedir + employID + ".csv").c_str(),ios::in);
		string data, messenges[] = { "ID nhan vien:","ten nhan vien:","bo phan lam viec:","email nhan vien:","ngay sinh nhan vien:","dia chi nhan vien:","so dien thoai nhan vien:","gioi tinh:" };
		for (int i = 0;i < 8;i++)
		{
			getline(file, data, ',');
			notifi(messenges[i]);
			cout << data<<endl;
		}
		system("pause");
	}
}
