#include "Set.h"
#include <iostream>
int Set::find(char ch)
{
	int i;
	for (i = 0; i < len; i++)
		if (members[i] == ch) return i;

	return -1;
}

// отображает содержимое множества
void Set::showset()
{
	std::cout << "{";
	for (int i = 0; i < len; i++)
		std::cout << members[i] << " ";
	std::cout << "}" << std::endl;
}

/* функци€ возвращает значение  true .если символ ch €вл€етс€ членом множества, в противном случае зозвращаетс€ значение  false
 */
bool Set::isMember(char ch)
{
	if (find(ch) != -1) return true;
	return false;
}

// добавление нового элемента в множество
Set Set::operator +(char ch)
{
	Set newset;
	if (len == MaxSize)
	{
		std::cout << " множество заполнено /n";
		return *this;
		//возвращает существующее   множество
	}
	newset = *this;// дублирует существующее множество

// провер€ем существует ли уже в множестве такой элемент
	if (find(ch) == -1)

		//если такой элемент не найден 
		 //его можно добавл€ть в множество
		 //  включаем новый элемент в новое множество
	{
		newset.members[newset.len++] = ch;
		//newset.len++;
	}
	return newset;
}

// удал€ем элемент из множества
Set Set::operator - (char ch)
{
	Set newset;
	int i = find(ch);//переменна€ получит значение  -1 если
// заданный элемент не будет найден в множестве

//копируем и уплотн€ем оставшиес€ элементы
	for (int j = 0; j < len; j++)
		if (j != i) newset = newset + members[j];
	return newset;

}


// ќбъединение множеств
Set Set::operator + (Set ob2)
{
	Set newset = *this; //копируем первое множество

	//добавл€ем в первое множество уникальные элементы из 
	//второго 
	for (int i = 0; i < ob2.len; i++)
		newset = newset + ob2.members[i];

	return newset;    // возвращаем модифицированное множество 
}

// –азность множеств
Set Set::operator - (Set ob2)
{
	Set newset = *this; //копируем первое множество

	// "вычитаем" элементы из второго множества
	for (int i = 0; i < ob2.len; i++)
		newset = newset - ob2.members[i];

	return newset;//возвращаем модифицированное множество 
}
