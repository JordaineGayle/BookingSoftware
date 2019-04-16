#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

typedef enum {Manager = 1, Clerk} UserType;
typedef enum  {GeneralReports, ArtisteReports, FoundationReports} ReportAction;
typedef enum {ArtisteAccount, FoundationAccount} AccountTypes;
typedef enum {zero,one}Binary;

typedef struct{
    int day;
    int month;
    int year;
}Date;

//User Database
typedef struct{
    int Id;
    char Username[40];
    char FirstName[40];
    char LastName[40];
    char Password[40];
    UserType UserType;
    char Address[40];
    char DateJoined[40];
}User;

//Artiste Database
typedef struct{
    int Id;
    char StageName[40];
    char FirstName[40];
    char LastName[40];
    char TelephoneNumber[40];
    char PhysicalAddress[40];
    char Email[40];
    char Genre[40];
    int FoundationId;
    float YearlyEarnings;
}Artiste;

//Foundation Database
typedef struct{
 int Id;
 char NameOfFoundation[100];
 int YearFounded;
 char Address[100];
 int NumberOfEmployees;
 char MajorityCurCharity[100];
}Foundation;

typedef struct{
 long AccountNum;//accountNumber
 float AccountBalance;
 AccountTypes AccountType; //(Artist or Foundation)
}AccountInfo;

//Accounts Database
typedef struct{
 int Id; //Record
 int RefId;//(weather artist id or foundation id)
 AccountInfo AccountInfo;
}Accounts;


typedef struct{
 char HotelInfo[100];
 float HotelCharge;
 char FlightInfo[100];
 float PlaneFare;
 int NumberOfPersons;
}AdditionalInfo;

typedef struct{
	float local;
	float overseas;
}Rate;

//Booking Database
typedef struct{
 int Id; //not entering
 int ArtisteId; //not entering
 int BookingNumber; //not entering
 char Type; //O,L
 Date DateBooked; //not entering
 int EmployeeId; //not entering
 char Location[100];
 char Guide[100];
 char PromoterName[100];
 Rate Rate;
 int IsVoluntary;
 AdditionalInfo Info;
}Booking;


typedef struct{
 int ReportId;
 char *FileName;
 int LastModified;
}SavedReports;

typedef struct{
 int Id;
 int ArtisteId;
 float YearlyEarnings;
 char Date[50];
}ArtisteReport;

typedef struct{
 int Id;
 int FoundationId;
 float Revenue;
 char CurrentMajorCharity[100];
 char Date[100];
}FoundationReport;

typedef struct{
  int Id;
  ArtisteReport ArtisteReport;
  FoundationReport FoundationReport;
}GeneralReport;

union ReportResults{
 GeneralReport GeneralReport[20];
 ArtisteReport ArtisteReport[20];
 FoundationReport FoundationReport[20];
};

//Logs Database
typedef struct{
 int UserId;
 char *Description;
 char *Date;
}ActivityLog;

typedef struct{
 int InvoiceId;
 char Date[50];
 char Description[100];
 int AmountOfShows;
 float Price;
 float GrandTotal;
}Invoice;

typedef struct{
    int Id;
    char Name[100];
}Promoter;



#endif // STRUCTURES_H_INCLUDED
