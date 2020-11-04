#include "Set.h"
#include <iostream>
int Set::find(char ch)
{
	int i;
	for (i = 0; i < len; i++)
		if (members[i] == ch) return i;

	return -1;
}

// ���������� ���������� ���������
void Set::showset()
{
	std::cout << "{";
	for (int i = 0; i < len; i++)
		std::cout << members[i] << " ";
	std::cout << "}" << std::endl;
}

/* ������� ���������� ��������  true .���� ������ ch �������� ������ ���������, � ��������� ������ ������������ ��������  false
 */
bool Set::isMember(char ch)
{
	if (find(ch) != -1) return true;
	return false;
}

// ���������� ������ �������� � ���������
Set Set::operator +(char ch)
{
	Set newset;
	if (len == MaxSize)
	{
		std::cout << " ��������� ��������� /n";
		return *this;
		//���������� ������������   ���������
	}
	newset = *this;// ��������� ������������ ���������

// ��������� ���������� �� ��� � ��������� ����� �������
	if (find(ch) == -1)

		//���� ����� ������� �� ������ 
		 //��� ����� ��������� � ���������
		 //  �������� ����� ������� � ����� ���������
	{
		newset.members[newset.len++] = ch;
		//newset.len++;
	}
	return newset;
}

// ������� ������� �� ���������
Set Set::operator - (char ch)
{
	Set newset;
	int i = find(ch);//���������� ������� ��������  -1 ����
// �������� ������� �� ����� ������ � ���������

//�������� � ��������� ���������� ��������
	for (int j = 0; j < len; j++)
		if (j != i) newset = newset + members[j];
	return newset;

}


// ����������� ��������
Set Set::operator + (Set ob2)
{
	Set newset = *this; //�������� ������ ���������

	//��������� � ������ ��������� ���������� �������� �� 
	//������� 
	for (int i = 0; i < ob2.len; i++)
		newset = newset + ob2.members[i];

	return newset;    // ���������� ���������������� ��������� 
}

// �������� ��������
Set Set::operator - (Set ob2)
{
	Set newset = *this; //�������� ������ ���������

	// "��������" �������� �� ������� ���������
	for (int i = 0; i < ob2.len; i++)
		newset = newset - ob2.members[i];

	return newset;//���������� ���������������� ��������� 
}
