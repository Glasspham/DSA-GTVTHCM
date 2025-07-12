#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <string>
using namespace std;
class Student {
private:
    int studentID;
    string name;
    string dateOfBirth;
    float gpa;

public:
    // Constructors
    Student() : studentID(0), name(""), dateOfBirth(""), gpa(0.0) {}
    Student(int id, const string& n, const string& d, float g) :
        studentID(id), name(n), dateOfBirth(d), gpa(g) {}

    // Getters and setters
    int getStudentID() const { return studentID; }
    void setStudentID(int id) { studentID = id; }
    const string& getName() const { return name; }
    void setName(const string& n) { name = n; }
    const string& getdateOfBirth() const { return dateOfBirth; }
    void setdateOfBirth(const string& d) { dateOfBirth = d; }
    float getGPA() const { return gpa; }
    void setGPA(float g) { gpa = g; }
};
#endif // _STUDENT_H_