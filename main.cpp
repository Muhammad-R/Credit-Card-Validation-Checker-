#include <algorithm>   // transform()
#include <cctype>      // toupper(), tolower()
#include <functional>  // ptr_fun()
#include <iostream>    // cin, cout
#include <string>      // getline(), string

using namespace std;

bool NumStr(const string& s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int main() {
    string cc;
    
    cout << "This program uses the Luhn Algorithm to validate a CC number." << endl;
    cout << "Enter 'exit' to quit." << endl;
    
    while (true) {
        
        cout << "Please enter a CC number for validation: ";
        
        //Using STL 
        getline( cin, cc );
        transform( cc.begin(), cc.end(), cc.begin(), ptr_fun <int, int> ( toupper ) );
        transform( cc.begin(), cc.end(), cc.begin(), ptr_fun <int, int> ( tolower ) );
          
          
        if (cc == "exit" )
            break;
        
        else if (!NumStr(cc)) {
            cout << "Bad input! ";
            continue;
        }
            
        int len = cc.length();
        int d = 0;
        
        // Step 1 is to double every second digit, starting from the right. If it
        // results in a two digit number, add both the digits to obtain a single
        // digit number. Finally, sum all the answers to obtain 'doubleEvenSum'.   
        
        for (int i = len - 2; i >= 0; i = i - 2) {
            int dbl = ((cc[i] - 48) * 2);
            if (dbl > 9) {
                dbl = (dbl / 10) + (dbl % 10);
            }
            d += dbl;
        }
        
        // Step 2 is to add every odd placed digit from the right to the value
    
        
        for (int i = len - 1; i >= 0; i = i - 2) {
            d += (cc[i] - 48);
        }
        
        // Step 3 is to check if the final variable d is a multiple of 10.
        // If yes, it is a valid CC number. 
        
        cout << (d % 10 == 0 ? "Valid!" : "Invalid!") << endl;
        
        continue;        
    }

    return 0;
}