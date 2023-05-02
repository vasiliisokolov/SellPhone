#include <iostream>
#include <vector>
#include <string>

class Contact
{
	std::string name;
	std::string number;

public:
	void setName(std::string& newName)
	{
		name = newName;
	}

	void setNumber(std::string& newNumber)
	{
		number = newNumber;
	}

	std::string getName()
	{
		return name;
	}

	std::string getNumber()
	{
		return number;
	}
};

class Phone
{
	std::vector<Contact> phoneBook;
	std::string find(std::string& buffer)
	{
		for (int i = 0; i < phoneBook.size(); i++)
		{
			if (buffer == phoneBook[i].getName())
			{
				return phoneBook[i].getNumber();
			}

			if (buffer == phoneBook[i].getNumber())
			{
				return phoneBook[i].getName();
			}

			return "Invalid number or name!";
		}
	}

public:
	void addContact()
	{
		std::string name, number;
		Contact contact;
		std::cout << "Enter the thelephone number: ";
		std::cin >> number;
		contact.setNumber(number);
		std::cout << "Enter the name of the contact: ";
		std::cin >> name;
		contact.setName(name);
		phoneBook.push_back(contact);
	}

	void callContact()
	{
		std::string buffer;
		std::cout << "Enter contact's name or number: ";
		std::cin >> buffer;
		std::cout << "Call" << std::endl;
		if (buffer[0] == '+')
		{
			std::cout << find(buffer) << std::endl;
			std::cout << buffer << std::endl;
		}
		else
		{
			std::cout << buffer << std::endl;
			std::cout << find(buffer) << std::endl;
		}
	}

	void smsContact()
	{
		std::string buffer;
		std::cout << "Enter contact's name or number: ";
		std::cin >> buffer;
		std::cout << "Send to: " << std::endl;
		if (buffer[0] == '+')
		{
			std::cout << find(buffer) << std::endl;
			std::cout << buffer << std::endl;
		}
		else
		{
			std::cout << buffer << std::endl;
			std::cout << find(buffer) << std::endl;
		}
		std::cout << "Enter the message: " << std::endl;
		std::getline(std::cin, buffer);
	}
};

enum operation
{
	add = 0,
	call = 1,
	sms = 2,
	ex = 3
};
int main()
{
	std::cout << "YouPhone." << std::endl;
	Phone phone;
	int op;
	while (true)
	{
		std::cout << "Choose the operation: ";
		std::cin >> op;
		if (op > 3 || op < 0)
		{
			std::cerr << "Error! Wrong operation! Try again!" << std::endl;
		}
		else
		{
			switch (op)
			{
			case operation::add:
				phone.addContact();
				break;
			case operation::call:
				phone.callContact();
				break;
			case operation::sms:
				phone.smsContact();
				break;
			case operation::ex:

				return 0;

			}
		}
	}
}
