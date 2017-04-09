#ifndef CONTROL_H
#define CONTROL_H
#include<string>
#include"data.h"
using std::string;
Session checkuser(string username,string password);
void logout(int* session);
void checkin();
void checkout();
#endif // CONTROL_H
