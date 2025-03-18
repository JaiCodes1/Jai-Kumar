#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    const int size = 10;
    string names[size] = {"Jai", "Suman", "Muneeb", "Aashir", "Haris", "Sameer", "Maria","Rafey", "Taha","Anas"};
    string status[size];
    int choice;
    
    do {
        cout << "\n============================================\n";
        cout << setw(40) << "Online Attendance System\n";
        cout << "============================================\n";
        cout << setw(30) << "1. Mark Attendance\n";
        cout << setw(30) << "2. View Attendance\n";
        cout << setw(25) << "3. Exit\n";
        cout << setw(30) << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 1) {
            ofstream file("attendance.txt");
            for (int i = 0; i < size; i++) {
                cout << setw(30) << names[i] + " (Present/Absent): ";
                getline(cin, status[i]);
                file << names[i] << " - " << status[i] << "\n";
            }
            file.close();
            cout << setw(35) << "Attendance saved successfully!\n";
        } 
        else if (choice == 2) {
            ifstream file("attendance.txt");
            string line;
            cout << "\n============================================\n";
            cout << setw(40) << "Attendance Record\n";
            cout << "============================================\n";
            while (getline(file, line)) {
                cout << setw(35) << line << endl;
            }
            file.close();
        } 
        else if (choice == 3) {
            cout << setw(25) << "Exiting...\n";
        } 
        else {
            cout << setw(40) << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);
    
    return 0;
}

