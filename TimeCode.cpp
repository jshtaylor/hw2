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
		
	void SetHours(unsigned int hours){
	// sets hours by directly~ changing
	
	t -= GetHours() * 3600;
	t += hours * 3600;
	
}
	void SetMinutes(unsigned int minutes){
	// sets minutes same way
	if(minutes > 59){
		cout << "error: cannot use minutes greater than 59\n"; 
		return;
		}
	t -= GetMinutes() * 60;
	t += minutes;
	
	
}
	void SetSeconds(unsigned int seconds){
	// sets second same way
	if(seconds > 59){
		cout << "error: cannot use seconds greater than 59\n";
		}
	t -= GetSeconds();
	t += seconds;
}
	
	void reset();//resets t
	

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



