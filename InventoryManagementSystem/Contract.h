#ifndef CONTRACT_H
#define CONTRACT_H

#include <string>

using namespace std;

class Contract {
public:
    // Constructor
    Contract(string _ID, string _startingDate, string _expirationDate, string contractTerms, string _supplierID);

    // Getter functions
    string getID() const { return ID; }
    string getStartingDate() const { return startingDate; }
    string getExpirationDate() const { return expirationDate; }
    string getSupplierID() const { return supplierID; }
    string getContractTerms() const { return contractTerms; }

    // Setter functions
    void setStartingDate(string newStartingDate) { startingDate = newStartingDate; }
    void setExpirationDate(string newExpirationDate) { expirationDate = newExpirationDate; }
    void setContractTerms(string newContractTerms) { contractTerms = newContractTerms; }

    // Other functions
    void printContractInfo() const;

    // Destructor
    ~Contract() = default;
private:
    const string ID;
    string startingDate;
    string expirationDate;
    string contractTerms;
    string supplierID;
};

inline Contract::Contract(string _ID, string _startingDate, string _expirationDate, string _contractTerms, string _supplierID) 
    : ID(_ID), startingDate(_startingDate), expirationDate(_expirationDate), contractTerms(_contractTerms), supplierID(_supplierID) {};

#endif