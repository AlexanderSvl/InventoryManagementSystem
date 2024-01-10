#include "Product.h"
#include <iostream>

float Product::calculatePriceWithVAT(float finalPrice, float VAT) {
	return finalPrice * (1 + VAT/100);
}

void Product::printProductInfo() const {
	cout << "Product ID: " << ID << "\nProduct name: " << productName << "\nProduct price: "
		<< productPrice << "\nProduct quantity: " << productQuantity;
}

float Product::calculatePriceWithDiscount(float totalPrice, float discount) {
	return totalPrice - (totalPrice * discount / 100);
}