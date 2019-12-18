#pragma once
#include <stdlib.h>
using namespace std;

template <typename T>
class DListElement
{
private:
	DListElement* m_pPrev;
	DListElement* m_pNext;
	T m_data;

public:
	DListElement(const T& data = T(), DListElement* prev = nullptr, DListElement* next = nullptr);
	DListElement* getPrev() const;
	DListElement* getNext() const;
	const T& getData() const;
	T& getData();
	void setData(const T& data);
	void setNext(DListElement* next);
	void setPrev(DListElement* prev);
};

template <typename T>
DListElement<T>::DListElement(const T& data, DListElement* prev, DListElement* next)
{
	m_data = data;
	m_pPrev = prev;
	m_pNext = next;
}

template <typename T>
DListElement<T>* DListElement<T>::getPrev() const
{
	return m_pPrev;
}

template <typename T>
DListElement<T>* DListElement<T>::getNext() const
{
	return m_pNext;
}

template <typename T>
const T& DListElement<T>::getData() const
{
	return m_data;
}

template <typename T>
T& DListElement<T>::getData()
{
	return m_data;
}

template <typename T>
void DListElement<T>::setData(const T& data)
{
	m_data = data;
}

template<typename T>
inline void DListElement<T>::setNext(DListElement* next)
{
	if (next != this)
		m_pNext = next;
}

template<typename T>
inline void DListElement<T>::setPrev(DListElement* prev)
{
	if (prev != this)
		m_pPrev = prev;
}

template <typename T>
class DList
{
private:
	DListElement<T>* m_head;
	DListElement<T>* m_tail;

public:
	DList();
	DList(DList&& other);

	void addHead(const T& data);
	void addTail(const T& data);
	void change(const T& data, size_t index);
	T del(size_t number);
	int search(const T& data) const;
	size_t amountElements() const;

	const T& operator [](size_t index) const;
	T& operator [](size_t index);
	DList<T>& operator = (const DList<T>& other);

	~DList();
};

template<typename T>
inline DList<T>::DList()
{
	m_head = m_tail = nullptr;
}

template<typename T>
inline DList<T>::DList(DList&& other)
{
	m_head = other.m_head;
	m_tail = other.m_tail;
	other.m_head = nullptr;
	other.m_tail = nullptr;
}

template<typename T>
inline void DList<T>::addHead(const T& data)
{
	DListElement<T>* p = new DListElement<T>(data, nullptr, m_head);
	if (m_head == nullptr)
		m_head = m_tail = p;
	else
	{
		m_head->setPrev(p);
		m_head = p;
	}
}

template<typename T>
inline void DList<T>::addTail(const T& data)
{
	DListElement<T>* p = new DListElement<T>(data, m_tail, nullptr);
	if (m_head == nullptr)
		m_head = m_tail = p;
	else
	{
		m_tail->setNext(p);
		m_tail = p;
	}
}

template<typename T>
inline void DList<T>::change(const T& data, size_t index)
{
	if (index >= amountElements())
        throw "Выход за пределы списка";//invalid_argument("Выход за пределы списка");
	DListElement<T>* p = m_head;
	for (size_t i = 0; i < index; i++)
		p = p->getNext();
    p->setData(data);
}

template<typename T>
inline T DList<T>::del(size_t number)
{
	DListElement<T>* p = m_head;
	for (size_t i = 0; i < number; i++)
		p = p->getNext();
	if (p->getNext() != nullptr)
		p->getNext()->setPrev(p->getPrev());
	if (p->getPrev() != nullptr)
		p->getPrev()->setNext(p->getNext());
	if (p == m_head)
		m_head = m_head->getNext();
	if (p == m_tail)
		m_tail = m_tail->getPrev();
	T data = p->getData();
	delete p;
	return data;
}

template<typename T>
inline int DList<T>::search(const T& data) const
{
	DListElement<T>* p = m_head;
	int i = 0;
	while (p != m_tail)
	{
		if (p->getData() == data)
			return i;
		p = p->getNext();
		i++;
	}
	return -8;
}

template<typename T>
inline size_t DList<T>::amountElements() const
{
	size_t count = 0;
	DListElement<T>* p = m_head;
	while (p != nullptr)
	{
		p = p->getNext();
		count++;
	}
	return count;
}

template<typename T>
inline const T& DList<T>::operator[](size_t index) const
{
	if (index >= amountElements())
		throw "Выход за пределы списка";//std::invalid_argument("Выход за пределы списка");
	DListElement<T>* p = m_head;
	for (size_t i = 0; i < index; i++)
		p = p->getNext();
	return p->getData();
}

template<typename T>
inline T& DList<T>::operator[](size_t index)
{
	if (index >= amountElements())
		throw "Выход за пределы списка";//std::invalid_argument("Выход за пределы списка");
	DListElement<T>* p = m_head;
	for (size_t i = 0; i < index; i++)
		p = p->getNext();
	return p->getData();
}

template<typename T>
inline DList<T>& DList<T>::operator=(const DList<T>& other)
{
	if (other.m_head == nullptr)
	{
		m_head = nullptr;
		m_tail = nullptr;
		return *this;
	}

	m_head = new DListElement<T>(other.m_head->getData(), nullptr);

	DListElement<T>* p1 = other.m_head;
	DListElement<T>* p2 = m_head;

	while (p1->getNext() != nullptr)
	{
		p1 = p1->getNext();
		p2->setNext(new DListElement<T>(p1->getData(), p2));
	}

	m_tail = p2;

	return *this;
}

template<typename T>
inline DList<T>::~DList()
{
	if (m_head != nullptr)
	{
		while (m_head != m_tail)
		{
			m_head = m_head->getNext();
			delete m_head->getPrev();
		}
		delete m_head;
	}
}
