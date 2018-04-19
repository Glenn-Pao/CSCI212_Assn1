
#include "Printer.h"

void Printer::printmainheader()
{
	cout << "\E[1;32m--------------------------------------------------------------------" << endl;
	cout << "    -          Welcome to Warehouse Management System          -" << endl;
        cout << "--------------------------------------------------------------------\E[0m" << endl;
}

void Printer::printloginheader()
{
	cout << "\E[1;34m--------------------------------------------------------------------" << endl;
	cout << "                 -          Please Login          -" << endl;
        cout << "--------------------------------------------------------------------\E[0m" << endl;
}

void Printer::printmenuheader()
{
	cout << "\E[1;35m--------------------------------------------------------------------" << endl;
	cout << "                 -          Main Menu          -" << endl;
        cout << "--------------------------------------------------------------------\E[0m" << endl;
}

void Printer::printinventorydisplayheader()
{
	cout << "\E[1;33m--------------------------------------------------------------------" << endl;
	cout << "               -          Current Inventory          -" << endl;
        cout << "--------------------------------------------------------------------\E[0m" << endl;
}

void Printer::printaddheader()
{
	cout << "\E[1;36m--------------------------------------------------------------------" << endl;
	cout << "               -          Add New Stock          -" << endl;
        cout << "--------------------------------------------------------------------\E[0m" << endl;
}

void Printer::printdeleteheader()
{
	cout << "\E[1;37m--------------------------------------------------------------------" << endl;
	cout << "               -          Delete Stock          -" << endl;
        cout << "--------------------------------------------------------------------\E[0m" << endl;
}

void Printer::printeditheader()
{
	cout << "\E[5;31m--------------------------------------------------------------------" << endl;
	cout << "               -          Edit Stock          -" << endl;
        cout << "--------------------------------------------------------------------\E[0m" << endl;
}

void Printer::printsearchheader()
{
	cout << "\E[5;32m--------------------------------------------------------------------" << endl;
	cout << "               -          Search Stock          -" << endl;
        cout << "--------------------------------------------------------------------\E[0m" << endl;
}

void Printer::printadduserheader()
{
	cout << "\E[5;33m--------------------------------------------------------------------" << endl;
	cout << "               -          Add User          -" << endl;
        cout << "--------------------------------------------------------------------\E[0m" << endl;
}

void Printer::printsortheader()
{
	cout << "\E[5;29m--------------------------------------------------------------------" << endl;
	cout << "               -          Sort Transaction          -" << endl;
        cout << "--------------------------------------------------------------------\E[0m" << endl;

}


void Printer::printdisplaymainmenu()
{
	printmenuheader();
	string str;
	cout<<"        "<<"1) Display All Stock"<<endl;
	cout<<"        "<<"2) Add Stock"<<endl;
	cout<<"        "<<"3) Remove Stock"<<endl;
	cout<<"        "<<"4) Edit Stock"<<endl;
	cout<<"        "<<"5) Search Stock"<<endl;
	cout<<"        "<<"6) Sorting"<<endl;
	cout<<"        "<<"9) Add User"<<endl;
	cout<<"        "<<"0) Exit"<<endl;
}


