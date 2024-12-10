#include <iostream>
#include "List.h"
using namespace std;

int main(int argc, char** argv) 
{
	StudentList obj;
    int choice, rollNo;
    string name;

    do {
    	cout<<"********************************";
        cout << "\nMenu:\n";
        cout << "1. Create List\n";
        cout << "2. Insert Student\n";
        cout << "3. Delete Student by Name\n";
        cout << "4. Modify Record\n";
        cout << "5. Display Record by Roll No\n";
        cout << "6. Display All Records\n";
        cout << "7. Display Result\n";
        cout << "8. Exit\n";
        cout<<"********************************";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                obj.createList();
                break;
            case 2:
                obj.insertStudent();
                break;
            case 3:
                cout << "\nEnter name of student to delete: ";
                cin >> name;
                obj.deleteStudentByName(name);
                break;
            case 4:
                cout << "\nEnter roll number of student to modify: ";
                cin >> rollNo;
                obj.modifyRecord(rollNo);
                break;
            case 5:
                cout << "\nEnter roll number to display record: ";
                cin >> rollNo;
                obj.displayRecord(rollNo);
                break;
            case 6:
                obj.displayAll();
                break;
            case 7:
                obj.displayResult();
                break;
            case 8:
                cout << "Exiting program!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 8);
	return 0;
}
