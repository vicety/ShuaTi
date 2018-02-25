//缺点： 增加新产品类型时需要修改工厂类 

#include<iostream>
using namespace std;
enum MAGICIANTYPE { FIRE, ICE };
class AbstractMagician;
class FireMagician;
class IceMagician;

class AbstractMagician {
public:
	virtual void showName() = 0;
	virtual ~AbstractMagician() {
		//使删除类的时候判断使用的析构函数根据其类型而非其指针类型 
		cout << "delete at base\n";
	}
};

class FireMagician :public AbstractMagician {
public:
	void showName() {
		cout << "A FireMagician\n";
	}
	~FireMagician() {
		cout << "delete at Fire\n";
	}
};

class IceMagician :public AbstractMagician {
public:
	void showName() {
		cout << "A IceMagician\n";
	}
	~IceMagician() {
		cout << "delete at Ice\n";
	}
};

// 不知道为什么注释的部分会报错 
class MagicianFactory {
public:
	static MagicianFactory& getInstance() {
		static MagicianFactory magicianFactory;
		return magicianFactory;
	}
	AbstractMagician* CreateMagician(MAGICIANTYPE magicianType) {
		switch (magicianType) {
			case FIRE:
				/*FireMagician* magician = new FireMagician();
				return magician;*/
				return new FireMagician();
				break;
			case ICE:
				/*IceMagician* _magician = new IceMagician();
				return _magician;*/
				return new IceMagician();
				break;
			default:
				return nullptr;
				break;
		}
		return null;
	}
private:
	MagicianFactory () {

	}
	MagicianFactory (const MagicianFactory&) {

	}
	MagicianFactory& operator = (const MagicianFactory&) {

	}
};



int main() {
	MagicianFactory &magicianFactory = MagicianFactory::getInstance();
	AbstractMagician* fireman = magicianFactory.CreateMagician(FIRE);
	AbstractMagician* iceman = magicianFactory.CreateMagician(ICE);
	//FireMagician* a = new FireMagician();
	fireman->showName();
	iceman->showName();
	system("pause");
	return 0;
}
