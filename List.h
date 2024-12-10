#ifndef List_H
#define List_H
#include<iostream>
#include <String.h>
using namespace std;
struct Student {
    int rollNo;
    string name;
    int marks[3];
    int totalMarks;
    float percentage;
    string division;
    Student *next;
};

class StudentList {
private:
    Student *head, *temp, *temp1;

public:
    StudentList();
    ~StudentList();
    void createList();
    void insertStudent();
    void deleteStudentByName(string name);
    void modifyRecord(int rollNo);
    void displayRecord(int rollNo);
    void displayResult();
    void displayAll();
    void calculateResult(Student *s);
};

StudentList::StudentList() {
    head=temp=temp1=NULL;
}

StudentList::~StudentList() {
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}
#endif
