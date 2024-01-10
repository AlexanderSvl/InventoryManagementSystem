#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

class Product {
public:
    // Constructor
	Product(string _ID, string _productName, int _productQuantity, float _productPrice);

    // Getter functions
    string getID() const { return ID; }
    string getProductName() const { return productName; }
    int getProductQuantity() const { return productQuantity; }
    float getProductPrice() const { return productPrice; }

    // Setter functions
    void setProductName(string newName) { productName = newName; }
    void setProductQuantity(int newQuantity) { productQuantity = newQuantity; }
    void setProductPrice(float newPrice) { productPrice = newPrice; }

    // Other functions
    float calculatePriceWithVAT(float finalPrice, float VAT);
    void printProductInfo() const;
    float calculatePriceWithDiscount(float totalPrice, float discount);

    // Operators
    bool operator==(const Product& other) const {
        return this->getID() == other.getID();
    }

    // Destructor
    ~Product() = default;
private:
	string ID;
	string productName;
	int productQuantity;
	float productPrice;
};

inline Product::Product(string _ID, string _productName, int _productQuantity, float _productPrice) 
	: ID(_ID), productName(_productName), productQuantity(_productQuantity), productPrice(_productPrice) {}

#endif