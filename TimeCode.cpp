#include "TimeCode.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;




TimeCode::TimeCode(unsigned int hr=0, unsigned int min = 0, long long unsigned int sec = 0){
	 //implement primary constructor
	 }
	 	
TimeCode::TimeCode(const TimeCode& tc){
		//implement second constructor options
		}
		
	void SetHours(unsigned int hours); // sets hours by directly~ changing T
	void SetMinutes(unsigned int minutes); // sets minutes same way
	void SetSeconds(unsigned int seconds);// sets second same way
	
	void reset();//resets t
	
/*
	unsigned int TimeCode::GetHours(){ 
	// returns the hours divide by 60 twice, math is in getcomponenets
		return hr;
	
	}

	unsigned int TimeCode::GetMinutes(){
	//divided by 60 mod 60, math is in getcomponenets
		return min;
	}
	
	unsigned int TimeCode::GetSeconds(){ 
	// modulo 60 t, math is in getcomponenets
		return sec;
	}

	long long unsigned int TimeCode::GetTimeCodeAsSeconds() { 
		//returns T value
		return t;
		} 
	
	void TimeCode::GetComponents(unsigned int& hr, unsigned int& min, unsigned int& sec) {
	// gets the components in their form
		hr = t/3600;
		min = (t/60)%60;
		sec = t%60;
		
	}
	//not certain if the math should be within the get componenets or the Get___ functions, the get___ having the math makes more sense as it can call the other functions and than assign the varibles within it, check with Novak later
	*/
unsigned int TimeCode::GetHours() const { 
	return t / 3600; 
}

unsigned int TimeCode::GetMinutes() const {
	return (t / 60) % 60;
}

unsigned int TimeCode::GetSeconds() const {
	return t % 60;
}	

long long unsigned int TimeCode::GetTimeCodeAsSeconds() const { 
	return t;
} 

void TimeCode::GetComponents(unsigned int& hr, unsigned int& min, unsigned int& sec) const {
	// Reuse the getter functions here
	hr = GetHours();
	min = GetMinutes();
	sec = GetSeconds();
}

static long long unsigned int TimeCode::ComponentsToSeconds(unsigned int hr, unsigned int min, unsigned long long int sec){
// converts from components into seconds -> t
	return hr * 3600  + min * 60 + sec;




}

string TimeCode::ToString() const; // its a to string, check how to format the return probably in h:m:s from

TimeCode TimeCode::operator+(const TimeCode& othetr) const; // adds
TimeCode TimeCode::operator-(const TimeCode& other) const; // subtracts
TimeCode TimeCode::operator*(double a) const; // multiplies
TimeCode TimeCode::operator/(double a)const; //divides



//bunch of boolean features, compares value, can proably just convert to second and convert those
bool operator TimeCode::== (const TimeCode& other) const;
bool operator TimeCode::!= (const TimeCode& other) const;

bool operator TimeCode::<(const TimeCode& other) const;
bool operator TimeCode::<=(const TimeCode& other) const;

bool operator TimeCode::>(const TimeCode& other) const;
bool operator TimeCode::>=(const TimeCode& other) const;



