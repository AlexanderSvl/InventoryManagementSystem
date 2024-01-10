#include "Contract.h"
#include <iostream>

void Contract::printContractInfo() const {
	cout << "\nContract ID: " << ID << "\nContract starting date: " << startingDate 
		<< "\nContract expiration date: " << expirationDate << "\nContract terms: " << contractTerms << endl;
}