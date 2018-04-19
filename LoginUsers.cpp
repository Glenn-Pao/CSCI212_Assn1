#include "LoginUsers.h"

LoginUsers::LoginUsers()
{
	SetLoginID("");
	SetPassword("");
}
LoginUsers::LoginUsers(std::string ID, std::string pwd)
{
	SetLoginID(ID);
	SetPassword(pwd);
}

LoginUsers::~LoginUsers()
{
}
void LoginUsers::SetLoginID(std::string ID)
{
	loginID = ID;
}
std::string LoginUsers::GetLoginID()
{
	return loginID;
}
void LoginUsers::SetPassword(std::string pwd)
{
	pw = pwd;
}
std::string LoginUsers::GetPassword()
{
	return pw;
}

std::string LoginUsers::ToString()
{
	std::string toString, login, pwd;
	
	login = "LoginUsers ID: " + loginID + '\n';
	pwd = "Password: " + pw + '\n';
	toString = login + pwd;
	
	return toString;
}
