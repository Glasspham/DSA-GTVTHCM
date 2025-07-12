#include "Appointment.h"
Appointment::Appointment() {}
Appointment::Appointment(string dt, string pn, string dn, string nt)
    : datetime(dt), patientName(pn), doctorName(dn), note(nt) {}
