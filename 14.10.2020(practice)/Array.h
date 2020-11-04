#pragma once
#include <ostream>
class Array
{
private:
	//static int getRandomNumber(int, int);
	int m_length;
	int* m_array;

public:
	Array();
	Array(int);
	Array(int, int* );
	virtual  ~Array();

	void initialize();

	int getLength()const;
	int* getArray()const;
	int getElement(int);

	Array& operator=(const Array&);
	const  Array operator+(const Array&)const; // so the first operand will change
	const  Array operator-(const Array&)const;
	const  Array operator*(const Array&)const;
	//friend std::ostream& operator<<(std::ostream&, const Array&);

	//void initRandom();
	//void shuffle();
	
	void show()const;
};