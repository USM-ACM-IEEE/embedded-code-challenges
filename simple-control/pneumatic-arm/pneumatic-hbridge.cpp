#include <iostream>

using namespace std;

/*******************************************************************************
********************************************************************************
*******************************************************************************/

/*
 * 		+====================================+
 * 		| Diagram |                          |
 * 		|=========+                          |
 * 		|                ||  ||              |
 * 		|             | Solenoid |           |
 * 		|              ||  ||  ||            |
 * 		|                                    |
 * 		|                                    |
 * 		|                    ||  ||          |
 * 		|      Reverse    | //  //   |       |
 * 		|                  ||  ||  ||        |
 * 		|                                    |
 * 		|                                    |
 * 		|            ||  ||                  |
 * 		|         |   \\  \\ |   Forward     |
 * 		|          ||  ||  ||                |
 * 		|                                    |
 * 		|                                    |
 * 		+====================================+
 * 
 * The DoubleSolenoid class is able to control a 5/2 solenoid similar to the one
 * shown above. Solenoids operate in a similar way to switches or relays, but
 * control the flow of a gas or fluid instead of electricity.
*/
class DoubleSolenoid {
	public:
		enum state {forward, off, reverse};
		state currentState;
		
		// Use this function to set solenoid state according to the enum
		void Set(DoubleSolenoid::state newState) {currentState = newState;};
};

class Arm {
	public:
		enum state {up, down, steady};
		
		// Solenoid objects
		DoubleSolenoid solenoidA;
		DoubleSolenoid solenoidB;
		
		// Scroll down to see what has to be done to implement this class
		void Set(Arm::state);
};

/*******************************************************************************
********************************************************************************
*******************************************************************************/

/*
 * Write a function definition for the function declared below using the
 * following specification.
 * 
 * Parameters:
 * 		Arm::state, desired state of values up, down, and steady
 * 
 * Task:
 * 
 * 		+====================================+
 * 		| Diagram |                          |
 * 		|=========+      **  ==              |
 * 		|                ||  ||              |
 * 		|    Reverse  | Solnd B  |  Forward  |
 * 		|               || || ||             |
 * 		|               -- // --             |
 * 		|                 //                 |
 * 		|                //  ==              |
 * 		|                ||  ||              |
 * 		|    Reverse  | Solnd A  |  Forward  |
 * 		|               || || ||             |
 * 		| == : Cap      == ++ --             |
 * 		| ** : Piston                        |
 * 		| -- : Air Outlet                    |
 * 		| ++ : Compressed Air                |
 * 		+====================================+
 * 		|    Air Flow    |      State        |
 * 		|====================================|
 * 		|    ++ -> **    |        Up         |
 * 		|    ** -> --    |       Down        |
 * 		|    ** -> ==    |      Steady       |
 * 		+====================================+
 * 
 * 	 An arm is attached to a robot and is being actuated by a pneumatic
 * cylinder. The arm needs to have 3 states: up, down, and steady. A mechanical
 * engineer you work with found some solenoids that will do the trick if
 * connected in the way shown above, but is your job to write the code to
 * control the arm using the solenoids.
 * 
 * 	 Write a function definition for Arm::Set that takes a desired state (up,
 * down, or steady) and sets the state of the two DoubleSolenoid objects
 * contained in the Arm class according to the flow diagram above. Documentation
 * for the DoubleSolenoid class can be found above.
*/
void Arm::Set(Arm::state) {
}

/*******************************************************************************
********************************************************************************
*******************************************************************************/

// Obfuscated test function, because this would to easy otherwise.
void test(Arm &a,Arm::state i,DoubleSolenoid::state A,DoubleSolenoid::state B){
static int counter=1;char red[]={0x1b,'[','1',';','3','1','m',0};char green[]={
0x1b,'[','1',';','3','2','m',0};char normal[]={0x1b,'[','0',';','3','9','m',0};
a.Set(i);bool aC = (a.solenoidA.currentState==A)||(A==DoubleSolenoid::off);bool
bC=(a.solenoidB.currentState==B)||(B==DoubleSolenoid::off);cout<<"[";if(aC&&bC)
cout<<green<<"Pass"<< normal;else cout<<red<<"Fail"<<normal;cout<<"]\tTest "<<
counter++;cout<<endl;}int main(){Arm a;test(a, static_cast<Arm::state>('b'-0x61)
,static_cast<DoubleSolenoid::state>(0x2F-0x2E),static_cast<DoubleSolenoid::state
>(0x7C-'z'));test(a,static_cast<Arm::state>(0b10),static_cast<DoubleSolenoid::
state>(0x32/0b11001),static_cast<DoubleSolenoid::state>(96-'`'));test(a,
static_cast<Arm::state>('$'-0x24), static_cast<DoubleSolenoid::state>(0b101010-
0x2A),static_cast<DoubleSolenoid::state>(0x0));return 0;}
