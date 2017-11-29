/*
 Name: Bernice Tran
 Class: CSCI 211-32A
 Main file for roster management program
 */

#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include "roster.h"
#include "student.h"

int capacity = 10;
Roster** myRosters;

void displayMenu();
void supervisorMode();
void userMode();
bool authenticate();
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
void loadRosters();
void saveRosters();
Student * parseStudent(string strStudent);
Date parseDate(string strDate);

int main()
{
   
    initializeRosters();
    loadRosters();
    displayMenu();
    saveRosters();
    
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
            bool authenticated = authenticate();
            while(!authenticated)
            {
                cout << endl << "Invalid authentication."<< endl;
                int reauthenticate = 0;
                cout << "Would you like to authenticate again?" << endl
                << "Enter 1 for yes or 0 for no: " << endl;
                cin >> reauthenticate;
                if (reauthenticate == 0)
                    break;
                
                authenticated = authenticate();
            }
            
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
            cout << "4 - List students" << endl; //sorted alphabetically by last name
        
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
                cout << endl << "Student successfully removed." << endl;
            }
            else
            {
                cout << endl << "Student not in roster." << endl;
            }
            
        }
        else if (choice == 3)
        {
            Student a;
            cout << endl << "Enter the first name of the student to be updated: " << endl;
            cin >> a;
            if (roster->updateStudent(a))
            {
                cout << endl << "Student successfully updated." << endl;
            }
            else
            {
                cout << endl << "Student not in roster." << endl;
            }
            
        }
        else if (choice == 4 && supervisorMode)
        {
            cout << endl;
            roster->printStudentList();
        }
        else if (choice != 0)
        {
            cout << endl << "Invalid choice. Please choose again." << endl;
        }
        
    }while (choice != 0);
}

//Prompts user for username and password to enter supervisor mode
bool authenticate()
{
    string userName,password, fUserName, fPassword;
    ifstream in;
    cout << endl << "Enter the username: ";
    cin >> userName;
    
    cout << "Enter the password: ";
    cin >> password;
    
    in.open("database.txt");
    
    while (!in.eof())
    {
        in >> fUserName;
        in >> fPassword;
        if(userName == fUserName && password == fPassword)
            return true;
    }
    
    return false;
}

//Prompts user input for course code to be searched
Roster* selectRoster()
{
    int code;
    
    cout << endl << "Enter the course code for the roster: " << endl;
    cin >> code;
    return findRoster(code);
    
}

//Searches for roster by course code
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

//Creates new roster
void createRoster()
{
    Roster* roster = new Roster();
    cin >> *roster;
    addRoster(*roster);
}

//Adds new roster created to existing array of rosters
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

//Deletes selected roster by course code
void dropRoster()
{
    cout << endl << "Dropping a roster." << endl;
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

//Grows roster array by 2 everytime it reaches capacity
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

//Prints out all rosters in system
void displayRosters()
{
    for (int i = 0; i < capacity; i++)
    {
        if (myRosters[i] != NULL)
        {
            cout << *(myRosters[i]) << endl;
        }
    }
}

//Reads in rosters from rosters.txt
void loadRosters()
{
    ifstream in;
    in.open("roster.txt");
   
    string rosterLine;
    
    while (in.good())
    {
       
        getline (in, rosterLine);
        
        stringstream strStream(rosterLine);
        string value;
        Roster* roster = new Roster();
        int i = 0;
        while (getline(strStream, value, '|'))
        {
            
            if(i == 0)
                roster->setCourseName(value);
            else if (i == 1)
                roster->setCourseCode(stoi(value));
            else if (i == 2)
                roster->setCredits(stoi(value));
            else if (i == 3)
                roster->setFirstName(value);
            else if (i == 4)
                roster->setLastName(value);
            
            i++;
        }
        
        while (getline (in, rosterLine))
        {
            if(rosterLine=="end_roster|") break;
            
           Student* student = parseStudent(rosterLine);
            roster->addStudent(*student);
            
        }
        if(i>0)
        addRoster(*roster);
        
    }
 
}

Student* parseStudent(string strStudent)
{
    stringstream strStream(strStudent);
    string value;
    Student * student = new Student();
    int i=0;
    while (getline(strStream, value, '|'))
    {
        if (i == 0)
            student->setFirstName(value);
        else if (i == 1)
            student->setLastName(value);
        else if (i == 2)
            student->setID(stoi(value));
        else if (i == 3)
            student->setStanding(5);
        else if (i == 4)
            student->setCredits(stoi(value));
        else if (i == 5)
            student->setGPA(stoi(value));
        else if (i == 6)
            student->setDoB(parseDate(value));
        else if (i == 7)
            student->setMatDate(parseDate(value));
        i++;
    }

    return student;
}

Date parseDate(string strDate)
{
    
    stringstream dateStream(strDate);
    string v;
    int dc = 0;
    int d = 0, m = 0, y=  0;
    while (getline(dateStream, v, '/'))
    {
        
        if (dc == 0)
            m = stoi(v);
        
        else if (dc == 1)
            d = stoi(v);
        else if (dc == 2)
            y = stoi(v);
        
        dc++;
        
    }
    
    Date  date(m,d,y);
    
    return date;
}

//Stores roster back into rosters.txt
void saveRosters()
{
    ofstream out;

    out.open("roster.txt");
    
    for(int i = 0; i < capacity; i++)
    {
            if(myRosters[i] != NULL)
            {
                out << myRosters[i]->getCourseName() << '|'
                << myRosters[i]->getCourseCode() << '|'
                << myRosters[i]->getCredits() << '|'
                << myRosters[i]->getProfessorName() << endl;
                myRosters[i]->saveStudentList(out);
                out << "end_roster|" << endl;
            }
    }
    
    out.close();
}


