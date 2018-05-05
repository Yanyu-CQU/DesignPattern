#include <iostream>
#include <string>
#include <list>
using namespace std;

class Observer
{
public:
	virtual void update() = 0;
};

class Blog
{
private:
	list<Observer*> list;
protected:
	string status;
public:
	virtual void addOb(Observer* ob)
	{
		list.push_back(ob);
	}
	virtual void remove(Observer* ob)
	{
		list.remove(ob);
	}
	virtual void setStatus(string& str)
	{
		status = str;
	}
	virtual string getStatus()
	{
		return status;
	}
	virtual void notify()
	{
		for (Observer* ob : list)
		{
			ob->update();
		}
	}
};

class CSDN : public Blog
{
private:
	string name;
public:
	CSDN(string& str) : name(str) {}
	virtual void setStatus(string& str) 
	{
		this->status = name + "'s CSDN blog's status: " + str;
	}
};

class Viewer : public Observer
{
private:
	string name;
	Blog* blog;
public:
	virtual void update()
	{
		string str = blog->getStatus();
		cout << name << " get the new status > " << str << endl;
	}
	Viewer(string& n, Blog* b = nullptr) : name(n), blog(b) {}
};

int main()
{
	/*
	定义对象间的一种一对多的依赖关系，当一个对象的状态发生改变时，
	所有依赖于它的对象都得到通知并被自动更新。
	*/
	string str = "yanyu";
	CSDN c(str);
	Viewer v1(str = "v1", &c), v2(str = "v2", &c);
	c.addOb(&v1);
	c.addOb(&v2);
	c.setStatus(str = "a new blog");
	c.notify();
	return 0;
}
