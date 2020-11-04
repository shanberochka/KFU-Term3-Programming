#pragma once
const int MaxSize = 100;
class Set
{
	int len;
	char members[MaxSize];
	int find(char ch);

public:
	Set() { len = 0; }

	// ��������� ���������� ��������� � ���������
	int getLength() { return len; }

	void showset();// ����������� ��������
	bool isMember(char ch);//�������� ��������

	Set operator +(char ch);
	// ���������� �������� 
	Set operator -(char ch);
	// �������� �������� 
	Set operator +(Set ob2);
	// ����������� �������� 
	Set operator -(Set ob2);// ��������� �������� ��������

};

