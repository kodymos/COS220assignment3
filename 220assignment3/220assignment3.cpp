/*
220assignment3.cpp
Assignment:  COS220_Assignment3
Programmer:  Kody Moseley
Description: This program takes in list of alternating
			lake ID numbers and fish weights. It then
			uses the lake ID to fill up a 2d array. 
			Some useful information is then calculated
			and displayed for the user, such as heaviest 
			fish, lightest fish, and histogram of number of
			fished per lake, etc.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	//user input variables
	int iLakeIdentifier = 0;	//integer lake ID
	double dFishWeight = 1;		//double fish weight

	//variables used to index the 2d array
	int indexChemo = 0;
	int indexGreene = 0;
	int indexHopkins = 0;	
	int indexToddy = 0;
	
	//string variables for the histogram below
	string chemoHisto = "";
	string greeneHisto = "";
	string hopkinsHisto = "";
	string toddyHisto = "";

	//ongoing variables, heaviest and lightest fish weight
	double heaviestFish = 0;
	double lightestFish = 0;


	int iTotalFish = 0;				//total number of fish, counter
	double dTotalFishWeight = 0.0;	//double, total fist weight

	//initialization of 2d array
	double finalArray[4][15];

	cout << setprecision(1) << fixed;

	do {	//do the following, while user input isn't ==> 0 0
		cin >> iLakeIdentifier;	//user input for lake ID
		cin >> dFishWeight;		//user input for fish weight


		if (iLakeIdentifier == 0) {	//if the lake ID is 0, this will exit do-while loop
			break;
		}
		if (iTotalFish == 0) {			//if there is no fish yet
			heaviestFish = dFishWeight;	//set heaviest fish to first fish
			lightestFish = dFishWeight;	//set lightest fish to first fish
		}
		if (dFishWeight > heaviestFish) {	//if next fish is heavier than current heaviest...
			heaviestFish = dFishWeight;		//set heaviest fish to new heaviest fish
		}
		if (lightestFish > dFishWeight) {	//if next fish is lighter than current lightest...
			lightestFish = dFishWeight;		//set lightest fish to new lightest fish
		}

		//the following if statements fill the 2d array
		if (iLakeIdentifier == 1000) {					//if the lake ID is for Chemo
			finalArray[0][indexChemo] = dFishWeight;	//set 2d array, first row next column to fish weight
			indexChemo += 1;							//increment Chemo index, for next pass
			chemoHisto += "*";							//add one more star to Chemo histogram
			iTotalFish += 1;							//add one to total number of fish
			dTotalFishWeight += dFishWeight;			//add fish weight to total fish weight

		}
		if (iLakeIdentifier == 1010) {					//if the lake ID is for Greene
			finalArray[1][indexGreene] = dFishWeight;	//set 2d array, second row next column to fish weight		
			indexGreene += 1;							//increment Greene index, for next pass
			greeneHisto += "*";							//add one more star to Greene histogram
			iTotalFish += 1;							//add one to total number of fish
			dTotalFishWeight += dFishWeight;			//add fish weight to total fish weight

		}
		if (iLakeIdentifier == 1050) {					//if the lake ID is Hopkins
			finalArray[2][indexHopkins] = dFishWeight;	//set 2d array, third row next column to fish weight
			indexHopkins += 1;							//increment Hopkins index, for next pass
			hopkinsHisto += "*";						//add one more star to Hoplins histogram
			iTotalFish += 1;							//add one to total number of fish
			dTotalFishWeight += dFishWeight;			//add fish weight to total fish weight

		}
		if (iLakeIdentifier == 1100) {					//if the lake ID is for Toddy
			finalArray[3][indexToddy] = dFishWeight;	//set 2d array, fourth row next column to fish weight
			indexToddy += 1;							//increment Toddy index, for next pass
			toddyHisto += "*";							//add one more star to Toddy histogram
			iTotalFish += 1;							//add one to total number of fish
			dTotalFishWeight += dFishWeight;			//add fish weight to total fish weight
		}

	} while (iLakeIdentifier != 0);	//loop terminator
	
	//print header
	cout << "\nIndividual Assignment 3 by Kody Moseley" << endl;
	cout << "---------------------------------------" << endl;

	//output for Chemo, row 1 in 2d array
	cout << "\nChemo (1000): " << setw(5);
	for (int i = 0; i < 15; i++) {
		if (finalArray[0][i] > 0) {
			cout << finalArray[0][i] << " ";
		}
	}

	//output for Greene, row 2 in 2d array
	cout << "\nGreene (1010): " << setw(4);
	for (int i = 0; i < 15; i++) {
		if (finalArray[1][i] > 0) {
			cout << finalArray[1][i] << " ";
		}
	}

	//output for Hopkins, row 3 in 2d array
	cout << "\nHopkins (1050): " << setw(3);
	for (int i = 0; i < 15; i++) {
		if (finalArray[2][i] > 0) {
			cout << finalArray[2][i] << " ";
		}
	}

	//output for Toddy, row 4 in 2d array
	cout << "\nToddy (1100): " << setw(5);
	for (int i = 0; i < 15; i++) {
		if (finalArray[3][i] > 0) {
			cout << finalArray[3][i] << " ";
		}
	}


	cout << "\n\nOverall number of fish collected: " << setw(3) << iTotalFish << endl;			//output, total fish
	cout << "Average fish weight over all sites: " << dTotalFishWeight / iTotalFish << endl;	//output, average weight overall
	cout << "Heaviest fish: " << setw(24) << heaviestFish << endl;								//output, heaviest fish
	cout << "Lightest fish: " << setw(24) << lightestFish << endl;								//output, lightest fish

	//output for histogram section
	cout << "\nLake ID" << setw(10) << "Lake Name" << endl;
	cout << "-------------------" << endl;
	cout << "Chemo: " << setw(5) << chemoHisto << endl;
	cout << "Greene: " << setw(3) << greeneHisto << endl;
	cout << "Hopkins: " << setw(2) << hopkinsHisto << endl;
	cout << "Toddy: " << setw(3) << toddyHisto << endl;
	cout << endl;


	system("pause");
    return 0;
}