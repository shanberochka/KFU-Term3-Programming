/*
«адание 1
»спользовать шаблоны
	1. ќписать класс List УЋинейный односв€зный списокФ.
	ѕримерна€ структура класса:
Х закрытые пол€: top, marker, prev Ц указатели на начало списка, на текущий элемент и на элемент перед текущим, соответственно;
Х открытые методы класса:
Ц конструктор List(coздаетс€ пустой список);
Ц Reset Ц установить маркер на начало;
Ц Move Ц сдвиг по списку на один шаг;
Ц EoList Ц проверка, не находитс€ ли marker на конце списка;
Ц Add Ц добавить элемент перед текущим после предыдущего;
Ц Del Ц удалить текущий элемента

	2. ќписать класс OrderedList У”пор€доченный линейный списокФ Ц наследник класса List.
	ћетоды класса OrderedList
Х конструктор OrderedList.
Х создание упор€доченного списка из элементов текстового файла;
Х объединение двух упор€доченных списка (с построением нового упор€доченного списка)Ц однопроходной алгоритм;
Х пересечение двух упор€доченных списков (с построением нового упор€доченного списка)Ц однопроходной алгоритм;
Х добавить элемент в упор€доченный линейный список;
Х вывести список в текстовый файл;
Х деструктор (с освобождением пам€ти).

	3. — использованием описанных классов составить программу дл€ решение следующей задачи:
Х построить три упор€доченных линейных списка l1, l2, l3. «начени€ вз€ть из
текстовых файлов;
Х построить и вывести четвертый список l4 = (l1Ul2)^l3.
Х добавить в l4 новый элемент с сохранением упор€доченности (значение вводитс€ с клавиатуры). –езультирующий список вывести на экран.
¬озможно добавление других методов в описание класса, если в этом возникает необходимость.
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
