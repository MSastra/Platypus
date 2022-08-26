//This is the description of the "Platypus.h" file
//Here you can see detailed information about functions and their abilities
#include "Platypus.h"
#include <iostream>
#include <time.h>//including time.h for random usage
using namespace std;
Platypus::Platypus()//default constructor for platypus
{ //everything is 0 or false by default
	hasEgg = false;
	weight = age = fight_ratio = 0;
	name = gender = '-';
	isAlive = isMutant = false;
	cout << "Dead platypus " << name << " has been created\n";
}

Platypus::Platypus(const char Gender, double Weight=0.1, short Age=0,const char Name='A')//explicit constructor of platypus
{ //hasEgg, isMutant and hasChild is false by default
	if (Weight <= 0 || Age < 0) {
		Weight = 0.1;
		Age = 0;
	}
		gender = Gender;
		weight = Weight;
		age = Age;
		name = Name;
		hasEgg = false;
		isAlive = true;
		fight_ratio = 0;
		isMutant = false;
		hasChild = false;
		cout << "---Platypus " << name << " has been summoned!---\n";
}

void Platypus::print() //function for ooutputting infomration about an adult platypus 
{
	cout << "\n\n*******************************************\n";
	if (isAlive) //if platypus is alive, we speak in present simple
	{
		cout << "Meet platypus " << name << "!(ᵔᴥᵔ)\nGender: " << gender << "\n"
			<< age << " months old, with weigt of " << weight << " pounds\n";
		if (isMutant) //mutation info
			cout << "It is a Mutant! \n";
		else 
			cout << "It is not a Mutant! \n";
		if (hasEgg) cout << "It has an laying egg"; //egg info
		if (hasChild) 
			cout << "It has a child\n";  child.Print(); //printing child info if it has one
	}
	else //if platypus is dead. We print the info in past simple
	{
		cout << "Platypus " << name << " was a great animal\n_____R.I.P_____\nGender: " << gender << "\n"
			<< age << " months old, with weigt of " << weight << " pounds\n";
		if (isMutant)
			cout << "It was a Mutant! \n";
		else
			cout << "It was not a Mutant! \n";
	}
	cout << "*******************************************\n\n";
}

void Platypus::age_me()//function for aging. There is 2% chance of becoming mutant. and also chance to die, which depends on the wight of the platypus
{
	if (isAlive) 
	{
		srand(time(0));
		age++;
		if (rand() % 50 == 0) isMutant == true; //It will include a 2 % chance that the object will become a mutant
		int death_chance = 10 / weight; //calculate death chance
		if (rand() % death_chance == 0)
		{
			isAlive == false; //generate random number to decide if death == true
			cout << "Platypus was " << age << " months old.Unfortunately it died.\nWas Mutant: " << (bool)isMutant << endl;
		}
		else cout << "Platypus " << name << " is now " << age << " months old.\n"; //printing changed info
		if (isMutant)
			cout << "It is a Mutant! \n";
		else
			cout << "It is not a Mutant! \n";

	}
	else cout << "Platypus " << name << " is dead, it can't age\n";
}

void Platypus::fight(Platypus& a) //function for fighting
{
	if (a == *this) //checking if platypus is trying to fight itself, and if it does, it dies
		cout << "Sadly... The platypus has commited suicide\n";
	if (isAlive && a.isAlive) //fight can be done only if both of the platypuses are alive
	{
		cout << "▬▬ι══════════  " << name << " VS " << a.name << "  ═══════════ι▬▬\n"; //printing opponent names
		cout << "Fight has started!";
		cout << "\n( 0_0)¤=[]:::::>      <:::::[]=¤(0_0 )\n";
		fight_ratio = (weight / a.weight) * 50; //calculating fight ratio
		srand(time(0));
		if (rand() % 100 + 1 < fight_ratio)  //deciding who dies
		{
			a.isAlive = false;
			cout << this->name << " has won the battle!\n▬▬ι═══════════════════════════════ι▬▬\n\n";
		}
		else 
		{
			isAlive = false;
			cout << a.name << " has won the battle!\n▬▬ι═══════════════════════════════ι▬▬\n\n";
		}
	}
	else if(!isAlive) cout << "Cmon, Platypus " << name << " is dead. But it was a great warrior tho.\n"; //if platypus is dead and trying to fight
	else cout << "Cmon, Platypus " << a.name << " is dead. But it was a great warrior tho.\n";
}

void Platypus::eat()//function for eating 
{
	if (isAlive) //eating can be done if and only if the platypus is alive
	{
		cout << "\nFeeding " << name << endl;
		srand(time(0));
		cout << "Platypus's weight was " << weight;
		weight = weight + (weight * (((rand() % 5) + (double)1) / (double)100));//deciding ho much weight will it add
		cout << " and became " << weight << endl; //printing news
	}
	else cout << "Are you trying to feed dead " << name << "? R.I.P\n"; //in case the platypus is dead
}

void Platypus::lay_egg() //function for laying eggs
{
	if (gender == 'F' && isAlive && age >=10) //platypus can lay an egg if and only if it is female, alive, over 10 months and younger than 80 months
		if (age <= 80) 
		{
			hasEgg = true; //laying the egg
			cout << "Congratualtions. Platypus " << name << " has laid an egg!\n"; //printing news
		}
		else cout << "Platypus " << name << " is too old to lay an egg\n"; //if platypus is old for motherhood
	else cout << "Platypus " << name << " can not lay eggs\n"; //if platypus is male or young or dead
}
Platypus Platypus::age_child() //function for growing up puggle(becoming an adult)
{
	Platypus pug(child.getGender(),child.getWeight(), child.getAge() + 1, child.getName() );//creating new platyous and increasing age
	pug.isAlive = child.getAlive();
	cout << child.getName() << " has become an adult!\n"; //printing news
	return pug; //returning new platypus so it can be independent
}

void Platypus::hatch() //function for hatching an egg
{
	if (hasEgg && isAlive)  //platypus can hatch an egg if it is alive and has an egg 
	{
		hasEgg = false; 
		hasChild = true;
		srand(time(0));
		if (rand() % 2 == 1) child.setGender('M'); //deciding the gender
		else child.setGender('F'); //setting gender

		child.setWeight(((rand() % 10) + (double)1) / (double)10); //deciding the weight with random 
		child.setName('A' + (rand() % 26)); //setting weight
		cout << child.getName() << " has been hatched. Congratulations mummy " << name << endl; //printing news
	}
	else cout << "Platypus " << name << " has no egg to hatch or is dead\n"; //if something goes wrong
}
//--------------------------------------------------------Puggle class
Puggle::Puggle()//default consturctor for puggle
{
	bWeight = 0.1;
	bAge = 0;
	bName = '-';
	bGender = '-';
	bsAlive = true;
}

void Puggle::Print() //printing puggle's info
{
	if (bGender != '-') //if an onlt if it has a parent
	{
		cout << "(ᵔᴥᵔ)";//info
		cout << "Meet her Puggle " << bName << "!\nGender: " << bGender << "\n"
			<< bAge << " years old, with weigt of " << bWeight << " pounds\n";
	}
}

void Puggle::feed() //function for feeding the child
{
	if (bGender != '-') //if an onlt if it has a parent
	{
		cout << "Feeding " << bName << endl;
		srand(time(0));
		cout << "Platypus's weight was " << bWeight;
		bWeight = bWeight + (bWeight * (((rand() % 5) + (double)1) / (double)100));//deciding the new weight
		cout << " and became " << bWeight << endl; //printing news
	}
}

//--------------From here we have getters. They all return const values
float Puggle::getWeight()const
{
	return bWeight;
}

short Puggle::getAge()const
{
	return bAge;
}

char Puggle::getName()const
{
	return bName;
}

char Puggle::getGender()const
{
	return bGender;
}

bool Puggle::getAlive()const
{
	return bsAlive;
}

//----------------From here we have setter for weight, name and gender, so class would have an access to them
void Puggle::setWeight(const float weight)
{
	if (weight <= 0) {
		bWeight = 0.1;
	}
	else bWeight = weight;
}

void Puggle::setName(const char name)
{
	bName = name;
}

void Puggle::setGender(const char gender)
{
	if (gender != 'F' || gender != 'M') {
		if (rand() % 2 == 1) bGender = 'M';
		else bGender = 'F';
	}
	else bGender = gender;
}

//overloading operator for checking if platypus is the same one 
bool operator==(Platypus& a, Platypus& b)
{
	return (a.age == b.age) && (a.gender == b.gender) && (a.name == b.name)&& (a.isAlive == b.isAlive)&& (a.hasChild == b.hasChild)&& (a.hasEgg == b.hasEgg)&& (a.weight == b.weight)&& (a.isMutant == b.isMutant) ;
}
