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
using std::cin;

string getStringValue(string datoDeseado, bool text) {
    if (text) {
        cout << datoDeseado << "(ingrese aqui): ";
    }
    string value;
    getline(cin, value);
    return value;
}

int getNumValue(int maxIndex, int minIndex, bool text) {
    if (maxIndex < 0 || minIndex > maxIndex) {
        throw runtime_error("Implementacion erronea de getNumValue");
    }

    int res;
    bool gotten = false;

    while (!gotten) {
        if (text) {
            cout << "Ingrese un numero entero entre " << minIndex << " y " << maxIndex << ": ";
        }
        cin >> res;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Seleccion invalida. Volver a intentar." << endl;
        }
        else if (res < 0 || res > maxIndex || res < minIndex) {
            cin.ignore(1000, '\n');
            cout << "Seleccion invalida. Volver a intentar." << endl;
        }
        else {
            cin.ignore(1000, '\n');
            gotten = true;
            return res;
        }
    }
}

void menu(BSTDictionary<int, string>* d1, BSTDictionary<int, string>* d2) {
    bool stop = false;
    int option = 0;
    int selectedDictionary = 0;
    while (!stop) {
        try {
            cout << endl;
            if (option == 0) {
                cout << "Diccionario 1: ";
                d1->print();
                cout << endl;
                cout << "Diccionario 2: ";
                d2->print();
                cout << endl;
                cout << "Ingrese la opcion deseada: " << endl;
                cout << "1. insert()" << endl;
                cout << "2. remove()" << endl;
                cout << "3. getValue()" << endl;
                cout << "4. setValue()" << endl;
                cout << "5. contains()" << endl;
                cout << "6. clear()" << endl;
                cout << "7. getKeys()" << endl;
                cout << "8. getValues()" << endl;
                cout << "9. getSize()" << endl;
                cout << "10. update()" << endl;
                cout << "11. zip()" << endl;
                cout << "12. Salir" << endl;
                option = getNumValue(12, 1, true);

                if (option != 12) {
                    cout << endl;
                    cout << "Ingrese el digito del diccionario que desea editar (1-diccionario1, 2-diccionario2):" << endl;
                    selectedDictionary = getNumValue(2, 1, false);
                }
            }
            else if (option == 1) {
                cout << "Insercion de dato" << endl;
                cout << "Ingrese la llave: ";
                int key = getNumValue(2147483647, -2147483648, false);
                string value = getStringValue("Valor", true);
                Pair<int, string> p(key, value);
                cout << "Se va insertar " << p << " al diccionario " << selectedDictionary << endl;
                if (selectedDictionary == 1) {
                    d1->insert(key, value);
                }
                else if (selectedDictionary == 2) {
                    d2->insert(key, value);
                }
                else {
                    throw runtime_error("Diccionario seleccionado invalido");
                }
                option = 0;
            }
            else if (option == 2) {
                cout << "Eliminar dato" << endl;
                cout << "Ingrese la llave: ";
                int key = getNumValue(2147483647, -2147483648, false);
                if (selectedDictionary == 1) {
                    string v = d1->remove(key);
                    cout << "Se elimina " << v << endl;
                }
                else if (selectedDictionary == 2) {
                    string v = d2->remove(key);
                    cout << "Se elimina " << v << endl;
                }
                else {
                    throw runtime_error("Diccionario seleccionado invalido");
                }
                option = 0;
            }
            else if (option == 3) {
                cout << "Conseguir valor" << endl;
                cout << "Ingrese la llave: ";
                int key = getNumValue(2147483647, -2147483648, false);
                if (selectedDictionary == 1) {
                    string v = d1->getValue(key);
                    cout << "Valor encontrado: " << v << endl;
                }
                else if (selectedDictionary == 2) {
                    string v = d2->getValue(key);
                    cout << "Valor encontrado: " << v << endl;
                }
                else {
                    throw runtime_error("Diccionario seleccionado invalido");
                }
                option = 0;
            }
            else if (option == 4) {
                cout << "Establecer valor" << endl;
                cout << "Ingrese la llave: ";
                int key = getNumValue(2147483647, -2147483648, false);
                string value = getStringValue("Valor", true);
                Pair<int, string> p(key, value);
                cout << "Se cambia el valor de la llave " << key << " a " << value << endl;
                if (selectedDictionary == 1) {
                    d1->setValue(key, value);
                }
                else if (selectedDictionary == 2) {
                    d2->setValue(key, value);
                }
                else {
                    throw runtime_error("Diccionario seleccionado invalido");
                }
                option = 0;
            }
            else if (option == 5) {
                cout << "Buscar llave" << endl;
                cout << "Ingrese la llave: ";
                int key = getNumValue(2147483647, -2147483648, false);
                cout << "0 = falso, 1 = verdadero" << endl;
                if (selectedDictionary == 1) {
                    cout << "La llave " << key << " se encuentra en d1: " << d1->contains(key) << endl;
                }
                else if (selectedDictionary == 2) {
                    cout << "La llave " << key << " se encuentra en d2: " << d2->contains(key) << endl;
                }
                else {
                    throw runtime_error("Diccionario seleccionado invalido");
                }
                option = 0;
            }
            else if (option == 6) {
                if (selectedDictionary == 1) {
                    cout << "Eliminacion de los datos de d1." << endl;
                    d1->clear();
                }
                else if (selectedDictionary == 2) {
                    cout << "Eliminacion de los datos de d2." << endl;
                    d2->clear();
                }
                else {
                    throw runtime_error("Diccionario seleccionado invalido");
                }
                option = 0;
            }
            else if (option == 7) {
                cout << "Conseguir llaves" << endl;
                if (selectedDictionary == 1) {
                    List<int>* keys = d1->getKeys();
                    cout << "Llaves de d1: ";
                    keys->print();
                    delete keys;
                }
                else if (selectedDictionary == 2) {
                    List<int>* keys = d2->getKeys();
                    cout << "Llaves de d2: ";
                    keys->print();
                    delete keys;
                }
                else {
                    throw runtime_error("Diccionario seleccionado invalido");
                }
                option = 0;
            }
            else if (option == 8) {
                cout << "Conseguir valores" << endl;
                if (selectedDictionary == 1) {
                    List<string>* values = d1->getValues();
                    cout << "Valores de d1: ";
                    values->print();
                    delete values;
                }
                else if (selectedDictionary == 2) {
                    List<string>* values = d2->getValues();
                    cout << "Valores de d2: ";
                    values->print();
                    delete values;
                }
                else {
                    throw runtime_error("Diccionario seleccionado invalido");
                }
                option = 0;
            }
            else if (option == 9) {
                cout << "Conseguir tamaño de diccionario" << endl;
                if (selectedDictionary == 1) {
                    cout << "Tamaño de d1: " << d1->getSize() << endl;
                }
                else if (selectedDictionary == 2) {
                    cout << "Tamano de d2: " << d2->getSize() << endl;
                }
                else {
                    throw runtime_error("Diccionario seleccionado invalido");
                }
                option = 0;
            }
            else if (option == 10) {
                if (selectedDictionary == 1) {
                    cout << "Actualizacion de d1 utilizando d2" << endl;
                    d1->update(d2);
                }
                else if (selectedDictionary == 2) {
                    cout << "Actualizacion de d2 utilizando d1" << endl;
                    d2->update(d1);
                }
                else {
                    throw runtime_error("Diccionario seleccionado invalido");
                }
                option = 0;
            }
            else if (option == 11) {
                cout << "Zip" << endl;
                cout << "Ingrese cantidad de elementos que desea tener en las listas" << endl;
                int amount = getNumValue(2147483647, 1, false);
                List<int>* keys = new ArrayList<int>(amount);
                List<string>* values = new ArrayList<string>(amount);

                cout << "Por favor ingrese " << amount << " llaves:" << endl;
                for (int i = 0; i < amount; i++) {
                    cout << i+1 << ". ";
                    int key = getNumValue(2147483647, -2147483648, false);
                    keys->append(key);
                }

                cout << "Por favor ingrese " << amount << " valores:" << endl;
                for (int j = 0; j < amount; j++) {
                    cout << j+1 << ". ";
                    string value = getStringValue("Valor", false);
                    values->append(value);
                }

                cout << "Lista de llaves ingresados: ";
                keys->print();
                cout << "Lista de valores ingresados: ";
                values->print();

                if (selectedDictionary == 1) {
                    cout << "Se ejecuta zip en d1." << endl;
                    d1->zip(keys, values);
                }
                else if (selectedDictionary == 2) {
                    cout << "Se ejecuta zip en d2." << endl;
                    d2->zip(keys, values);
                }
                else {
                    throw runtime_error("Diccionario seleccionado invalido");
                }
                delete keys;
                delete values;
                option = 0;
            }
            else if (option == 12) {
                stop = true;
            }
            else {
                throw runtime_error("Opcion invalida seleccionada.");
            }
        }
        catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
            option = 0;
        }
    }
}


int main(){
    BSTDictionary<int, string>* diccionario1 = new BSTDictionary<int, string>();
    BSTDictionary<int, string>* diccionario2 = new BSTDictionary<int, string>();
    menu(diccionario1, diccionario2);
    delete diccionario1;
    delete diccionario2;
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
