#include "TimeCode.h"
#include <iostream>
#include <string>

using namespace std;

TimeCode::TimeCode(unsigned int hr, unsigned int min, long long unsigned int sec){
	 //implement primary constructor
	 t = ComponentsToSeconds(hr, min, sec);
}
	 	
TimeCode::TimeCode(const TimeCode& tc){
	//implement second constructor options
	t = tc.t;
}
		
void TimeCode::SetHours(unsigned int hours){
	// sets hours by directly~ changing
	t-= GetHours() * 3600;
	t+= hours * 3600;
	
}
void TimeCode::SetMinutes(unsigned int minutes){
	// sets minutes same way
	if(minutes > 59){
		cout << "error: cannot use minutes greater than 59\n"; 
		return;
		}
	t-= GetMinutes() * 60;
	t+= minutes;
	
	
}
void TimeCode::SetSeconds(unsigned int seconds){
	// sets second same way
	if(seconds > 59){
		cout << "error: cannot use seconds greater than 59\n";
		}
	t-= GetSeconds();
	t+= seconds;
}
	
	void TimeCode::reset(){
	//resets t
	t = 0;
}

unsigned int TimeCode::GetHours() const {
	//same as diving by 60 twice 
	return t/ 3600; 
}

unsigned int TimeCode::GetMinutes() const {
	//converts to minutes and than removes all of them above 60, faster than doing divide and subtract by values
	return (t/ 60) % 60;
}

unsigned int TimeCode::GetSeconds() const {
	//converts to second by removing all of them above 60
	return t% 60;
}	

void TimeCode::GetComponents(unsigned int& hr, unsigned int& min, unsigned int& sec) const {
	// Reuse the getter functions here
	hr = GetHours();
	min = GetMinutes();
	sec = GetSeconds();
}

long long unsigned int TimeCode::ComponentsToSeconds(unsigned int hr, unsigned int min, unsigned long long int sec){
// converts from components into seconds -> t
	return hr * 3600  + min * 60 + sec;




}

string TimeCode::ToString() const{
	return to_string(GetHours()) + ":" + to_string(GetMinutes()) + ":" + to_string(GetSeconds());
	
}
// its a to string, check how to format the return probably in h:m:s from

TimeCode TimeCode::operator+(const TimeCode& other) const{
	TimeCode result;
    result.t = this->t + other.t;
    return result;
	} // adds
TimeCode TimeCode::operator-(const TimeCode& other) const{
	if (this->t < other.t) {
        throw invalid_argument("TimeCode cannot be negative");
    }
    TimeCode result;
    result.t = this->t - other.t;
    return result;
	} // subtracts
TimeCode TimeCode::operator*(double a) const{
	if (a < 0) {
        throw invalid_argument("Multiplier cannot be negative");
    }
    TimeCode result;
    result.t = static_cast<long long unsigned int>(this->t * a);
    return result;
	} // multiplies
TimeCode TimeCode::operator/(double a)const{
	if (a <= 0) {
        throw invalid_argument("Divisor must be greater than 0");
    }
    TimeCode result;
    result.t = static_cast<long long unsigned int>(this->t / a);
    return result;
	} //divides



//bunch of boolean features, compares value, can proably just convert to second and convert those
bool  TimeCode::operator== (const TimeCode& other) const{
	return this->t == other.t;
	}
bool  TimeCode::operator!= (const TimeCode& other) const{
	return this->t != other.t;
	}

bool TimeCode::operator <(const TimeCode& other) const{
	return this->t < other.t;
	}
bool TimeCode::operator <=(const TimeCode& other) const{
	return this->t <= other.t;
	}

bool TimeCode::operator >(const TimeCode& other) const{
	return this->t > other.t;
	}
bool TimeCode::operator >=(const TimeCode& other) const{
	return this->t >= other.t;
	}



