#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED
#include <time.h>
#include "Structures.h"

char * UserFileName = "Database/User/User.dat";
char * ArtisteFileName = "Database/Artiste/Artiste.dat";
char * FoundationFileName = "Database/Artiste/Foundation.dat";
char * BookingFileName = "Database/Booking/Booking.dat";
char * AccountsFileName = "Database/Artiste/Accounts.dat";
char * ReportFileName = "Database/Reports/Report.txt";
char * ActivityFileName = "Database/Log/Logs.txt";
int recordCounter = 0;
int recordExist = 0;
UserType globalUser;
int LoggedInUser;
int ListPos;
#endif // VARIABLES_H_INCLUDED
