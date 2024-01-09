#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <sstream>
#include <iomanip>

#include "Supplier.h"
#include "Product.h"
#include "Contract.h"

using namespace std;
int counter = 0;

const char* boldCode = "\033[1m";
const char* greenCode = "\033[32m";
const char* redCode = "\033[31m";
const char* resetCode = "\033[0m";

string generateID();

int main() {
	vector<Product> products;
	vector<Supplier> suppliers;
	vector<Contract> contracts;

	/*cout << generateID() << endl;
	std::chrono::seconds duration(2);
	std::this_thread::sleep_for(duration);
	cout << generateID() << endl;
	std::chrono::seconds duration(2);
	std::this_thread::sleep_for(duration);	cout << generateID() << endl;
	cout << generateID() << endl;*/

	cout << "|======| Inventory system |======|" << endl;
	cout << "\n  |==|  1 - Add product";
	cout << "\n  |==|  2 - Add supplier";
	cout << "\n  |==|  3 - Display products";
	cout << "\n  |==|  4 - Display suppliers";
	cout << "\n  |==|  5 - Display all products of a supplier";
	cout << "\n  |==|  6 - Display contract of a supplier";
	cout << "\n  |==|  0 - Exit the program\n\n";

	int option;
	cout << redCode << boldCode << "\nChoose an option: " << resetCode;
	cin >> option;

	while (option != 0)
	{
		switch (option)
		{
		case 1: {
			string ID, name;
			int quantity;
			float price;

			ID = generateID();

			cout << "\n\Generated product ID: " << boldCode << greenCode << ID << resetCode;

			cout << "\n\nEnter product name: ";
			cin.ignore();
			getline(cin, name);

			cout << "\nEnter product quantity: ";
			cin >> quantity;

			cout << "\nEnter product price: ";
			cin >> price;

			products.push_back(Product(ID, name, quantity, price));
			break;
		}
		case 2: {
			string ID, name, email, phoneNumber, contractID, startingDate, expirationDate;

			ID = generateID();
			contractID = generateID();

			cout << "\nGenerated supplier ID: " << boldCode << greenCode << ID << resetCode;
			cout << "\nGenerated supplier contract ID: " << boldCode << greenCode << contractID << resetCode;;

			cout << "\n\nEnter supplier name: ";
			cin.ignore();
			getline(cin, name);

			cout << "\nEnter supplier email: ";
			getline(cin, email);

			cout << "\nEnter supplier phone number: ";
			getline(cin, phoneNumber);

			cout << "\nEnter contract starting date: (DD/MM/YYYY) ";
			getline(cin, startingDate);

			cout << "\nEnter contract expiration date: (DD/MM/YYYY) ";
			getline(cin, expirationDate);

			suppliers.push_back(Supplier(ID, name, email, phoneNumber, contractID));
			contracts.push_back(Contract(contractID, startingDate, expirationDate, ID));
			break;
		}
		case 3: {
			if (!products.empty()) {
				int counter = 1;
				for (Product product : products) {
					cout << "\n|===| #" << counter << " |===|\n";
					product.printProductInfo();
					cout << "\n";
					counter++;
				}
			}
			else {
				cout << "\nNo product to print info for.\n";
			}

			break;
		}
		case 4: {
			for (Supplier supplier : suppliers) {
				string id = supplier.getSupplierContractID();

				auto it = std::find_if(contracts.begin(), contracts.end(), [id](const Contract contract) {
					return contract.getID() == id;
					});
					
				if (it != contracts.end()) {
					const Contract& foundContract = *it;
					cout << "\n";
					supplier.printSupplierInfo(foundContract);
					cout << "\n";
				}
				else {
					cout << "Contract not found for supplier with ID: " << supplier.getID() << std::endl;
				}
			}

			break;
		}
		case 5: {
			string supplierID;
			cout << "\nSupplier ID: ";
			cin.ignore();
			getline(cin, supplierID);

			auto it = std::find_if(suppliers.begin(), suppliers.end(), [supplierID](const Supplier supplier) {
				return supplier.getID() == supplierID;
			});

			if (it != suppliers.end()) {
				const Supplier& supplier = *it;

				if (!supplier.getSupplierProducts().empty()) {
					cout << "\nAll products of supplier #" << supplierID << ":\n\n";

					for (const Product& products : supplier.getSupplierProducts())
					{
						products.printProductInfo();
					}
				}
				else {
					cout << "\nSupplier #" << supplierID << " has no products!\n";
				}
			}
			else {
				cout << "\nNo supplier with ID #" << supplierID << " found!\n";
			}

			break;
		}
		case 6: {
			string supplierID;
			cout << "\nSupplier ID: ";
			cin.ignore();
			getline(cin, supplierID);

			auto it = std::find_if(suppliers.begin(), suppliers.end(), [supplierID](const Supplier supplier) {
				return supplier.getID() == supplierID;
			});

			if (it != suppliers.end()) {
				const Supplier supplier = *it;
				string IDToSearchFor = supplier.getSupplierContractID();

				auto itt = std::find_if(contracts.begin(), contracts.end(), [IDToSearchFor](const Contract& contract) {
					return contract.getID() == IDToSearchFor;
				});

				if (itt != contracts.end()) {
					const Contract foundContract = *itt;
					
					foundContract.printContractInfo();
				}
				else {
					cout << "Contract not found for supplier with ID: " << supplier.getID() << std::endl;
				}
			}
			else {
				cout << "\nNo supplier with ID #" << supplierID << " found!\n";
			}

			break;
		}

		}

		cout << redCode << boldCode << "\nChoose an option: " << resetCode;
		cin >> option;
	}

	cout << "dfd";
}

string generateID() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 15);

	std::stringstream ss;
	const char* hexChars = "0123456789abcdef";

	for (int i = 0; i < 32; ++i) {
		if (i == 8 || i == 12 || i == 16 || i == 20) {
			ss << "-";
		}
		ss << hexChars[dis(gen)];
	}

	return ss.str();
}