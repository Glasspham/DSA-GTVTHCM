#pragma once
#include <string>
using namespace std;

class Appointment {
public:
    string datetime; // yyyyMMddhhmm
    string patientName;
    string doctorName;
    string note;
    Appointment();
    Appointment(string dt, string pn, string dn, string nt);
};
