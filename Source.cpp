//This program will create classes called platypus and Puggle(child of Platypus)
//In the main function we are testing all the functions created in the header file: "Platypus.h".
// Description of "Platypus.h" is in "Platypus.cpp" file.
// They are able to fight, eat, lay eggs, hatch them, grow up, and feed their children.
// If you want to output information about objects print() function serves it.
#include "Platypus.h"
using namespace std;


//this is the main driver, where all the functions are tested
int main() {
	Platypus Mike, Lilly('F', 1.2, 10, 'L'), Max('M', 3.4, 19, 'M'); //calling constructors and creating platypusses 
	Platypus Bill('M', 2.0, 12, 'B'), Jill('F', 3.0, 23, 'J');
	Bill.lay_egg(); //trying to lay an egg, fails, because bill is a male
	Jill.lay_egg(); // jill - female is laying an egg 
	Jill.hatch(); //hatching 
	Jill.age_me(); //Jill's age is increasing
	Jill.print(); //outputting jill's info
	Jill.child.feed(); //jill is feeding her child
	Platypus adult = Jill.age_child(); //child is growing up, becoming an adult
	adult.eat(); //adult is feeding him/her self
	adult.print(); //outputting adult info 

	Max.fight(Lilly); //starting fight against Max and Lilly

	Mike.hatch(); //mike is trying to hatch an egg, fails
	Bill.age_me(); //bill is aging
	Bill.eat(); //bill is eating
	Bill.fight(Max); //fighting bill vs max

	Bill.print(); //outputting Bill's info
	Mike.print(); //outputting Mike's info
	
}