/*
구현부를 cpp로 분리하면 오류발생함
+	일반적으로 헤더에 구현하는게 맞다고하는데
	과제2번떄는 왜 cpp로 구현을했을까?
	c++의세계 쉽지않다
*/


//#include "Inventory.h"
//
//
//template<typename T>
//Inventory<T>::Inventory(int capacity):capacity_(capacity) {
//	pItems_ = new T[capacity_];
//}
//
//template<typename T>
//Inventory<T>::~Inventory()
//{
//	delete[] pItems_;
//}
//
//template<typename T>
//void Inventory<T>::addItem(const T& item)
//{
//	this->pItems_[this->size_] = item;
//	size_ += 1;
//}
//
//template<typename T>
//void Inventory<T>::removeLastItem()
//{
//	this->pItems_[this->size_] = nullptr;
//	size_ -= 1;
//}
//
//template<typename T>
//void Inventory<T>::printAllItems()
//{
//	/*for (Item i : this->pItems_) {
//		cout << "아이템 : " << i.name_ << ", 가격 : " << i.price_ << endl;
//	}*/
//}
//
//template<typename T>
//int Inventory<T>::getCapasity() const
//{
//	return this->capacity_;
//}
//
//template<typename T>
//int Inventory<T>::getSize() const
//{
//	return this->size_;
//}
