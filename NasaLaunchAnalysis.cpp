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


TimeCode parse_line(string line) {
    size_t firstQuote = line.find('"');
    size_t secondQuote = line.find('"', firstQuote + 1);

    // If quotes are missing, throw so main()'s catch block skips this line
    if (firstQuote == string::npos || secondQuote == string::npos) {
        throw invalid_argument("No quotes found in line");
    }

    string dateTimeStr = line.substr(firstQuote + 1, secondQuote - firstQuote - 1);
    vector<string> spaceParts = split(dateTimeStr, ' ');

    string timeStr = "";
    for (const string& part : spaceParts) {
        if (part.find(':') != string::npos) {
            timeStr = part;
            break;
        }
    }

    // If no HH:MM format exists inside the quotes, throw
    if (timeStr.empty()) {
        throw invalid_argument("No timestamp with ':' found");
    }

    vector<string> timeParts = split(timeStr, ':');
    if (timeParts.size() < 2) {
        throw invalid_argument("Invalid time string structure");
    }

    try {
        unsigned int hr = stoi(timeParts[0]);
        unsigned int min = stoi(timeParts[1]);
        unsigned long long sec = 0;

        return TimeCode(hr, min, sec);
    } catch (...) {
        throw invalid_argument("stoi failed to parse integers");
    }
}




int main(){
    string fileName{"Space_Corrected.csv"};
    ifstream input(fileName);
    cout << "test one \n";

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
        try {
            // parse_line returns a TimeCode object directly
            TimeCode tc = parse_line(line); 

            // Both operations only execute if parse_line succeeds
            totalSum = totalSum + tc; 
            count++;
        } catch (const invalid_argument&) {
            // Skip bad/unparseable lines without updating sum or count
            continue;
        }
    }

    input.close();

    cout << "file is read here \n";

    if (count > 0){
        TimeCode averageTime = totalSum / count;//should return an average of 12:7:56 based on the math numbers
        cout << totalSum.ToString() << " / " << count << " = " << averageTime.ToString() << '\n' ;
        cout <<  "As seconds " << totalSum.GetTimeCodeAsSeconds() << " / " << count << " = " << averageTime.GetTimeCodeAsSeconds();
        return 1;
        }
    cout << "if statement didn't work \n";

return 0;
}