#include <iostream>

using namespace std;

/*
 * Write a function definition for the function declared below using the
 * following specification.
 * 
 * Parameters:
 * 		bool, Whether the 'A' button is pressed on the controller
 * 		bool, Whether the 'B' button is pressed on the controller
 *		float, Amount of current being sent to the motor
 * 
 * Return:
 * 		float, Value to write to the motor
 * 
 * Task:
 * 		When the 'A' button is pressed, start climbing. When the 'B' button
 * is pressed, set the motor value to -1 and stop climbing if the robot was
 * previously climbing. While climbing, set the motor value to 0.1 if the
 * motor current exceeds 30, otherwise set the motor value to 1. If not
 * climbing and the 'B' button is not pressed, set the motor value to a default
 * of 0.
*/
float climber(bool, bool, float);





/*******************************************************************************
********************************************************************************
*******************************************************************************/

void test(bool a, bool b, float c, float desired) {
	static int counter = 1;
	char red[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
	char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
	char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };

	float value = climber(a, b, c);

	cout << "["; 
	if(value == desired)
		cout << green << "Pass" << normal;
	else
		cout << red << "Fail" << normal;
	
	cout << "]\tTest " << counter++;
	
	if(value != desired)
		cout << "\t\tclimber(" << a << ", " << b << ", " << c << ") returned " << value << " instead of " << desired;
	
	cout << endl;
}

int main() {
	test(false, false, 0.0, 0.0);
	test(true, false, 0.0, 1.0);
	test(false, false, 0.0, 1.0);
	test(true, false, 15.0, 1.0);
	test(false, false, 15.0, 1.0);
	test(true, false, 35.0, 0.1);
	test(false, false, 35.0, 0.1);
	test(false, false, 30.0, 1.0);
	test(false, false, 30.0, 1.0);
	test(false, true, 0.0, -1);
	test(false, false, 0.0, 0.0);
	test(false, true, 0.0, -1);
	test(false, false, 0.0, 0.0);
	test(false, true, 0.0, -1);
	test(false, true, 0.0, -1);
	test(false, false, 0.0, 0.0);	
	
	return 0;
}
