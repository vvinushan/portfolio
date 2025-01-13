#include "FlexArray.h"

FlexArray::FlexArray() {
	
	m_capacity = INITIALCAP;
	m_size = 0;
	m_tailroom = m_capacity / 2;
	m_headroom = m_capacity / 2 + m_capacity % 2;

	arr_ = new int[m_capacity];

	for (int i = 0; i < m_capacity; i++)
	{
		arr_[i] = 0;
	}
}

FlexArray::FlexArray(const int* arr, int size) {
	
	m_capacity = LO_THRESHOLD * size;
	m_size = size;
	
	m_tailroom = (m_capacity - m_size) / 2;
	m_headroom = (m_capacity - m_size) / 2 + (m_capacity - m_size) % 2;

	arr_ = new int[m_capacity];

	for (int i = 0; i < m_capacity; i++)
		arr_[i] = 0;

	for (int i = 0; i < m_size; i++)
	{
		arr_[i + m_headroom] = arr[i];
	}
}

FlexArray::~FlexArray() {
	
	delete[] arr_;
	arr_ = nullptr;
}

FlexArray::FlexArray(const FlexArray& other) {
	
	m_capacity = other.m_capacity;
	m_size = other.m_size;
	m_headroom = other.m_headroom;
	m_tailroom = other.m_tailroom;

	arr_ = new int[m_capacity];

	for (int i = 0; i < m_capacity; i++)
	{
		arr_[i] = other.arr_[i];
	}
}

FlexArray& FlexArray::operator=(const FlexArray& other) {
	
	if (&other != this)
	{
		delete[] arr_;
		
		m_capacity = other.m_capacity;
		m_size = other.m_size;
		m_headroom = other.m_headroom;
		m_tailroom = other.m_tailroom;

		arr_ = new int[m_capacity];

		for (int i = 0; i < m_capacity; i++)
		{
			arr_[i] = other.arr_[i];
		}
	}

	return *this;
}

int FlexArray::getSize() const {
	
	return m_size;
}

int FlexArray::getCapacity() const {
	
	return m_capacity;
}

string FlexArray::print() const {
	
	string tempPrint = "[";
	
	for (int i = 0; i < m_capacity; i++)
	{
		if (i > m_headroom && i < (m_headroom + m_size) + 1)
		{
			tempPrint = tempPrint + std::to_string(arr_[i - 1]);
			if (i < (m_headroom + m_size))
				tempPrint = tempPrint + ", ";
		}
	}
	
	tempPrint = tempPrint + "]";
	
	return tempPrint;
}

string FlexArray::printAll() const {
	
	string tempPrintAll = "[";

	for (int i = 0; i <= m_capacity; i++)
	{
		if (i < m_headroom || m_size == 0)
		{
			if (i != m_capacity)
				tempPrintAll = tempPrintAll + "X";
			if (i + 1 < m_capacity)
				tempPrintAll = tempPrintAll + ", ";
		}
		else if (i > m_headroom && i < (m_headroom + m_size) + 1)
		{
			tempPrintAll = tempPrintAll + std::to_string(arr_[i - 1]);
			if (i < (m_headroom + m_size) || m_tailroom != 0)
				tempPrintAll = tempPrintAll + ", ";
		}
	}

	for (int j = 0; j < m_tailroom; j++)
	{
		if (m_size != 0)
		{
			tempPrintAll = tempPrintAll + "X";
			if (j + 1 < m_tailroom)
				tempPrintAll = tempPrintAll + ", ";
		}
	}

	tempPrintAll = tempPrintAll + "]";
	
	return tempPrintAll;
}

int FlexArray::get(int i) const {
	
	if (i + m_headroom < m_capacity)
		return arr_[i + m_headroom];
}

bool FlexArray::set(int i, int v) {
	
	for (int j = 0; j < m_capacity; j++)
		if (j > m_headroom && i >= 0)
		{
			if (i + j < (m_headroom + m_size + 1))
			{
				arr_[j + i - 1] = v;
				return true;
				break;
			}
		}

	return false;
}

void FlexArray::push_back(int v) {
	
	int lastElement;
	
	if (m_size == 0)
	{	
		m_tailroom = m_capacity / 2;
		m_headroom = (m_capacity / 2) + (m_capacity % 2);
		
		if (m_capacity % 2 == 0)
			lastElement = m_capacity / 2 - 1;
		else
			lastElement = m_capacity / 2;
		
		arr_[lastElement] = v;
		m_headroom = m_headroom - 1;
		m_size = m_size + 1;
	}
	else if (m_tailroom != 0)
	{
		lastElement = m_headroom + m_size;
		if (lastElement != m_capacity)
			arr_[lastElement] = v;
		m_size = m_size + 1;
		m_tailroom = m_tailroom - 1;
	}
	else if (m_tailroom == 0)
	{
		// resize array
		resizeArr();
		push_back(v);
	}
}

bool FlexArray::pop_back() {
	
	if (m_size == 0)
		return false;
	else
	{
		arr_[m_headroom + m_size] = -1;
		m_tailroom = m_tailroom + 1;
		m_size = m_size - 1;
		
		if (m_size == 0)
		{
			m_tailroom = (m_capacity - m_size) / 2;
			m_headroom = (m_capacity - m_size) / 2 + (m_capacity - m_size) % 2;
		}

		checkCapacity();

		return true;
	}
}

void FlexArray::push_front(int v) {
	
	int firstElement;
	
	if (m_size == 0)
	{
		m_tailroom = m_capacity / 2;
		m_headroom = (m_capacity / 2) + (m_capacity % 2);
		
		if (m_capacity % 2 == 0)
			firstElement = m_capacity / 2 - 1;
		else
			firstElement = m_capacity / 2;
		
		arr_[firstElement] = v;
		m_headroom = m_headroom - 1;
		m_size = m_size + 1;
	}
	else if (m_headroom != 0)
	{
		firstElement = m_headroom;
		arr_[firstElement - 1] = v;
		m_size = m_size + 1;
		m_headroom = m_headroom - 1;
	}
	else if (m_headroom == 0)
	{
		// resize array
		resizeArr();
		push_front(v);
	}
}

bool FlexArray::pop_front() {
	
	if (m_size == 0)
		return false;
	else
	{
		arr_[m_headroom - 1] = -1;
		m_headroom = m_headroom + 1;
		m_size = m_size - 1;

		if (m_size == 0)
		{
			m_tailroom = (m_capacity - m_size) / 2;
			m_headroom = (m_capacity - m_size) / 2 + (m_capacity - m_size) % 2;
		}

		checkCapacity();

		return true;
	}
}

bool FlexArray::insert(int i, int v) {
	
	const int insertIndex = m_headroom + i;
	int leftOfInsert = 0;
	int rightOfInsert = 0;
	
	if (m_size == 0 && i == 0)
	{	
		push_back(v);
		return true;
	}
	else if (m_size < m_capacity && i >= 0 && i <= m_size)
	{
		for (int j = m_headroom; j < insertIndex; j++)
			leftOfInsert = leftOfInsert + 1;

		for (int j = insertIndex; j < m_headroom + m_size; j++)
			rightOfInsert = rightOfInsert + 1;

		if ((leftOfInsert < rightOfInsert && m_headroom > 0) || m_tailroom == 0) // shift left
		{
			for (int k = 0; k < insertIndex; k++)
				arr_[k] = arr_[k + 1];

			arr_[insertIndex - 1] = v;
			m_headroom = m_headroom - 1;
			m_size = m_size + 1;
			return true;
		}
		else if (leftOfInsert >= rightOfInsert || m_headroom == 0) // shift right
		{
			arr_[m_capacity - 1] = arr_[m_capacity];
			
			for (int k = m_capacity; k > insertIndex; k--)
				arr_[k] = arr_[k - 1];

			arr_[insertIndex] = v;
			m_tailroom = m_tailroom - 1;
			m_size = m_size + 1;
			return true;
		}
	}
	else if (m_size == m_capacity)
	{
		// resize array
		resizeArr();
		insert(i, v);
	}

	return false;
}

bool FlexArray::erase(int i) {
	
	const int eraseIndex = m_headroom + i;
	int leftOfErase = 0;
	int rightOfErase = 0;
	
	if (m_size == 0)
		return false;
	else if (i >= 0 && i <= m_size - 1)
	{
		for (int j = m_headroom; j < eraseIndex; j++)
			leftOfErase = leftOfErase + 1;

		for (int j = eraseIndex + 1; j < m_headroom + m_size; j++)
			rightOfErase = rightOfErase + 1;

		if (leftOfErase >= rightOfErase) // right elements shift left
		{
			arr_[eraseIndex] = arr_[eraseIndex + 1];

			for (int k = eraseIndex; k < m_capacity - 1; k++)
				arr_[k + 1] = arr_[k];


			m_tailroom = m_tailroom + 1;
			m_size = m_size - 1;

			checkCapacity();
			return true;
		}
		else if (leftOfErase < rightOfErase) // left elements shift right
		{
			arr_[eraseIndex] = arr_[eraseIndex - 1];

			for (int k = 0; k < eraseIndex - 1; k++)
				arr_[k + 1] = arr_[k];


			m_headroom = m_headroom + 1;
			m_size = m_size - 1;

			checkCapacity();
			return true;
		}
	}
	else if (m_size - 1 == 0)
	{
		m_tailroom = m_capacity / 2;
		m_headroom = m_capacity / 2 + m_capacity % 2;
		m_size = m_size - 1;
		return true;
	}
	return false;
}

void FlexArray::resizeArr()
{
	int* tempArr_;
	tempArr_ = new int[m_size];

	for (int i = 0; i < m_size; i++)
		tempArr_[i] = arr_[i + m_headroom];

	delete[] arr_;

	m_capacity = LO_THRESHOLD * m_size;

	m_tailroom = (m_capacity - m_size) / 2;
	m_headroom = (m_capacity - m_size) / 2 + (m_capacity - m_size) % 2;

	arr_ = new int[m_capacity];

	for (int i = 0; i < m_capacity; i++)
		arr_[i] = 0;

	for (int i = 0; i < m_size; i++)
		arr_[i + m_headroom] = tempArr_[i];

	delete[] tempArr_;
	tempArr_ = nullptr;
}

void FlexArray::checkCapacity()
{
	if (m_capacity > (m_size * HI_THRESHOLD))
		if (m_size != 0)
			resizeArr();
}

