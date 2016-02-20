/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: reuben
 *
 * Created on 18 February, 2016, 7:51 PM
 */
#include "main.h"
#include "Authentication.h"
#include "MemberManagement.h"
#include "Facilities.h"
#include "FacilitiesManagement.h" 
#include "User.h"
Authentication authenticate;
MemberManagement memManage;
FacilitiesManagement facManage;
User u;
int main()
{
    facManage.fileToArray();
    mainMenu();
}

void makePartition()
{
    cout << "----------------------------------------------------------------";
    cout << endl;
}

void pressEnter()
{
    cout << "Press enter to continue..." << endl;
    cin.ignore(300,'\n');
}

int mainMenu()
{
    makePartition();
    cout << setw(50) << "Country Club Facilities Booking System" << endl;
    cout << setw(55) << "Please key in the following information to login" << endl;
    makePartition();
    cout << endl;
    string username, password;
    int counter = 0;
    int options;
    bool flag = true;
    
    do
    {
        if (flag == false && options == -1)
        {
            cout << "-----------------------------------------" << endl;
            cout << "Invalid username, please try again." << endl;
            cout << "WARNING!   " << counter << " of 3 tries" << endl;
            cout << "-----------------------------------------" << endl;
            cout << endl;
        }
        else if (flag == false && options == -2)
        {
            cout << "-----------------------------------------" << endl;
            cout << "Wrong password, please try again" << endl;
            cout << "WARNING!   " << counter << " of 3 tries" << endl;
            cout << "-----------------------------------------" << endl;
            cout << endl;
        }
        
        do
        {
            cout << "Username: ";
            cin >> username;
        }while (username.empty());
        do
        {
            cout << "Password: ";
            cin >> password;
        }while (password.empty());
        cout << endl;
        
        options = authenticate.verify(username, password, u);
        flag = false;
    //go through authentication class for user and password and return 
    }while ((options == -1 || options == -2)  && counter++ < 2);
    
    if (counter == 3)
    {
        cout << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Invalid user/password entered for 3 times" << endl;
        cout << "Program will now terminate." << endl;
        cout << "-----------------------------------------" << endl;
        return 0;
    }
    
    switch (options)
    {
        case 1: adminMenu();
                break;
        case 2: memberMenu();
                break;
        default: cout << "Error" << endl;
    }
}
void adminMenu()
{   
    int options;
    do
    {
        makePartition();
        cout << setw(50) << "Country Club Facilities Booking System" << endl;
        cout << setw(49) << "+++++++  Club Manager's Menu  +++++++" << endl;   
        makePartition();
        cout << "    1.) Facilities Management Sub-system" << endl;
        cout << "    2.) Member Management Sub-system" << endl;
        cout << "    3.) Report Sub-system" << endl;
        cout << "    4.) Help" << endl;
        cout << "    9.) Quit" << endl;
       
        cout << "Option :";
        cin >> options;
        cin.clear();
        cin.ignore(300,'\n');
        switch (options)
        {
            case 1: facilitiesManagement();
                   break;
            case 2: memberManagement();
                   break;
            case 3: cout << "test3" << endl;
                   break;
            case 4: cout << "test4" << endl;
                   break;     
            case 9:
                   break;
            default: cout << "Please enter a valid option" << endl;
        }
    }while (options != 9);
}

void memberMenu()
{   
    int options;
    do
    {
        makePartition();
        cout << setw(50) << "Country Club Facilities Booking System" << endl;
        cout << setw(46) << "+++++++  Member's Menu  +++++++" << endl;
        makePartition();
        cout << "    1.) Update Particulars" << endl;
        cout << "    2.) Upgrade Ranking" << endl;
        cout << "    3.) Search Portal Sub-system" << endl;
        cout << "    4.) View Bookings" << endl;
        cout << "    5.) Delete Booking" << endl;
        cout << "    6.) Booking Preferences" << endl;
        cout << "    7.) Help" << endl;
        cout << "    9.) Quit" << endl;
        
        cout << "Option :";
        cin >> options;
        cin.clear();
        cin.ignore(300,'\n');
        switch (options)
        {
            case 1: cout << "test" << endl;
                   break;
            case 2: cout << "test2" << endl;
                   break;
            case 3: cout << "test3" << endl;
                   break;
            case 4: cout << "test4" << endl;
                   break;
            case 5: cout << "test5" << endl;
                   break;   
            case 6: cout << "test4" << endl;
                   break;
            case 7: cout << "test5" << endl;
                   break; 
            case 9:
                   break;
            default: cout << "Please enter a valid option" << endl;
        }
    }while (options != 9);
}

void facilitiesManagement()
{
    int options;
    do
    {
        cout << setw(50) << "Country Club Facilities Booking System" << endl;
        cout << setw(49) << "++ Facilities Management Sub-system ++" << endl;   
        makePartition();
        cout << "    1.) Add facilities" << endl;
        cout << "    2.) Delete facilities" << endl;
        cout << "    3.) Update facilities" << endl;
        cout << "    4.) View facilities" << endl;
        cout << "    9.) Back to main menu" << endl;

        cout << "Option :";
        cin >> options;
        cin.clear();
        cin.ignore(300,'\n');
        string name, description;
        int check;
        switch (options)
        {
            case 1: cout << "Facility Name: ";
                    getline (cin, name);
                    cout << "Facility Description: ";
                    getline (cin, description);
                    check = facManage.addFacility(name, description);
                    if (check == -1)
                    {
                        cout << "The keyed in Facility already exist!" << endl;
                        pressEnter();
                    }
                   break;
            case 2: cout << "Facility Name: ";
                    getline (cin, name);
                    check = facManage.removeFacility(name);
                    if (check == -1)
                    {
                        cout << "The keyed in Facility does not exist!" << endl;
                        pressEnter();
                    }
                   break;
            case 3: cout << "update" << endl;
                   break;
            case 4: cout << "view" << endl;
                   break;     
            case 9:
                   break;
            default: cout << "Please enter a valid option" << endl;
        }
    }while (options != 9);
}

void memberManagement()
{
    int options;
    string newUser;
    string newPassword;
    int newRole;
    
    do
    {
        cout << setw(50) << "Country Club Facilities Booking System" << endl;
        cout << setw(49) << "++++ Member Management Sub-system ++++" << endl;   
        makePartition();
        cout << "    1.) Add member" << endl;
        cout << "    2.) Delete member" << endl;
        cout << "    3.) List all Club Member" << endl;
        cout << "    4.) List all Club Manager" << endl;
        cout << "    9.) Back to main menu" << endl;

        cout << "Option :";
        cin >> options;
        cin.clear();
        cin.ignore(300,'\n');
        switch (options)
        {
            case 1: int isExist;
                    do
                    {
                        newPassword = "";
                        if (isExist == -2)
                        {
                            cout << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "Username: " << newUser << " already exists. " << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << endl;
                        }
                        
                        do
                        {
                            cout << "Username: ";
                            cin >> newUser;
                        }while (newUser.empty());
                        
                        // check for existing username
                        isExist = authenticate.verify(newUser, newPassword, u);
                    } while (isExist == -2);
                   
                    do
                    {
                        cout << "Password: ";
                        cin >> newPassword;
                    }while (newPassword.empty());
                    
                    do
                    {
                        cout << endl;
                        cout << "For club manager account type, key in 1" << endl;
                        cout << "For club member account type, key in 2" << endl;
                        cout << "Role: ";
                        cin >> newRole;
                        cin.clear();
                        cin.ignore(300,'\n');
                    }while (newRole != 1 && newRole != 2);
                    
                    memManage.addUser(newUser, newPassword, newRole);
                    pressEnter();
                   break;
            case 2: cout << "delete" << endl;
                   break;
            case 3: cout << "List" << endl;
                   break;
            case 4: cout << "List" << endl;
                   break;     
            case 9:
                   break;
            default: cout << "Please enter a valid option" << endl;
        }
    }while (options != 9);
}
