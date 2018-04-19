#include "Printer.h"
#include "Database.h"
using namespace std;

Printer printer;		// Printer class
Database mainDatabase;		// Database class

void login(int tries);
void displayoption(int option);

bool failedLogin = false;
int main()
{
	mainDatabase = Database();	//initialize the database
	printer = Printer();
	printer.printmainheader(); 	//display
	printer.printloginheader();
	
	int tries = -1;//max 3 tries
	
	login(tries);
	
	//check that the user did not exceed 3 attempts
	//if he didn't and passes, move on to this segment
	if(!failedLogin)
	{
		int option=-1; //initialise int
		do
		{
			printer.printdisplaymainmenu(); //display menu
			cout<<endl<<"        "<<"Enter Option :";	
			cin>>option;
			displayoption(option);
		}while(option!=0);
	}
	//otherwise it will ignore the above statement and end the program
}

void login(int tries)
{
	do //keep in login screen
	{
		tries = tries + 1;
		if(tries == 3)
		{
			cout<<"    max number of attempt. program close...."<<endl;
			failedLogin = true;
			break;
		}
	}
	while(!mainDatabase.checkLoginOK());
}
void displayoption(int option)
{
//option control functions
	switch(option)
	{
	case 1:
	//displaystockpile();
	break;
	case 2:
	//printer.printaddheader();
	//addstock();
	break;
	case 3:
	//removestock();
	break;
	case 4:
	//editstock();
	break;
	case 5:
	//searchstock();
	break;
	case 6:
	//sortstock();
	break;
	case 9:
	//createuser();
	break;
	default:break;
	}
}

