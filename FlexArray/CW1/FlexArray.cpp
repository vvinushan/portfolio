#include "FlexArray.h"

FlexArray::FlexArray() {
	// IMPLEMENT ME
	m_capacity = INITIALCAP;
	m_size = 0;
	m_headroom = m_capacity - m_size;
	m_tailroom = 0;

	arr_ = new int[m_capacity];
}

FlexArray::FlexArray(const int* arr, int size) {
	// IMPLEMENT ME
	m_capacity = LO_THRESHOLD * size;
	m_size = size;

	//int middle = (m_capacity - m_size) / 2;
	m_headroom = middle();
	m_tailroom = middle();
	
	arr_ = new int[m_capacity];
	
	//arr_[(m_headroom + 1)] = *arr;

	/*for (int i = 0; i < m_headroom; i++)
		arr_[i] = -1;*/
	emptySpaces();

	for (int i = m_headroom - 1; i < m_size; i++)
	{
		if (arr[i] != -1)
			arr_[i] = arr[i];
	}
}

FlexArray::~FlexArray() {
	// IMPLEMENT ME
	delete[] arr_;
	arr_ = nullptr;
}

FlexArray::FlexArray(const FlexArray& other) {
	// IMPLEMENT ME

	arr_ = new int[other.m_capacity];

	for (int i = 0; i < other.m_capacity; i++)
	{
		arr_[i] = other.arr_[i];
	}
}

FlexArray& FlexArray::operator=(const FlexArray& other) {
	// IMPLEMENT ME
	if (&other != this)
	{
		m_capacity = other.m_capacity;
		m_size = other.m_size;
		m_headroom = other.m_headroom;
		m_tailroom = other.m_tailroom;
		
		

		FlexArray copyArr_(other);

		delete[] arr_;
	}

	return *this;
}

int FlexArray::getSize() const {
	// IMPLEMENT ME
	return m_size;

	//return -1; // dummy
}

int FlexArray::getCapacity() const {
	// IMPLEMENT ME
	return m_capacity;

	//return -1; // dummy
}

string FlexArray::print() const {
	// IMPLEMENT ME
	string tempPrint;
	int i;

	for (i = 0; i < m_size; i++)
	{
		if (arr_[i] != -1)
		{
			tempPrint = "[" + std::to_string(arr_[0]);
			break;
		}
	}
	
	//string tempPrint = "[" + std::to_string(arr_[0]);
	
	for (int j = i + 1; j < m_size; j++)
	{
		if (arr_[j] != -1)
			tempPrint = tempPrint + ", " + std::to_string(arr_[i]);
	}
	return tempPrint + "]";

	//return ""; // dummy
}

string FlexArray::printAll() const {
	// IMPLEMENT ME
	string tempPrintAll;

	if (arr_[0] != -1)
		tempPrintAll = "[" + std::to_string(arr_[0]);
	else
		tempPrintAll = "[X";
	
	for (int i = 0; i < m_size; i++)
	{
		if (arr_[i] != -1)
			tempPrintAll = tempPrintAll + ", " + std::to_string(arr_[i]);
		else
			tempPrintAll = tempPrintAll + ", X";
	}
	return tempPrintAll + "]";

	//return ""; // dummy
}

int FlexArray::get(int i) const {
	// IMPLEMENT ME
	int j;
	for (j = 0; j < m_capacity; j++)
		if (arr_[j] != -1)
		{
			break;
		}

	return arr_[(i + j)];

	//return -1; // dummy
}

bool FlexArray::set(int i, int v) {
	// IMPLEMENT ME
	for (int j = 0; j < m_capacity; j++)
		if (arr_[j] != -1)
		{
			arr_[j + i] = v;
			return true;
			break;
		}

	return false;
	//return false; // dummy
}

void FlexArray::push_back(int v) {
	// IMPLEMENT ME

}

bool FlexArray::pop_back() {
	// IMPLEMENT ME

	return false; // dummy
}

void FlexArray::push_front(int v) {
	// IMPLEMENT ME

}

bool FlexArray::pop_front() {
	// IMPLEMENT ME

	return false; // dummy
}

bool FlexArray::insert(int i, int v) {
	// IMPLEMENT ME

	return false; // dummy
}

bool FlexArray::erase(int i) {
	// IMPLEMENT ME

	return false; // dummy
}

void FlexArray::emptySpaces()
{
	for (int i = 0; i < m_headroom; i++)
		arr_[i] = -1;
	for (int j = m_headroom + m_size; j < m_capacity; j++)
		arr_[j] = -1;
}

int FlexArray::middle()
{
	return m_capacity / 2;
}

//int FlexArray::firstElement()
//{
//	int i;
//	for (i = 0; i < m_size; i++)
//		if (&arr_[i] != nullptr)
//		{
//			break;
//		}
//
//	return i;
//}



