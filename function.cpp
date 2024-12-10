#include <iostream>
#include "List.h"
using namespace std;
void StudentList::createList() {
    int n;
    cout<<"\nHow many students you want to enter in list : ";
    cin>>n;
    for(int i=0; i<n; i++) {
        insertStudent();
    }
}

void StudentList::insertStudent() {
    Student *s = new Student;
    cout << "\nEnter roll number: ";
    cin >> s->rollNo;
    cout << "Enter name: ";
    cin >> s->name;
    cout<<"Enter marks in 3 subjects (each out of 100): "<<endl;
    for (int i = 0; i < 3; i++) {
        cout<<"Subject "<<i+1<<" : ";
		cin>>s->marks[i];
    }

    calculateResult(s);

    s->next = NULL;

    if (head == NULL) {
        head = s;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = s;
    }

    cout << "Student record inserted!\n";
}

void StudentList::deleteStudentByName(string name) {
    if (head == NULL) {
        cout<<"List is empty!"<<endl;
        return;
    }
    temp = head;
    if (head->name == name) {
        head = head->next;
        delete temp;
        cout<<"Record of "<<name<<" deleted!"<<endl;
        return;
    }

    while (temp->next != NULL && temp->next->name != name) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Student not found!" << endl;
    } else {
        temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;
        cout << "Record of " << name << " deleted!" << endl;
    }
}

void StudentList::modifyRecord(int rollNo) {
    temp = head;
    while (temp != NULL && temp->rollNo != rollNo) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Student not found!" << endl;
    } else {
//        cout << "Enter new name: ";
//        cin >> temp->name;
         cout<<"Modify Record of "<<rollNo<<" named: "<<temp->name<<endl;
        cout << "Enter new marks in 3 subjects: ";
        for (int i = 0; i < 3; i++) {
        	cout<<"Marks of Subject "<<i+1<<" : ";
            cin >> temp->marks[i];
        }

        calculateResult(temp);
        cout << "Record modified!" << endl;
    }
}

void StudentList::displayRecord(int rollNo) {
    temp = head;
    while (temp != NULL && temp->rollNo != rollNo) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Student not found!" << endl;
    } else {
        cout << "Roll No: " << temp->rollNo << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Marks: ";
        for (int i = 0; i < 3; i++) {
            cout << temp->marks[i] << " ";
        }
        cout << "\nTotal Marks: " << temp->totalMarks;
        cout << "\nPercentage: " << temp->percentage;
        cout << "\nDivision: " << temp->division << endl;
    }
}

void StudentList::displayAll() {
    temp = head;
    if (temp == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    while (temp != NULL) {
        cout << "Roll No: " << temp->rollNo << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Marks: ";
        for (int i = 0; i < 3; i++) {
            cout << temp->marks[i] << " ";
        }
        cout << "\nTotal Marks: " << temp->totalMarks;
        cout << "\nPercentage: " << temp->percentage;
        cout << "\nDivision: " << temp->division << endl<<endl<<endl;
        temp = temp->next;
    }
}

void StudentList::displayResult() {
    int first = 0, second = 0, third = 0, fail = 0;

    temp = head;
    while (temp != NULL) {
        if (temp->division == "First") {
            first++;
        } else if (temp->division == "Second") {
            second++;
        } else if (temp->division == "Third") {
            third++;
        } else {
            fail++;
        }
        temp = temp->next;
    }

    cout << "First Division: " << first << endl;
    cout << "Second Division: " << second << endl;
    cout << "Third Division: " << third << endl;
    cout << "Fail: " << fail << endl;
}

void StudentList::calculateResult(Student *s) {
    s->totalMarks = 0;
    for (int i = 0; i < 3; i++) {
        s->totalMarks += s->marks[i];
    }
    s->percentage = s->totalMarks / 3.0;

    if (s->percentage >= 60) {
        s->division = "First";
    } else if (s->percentage >= 50) {
        s->division = "Second";
    } else if (s->percentage >= 40) {
        s->division = "Third";
    } else {
        s->division = "Fail";
    }
}
