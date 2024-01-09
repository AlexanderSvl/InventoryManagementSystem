#include <iostream>
#include <algorithm>

#include "Supplier.h"
#include "Contract.h"

using namespace std;

void Supplier::addProduct(Product product) {
	if (find(products.begin(), products.end(), product) == products.end()) {
		products.push_back(product);
		cout << "Product " << product.getProductName() << " added.";
	}
	else {
		cout << "Product " << product.getProductName() << " already exists.";
	}
}

void Supplier::removeProduct(string ID) {
    auto isFound = std::find_if(products.begin(), products.end(), [ID](const Product product) {
        return product.getID() == ID;
    });

    if (isFound != products.end()) {
        products.erase(isFound);
        std::cout << "Product with ID " << ID << " removed.\n";
    }
    else {
        std::cout << "Product with ID " << ID << " not found.\n";
    }
}

void Supplier::printSupplierInfo(Contract contract) {
    cout << "Supplier ID: " << ID << "\nSupplier name: " << supplierName << "\nSupplier email: "
        << supplierEmail << "\nSupplier phone number: " << supplierPhoneNumber << "\nSupplier contract ID: " 
        << supplierContractID << "\nSupplier contract starting date: " << contract.getStartingDate() << "\nSupplier contract expirations date: "
        << contract.getExpirationDate();
}

void Supplier::displayAllProducts() {
    for (const auto& product : products)
    {
        product.printProductInfo();
    }
}