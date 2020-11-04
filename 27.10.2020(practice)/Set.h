#pragma once
const int MaxSize = 100;
class Set
{
	int len;
	char members[MaxSize];
	int find(char ch);

public:
	Set() { len = 0; }

	// получение количества элементов в множестве
	int getLength() { return len; }

	void showset();// отображение множства
	bool isMember(char ch);//проверка членства

	Set operator +(char ch);
	// добавление элемента 
	Set operator -(char ch);
	// удаление элемента 
	Set operator +(Set ob2);
	// объединение мнлжеств 
	Set operator -(Set ob2);// получение разности множеств

};

