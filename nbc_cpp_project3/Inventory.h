#pragma once
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct BaseItem {
	int id_=-1;
	string name_;
	int price_=-1;
	void PrintInfo() const {
		cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
	}

};
bool compareItemsByPrice(BaseItem a, BaseItem b) {
	return a.price_ < b.price_;
}


template <typename T>
class Inventory {
private:
	T* pItems_;
	int capacity_;
	int size_;
	void resize(const int newSize);
public:
	Inventory(int capacity = 10);
	Inventory(const Inventory<T>& other);
	~Inventory();

	void assign(const Inventory<T>& other);
	void sortItems();
	
	void addItem(const T& item);
	void removeLastItem();
	void printAllItems();

	//const를 달면 내부값 변경을 할 수 없음.
	int getCapasity() const;
	int getSize() const;
};

template<typename T>
Inventory<T>::Inventory(int capacity) :capacity_(capacity=10) {
	this->size_ = 0;
	this->pItems_ = new T[capacity_];
}

template<typename T>
Inventory<T>::Inventory(const Inventory<T>& other) : size_(other.size_), capacity_(other.capacity_)
{
	this->pItems_ = new T[capacity_];
	copy(other.pItems_, other.pItems_ + getSize(), this->pItems_);

}

template<typename T>
Inventory<T>::~Inventory()
{
	delete[] pItems_;
}

template<typename T>
void Inventory<T>::assign(const Inventory<T>& other)
{
	if (pItems_ != nullptr) {
		delete[] this->pItems_;
	}
	this->capacity_ = other.capacity_;
	this->size_ = other.size_;
	this->pItems_ = new T[capacity_];
	copy(other.pItems_, other.pItems_ + getSize(), this->pItems_);

}

template<typename T>
void Inventory<T>::resize(const int newCapacity)
{
	//인벤토리가 늘어나는 경우
	if (newCapacity > getSize()) {
		T* newItems = new T[newCapacity];
		for (int i = 0; i < getSize(); i++) {
			newItems[i] = this->pItems_[i];
		}
		delete[] this->pItems_;
		this->pItems_ = newItems;

		this->capacity_ = newCapacity;
	}
	//인벤토리가 줄어든다면 새 크기를 초과하는 부분은 버리고 진행하도록.
	else {
		T* newItems = new T[newCapacity];
		for (int i = 0; i < newCapacity; i++) {
			newItems[i] = this->pItems_[i];
		}
		delete[] this->pItems_;
		this->pItems_ = newItems;
		this->size_ = this->size_ > newCapacity ? newCapacity : this->size_;//작은쪽으로
		this->capacity_ = newCapacity;


	}
}

template<typename T>
inline void Inventory<T>::sortItems()
{
	//기본 sort사용
	sort(pItems_, pItems_ + size_);
}


template<>
//BaseItem특화 정렬
inline void Inventory<BaseItem>::sortItems()
{
	//커스텀 정렬기준 사용.
	sort(pItems_, pItems_ + size_, compareItemsByPrice);
}


template<typename T>
void Inventory<T>::addItem(const T& item)
{
	if (getSize() == getCapasity()) {
		cout << "인벤토리 자동확장" << endl;
		resize(getCapasity() * 2);
	}

	this->pItems_[getSize()] = item;
	size_ += 1;
}

template<typename T>
void Inventory<T>::removeLastItem()
{
	if (size_ > 0) {
		//this->pItems_[this->size_] = NULL;
		size_ -= 1;

	}
}

template<typename T>
void Inventory<T>::printAllItems()
{
	cout << "현재 아이템 " << to_string(this->size_) << "개, 인벤토리 총 " << to_string(this->capacity_) << "칸 저장 가능" << endl;
	for (int i = 0; i < size_; i++) {
		cout << pItems_[i] << endl;
	}
}
//template<typename T>
//void CopyItem(Inventory<T> other) {
//
//}

//템플릿 특화, BaseItem에 대응하도록.
template<>
void Inventory<BaseItem>::printAllItems()
{
	cout << "현재 아이템 " << to_string(this->size_) << "개, 인벤토리 총 " << to_string(this->capacity_) << "칸 저장 가능" << endl;
	for (int i = 0; i < size_; i++) {
		BaseItem b = pItems_[i];
		b.PrintInfo();
	}
}

template<typename T>
int Inventory<T>::getCapasity() const
{
	return this->capacity_;
}

template<typename T>
int Inventory<T>::getSize() const
{
	return this->size_;
}

