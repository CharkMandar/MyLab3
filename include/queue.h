#include <iostream>

const int MAX_QUEUE_SIZE = 10000;
using namespace std;

template<typename T>
class TQueue {
	T* pMem;
	int front;
	int back;
	size_t memSize;
public:
	TQueue(size_t size)
	{
		if (size < 0 || size > MAX_QUEUE_SIZE)
			throw "Invalid value";
		this->memSize = size;
		this->pMem = new T[size];
		this->front = -1;
		this->back = -1;
	}
	~TQueue()
	{
		delete[] this->pMem;
	}
	T pop()
	{

		if (this->isEmpty())
			throw "Queue is empty";
		if (front == back) {
			front = -1;
			back = -1;
		}
		return this->pMem[++front];
	}
	void push(const T& val)
	{

		if (isFull()) {
			T* tmpMem = new T[memSize * 2];
			std::copy(pMem, pMem + memSize, tmpMem);
			delete[] pMem;
			this->pMem = tmpMem;
			this->memSize *= 2;
		}
		if (this->front == -1)
			this->front = 0;
		if (back < memSize - 1)
			this->pMem[++back] = val;
		else {
			this->back = -1;
			this->pMem[++back] = val;
		}
		
	}

	size_t getSize() const
	{
		return this->back + 1;
	}
	bool isFull()
	{
		if (front == 0 && back == memSize - 1) {
			return 1;
		}
		if (front == back + 1) {
			return 1;
		}
		return 0;
	}
	bool isEmpty()
	{
		return front == -1;
	}

	int getFront()
	{
		return this->pMem[front];
	}

	int getBack()
	{
		return this->pMem[back];
	}

};