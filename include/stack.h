#include<iostream>

using namespace std;
const int MAX_MEM_SIZE = 100000;

template<typename T>
class TStack {
	size_t memSize;
	T* pMem;
	int top;
public:
	TStack(size_t _memSize) : top(-1), memSize(_memSize), pMem(new T[memSize])
	{
		if (_memSize < 0 || _memSize > MAX_MEM_SIZE)
			throw "Invalid value";
	}
	~TStack()
	{
		delete[] this->pMem;
	}
	size_t getSize() const
	{
		return top +1 ;
	}
	void push(const T& val)
	{
		if (top == memSize - 1) {
			T* tmpMem = new T[memSize * 2];
			std::copy(pMem, pMem + memSize, tmpMem);
			delete[] pMem;
			this->pMem = tmpMem;
			memSize *= 2;
		}
		pMem[++top] = val;
	}
	T pop()
	{
		if (isEmpty())
			throw "stack is empty";

		return this->pMem[top--];
	}
	bool isEmpty() const
	{
		return top == -1;
	}
	bool isFull() const
	{
		return top == memSize - 1;
	}
	T getTop()
	{
		return this->pMem[top++];
	}

};