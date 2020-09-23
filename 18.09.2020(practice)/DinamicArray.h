#pragma once
class DinamicArray
{
private:
	int* m_array;
	int m_length;
	static int getRandomNumber(int, int);

public:
	DinamicArray();
	DinamicArray(int);
	~DinamicArray();

	void initRandom();
	void shuffle();
	int getDiffCount();
	void print();
};

