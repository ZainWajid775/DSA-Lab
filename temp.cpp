#include <iostream>
#include <string>
using namespace std;

// Custom comparison function
bool customCompare(const string& a, const string& b) {
    // Split into alphabetic and numeric parts
    string alphaA = a.substr(0, 3); // First 3 characters
    string alphaB = b.substr(0, 3);
    string numA = a.substr(3);      // Remaining characters
    string numB = b.substr(3);

    // Compare alphabetic parts first
    if (alphaA != alphaB)
        return alphaA > alphaB; // Higher alphabetic part means "greater"

    // If alphabetic parts are equal, compare numeric parts
    return stoi(numA) > stoi(numB);
}

int main() {
    string a = "aaa123";
    string b = "abv123";

    bool result = customCompare(a, b);
    cout << "Custom result: " << result << endl;

    return 0;
}
