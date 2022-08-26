//Tis is a header file where all the functions are shotly written
#pragma once
class Puggle {//class for child platypusses - puggles
	//all the private members, which puggles need
	double bWeight;
	short bAge;//months
	char bName;
	char bGender;
	bool bsAlive;
public:
	Puggle();//default constuctor
	void Print();//print function
	void feed();//feeding function
	//getters
	float getWeight()const;
	short getAge()const;
	char getName()const;
	char getGender()const;
	bool getAlive()const;
	//setters
	void setWeight(const float);
	void setName(const char);
	void setGender(const char);
};
class Platypus//the mainc class - Platypus. It has a Puggle in it. so it can be child
{
	//all the private members that adult platypus needs
	bool hasChild;
	bool hasEgg;
	short age;//months
	char name;
	char gender;
	double weight;
	bool isAlive;
	bool isMutant;
	short fight_ratio;
public:
	Puggle child;//owning a child from puggle class
	Platypus();//default destructor, creates dead platypus
	Platypus(const char gender,const double weight,const short age,const char name);//explicit constructor

	void print();
	void age_me(); //aging itself
	void fight(Platypus&); 
	void eat(); 
	void lay_egg();
	Platypus age_child();//growing up a child
	void hatch(); 
	friend bool operator ==(Platypus& a, Platypus& b);//overloading == operator
};