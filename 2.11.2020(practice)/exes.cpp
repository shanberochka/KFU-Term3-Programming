/*
������� 1
������������ �������
	1. ������� ����� List ��������� ����������� ������.
	��������� ��������� ������:
� �������� ����: top, marker, prev � ��������� �� ������ ������, �� ������� ������� � �� ������� ����� �������, ��������������;
� �������� ������ ������:
� ����������� List(co������� ������ ������);
� Reset � ���������� ������ �� ������;
� Move � ����� �� ������ �� ���� ���;
� EoList � ��������, �� ��������� �� marker �� ����� ������;
� Add � �������� ������� ����� ������� ����� �����������;
� Del � ������� ������� ��������

	2. ������� ����� OrderedList �������������� �������� ������ � ��������� ������ List.
	������ ������ OrderedList
� ����������� OrderedList.
� �������� �������������� ������ �� ��������� ���������� �����;
� ����������� ���� ������������� ������ (� ����������� ������ �������������� ������)� ������������� ��������;
� ����������� ���� ������������� ������� (� ����������� ������ �������������� ������)� ������������� ��������;
� �������� ������� � ������������� �������� ������;
� ������� ������ � ��������� ����;
� ���������� (� ������������� ������).

	3. � �������������� ��������� ������� ��������� ��������� ��� ������� ��������� ������:
� ��������� ��� ������������� �������� ������ l1, l2, l3. �������� ����� ��
��������� ������;
� ��������� � ������� ��������� ������ l4 = (l1Ul2)^l3.
� �������� � l4 ����� ������� � ����������� ��������������� (�������� �������� � ����������). �������������� ������ ������� �� �����.
�������� ���������� ������ ������� � �������� ������, ���� � ���� ��������� �������������.
*/

#include <iostream>
//#include "List.h"
//#include "List.cpp"
#include "OrderedList.h"
#include "OrderedList.cpp"

void ex()
{
	
	OrderedList<int> orderList1;
	std::ifstream in("list1.txt");
	orderList1.getFromFile(in);
	in.close();

	OrderedList<int> orderList2;
	in.open("list2.txt");
	orderList2.getFromFile(in);
	in.close();

	OrderedList<int> orderList3;
	in.open("list3.txt");
	orderList3.getFromFile(in);
	in.close();
	
	OrderedList<int> orderList4;
	std::ofstream out("out.txt");

	orderList4 = (orderList1 + orderList2) ^ orderList3;

	std::cout << "\t Enter the value: ";
	int value;
	std::cin >> value;
	orderList4.addElement(value);

	orderList4.printToFile(out);
	out.close();

	//std::cout << (orderList1 + orderList2).getSize() << "\n";
	//orderList2.addElement(99);
	//orderList3 = (orderList1 + orderList2);
	//orderList3.printToFile(out);
	//(orderList1 + orderList2).printToFile(out);
	//std::cout << (orderList3).getMarked()->data << "\n";
	//(orderList1 ^ orderList2).printToFile(out);	
}
