#ifndef DATA_H
#define DATA_H
#include<string>
//define data
using std::string;
typedef struct Session{
    int permission;
    string ID;
}Session;

typedef struct Borrow
{
    string borrowID;
    string bookID;
    string employeeID;
    string startDate;
    string dueDate;
    string realDate;
    string borrowstatus;
}Borrow;
typedef struct book
{
    string bookID;
    string ISBN;
    string Title;
    int numOfcopies;
    string author;
    string publisher;
    string nextbook;
}book;
//employee
typedef struct Employee
{
    string employeeID;
    string password;
    string Name;
    string address;
    string phoneNum;
    string Department;
    string dateofbirth;
    string email;
    string gender;
}employee;
typedef struct user
{
    string ID;
    string name;
    string password;
    string email;
    string dateofbirth;
    int phoneNum;
}user;

//data directory

#define bookdir "data/book/"
#define userdir "data/user/"
#define employeedir "data/employee/"
#define logindir "data/etc/login/"

//process

void bookprocess(string mode);
void userprocess(string mode,string sessionID);
void employeeprocess(string mode,string sessionID);

#endif // DATA_H
