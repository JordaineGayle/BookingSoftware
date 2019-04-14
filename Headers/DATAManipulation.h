#ifndef DATAMANIPULATION_H_INCLUDED
#define DATAMANIPULATION_H_INCLUDED
#define MAX_ARTISTE 20
#define MAX 20
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <windows.h>
#include <string.h>
#include "Helpers.h"

/**************************************************************************/


int CreateUser(User user, char *path, char *mode){

    //setting the record counter
    recordCounter = 0;

    FILE * usr;

    int exist = file_exists(path);

    //User userObject;

    if(exist == 0){

        int currentUsers = UserDataCount();

        if(currentUsers >= 3){

            return 1;

        }else{
            User * ptr = ListOfUser();

            for(int x = 0; x < currentUsers; x++){
                if( (ptr+x)->Id == user.Id && (strcmp((ptr+x)->Username, user.Username) == 0)){
                    return 2;
            }
        }

            usr = fopen(path,mode);

            fseek(usr, user.Id, SEEK_SET);
            fwrite(&user, sizeof(user),1,usr);

            fclose(usr);

            return 3;
        }

    }else{

        FILE * fp;

        fp = fopen(path,mode);

        fseek(fp, user.Id, SEEK_SET);
        fwrite(&user, sizeof(user),1,fp);

        fclose(fp);

        return 3;
    }
    //this while loop is responsible for looping through the file and check if the username exist or max record is reached

}

char * CreateBooking(Booking booking, char *path, char *mode){

    recordCounter = 0;

    //file pointer
    FILE * book = NULL;

    //opening the file
    book = fopen(path,mode);

    //creating an instance of the Artiste structure to model data
    Booking bObj;

    while(!feof(book)){

        //setting back the recordExist flag 0 on each run
        recordExist = 0;

        //reading data from file and sending it to struct
        fread(&bObj,sizeof(bObj),1,book);

        //check if the stageName sent in matches the stageName in the file and also Id
        if( (bObj.ArtisteId == booking.ArtisteId) && (bObj.DateBooked == booking.DateBooked)){

            //setting recordExist to one if record exist
            recordExist = 1;

            //recordCounter++;
            break;
        }

        if( (bObj.ArtisteId == booking.ArtisteId) && (bObj.DateBooked == booking.DateBooked)){

           //checking the number of records in the file
           recordCounter++;

        }

    }

    //checking if the recordCounter is less than or equal to three
    if(recordCounter <= 15 && recordExist == 0){

        //writing user data from a user structure to the file
        fwrite(&booking, sizeof(booking),1,book);

        //return a message if data was added successfully
        return "Record Created Successfully!";

    }else if(recordCounter <= 15 && recordExist == 1){ //checking if the RecordExist and return message
        return "Booking Already Exist"; //tell the worker the record exist
    }else{
        return "Booking For Artiste is full"; //telling the worker that no more records can be entered
    }

    //closing back the user file
    fclose(book);
}

char * CreateArtiste(Artiste artiste, char *path, char *mode){
    //setting the record counter
    recordCounter = 0;

    //file pointer
    FILE * art = NULL;

    //opening the file
    art = fopen(path,mode);

    //creating an instance of the Artiste structure to model data
    Artiste artObj;

    while(!feof(art)){

        //setting back the recordExist flag 0 on each run
        recordExist = 0;

        //reading data from file and sending it to struct
        fread(&artObj,sizeof(artObj),1,art);

        //check if the stageName sent in matches the stageName in the file and also Id
        if((strcmp(artObj.StageName, artiste.StageName)==0) && (artiste.Id == artObj.Id) ){

            //setting recordExist to one if record exist
            recordExist = 1;

            //recordCounter++;
            break;
        }
        //checking the number of records in the file
        recordCounter++;
    }

    //checking if the recordCounter is less than or equal to three
    if(recordCounter <= MAX && recordExist == 0){

        //writing user data from a user structure to the file
        fwrite(&artiste, sizeof(artiste),1,art);

        //return a message if data was added successfully
        return "Record Created Successfully!";

    }else if(recordCounter <= MAX && recordExist == 1){ //checking if the RecordExist and return message
        return "Artiste Already Exist"; //tell the worker the record exist
    }else{
        return "Artiste list is full"; //telling the worker that no more records can be entered
    }

    //closing back the user file
    fclose(art);


}

char * CreateFoundation(Foundation found, char *path, char *mode){
        //setting the record counter
    recordCounter = 0;

    //file pointer
    FILE * foundation = NULL;

    //opening the file
    foundation = fopen(path,mode);

    //creating an instance of the Artiste structure to model data
    Foundation fObj;

    while(!feof(foundation)){

        //setting back the recordExist flag 0 on each run
        recordExist = 0;

        //reading data from file and sending it to struct
        fread(&fObj,sizeof(fObj),1,foundation);

        //check if the stageName sent in matches the stageName in the file and also Id
        if((strcmp(fObj.NameOfFoundation, found.NameOfFoundation)==0) && (fObj.Id == found.Id) ){

            //setting recordExist to one if record exist
            recordExist = 1;

            //recordCounter++;
            break;
        }
        //checking the number of records in the file
        recordCounter++;
    }

    //checking if the recordCounter is less than or equal to three
    if(recordCounter <= MAX && recordExist == 0){

        //writing user data from a user structure to the file
        fwrite(&found, sizeof(found),1,foundation);

        //return a message if data was added successfully
        return "Record Created Successfully!";

    }else if(recordCounter <= MAX && recordExist == 1){ //checking if the RecordExist and return message
        return "Foundation Already Exist"; //tell the worker the record exist
    }else{
        return "Foundation list is full"; //telling the worker that no more records can be entered
    }

    //closing back the user file
    fclose(foundation);
}

char * CreateAccount(Accounts account, char *path, char *mode){
        //setting the record counter
    recordCounter = 0;

    //file pointer
    FILE * acc = NULL;

    //opening the file
    acc = fopen(path,mode);

    //creating an instance of the Artiste structure to model data
    Accounts accObj;

    while(!feof(acc)){

        //setting back the recordExist flag 0 on each run
        recordExist = 0;

        //reading data from file and sending it to struct
        fread(&accObj,sizeof(accObj),1,acc);

        //check if the stageName sent in matches the stageName in the file and also Id
        if( (accObj.RefId == account.RefId) && (accObj.AccountInfo.AccountType == account.AccountInfo.AccountType) ){

            //setting recordExist to one if record exist
            recordExist = 1;

            //recordCounter++;
            break;
        }
        //checking the number of records in the file
        recordCounter++;
    }

    //checking if the recordCounter is less than or equal to three
    if(recordCounter <= MAX && recordExist == 0){

        //writing user data from a user structure to the file
        fwrite(&account, sizeof(account),1,acc);

        //return a message if data was added successfully
        return "Record Created Successfully!";

    }else if(recordCounter <= MAX && recordExist == 1){ //checking if the RecordExist and return message
        return "Account Already Exist"; //tell the worker the record exist
    }else{
        return "Account list is full"; //telling the worker that no more records can be entered
    }

    //closing back the user file
    fclose(acc);
}

char * ArtisteRep(ArtisteReport report, char *path, char *mode){

    //file pointer
    FILE * aReport = NULL;

    //opening the file
    aReport = fopen(path,mode);

    fprintf(aReport,"Id\tArtisteId\tYearly Earnings\n%d\t%d\t%.2f\t%s\n****************************************************************\n\n",report.Id,report.ArtisteId,report.YearlyEarnings,report.Date);


    fclose(aReport);

    return "Record Created Successfully!";

}

char * FoundationRep(FoundationReport report, char *path, char *mode){
    //file pointer
    FILE * fReport = NULL;

    //opening the file
    fReport = fopen(path,mode);

    fprintf(fReport,"Id\tFoundationId\tMajor Charity\tYearly Earnings\n%d\t%d\t%s\t%.2f\t%s\n****************************************************************\n\n",report.Id,report.FoundationId,report.CurrentMajorCharity,report.Revenue,report.Date);

    fclose(fReport);

    return "Record Created Successfully!";
}

char * GeneralRep(GeneralReport report, char *path, char *mode){
    //file pointer
    FILE *gReport = NULL;

    //opening the file
    gReport = fopen(path,mode);

    fprintf(gReport,"Id\tArtisteId\tYearly Earnings\n%d\t%d\t%.2f\t%s\n",report.ArtisteReport.Id,report.ArtisteReport.ArtisteId,report.ArtisteReport.YearlyEarnings,report.ArtisteReport.Date);

    fprintf(gReport,"Id\tFoundationId\tMajor Charity\tYearly Earnings\n%d\t%d\t%s\t%.2f\t%s\n****************************************************************\n\n",report.FoundationReport.Id,report.FoundationReport.FoundationId,report.FoundationReport.CurrentMajorCharity,report.FoundationReport.Revenue,report.FoundationReport.Date);

    fclose(gReport);



    return "Record Created Successfully!";

}

void AddLog(ActivityLog log,char *path, char *mode){
    //file pointer
    FILE * logs = NULL;

    //opening the file
    logs = fopen(path,mode);

    //writing ActivityLog data from a ActivityLog structure to the file
    fprintf(logs,"UserId: %d\nDescription: %s\nDate: %s\n*****************************************\n\n",log.UserId,log.Description,log.Date);


    //closing back the user file
    fclose(logs);
}

/**************************************************************************/




/*char * current_Time(){
    time_t now;

	// Obtain current time
	// time() returns the current time of the system as a time_t value
	time(&now);

	// Convert to local time format and print to stdout
	return ctime(&now);
}*/


#endif // DATAMANIPULATION_H_INCLUDED
