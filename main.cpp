#include <iostream>
#include <string>

using namespace std;

class Furniture {
public:
    virtual void StoreObject(const string& object) {
        cout << "Storing " << object << " in furniture." << endl;
    }
};

class Bookcase : public Furniture {
public:
    void StoreObject(const string& object) override{
        cout << "Storing " << object << " in bookcase." << endl;
    }
};

class Cupboard : public Furniture {
public:
    void StoreObject(const string& object) override{
        cout << "Storing " << object << " in cupboard." << endl;
    }
};

int main() {
    while(true)
    {

            int choice;
            string object;
            Furniture *furniture = nullptr;
            cout << "Enter name of the object to store:" << endl;
            cin >> object;

            cout << "Choose where to store object:"
                    "\n1. Furniture"
                    "\n2. Bookcase"
                    "\n3. Cupboard"
                    "\n4. End program."
                    "\nYour choice: ";
        try {
            cin >> choice;
        }
        catch (const exception &e) {
            cerr << "Exception caught: " << e.what() << endl;
            return 1;
        }
        try {
        switch (choice) {
                case 1:
                    furniture = new(nothrow) Furniture();
                    if (!furniture) throw runtime_error("Failed to allocate memory for Furniture.");
                    break;
                case 2:
                    furniture = new(nothrow) Bookcase();
                    if (!furniture) throw std::runtime_error("Failed to allocate memory for Bookcase.");
                    break;
                case 3:
                    furniture = new(nothrow) Cupboard();
                    if (!furniture) throw runtime_error("Failed to allocate memory for Cupboard.");
                    break;
                case 4:
                    cout << "Exiting program." << endl;
                    return 0;
                default:
                    cout << "Invalid choice." << endl;
                    return 0;
            }
        }
        catch (const exception &e) {
            cerr << "Exception caught: " << e.what() << endl;
            return 1;
        }
            furniture->StoreObject(object);
            delete furniture;
    }
}