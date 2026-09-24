


#include <ctime> // for time(0)
#include <iostream> // for cin and cout
#include <cmath> // for M_PI and others
#include <vector> // for vectors (duh)
#include <cstdlib> // for random
#include <cassert> // for assert in the tests() function
#include "TimeCode.h" // for timecode's (duh)

using namespace std;




struct DryingSnapShot {
	// This is a struct, it's like an object
	// that doesn't have any methods.
	// You can read more about them in the ZyBook
	// just search for "struct"
	string name;
	time_t startTime;
	TimeCode *timeToDry;
};


long long int get_time_remaining(DryingSnapShot dss){
	// Replace with your code
	time_t now = time(0);
	long long int rem = (dss.startTime + dss.timeToDry->GetTimeCodeAsSeconds()) - now;

	return rem;
}


string drying_snap_shot_to_string(DryingSnapShot dss){
	// Replace with your code
	string name = dss.name;
	string startTime = to_string(dss.startTime);
	string timeTill = dss.timeToDry->ToString();


	return name + " " + startTime  + " " + timeTill;
}


double get_sphere_sa(double rad){
	// replace with your code
	double surf = 4 * M_PI * (rad * rad);
	return surf;
}


TimeCode *compute_time_code(double surfaceArea){
	// replace with your code
	long long unsigned int sec = surfaceArea;
	TimeCode *tc = new TimeCode(0,0, sec);
	return tc;
}


void tests(){
	// get_time_remaining
	DryingSnapShot dss;
	dss.name = "sphere 5";
	dss.startTime = time(0);
	TimeCode tc = TimeCode(0, 0, 7);
	dss.timeToDry = &tc;
	long long int ans = get_time_remaining(dss);
	assert(ans > 6 && ans < 8);
	// add more tests here


	// get_sphere_sa
	double sa = get_sphere_sa(2.0);
	assert (50.2654 < sa && sa < 50.2655);
	// add more tests here
	

	// compute_time_code
	TimeCode *tc2 = compute_time_code(1.0);
	//cout << "tc: " << tc.GetTimeCodeAsSeconds() << endl;
	assert(tc2->GetTimeCodeAsSeconds() == 1);
	delete tc2;


	// add more tests here
	string strTest = drying_snap_shot_to_string(dss);
    cout << "String conversion test output: " << strTest << '\n';


	DryingSnapShot biggerSphere;
	biggerSphere.name = "big Sphere";
	biggerSphere.startTime = time(0);
	double bigSphere = get_sphere_sa(50);
	TimeCode *tc3 = compute_time_code(bigSphere);
	biggerSphere.timeToDry = tc3;
	cout << drying_snap_shot_to_string(biggerSphere);
	delete tc3;
	


	cout << "ALL TESTS PASSED!" << endl;

}


int main(){
	// replace with your code
	tests();
	return 0;
}