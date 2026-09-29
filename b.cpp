
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("Record_File.txt", ios::in);
    if (!file) {
        cout << "Cannot open file!";
        return 0;
    }

    double searchNum;           // user input
    cout << "            NO. : ";
    cin >> searchNum;

    double roll;                // read from file
    string a, b, c, d, e, f, g;
    bool found = false;

    while (file >> roll) {      // read roll from file
        file.ignore();          // skip leftover newline

        getline(file, a);
        getline(file, b);
        getline(file, c);
        getline(file, d);
        getline(file, e);
        getline(file, f);
        getline(file, g);

        if (roll == searchNum) {   // compare with input
            cout << "\n--- Student Found ---\n";
            cout << "Roll: " << roll << endl;
            cout << "1: " << a << endl;
            cout << "2: " << b << endl;
            cout << "3: " << c << endl;
            cout << "4: " << d << endl;
            cout << "5: " << e << endl;
            cout << "6: " << f << endl;
            cout << "7: " << g << endl;
            found = true;
            break;                 // stop after first match
        }
    }

    if (!found) {
        cout << "\n              Sorry! No match found \n\n";
    }

    file.close();
}
