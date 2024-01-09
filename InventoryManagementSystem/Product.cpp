#include "Product.h"
#include <iostream>

float Product::calculatePriceWithVAT(float VAT) {
	return productPrice * (1 + VAT);
}

void Product::printProductInfo() const {
	cout << "Product ID: " << ID << "\nProduct name: " << productName << "\nProduct price: "
		<< productPrice << "\nProduct quantity: " << productQuantity;
}

float Product::calculatePriceWithDiscount(float discount) {
	return productPrice - discount * productPrice;
}

float Product::calculateTotalPrice() {
	return productQuantity * productPrice;
}