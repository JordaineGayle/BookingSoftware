#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

typedef enum {Manager = 1, Clerk} UserType;
typedef enum  {GeneralReports, ArtisteReports, FoundationReports} ReportAction;
typedef enum {ArtisteAccount, FoundationAccount} AccountTypes;

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
    char *StageName;
    char *FirstName;
    char *LastName;
    char *TelephoneNumber;
    char *PhysicalAddress;
    char *Email;
    char *Genre;
    char FoundationId;
}Artiste;

//Foundation Database
typedef struct{
 int Id;
 char *NameOfFoundation;
 int YearFounded;
 char *Address;
 int NumberOfEmployees;
}Foundation;

typedef struct{
 int AccountNum;
 float AccountBalance;
 AccountTypes AccountType; //(Artist or Foundation)
}AccountInfo;

//Accounts Database
typedef struct{
 int Id;
 int RefId;//(weather artist id or foundation id)
 AccountInfo AccountInfo;
 float YearlyEarnings;
 char *MajorityCurCharity;
}Accounts;


typedef struct{
 char HotelInfo;
 float HotelCharge;
 char FlightInfo;
 float PlaneFare;
 int NumberOfPersons;
}AdditionalInfo;


//Booking Database
typedef struct{
 int Id; //not entering
 int ArtisteId; //not entering
 int BookingNumber; //not entering
 char Type; //O,V,L
 int DateBooked; //not entering
 int EmployeeId; //not entering
 char Location;
 char Guide;
 char PromoterName[100];
 float Rate;
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
 char *Date;
}ArtisteReport;

typedef struct{
 int Id;
 int FoundationId;
 float Revenue;
 char *CurrentMajorCharity;
 char *Date;
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

 char *Date;
 char *Description;
 int AmountOfShows;
 float Price;
 float GrandTotal;
}Invoice;

typedef struct{
    int Id;
    char Name[100];
}Promoter;



#endif // STRUCTURES_H_INCLUDED
