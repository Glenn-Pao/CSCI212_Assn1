#include <string>

class LoginUsers
{
private:
	std::string loginID;			//ID to login
	std::string pw;				//password for login
public:
	LoginUsers();
	LoginUsers(std::string ID, std::string pwd);
	~LoginUsers();

	void SetLoginID(std::string ID);
	std::string GetLoginID();

	void SetPassword(std::string pwd);
	std::string GetPassword();
		
	std::string ToString();
};
