#include "OrderedList.h"
#include <cassert>

template<typename T>
OrderedList<T>::OrderedList(): List<T>(){}

template<typename T>
OrderedList<T>::~OrderedList()
{
	
	assert((*this).m_end);
	Node<T>* q = new Node<T>;
	Node<T>* p = new Node<T>;
	q = (*this).m_end;
	
	while (q)
	{
		std::cout << q->data << "!!\n";
		p = q->next;
		delete q;
		q = p;
		
		//std::cout << q->data << '\t';
		//q = q->next;
	}
	
	
	std::cout << "\nCleaned up!\n";
	(*this).m_top = nullptr;
	(*this).m_marker = nullptr;
	(*this).m_prev = nullptr;
	(*this).m_end = nullptr;
	
}
template<typename T>
void OrderedList<T>::doOrdered()
{
	Node<T>* q = new Node<T>;
	Node<T>* p = new Node<T>;
	q = (*this).m_end;

	while (q != (*this).m_top)
	{
		(*this).Reset();
		while ((*this).m_marker != q )//(!(*this).EoList()) optimally perform before q, not to the last 
		{
			if (q->data < (*this).m_marker->data) // only if compariable
			{
				p->data = q->data;
				q->data = (*this).m_marker->data;
				(*this).m_marker->data = p->data;
				//(*this).m_end->data = q->data;
			}
			(*this).Move();
		}
		q = q->next;
	}
}


template<typename T>
void OrderedList<T>::getFromFile(std::ifstream& in)
{
	assert(!in.fail());

	T data;
	in >> data;

	while (!in.eof())
	{
		(*this).Add(data);
		in >> data;
	}
	(*this).doOrdered();
}

template<typename T>
void OrderedList<T>::printToFile(std::ofstream& out)
{
	(*this).Reset();
	while (!(*this).EoList())
	{
		out << (*this).getMarked()->data << "\t";
		(*this).Move();
	}
	if ((*this).getMarked())
	{
		out << (*this).getMarked()->data << "\t";
	}
	out << "\n";
	(*this).Reset();
}

template<typename T>
OrderedList<T> OrderedList<T>::operator=(OrderedList list)
{
	/*if (this == &list)
	{
		return *this;
	}
	// need to clean this
	// ...
	*/
	list.Reset();
	if (!list.getEnd())
	{
		std::cout << "list is empty\n";
	}
	
	/*
	Create a new list 
	//OrderedList result;
	while (!list.EoList())
	{
		(*this).Add(list.m_marker->data);
		list.Move();
	}
	(*this).Add(list.m_marker->data);
	list.Reset();
	*/
	
	(*this).m_top = list.m_top;		// Better to create a new list!(ссылаюсь на имеющийся во имя экономии памяти, которая пока не очищается деструктором)
	(*this).m_marker = list.m_marker;
	(*this).m_prev = list.m_prev;
	(*this).m_end = list.m_end;
	(*this).m_size = list.m_size;
	
	return (*this);
}

template<typename T>
OrderedList<T> OrderedList<T>::operator+(OrderedList& second)
{
	OrderedList result;

	(*this).Reset();
	second.Reset();

	while (!(*this).EoList())
	{
		result.Add((*this).m_marker->data);
		(*this).Move();
	}
	result.Add((*this).m_marker->data);
	(*this).Reset();

	while (!(second).EoList())
	{
		result.Add(second.m_marker->data);
		second.Move();
	}
	result.Add(second.m_marker->data);
	second.Reset();

	result.m_size = (*this).m_size + second.m_size;
	result.doOrdered();
	result.Reset();
	return result;
}
template<typename T>
OrderedList<T> OrderedList<T>::operator^(OrderedList& second)
{
	OrderedList result;
	(*this).Reset();
	second.Reset();

	while (!(*this).EoList() && !second.EoList())
	{
		if ((*this).m_marker->data == second.m_marker->data)
		{
			//std::cout << (*this).m_marker->data << " == " << second.m_marker->data << "\n";
			result.Add((*this).m_marker->data);
			(*this).Move();
			second.Move();
		}
		if ((*this).m_marker->data < second.m_marker->data)
		{
			std::cout << (*this).m_marker->data << " < " << second.m_marker->data << "\n";
			(*this).Move();
		}
		if ((*this).m_marker->data > second.m_marker->data)
		{
			//std::cout << (*this).m_marker->data << " > " << second.m_marker->data << "\n";
			second.Move();
		}
	}
	if ((*this).m_marker->data == second.m_marker->data)//fails 333 ^ 33 = 333
	{
		result.Add((*this).m_marker->data);
	}

	(*this).Reset();
	second.Reset();

	result.doOrdered();
	return result;
}

template<typename T>
void OrderedList<T>::addElement(T value)
{
	// or.. we can simply add a new element and call doOrder()
	(*this).Add(value);
	(*this).doOrdered();

	/*(*this).Reset();
	Node<T>* q = new Node<T>;
	q->data = value;

	if ((*this).m_top->data > value)
	{
		(*this).Add(value);
	}
	else
	{
		while (!(*this).EoList() && ((*this).m_marked->data < value))// доходим до конца либо маркер перемещается на большее чем добавляемое и тогда просто добавим перед маркером
																	
																	
		{
			(*this).Move();
		}
		if (!(*this).EoList())													// на конце возможны два случая
		{
			if ((*this).m_marked->data < value)								// добавляемое больше последнего
			{
				q->next = (*this).m_end;
				(*this).m_end = q;
			}	
			else																// добавляемое меньше или равно последнему
			{
				(*this).Add(value);	
			}												
		}

	}	
	(*this).Reset();
	*/
}