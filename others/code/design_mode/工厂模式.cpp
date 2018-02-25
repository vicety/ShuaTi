// 虚拟生产线
// 实际生产线 每种生产线对应一种产品 

#include<iostream>
using namespace std;
class AbstractMagician {
public:
	virtual void show() = 0;
	virtual ~AbstractMagician() {

	}
};
class FireMagician :public AbstractMagician {
public:
	void show() {
		cout << "A FireMagician\n";
	}
};
class IceMagician :public AbstractMagician {
public:
	void show() {
		cout << "A IceMagician\n";
	}
};
class AbstractMagicianFactory {
public:
	virtual AbstractMagician* CreateMagician() = 0;
};
class FireMagicianFactory :public AbstractMagicianFactory {
public:
	AbstractMagician* CreateMagican() {
		return new FireMagician();
	}
};
class IceMagicianFactory :public AbstractMagicianFactory {
public:
	AbstractMagician* CreateMagican() {
		return new IceMagician();
	}
};
int main() {
	FireMagicianFactory fireMagicianFactory;
	IceMagicianFactory iceMagicianFactory;
	AbstractMagician* iceman = iceMagicianFactory.CreateMagican();
	AbstractMagician* fireman = fireMagicianFactory.CreateMagican();
	iceman->show();
	fireman->show();
}
