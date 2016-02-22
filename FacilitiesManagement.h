/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FacilitiesManagement.h
 * Author: Amos Laptop
 *
 * Created on February 19, 2016, 4:56 PM
 */

#ifndef FACILITIESMANAGEMENT_H
#define FACILITIESMANAGEMENT_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Facilities.h"

using namespace std;
class FacilitiesManagement {
public:
    FacilitiesManagement();
    FacilitiesManagement(const FacilitiesManagement& orig);
    virtual ~FacilitiesManagement();
    
    void fileToArray ();
    int checkExists (string str);
    int addFacility(string fac_name, string fac_desc, double rates);
    int removeFacility(string fac_name);
    int editFacility(int opt, string fac_name, string new_name, string fac_desc, double rates);
    void printAllFacilities();
private:
    struct FacilitiesDB 
    {
         Facilities facility;
    }facilities[100];
};

#endif /* FACILITIESMANAGEMENT_H */

