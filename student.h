/*
 Name: Bernice Tran
 Class: CSCI 211-32A
 Header file for student class.
 */

#ifndef STUDENT_H
#define	STUDENT_H
#include <iostream>
#include <string>
#include "date.h"

using namespace std;

class Student
{
    string lastName, firstName, standing;
    Date birthday, matriculationDate;
    double credits, gpa;
    int ID;
    
public:
    
    //Constructors******************************************************************
    
    Student(string last_n = "", string first_n = "", int id = 0, string standing_n = "Freshman", Date dob_n = Date(1, 1, 1970), Date matdate_n = Date(1, 1, 1970), double credits_n = 0, double gpa_n = 0) :
    lastName(last_n), firstName(first_n), standing(standing_n), birthday(dob_n), matriculationDate(matdate_n), credits(credits_n), gpa(gpa_n), ID(id)
    {}
    
    //Accessors (getters)***********************************************************
    
    string getFirstName() const;
    string getLastName() const;
    string getName() const;
    string getStanding() const;
    Date getDoB() const;
    Date getMatDate() const;
    double getCredits() const;
    double getGPA() const;
    int getID() const;
    
    //Mutators (setters)************************************************************
    
    void setLastName(string last);
    void setFirstName(string first);
    void setStanding(double credits);
    void setDoB(Date bday);
    void setMatDate(Date mday);
    void setCredits(double creds);
    void setGPA(double gpas);
    void setID(int id);
    
    //Overloaded Operators**********************************************************
    
    bool operator==(const Student&);
    
    bool operator!=(const Student&);
    
    bool operator<(const Student&);
    
    bool operator>(const Student&);
    
    bool operator<=(const Student&);
    
    bool operator>=(const Student&);
    
    friend ostream& operator<<(ostream&, const Student&);
    
    friend istream& operator>>(istream&, Student&);
};


#endif	/* STUDENT_H */