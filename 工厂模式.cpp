#include <iostream>
#include <string>

using namespace std;

enum CoreType
{
	coreA,
	coreB
};
class Core
{
public:
	virtual void show() = 0;
};

class SingleCoreA : public Core
{
public:
	void show()
	{
		cout << "single core A!" << endl;
	}
};

class SingleCoreB : public Core
{
public:
	void show()
	{
		cout << "single core B!" << endl;
	}
};


/********************简单工厂模式************************/
//需要哪种产品，直接在工厂类中判断
//增加新产品时，需要修改工厂类，违反开放封闭原则（软件实体可以扩展，不可修改）
/*
class Factory
{
public:
	Core* getCore(CoreType type)
	{
		if (type == CoreType::coreA)
			return new SingleCoreA();
		else if (type == CoreType::coreB)
			return new SingleCoreB();
	}
};*/


/********************工厂方法模式****************************/
//每种工厂生产专门的产品
//增加新产品时，就要增加新的工厂
/*
class Factory
{
public:
	virtual Core* getCore() = 0;
};
class FactoryA : public Factory
{
public:
	SingleCoreA* getCore()
	{
		return new SingleCoreA();
	}
};
class FactoryB : public Factory
{
public:
	SingleCoreB* getCore()
	{
		return new SingleCoreB();
	}
};*/


/********************抽象工厂模式***********************/
//每个工厂，生产一系列类似产品
class MultiCore      
{    
public:    
    virtual void show() = 0;  
};    
class MultiCoreA : public MultiCore      
{    
public:    
    void show() { cout<<"Multi Core A"<<endl; }    
    
};
class MultiCoreB : public MultiCore      
{    
public:    
    void show() { cout<<"Multi Core B"<<endl; }    
};
//工厂    
class CoreFactory      
{
public:    
    virtual Core* CreateSingleCore() = 0;  
    virtual MultiCore* CreateMultiCore() = 0;  
};    
//工厂A，专门用来生产A型号的处理器    
class FactoryA :public CoreFactory    
{    
public:    
    SingleCoreA* CreateSingleCore() { return new SingleCoreA(); }    
    MultiCoreA* CreateMultiCore() { return new MultiCoreA(); }    
};    
//工厂B，专门用来生产B型号的处理器    
class FactoryB : public CoreFactory    
{    
public:    
    SingleCoreB* CreateSingleCore() { return new SingleCoreB(); }    
    MultiCoreB* CreateMultiCore() { return new MultiCoreB(); }    
};

int main()
{
	/********工厂模式*******/
	/*
	Factory fac;
	SingleCoreA* ptr = dynamic_cast<SingleCoreA*>(fac.getCore(coreA));
	ptr->show();*/
	
	/*******工厂方法模式*******/
	/*
	FactoryB facB;
	SingleCoreB* ptr = facB.getCore();
	ptr->show();*/
	
	/*******抽象工厂模式*******/
	FactoryA facA;
	MultiCoreA* ptr = facA.CreateMultiCore();
	ptr->show();
	
	return 0;
}
