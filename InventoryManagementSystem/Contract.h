#ifndef CONTRACT_H
#define CONTRACT_H

#include <string>

using namespace std;

class Contract {
public:
    // Constructor
    Contract(string _ID, string _startingDate, string _expirationDate, string _supplierID);

    // Getter functions
    string getID() const { return ID; }
    string getStartingDate() const { return startingDate; }
    string getExpirationDate() const { return expirationDate; }
    string getSupplierID() const { return supplierID; }

    // Setter functions
    void setStartingDate(string newStartingDate) { startingDate = newStartingDate; }
    void setExpirationDate(string newExpirationDate) { expirationDate = newExpirationDate; }

    // Other functions
    void printContractInfo() const;

    // Destructor
    ~Contract() = default;
private:
    const string ID;
    string startingDate;
    string expirationDate;
    string supplierID;
};

inline Contract::Contract(string _ID, string _startingDate, string _expirationDate, string _supplierID) : ID(_ID), startingDate(_startingDate), expirationDate(_expirationDate), supplierID(_supplierID) {};

#endif