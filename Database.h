#include "LoginUsers.h"
#include "Sales.h"
#include <termios.h> 	//password masking
#include <unistd.h>	//password masking
using namespace std;

class Database
{
private:
	int MAX;
	LoginUsers users[50];
	Sales salesItems[50];
public:
	Database();
	~Database();
	void readUserDatabase();                // read employee info from userdatabase.txt
	void readSalesDatabase();                // read sales info from stockdatabase.txt
	void writeSalesDatabase();               // write employee info to userdatabase.txt
	void storeduserdata(string,int);	// store read data
	void storedsalesdata(string,int);	// store read data

	bool checkLoginOK();
	string getname(string id);
	string getpw(string id);


	//password masking			
	int getch();				// get **** char
	string getpass(const char* , bool );	// get passward


	//encrypt and decryptio
	string Encrypt(string&);		// encrypt string
	string Decrypt(string strTarget);	// decrypt

	
	void displayoption(int);		// get option by user
	void displaysales();			// display sales
	void addsales();			// add
	void removesales();			// remove
	void editsales();			// edit
	void searchsales();			// search
	void sortsales();			// sorting

	void displaysalesid();			// display all sales id
	void displaysalesinfobyid(int,int k =1);	// display sales by id
	int getsalessize();			// return sales size

	void sortid();				// sort by id
	void sortprice();			// sort by price

	void createuser();			// create new log in user

	int salessize();			// return occupied size	

	int getindex(string);			// get empty index

	int get_Integer();			// get integer input cin
	void displaymainsalesinfo(int k=1);	// display all sales

};
