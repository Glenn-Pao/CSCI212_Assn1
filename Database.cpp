#include "Database.h"
#include <iostream>		// cin, cout
#include <fstream>		// ifstream, ofstream
#include <sstream>		// stringstream
#include <iomanip>      // std::setw
#include <stdlib.h>     /* atoi */
#include <stdio.h>

Database::Database()
{
	MAX = 50;
	for(int i = 0; i < MAX; i++)
	{
		users[i] = LoginUsers();
		salesItems[i] = Sales();
	}
	readUserDatabase(); //read file database
	readSalesDatabase();  //read file database
}
Database::~Database()
{

}
void Database::readUserDatabase()
{
	string tempString;
	
	ifstream userDatabaseIN("userdatabase.txt", ios::in); //initialise object, reading file
	if (userDatabaseIN.is_open()) //test open
	{
		int i = 0;
		while (userDatabaseIN.good())
		{
			getline (userDatabaseIN, tempString); //reading line in file
			if (tempString == "")
				break;		
			storeduserdata(tempString,i);
			i++;
		} // end while
	} // end if
	else
		cout << "Unable to open \"userdatabase.txt\"" << endl;


	userDatabaseIN.close (); //close file
}               
void Database::readSalesDatabase()
{
	string tempString;
	
	ifstream stockDatabaseIN("stockdatabase.txt", ios::in); //initialise object
	if (stockDatabaseIN.is_open()) //test open
	{
		int i = 0;
		while (stockDatabaseIN.good())
		{
			getline (stockDatabaseIN, tempString); //reading line in file
			if (tempString == "")
				break;		
			storedsalesdata(tempString,i);
			i++;
		} // end while
	} // end if
	else
		cout << "Unable to open \"userdatabase.txt\"" << endl;


	stockDatabaseIN.close (); //close file
}
void Database::writeSalesDatabase()
{
	ofstream outfile;
	outfile.open ("stockdatabase.txt");
	
	
	if (!outfile)
	{
		cout << "\E[1;31mFile opened for writing failed\E[0m" << endl;
	}
	//023:Samsung Phone XYZ:Electronics:Mobile Phone:-300:100:15:Dec:12
	for(int i=0;i<MAX-1; i++) // get the index of array to be display out
	{
		if(salesItems[i].GetDescription()!="")
		{
		outfile<<salesItems[i].GetDescription()<<":";
		outfile<<salesItems[i].GetUnitPrice()<<":";
		outfile<<salesItems[i].GetQtyPurchased()<< ":";
		outfile<<salesItems[i].GetDatePurchased()<<endl;;
		}
	}
	outfile.close();
}               
void Database::storeduserdata(string tempString,int i)
{
	string str = tempString;
	string word;
	stringstream stream(str);
	int col = 0;
	while( getline(stream, word, ';') ) //split string
	{
		//storing into the right structure element
		if(col==0)
		{
		users[i].SetLoginID(word);
		}
		else if(col==1)
		{
		users[i].SetPassword(word);
		}
		col = col +1; //next column data
	}
}	
void Database::storedsalesdata(string tempString,int i)
{
	string str = tempString;
	string word;
	stringstream stream(str);
	int col = 0;
	while( getline(stream, word, ':') ) //split string
	{
		//storing into the right structure element

		if(col==0)
		{
		salesItems[i].SetDescription(word);
		}
		else if(col==1)
		{
		salesItems[i].SetUnitPrice(atoi(word.c_str()));
		}
		else if(col==2)
		{
		salesItems[i].SetQtyPurchased(atoi(word.c_str()));
		}
		else if(col==3)
		{
		salesItems[i].SetDatePurchased(word);
		}
		col = col +1; //next column data
	}
}	
bool Database::checkLoginOK()
{
	string id,inputpw,storedpw,name;

	cout<<"	   Enter login ID :";
	cin>>id;
	cin.clear();
	cin.ignore(100,'\n');
	//cout<<"++"<<inputpw<<endl;
	inputpw = getpass("	   Enter the password: ",true); // Show asterisks
	//cout<<"**"<<inputpw<<endl;
	
	storedpw = getpw(id);
	
	if(Decrypt(inputpw)==storedpw) //doing the match
	{
	name = getname(id);
	cout<<"	   login success !"<<endl<<endl;
	cout<<"\E[1;32m	   WELCOME BACK "<<name<<"!!!\E[0m"<<endl;
	return true;
	}
	else
	{
	cout<<"	   login fail !"<<endl<<endl;
	return false;
	}
}
string Database::getname(string id)
{
	for(int i=0;i<MAX-1; i++) //check with stored user name and pw;
	{
		if(users[i].GetLoginID()==id)
		{
		return users[i].GetLoginID(); //return userid password
		}
	}
	return "rubbishvalue"; //return this not found
}
string Database::getpw(string id)
{
	for(int i=0;i<MAX-1; i++) //check with stored user name and pw;
	{
		if(users[i].GetLoginID()==id)
		{
		return users[i].GetPassword(); //return userid password
		}
	}
	return "rubbishvalue"; //return this not found
}
//password masking
int Database::getch() 
{
    int ch;
    struct termios t_old, t_new;

    tcgetattr(STDIN_FILENO, &t_old);
    t_new = t_old;
    t_new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
    return ch;
}


string Database::getpass(const char *prompt, bool show_asterisk=true)
{
  const char BACKSPACE=127;
  const char RETURN=10;

  string password;
  unsigned char ch=0;

  cout <<prompt;

  while((ch=getch())!=RETURN)
    {
       if(ch==BACKSPACE)
         {
            if(password.length()!=0)
              {
                 if(show_asterisk)
                 cout <<"\b \b";
                 password.resize(password.length()-1);
              }
         }
       else
         {
             password+=ch;
             if(show_asterisk)
                 cout <<'*';
         }
    }
  cout <<endl;
  return password;
}

//password encryption method
string Database::Encrypt(string &strTarget)
{
	int len = strTarget.length();
	char a;
	string strFinal(strTarget);

	for (int i = 0; i <= (len-1); i++)
	{
		a = strTarget.at(i); 
		int b = (int)a; //get the ASCII value of 'a'
		b += 2; //Mulitply the ASCII value by 2
		if (b > 254) { b = 254; }
		a = (char)b; //Set the new ASCII value back into the char
		strFinal.insert(i , 1, a); //Insert the new Character back into the string
	}
	string strEncrypted(strFinal, 0, len);
	strTarget = strEncrypted;
	
	return strTarget;
}

string Database::Decrypt(string strTarget)
{
	int len = strTarget.length();
	char a;
	string strFinal(strTarget);

	for (int i = 0; i <= (len-1); i++)
	{
		a = strTarget.at(i);
		int b = (int)a;
		b -= 2;

		a = (char)b;
		strFinal.insert(i, 1, a);
	}
	string strDecrypted(strFinal, 0, len);
	return strDecrypted;
}
void displaystockpile()
{
/*
	printer.printinventorydisplayheader(); //display 
	
	displaymainstockinfo();

	
	cout<<"   	Total "<<stockpilesize()<<" records"<<endl;
	cout<<"   	End of Stock Pile";
*/
}

void displaymainstockinfo(int k)
{
/*
//for sorting
//printout selected id information, with highlighting
	for(int i=0;i<MAX-1; i++) //check with stored user name and pw;
	{
		if(stockpile[i].itemid!="")
		{
		if(k==1)
		{
		cout<<"   	Stock ID         :\E[1;32m"<<stockpile[i].itemid<<"\E[0m"<<endl;
		cout<<"   	Description      :"<<stockpile[i].itemdesc<<endl;
		cout<<"   	Price       	 :"<<stockpile[i].unitprice<<endl;
		}
		else if(k==2)
		{
		cout<<"   	Stock ID         :"<<stockpile[i].itemid<<endl;
		cout<<"   	Description      :"<<stockpile[i].itemdesc<<endl;
		cout<<"   	Price      	 :\E[1;32m"<<stockpile[i].unitprice<<"\E[0m"<<endl;
		}
		

		
		}
	}
*/
}

int stockpilesize()
{/* //return stock size
 	int stockpilesize1=0;
	for(int i=0;i<MAX-1; i++) //check with stored user name and pw;
	{
		if(stockpile[i].itemid!="")
		{
		stockpilesize1++;
		}
	}
	
	return stockpilesize1;
*/
}

void addstock()
{
	/*
	string itemid;
	string itemdesc;
	int unitprice;
	int balstock;
		
	
	//getting input from user
	cout<<"";
	getline(cin, itemid);
	cout<<"   	Stock ID         :";
	getline(cin, itemid);
	
	cout<<"   	Description      :";
	getline(cin, itemdesc);
	
	cout<<"   	Price       :";
	unitprice = get_Integer();
	
	
	
	cout<<itemid<<" "<<itemdesc<<" "<<unitprice<<" "<<balstock<<endl;
	
	
	//storing to array
	int i = getstockpilesize();
	stockpile[i].itemid = itemid;
	stockpile[i].itemdesc = itemdesc;
	stockpile[i].unitprice = unitprice;
		
	writeUserDatabase(); //update stockdatabasefile
	cout<<"   	\E[1;29mStock ID "<<itemid<<" added...\E[0m"<<endl;
*/
}


int get_Integer()		// Function that asks for Integer while ignoring invalid input such as char or string
{
	stringstream ss;                // Multi-purpose stringstream
        string tempString;		// Global string variable for various uses     
	int temp;		// Initialize a temporary Integer
	tempString = "";	// Initialize tempString back to null
	ss.clear();		// reset eof bit counter in stringstream
	ss.str("");		// clear the contents in stringstream

	getline(cin, tempString);
/*
	while( cin.fail() )	// If i use cin >> temp, I will need this while loop
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n' );
	}
*/
	ss.str(tempString);	// Put the contents of tempString into ss
	ss >> temp;		// Extract the Integer out of ss to temp

	return temp;		// Return the Integer value of user's choice
}

void removestock()
{
/*	
	printer.printdeleteheader();
	cout<<endl;
	displaystockid(); //display list of stock ID to select
	string selectedid;
	cout<<"   	enter ID to remove :"; //getting input
	cin>>selectedid;
	cout<<endl;
	
	int i = getindex(selectedid);
	displaystockinfobyid(i); //display selected stock ID information
	if(i!=-1)
	{
	cout<<"   	are you sure you want to remove (Y/N) :"; //confirmation
	string yesno;
	cin>>yesno;

		if(yesno=="y")
		{
		stockpile[i].itemid = "";
		cout<<"   	\E[1;29mStock ID "<<selectedid<<" deleted...\E[0m"<<endl;
		writeUserDatabase(); //update stockdatabasefile
		}
		else
		{
		cout<<"   	\E[1;31mDelete Fail...\E[0m"<<endl;
		}
	}
*/
}

void editstock()
{
	
/*
	printer.printeditheader();
	displaystockid(); //display list of stock ID to select
	string selectedid;
	cout<<"   	enter ID to edit :"; //getting input
	cin>>selectedid;
	cout<<endl;
	
	int i = getindex(selectedid);
	displaystockinfobyid(i); //display selected stock ID information
	
	string itemid;
	string itemdesc;
	int unitprice;
		
	
	//getting input from user
	cout<<"";
	getline(cin, itemid);
	cout<<"   	Stock ID         :";
	getline(cin, itemid);
	
	cout<<"   	Description      :";
	getline(cin, itemdesc);
	
	cout<<"   	Price       :";
	unitprice = get_Integer();
	
	
	//storing to array
	stockpile[i].itemid = itemid;
	stockpile[i].itemdesc = itemdesc;
	stockpile[i].unitprice = unitprice;
		
	writeUserDatabase(); //update stockdatabasefile
	cout<<"   	\E[1;29mStock ID "<<selectedid<<" edited...\E[0m"<<endl;
*/
}

void searchstock()
{
/*
//search by any similar.
	printer.printsearchheader();
	//displaystockid(); //display list of stock ID to select
	string selectedword;
	cout<<"   	enter word to search :"; //getting input
	cin>>selectedword;
	cout<<endl;
	int found;
	for(int i = 0; i < MAX- 1; i++)
     	{
     	if(stockpile[i].itemid !="")
		{
		//find all similar search word
			found = stockpile[i].itemid.find(selectedword);
			if(found<stockpile[i].itemid.length())
			{
				displaystockinfobyid(i,1);
			}
		
			found = stockpile[i].itemdesc.find(selectedword);
			if(found<stockpile[i].itemdesc.length())
			{
				displaystockinfobyid(i,2);
			}
		}
	
	}
*/
}

void sortstock()
{
/*
//different sort option
	printer.printsortheader();
	
	cout<<"  	1) sort by id"<<endl;
	cout<<"  	2) sort by price"<<endl;
	
	
	int choice;
	cout<<endl<<"  	enter choice :";
	cin>>choice;
	cout<<endl;
	
	if(choice==1)
	{
		sortid();
		displaymainstockinfo();
		cout<<"   	sorted by Stock ID"<<endl;
	}
	else if(choice==2)
	{
		sortprice();
		displaymainstockinfo(2);
		cout<<"   	sorted by Price"<<endl;
	}
*/
	
}

void sortid()
{
/*
 	StockPile temp;
     for(int i = 0; i < MAX- 1; i++)
     {
          for (int j = i + 1; j < MAX; j++)
          {
		  if(stockpile[j].itemid !="")
		  {
		  if (stockpile[ i ].unitprice > stockpile[ j ].unitprice)  //comparing 
		       {
		             temp = stockpile[ i ];    //swapping entire struct
		             stockpile[ i ] = stockpile[ j ];
		             stockpile[ j ] = temp;
		       }
		  }
          }	

     }
*/
}

void sortprice()
{
/*
 	StockPile temp;
     for(int i = 0; i < MAX- 1; i++)
     {
          for (int j = i + 1; j < MAX; j++)
          {
          
		  if(stockpile[j].itemid !="")
		  {
		  if (stockpile[ i ].unitprice > stockpile[ j ].unitprice)  //comparing 
		       {
		             temp = stockpile[ i ];    //swapping entire struct
		             stockpile[ i ] = stockpile[ j ];
		             stockpile[ j ] = temp;
		       }
		  }
          }	

     }
*/
}



void displaystockid()
{
/*
	for(int i=0;i<MAX-1; i++) //check with stored user name and pw;
	{
		if(stockpile[i].itemid!="")
		{
		cout<<"   	Stock ID         :\E[1;32m"<<stockpile[i].itemid<<"\E[0m"<<endl;
		}
	}
	cout<<endl;
*/
}

void displaystockinfobyid(int id,int k)
{
/*
//printout selected id information, with highlighting
	int i=id;
	if(i!=-1)
	{
	if(k==1)
	{
	cout<<"   	Stock ID         :\E[1;32m"<<stockpile[i].itemid<<"\E[0m"<<endl;
	cout<<"   	Description      :"<<stockpile[i].itemdesc<<endl;
	cout<<"   	Price      	 :"<<stockpile[i].unitprice<<endl<<endl;
	}
	else if(k==2)
	{
	cout<<"   	Stock ID         :"<<stockpile[i].itemid<<endl;
	cout<<"   	Description      :\E[1;32m"<<stockpile[i].itemdesc<<"\E[0m"<<endl;
	cout<<"   	Price            :"<<stockpile[i].unitprice<<endl<<endl;
	}
	
	}
	else
	{
	cout<<"   	\E[1;31mNo such Stock ID...\E[0m"<<endl;
	}
*/
}

int getindex(string id)
{
/*
	int i=-1;
	for(int i=0;i<MAX-1; i++) // get the index of array to be display out
	{
		if(stockpile[i].itemid==id)
		{
		return i;
		}
	}
	return i;
*/
}

int getstockpilesize()
{
/*
	int result=0;
	for(int i=0;i<MAX-1; i++) //check with stored user name and pw;
	{
		if(stockpile[i].itemid=="")
		{
		return i;
		}
	}
	return result;
*/

}

void createuser()
{
	/*printer.printadduserheader(); //display 
	
	string loginID1;
	string pw1;			
		
	cout<<"Enter login ID:";
	cin>>loginID1;
	cout<<"Enter password:";
	cin>>pw1;
	
	
	int size=0;
	for(int i=0;i<MAX-1; i++) //check with stored user name and pw;
	{
		if(stockpile[i].itemid=="")
		{
		size = i;
		break;
		}
	}
	
	users[size].loginID = loginID1;
	users[size].pw = pw1;
	
	
	ofstream myfile;
	myfile.open ("userdatabase.txt", ios::out | ios::app ); //append to file
	
	myfile<<loginID1<<";"<<Decrypt(pw1)<<endl;
	myfile.close();
	
	cout<<"\E[1;32mnew user "<<loginID1<<" added !!!\E[0m"<<endl;
*/
}


