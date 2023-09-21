#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <fstream>
using namespace std;

struct Student
{
    int roll, grade;
    char div;
    string fname, lname;
};

class DBoperations
{
private:
    struct Student student;
    fstream f;
    string filename = "studentDB.csv";

public:
    void setStudent();
    void newEntry();
    string fileCont()
    {
        string line, fcont = "";
        f.open(filename, ios::in);
        while (getline(f, line))
        {
            fcont += line + "\n";
        }
        f.close();
        return fcont;
    }
};

void DBoperations::setStudent()
{
    int count = 0;
    while (count <= 4)
    {
        switch (count)
        {
        case 0:
            cout << "Enter Roll no.\n";
            cin >> student.roll;
            if (student.roll > 0)
            {
                count++;
            }
            break;
        case 1:
            cout << "Enter First Name:\n";
            cin >> student.fname;
            count++;
            break;
        case 2:
            cout << "Enter Last Name:\n";
            cin >> student.lname;
            count++;
            break;
        case 3:
            cout << "Enter Grade:\n";
            cin >> student.grade;
            if (student.grade > 0 && student.grade < 13)
            {
                count++;
            }
            break;
        case 4:
            cout << "Enter Division(CAPITAL):\n";
            cin >> student.div;
            if (student.div >= 'A' && student.div <= 'E')
            {
                count++;
            }
            break;
        default:
            break;
        }
    }
}
void DBoperations::newEntry()
{
    string fcont = fileCont();
    f.open(filename, ios::out);
    f << fcont << student.roll << ", " << student.fname << ", " << student.lname << ", " << student.grade << ", " << student.div << "\n";
    f.close();
}
int main()
{
    DBoperations student;
    int op;
    string operationList = "0. To repeat this list.\n1. List Students.\n2. Enter New Student.\n.\n.\n.\n99. Exit.\n";
    cout << "||STUDENT DATABASE MANAGEMENT SYSTEM||\n";
    cout << "Enter 0 to list operations.\n";
    while (1)
    {
        cin >> op;
        switch (op)
        {
        case 0:
            cout << operationList;
            break;
        case 1:
            cout << student.fileCont();
            break;
        case 2:
        student.setStudent();
        student.newEntry();
            break;
        case 99:
            exit(0);
            break;
        default:
            cout << "Please Enter Valid Operation!\n";
            break;
        }
    }
    return 0;
}