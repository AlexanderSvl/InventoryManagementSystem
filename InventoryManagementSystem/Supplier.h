#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>
#include <vector>
#include "Product.h"
#include "Contract.h"

using namespace std;

class Supplier {
public:
    // Constructor
	Supplier(string _ID, string _supplierName, string _supplierEmail, string _supplierPhoneNumber, string _supplierContractID);

    // Getter functions
    string getID() const { return ID; }
    string getSupplierName() const { return supplierName; }
    string getSupplierEmail() const { return supplierEmail; }
    string getSupplierPhoneNumber() const { return supplierPhoneNumber; }
    string getSupplierContractID() const { return supplierContractID; }
    vector<Product> getSupplierProducts() const { return products; }

    // Setter functions
    void setSupplierName(string newName) { supplierName = newName; }
    void setSupplierEmail(string newEmail) { supplierEmail = newEmail; }
    void setSupplierPhoneNumber(string newPhoneNumber) { supplierPhoneNumber = newPhoneNumber; }

    // Other functions
    void addProduct(Product product);
    void removeProduct(string ID);
    void displayAllProducts();
    void printSupplierInfo(Contract contract);

    // Destructor
    ~Supplier() = default;
private:
	const string ID;
	string supplierName;
	string supplierEmail;
	string supplierPhoneNumber;
    string supplierContractID;
    vector<Product> products;
};

inline Supplier::Supplier(string _ID, string _supplierName, string _supplierEmail, string _supplierPhoneNumber, string _supplierContractID) 
	: ID(_ID), supplierName(_supplierName), supplierEmail(_supplierEmail), supplierPhoneNumber(supplierPhoneNumber), supplierContractID(_supplierContractID) { }

#endif
