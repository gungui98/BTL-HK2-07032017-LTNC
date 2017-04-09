#include <iostream>
#include"libs\view.h"
#include"libs\control.h"
#include"libs\data.h"
#include<windows.h>

#define ad 1
#define usr 2
#define emlye 3



using namespace std;

Session session;


int main()
{
    session.permission=0;
    session.ID="";
    while(1)
    {
        greet();
        session=loginscreen();
        if(session.permission==0)
        {
            notifi("xin loi,tai khoan hoac mat khau ban vua nhap khong dung!");
        }
        else
            notifi("dang nhap thanh cong");
        switch(session.permission)
            {
                case ad: adminscreen(session);break;
                case usr: userscreen(session);break;
                case emlye: employeescreen(session);break;
            };
        logout(&session.permission);
    }
return 0;
}
