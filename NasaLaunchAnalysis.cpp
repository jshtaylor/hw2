#include "TimeCode.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<string> split(string line, char delim){
    //splits line by a delimiter
    vector<string> tokens; // vector of strings
    stringstream ss(line); // something with the s string
    string token; // variable

    while(getline(ss,token,delim)){ 
        //loop that splits until the line is through
        tokens.push_back(token); // adds split to the vector
    }
    return tokens;

}


TimeCode parse_line(string line){
//implement this to take a line from the file and return the time code from said line
    size_t firstQuote = line.find('"');
    size_t secondQuote = line.find('"', firstQuote + 1); // find first and second quotes to simplify finding the time 

    if (firstQuote == string::npos || secondQuote == string::npos) {
        return TimeCode(0, 0, 0); // Handle malformed lines safely
    }

    string dateTimeStr = line.substr(firstQuote + 1, secondQuote - firstQuote - 1); // gets a substring of the line

    vector<string> spaceParts = split(dateTimeStr, ' '); // splits that sub string into componenets

    if (spaceParts.size() < 5) {
        // size check for safety
        return TimeCode(0, 0, 0);
    }

    string timeStr = spaceParts[4];// the time is index 4 of said line

    vector<string> timeParts = split(timeStr, ':');

    unsigned int hr = stoi(timeParts[0]); // convert into correct data type
    unsigned int min = stoi(timeParts[1]); // convert into correct data type
    unsigned long long sec = 0; // no seconds in the csv

    return TimeCode(hr, min, sec);
}




int main(){
    string fileName{"Space_Corrected.csv"};
    ifstream input(fileName);

    if (!input.is_open()) {
        //handles issues with error opening file, likely if file is missing
        cerr << "Error opening file " << fileName << endl;
        return 1;
    }

    string line;
    TimeCode totalSum; // store summation of time

    unsigned int count = 0; // counts number of lines, so number of time codes

    getline(input, line);

    while(getline(input,line)){
        if (line.empty()) continue;

        TimeCode tc = parse_line(line); // holds the timecode for each line iterated
        totalSum = totalSum + tc; // adds that to the grandsum
        count ++; // coint increments
    }

    input.close();

    if (count > 0){
        TimeCode averageTime = totalSum / count;//should return an average of 12:7:56 based on the math numbers
         int average = stoi(TimeCode::ToString(averageTime)); // need to fix this return type to be the correct type
    }

return 0;
}