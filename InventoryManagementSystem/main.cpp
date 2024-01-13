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
float balance = 0.00;

const char* boldCode = "\033[1m";
const char* greenCode = "\033[32m";
const char* redCode = "\033[31m";
const char* resetCode = "\033[0m";

string generateID();

int main() {
	vector<Product> products;
	vector<Supplier> suppliers;
	vector<Contract> contracts;

	cout << "|======| Inventory system |======|" << endl;
	cout << "\n  |==|   0 - Exit the program";
	cout << "\n  |==|   1 - Add product";
	cout << "\n  |==|   2 - Add supplier (contract included)";
	cout << "\n  |==|   3 - Display products";
	cout << "\n  |==|   4 - Display suppliers";
	cout << "\n  |==|   5 - Display all products of a supplier";
	cout << "\n  |==|   6 - Display contract of a supplier";
	cout << "\n  |==|   7 - Edit contract of a supplier";
	cout << "\n  |==|   8 - Edit supplier information";
	cout << "\n  |==|   9 - Edit product information";
	cout << "\n  |==|  10 - Sell product";
	cout << "\n  |==|  11 - Remove supplier";
	cout << "\n  |==|  12 - Remove product";
	cout << "\n  |==|  13 - Show balance\n\n";

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
			string ID, name, email, phoneNumber, contractID, startingDate, expirationDate, contractTerms;

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

			cout << "\nEnter contract starting date: (DD/MM/YYYY) ";
			getline(cin, startingDate);

			cout << "\nEnter contract terms: ";
			getline(cin, contractTerms);

			suppliers.push_back(Supplier(ID, name, email, phoneNumber, contractID));
			contracts.push_back(Contract(contractID, startingDate, expirationDate, contractTerms, ID));
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
			if (!suppliers.empty()) {
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
			}
			else {
				cout << "\nNo product to print info for.\n";
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
		case 7: {
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
					string newStartingDate, newExpirationDate, newContractTerms;

					cout << "\nNew contract starting date: ";
					getline(cin, newStartingDate);

					cout << "\nNew contract expiration date: ";
					getline(cin, newExpirationDate);

					cout << "\nNew contract terms: ";
					getline(cin, newContractTerms);

					itt->setStartingDate(newStartingDate);
					itt->setExpirationDate(newExpirationDate);
					itt->setContractTerms(newContractTerms);

					cout << "\nUpdated contract information:\n";
					itt->printContractInfo();
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
		case 8: {
			string supplierID;
			cout << "\nSupplier ID: ";
			cin.ignore();
			getline(cin, supplierID);

			auto it = std::find_if(suppliers.begin(), suppliers.end(), [supplierID](const Supplier supplier) {
				return supplier.getID() == supplierID;
			});

			if (it != suppliers.end()) {
				string newName, newEmail, newPhoneNumber;

				cout << "\nNew supplier name: ";
				getline(cin, newName);

				cout << "\nNew supplier email: ";
				getline(cin, newEmail);

				cout << "\nNew supplier phone number: ";
				getline(cin, newPhoneNumber);

				it->setSupplierName(newName);
				it->setSupplierEmail(newEmail);
				it->setSupplierPhoneNumber(newPhoneNumber);
			}
			else {
				cout << "\nNo supplier with ID #" << supplierID << " found!\n";
			}

			break;
		}
		case 9: {
			string productID;
			cout << "\Product ID: ";
			cin.ignore();
			getline(cin, productID);

			auto it = std::find_if(products.begin(), products.end(), [productID](const Product product) {
				return product.getID() == productID;
			});

			if (it != products.end()) {
				string newName;
				int newQuantity;
				float newPrice;

				cout << "\nNew product name: ";
				getline(cin, newName);

				cout << "\nNew product quantity: ";
				cin >> newQuantity;

				cout << "\nNew productPrice: ";
				cin >> newPrice;

				it->setProductName(newName);
				it->setProductQuantity(newQuantity);
				it->setProductPrice(newPrice);
			}
			else {
				cout << "\nNo product with ID #" << productID << " found!\n";
			}

			break;
		}
		case 10: {
			string productID;
			cout << "\nProduct ID: ";
			cin.ignore();
			getline(cin, productID);

			auto it = std::find_if(products.begin(), products.end(), [productID](const Product product) {
				return product.getID() == productID;
				});

			if (it != products.end()) {
				int quantityToSell;
				float VAT;
				float discount;

				cout << "\nQuantity to sell: ";
				cin >> quantityToSell;

				if (it->getProductQuantity() - quantityToSell >= 0) {
					cout << "\nVAT (0-100): ";
					cin >> VAT;

					cout << "\nDiscount (0-100): ";
					cin >> discount;

					float totalSellingPrice = quantityToSell * it->getProductPrice();
					float totalSellingPriceWithDiscount = it->calculatePriceWithDiscount(totalSellingPrice, discount);
					float totalSellingPriceWithVAT = it->calculatePriceWithVAT(totalSellingPriceWithDiscount, VAT);

					balance += totalSellingPriceWithVAT;

					cout << "\nID: " << productID << "\nSold quantity: " << quantityToSell
						<< "\nTotal selling price (including discount and VAT): " << std::fixed
						<< std::setprecision(2) << totalSellingPriceWithVAT << endl;

					it->setProductQuantity(it->getProductQuantity() - quantityToSell);
				}
				else {
					cout << "\nNot enough quantity of product with ID: " << productID << " available.";
				}
			}
			else {
				cout << "\nNo product with ID #" << productID << " found!\n";
			}

			break;
		}
		case 11: {
			string supplierID;
			cout << "\nSupplier ID: ";
			cin.ignore();
			getline(cin, supplierID);

			auto it = std::find_if(suppliers.begin(), suppliers.end(), [supplierID](const Supplier& supplier) {
				return supplier.getID() == supplierID;
				});

			if (it != suppliers.end()) {
				suppliers.erase(it);
				std::cout << "Supplier with ID #" << supplierID << " removed.\n";
			}
			else {
				cout << "\nNo supplier with ID #" << supplierID << " found!\n";
			}

			break;
		}
		case 12: {
			string productID;
			cout << "\nProduct ID: ";
			cin.ignore();
			getline(cin, productID);

			auto it = std::find_if(products.begin(), products.end(), [productID](const Product& product) {
				return product.getID() == productID;
				});

			if (it != products.end()) {
				products.erase(it);
				std::cout << "Product with ID #" << productID << " removed.\n";
			}
			else {
				std::cout << "No product with ID #" << productID << " found!\n";
			}

			break;
		}
		case 13: {
			cout << "\nBalance: " << boldCode << greenCode << balance << resetCode;
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