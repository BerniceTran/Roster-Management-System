/*
 Name: Bernice Tran
 Class: CSCI 211-32A
 Driver program for roster program.
 */

/*#include <fstream>
#include <cstdlib>
#include "roster.h"
#include "student.h"

int capacity = 10;
Roster** myRosters;

void displayMenu();
void supervisorMode();
void userMode();
void password();
void createRoster();
void addRoster(Roster& r);
int findRoster(Roster& r);
void dropRoster();
void displayRosters();
Roster* selectRoster();
Roster* findRoster(int);
void rosterOperations(Roster*, bool);
void operationMenu(bool);
void grow();
void initializeRosters();

int main()
{

   
    
    
    initializeRosters();
    displayMenu();
    
    
    
            
    
    
    
    
    
    Student a("Bernice", "Tran", 1234), b("John", "Doe", 4321);
    
    cout << "Equality test" << endl;
    cout << "a==b: " << (a==b) << endl;
    cout << "a!=b: " << (a!=b) << endl;
    cout << "a<b: " << (a<b) << endl;
    cout << "a>b: " << (a>b) << endl;
    cout << "a<=b: " << (a<=b) << endl;
    cout << "a>=b: " << (a>=b) << endl << endl;
    
    Roster r1;
    cin >> r1;
    
    cout << "Please enter the information for student a: " << endl;
    cin >> a;
    cout << endl;
    
    
    cout << "Please enter the information for student b: " << endl;
    cin >> b;
    cout << endl;
    
    r1.addStudent(a);
    r1.addStudent(b);
    
    
    //add other students to test grow function
    for (int i = 0; i < 13; i++)
    {
        char x = 65 + i;
        char y = 75 + i;
        string firstName="",  lastName = "";
        lastName.append(1, x);
        lastName.append("an");
        
        firstName.append(1, y);
        firstName.append("ick");
        
        Student *t = new Student(lastName,  firstName, i);
        r1.addStudent(*t);
    }
    cout << r1;
    
    cout << endl;
    
    r1.printStudentList();
    
    cout << "After deleting student: " << endl << endl;
    
    r1.deleteStudent(b);
    
    cout << r1;
    
    r1.printStudentList();
    
    return 0;
}


void displayMenu()
{
    int choice;
    
    do
    {
    cout << "**********************************************" << endl;
    cout << "   Welcome to the roster management system.   " << endl;
    cout << "**********************************************" << endl << endl;
    cout << "Please choose a mode:" << endl;
    cout << "1 - Supervisor Mode" << endl;
    cout << "2 - User Mode" << endl;
    cout << "3 - Exit" << endl << endl;
    
    cin >> choice;
    
    if (choice == 1)
    {
        password();
        operationMenu(true);
    }
    
    else if (choice == 2)
    {
        operationMenu(false);
    }
    
    else if (choice !=3)
    {
        cout << endl;
        cout << "Not a valid choice. Please choose again." << endl << endl;
    }
        
    }while(choice != 3);
}

void operationMenu(bool supervisorMode)
{
    int choice;
    
    do{
        cout << endl;
        cout << "**********************************************" << endl;
        
        if(supervisorMode)
            cout << "              Supervisor Mode                 " << endl;
        else
            cout << "                 User Mode                    " << endl;
        
        cout << "**********************************************" << endl << endl;
        
        cout << "Please choose an action: " << endl << endl;
        cout << "1 - Select a roster to perform the following operations: " << endl;
        cout << "\tA - Insert new student to a roster" << endl;
        cout << "\tB - Remove a student from a roster" << endl;
        cout << "\tC - Update student in a roster" << endl;
        
        if (supervisorMode)
        {
            cout << "\tD - List students in selected roster" << endl;
            cout << "2 - Create a roster" << endl;
            cout << "3 - Drop a roster" << endl;
            cout << "4 - Display roster information" << endl;
            cout << "5 - Display all rosters" << endl;
        
        }
        cout << "0 - Exit" << endl << endl;
        
        cin >> choice;
        
        if (choice == 1)
        {
            Roster* roster = selectRoster();
            if (roster != NULL)
                rosterOperations(roster, supervisorMode);
            else
            {
                cout << endl << "Invalid roster code. Please choose again." << endl;
            }
        }
        else if (choice == 2 && supervisorMode)
        {
            createRoster();
        }
        else if (choice == 3 && supervisorMode)
        {
            dropRoster();
        }
        else if (choice == 4 && supervisorMode)
        {
            Roster* roster = selectRoster();
            if (roster != NULL)
                cout << *roster;
            else
            {
                cout << endl << "Invalid roster code. Please choose again." << endl;
            }
        }
        else if (choice == 5 && supervisorMode)
        {
            displayRosters();
        }
        else if (choice != 0)
        {
            cout << "Invalid choice." << endl;
        }
    
    }while (choice != 0);
    
}


void rosterOperations(Roster* roster, bool supervisorMode)
{
    int choice;
    
    do
    {
        cout << endl;
        cout << "1 - Insert new student to roster" << endl;
        cout << "2 - Remove a student from a roster" << endl;
        cout << "3 - Update a student in a roster" << endl;
        
        if (supervisorMode)
            cout << "4 - List students" << endl;
        
        cout << "0 - Exit" << endl << endl;
    
        cin >> choice;
    
        if (choice == 1)
        {
            Student * a = new Student();
            cout << endl << "Enter information for student: " << endl;
            cin >> *a;
            roster->addStudent(*a);
        }
    
        else if (choice == 2)
        {
            Student a;
            cout << endl << "Enter information for student who is to be removed: " << endl;
            cin >> a;
            if(roster->deleteStudent(a))
            {
                cout << "Student successfully removed." << endl;
            }
            else
            {
                cout << "Student not in roster." << endl;
            }
        
        }
        else if (choice == 3)
        {
        
        }
        else if (choice == 4 && supervisorMode)
        {
            cout << endl;
            roster->printStudentList();
        }
        else if (choice != 0)
        {
            cout << "Invalid choice. Please choose again." << endl;
        }
        
    }while (choice != 0);
}

 void password()
{
    string password, supervisorPassword;
    
    ifstream in;
    ofstream out;
    
    out.open("database.txt");
    
   // bool adminpass = false;
    if (out.is_open())
    {
        out << "Fall2015\n";
        out.close();
    }
    
    in.open("database.txt");
    if (in.is_open())
    {
        while (getline(in, password))
        {
            cout << endl << "Please enter the password to go into supervisor mode." << endl;
            cin >> supervisorPassword;
            
            if (supervisorPassword == password)
            {
                cout << endl << "Entering supervisor mode." << endl;
            }
        
            if (supervisorPassword != password)
            {
                cout << "Wrong password. Please try again." << endl;
                cin >> supervisorPassword;
            }
        }
        in.close();
    }
}

Roster* selectRoster()
{
    int code;
    
    cout << endl << "Enter the course code for the roster: " << endl;
    cin >> code;
    return findRoster(code);
    
}

Roster* findRoster(int code)
{
    Roster* selected = NULL;
    for (int i = 0; i < capacity; i++)
    {
        if (myRosters[i] != NULL && myRosters[i]->getCourseCode() == code)
        {
            selected = myRosters[i];
        }
    }
    return selected;
}


void createRoster()
{
    Roster * roster = new Roster();
    cin >> *roster;
    addRoster(*roster);
}

void addRoster(Roster& r)
{
    for (int i = 0; i < capacity; i++)
    {
        if (myRosters[i] == NULL)
        {
            myRosters[i] = &r;
            return;
        }
    }
    
    grow();
    
    myRosters[capacity/2] = &r;
}

void dropRoster()
{
    cout << "Dropping a roster." << endl;
    Roster* roster = selectRoster();
    
    if (roster != NULL)
    {
    for (int i = 0; i < capacity; i++)
    {
        if(myRosters[i] == roster)
        {
            myRosters[i] = NULL;
            delete roster;
            return;
        }
    }
    }
    cout << "Could not find roster to delete." << endl;
    
}

void grow()
{
    capacity = capacity * 2;
    
    Roster** newRosterList = new Roster*[capacity];
    
    for (int i = 0; i < capacity; i++)
    {
        if (i < capacity/2)
        {
            newRosterList[i] = myRosters[i];
        }
        else
            newRosterList[i] = NULL;
    }
    
    delete myRosters;
    
    myRosters = newRosterList;
}

void initializeRosters()
{
    myRosters = new Roster*[capacity];
    for (int i = 0; i < capacity; i++)
    {
        myRosters[i] = NULL;
    }

}

void displayRosters()
{
    for (int i = 0; i < capacity; i++)
    {
        if (myRosters[i] != NULL)
        {
            cout << *(myRosters[i]) << endl;
        }
    }
}*/




