/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.h
 * Author: reuben
 *
 * Created on 18 February, 2016, 8:59 PM
 */

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void makePartition();
void pressEnter();
int mainMenu();
void clubManagerMenu(string);
void memberMenu(string);
void bookingMenu(string);

// manager menu
void facilitiesManagement();
void updateFacilitiesMenu ();
void memberManagement(string);

// member menu
#endif /* MAIN_H */

