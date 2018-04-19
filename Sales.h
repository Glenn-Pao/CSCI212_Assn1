#include <string>
#include <sstream>

//the class that sales information
class Sales
{
private:
	std::string description;
	int unitPrice;
	int quantityPurchased;
	std::string datePurchased;

public:
	Sales();					//default constructor
	Sales(std::string description, int unitPrice, int quantityPurchased, std::string dataPurchased);		//overloaded constructor
	~Sales();					//destructor

	void SetDescription(std::string description);
	std::string GetDescription();

	void SetUnitPrice(int unitPrice);
	int GetUnitPrice();	

	void SetQtyPurchased(int quantityPurchased);
	int GetQtyPurchased();

	void SetDatePurchased(std::string datePurchased);
	std::string GetDatePurchased();

	std::string ToString();
};
