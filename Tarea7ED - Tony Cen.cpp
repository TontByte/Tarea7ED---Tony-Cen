// Tarea7ED - Tony Cen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stdexcept>
#include "BSTDictionary.h"
#include "Dictionary.h"
#include "List.h"

using std::cout;
using std::string;
using std::runtime_error;
using std::endl;

int main(){
    // 1. Create a dictionary mapping integer keys to string values
    BSTDictionary<int, string> dict;

    cout << "--- Testing BSTDictionary ---" << endl;
    cout << "Is empty? " << (dict.isEmpty() ? "Yes" : "No") << endl;

    // 2. Test Insert
    cout << "\nInserting elements..." << endl;
    dict.insert(10, "Apple");
    dict.insert(5, "Banana");
    dict.insert(20, "Cherry");
    dict.print();
    cout << endl;
    dict.getKeys()->print();
    dict.getValues()->print();

    cout << "Is empty? " << (dict.isEmpty() ? "Yes" : "No") << endl;

    // 3. Test Contains and GetValue
    cout << "\nRetrieving elements:" << endl;
    if (dict.contains(10)) {
        cout << "Key 10 maps to: " << dict.getValue(10) << endl;
    }
    if (dict.contains(5)) {
        cout << "Key 5 maps to: " << dict.getValue(5) << endl;
    }

    // 4. Test SetValue (Updating an existing key)
    cout << "\nUpdating key 5..." << endl;
    dict.setValue(5, "Blueberry");
    cout << "Key 5 now maps to: " << dict.getValue(5) << endl;
    dict.print();

    // 5. Test Remove
    cout << "\nRemoving key 10..." << endl;
    string removedValue = dict.remove(10);
    cout << "Removed value: " << removedValue << endl;
    cout << "Does it still contain key 10? " << (dict.contains(10) ? "Yes" : "No") << endl;
    dict.print();

    // 6. Test Exception Handling
    cout << "\nTesting exception handling..." << endl;
    try {
        dict.getValue(99); // This key doesn't exist
    }
    catch (const std::runtime_error& e) {
        cout << "Caught expected exception: " << e.what() << endl;
    }

    try {
        dict.insert(5, "Duplicate Banana"); // Key 5 already exists
    }
    catch (const std::runtime_error& e) {
        cout << "Caught expected exception: " << e.what() << endl;
    }

    // 7. Test Clear
    cout << "\nClearing dictionary..." << endl;
    dict.clear();
    cout << "Is empty after clear? " << (dict.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
