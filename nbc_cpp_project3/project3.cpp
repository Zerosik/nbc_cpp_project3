#include <iostream>
#include <vector>
#include <string>
#include "Inventory.h"

using namespace std;

void drawLine() {
	std::cout << "────────────────────────────────────────" << std::endl;
}
int main() {
	Inventory<BaseItem>* inven = new Inventory<BaseItem>{};

	while (true) {
		drawLine();
		cout << "1. 아이템 추가, 2. 아이템삭제, 3. 정렬, 4.조회, 0. 종료" << endl;
		int select;	
		string name;int price;//아이템추가용
		cin >> select;
		switch (select) {
		case 1:
			cout << "이름과 가격 입력" << endl;
			cout << "이름 : ";
			cin >> name;
			cout << "가격 : ";
			cin >> price;
			inven->addItem(BaseItem(0, name, price));
			break;
		case 2:
			inven->removeLastItem();
			break;
		case 3:
			inven->sortItems();
			break;
		case 4:
			inven->printAllItems();
			break;
		case 0:
			break;
		default:
			cout << "입력오류" << endl;
		}
		if (select == 0) { break; }

	}
	delete inven;

	//기타등등 테스트한것
	/*inven.addItem(BaseItem(1, "item1", 1000));
	inven.addItem(BaseItem(2, "item2", 2000));
	inven.addItem(BaseItem(3, "item3", 3000));
	inven.addItem(BaseItem(4, "item4", 4000));
	inven.addItem(BaseItem(5, "item5", 5000));
	inven.printAllItems();

	cout << "현재 아이템 수 : " << inven.getSize() << ", 최대 아이템 수 : " << inven.getCapasity() << endl;
	drawLine();
	inven.removeLastItem();
	inven.removeLastItem();
	inven.printAllItems();

	cout << "2개 삭제후 아이템 수 : " << inven.getSize() << ", 최대 아이템 수 : " << inven.getCapasity() << endl;
	drawLine();
	cout << "복사본 생성 및 복사본에 아이템 1개 추가" << endl;
	Inventory<BaseItem> copied(inven);
	copied.addItem(BaseItem(999, "copy", 999999));


	inven.printAllItems();
	cout << "원본 아이템 수 : " << inven.getSize() << ", 최대 아이템 수 : " << inven.getCapasity() << endl;
	copied.printAllItems();
	cout << "복사본 아이템 수 : " << copied.getSize() << ", 최대 아이템 수 : " << copied.getCapasity() << endl;
	drawLine();

	cout << "대입 사용한 인벤토리 생성" << endl;
	Inventory<BaseItem> assigned;
	assigned.assign(inven);
	assigned.printAllItems();
	cout << "대입 아이템 수 : " << assigned.getSize() << ", 대입 아이템 수 : " << assigned.getCapasity() << endl;

	drawLine();
	cout << "아이템 10개 추가 전 크기" << inven.getCapasity() << endl;
	for (int i = 0; i < 10; i++) {
		inven.addItem(BaseItem{ i, "temp_"+to_string(i), i * 333});
	}
	cout << "아이템 10개 추가 후 크기" << inven.getCapasity() << endl;
	inven.printAllItems();
	drawLine();

	cout << "정렬후 내부 상태, 크기:" << inven.getCapasity() << endl;
	inven.sortItems();
	inven.printAllItems();

	drawLine();
	cout << "int타입 인벤토리 추가 및 정렬 테스트?" << endl;
	Inventory<int> inven2{ 10 };
	inven2.addItem(1000);
	inven2.addItem(4000);
	inven2.addItem(3000);
	inven2.addItem(2000);
	inven2.addItem(5000);
	inven2.sortItems();
	inven2.printAllIte*/
	return 0;
}