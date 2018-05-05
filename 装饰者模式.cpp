#include <iostream>
#include <deque>
#include <string>
#include <functional>
using namespace std;

template<typename T>
class Sequence 
{
public:
	virtual void push(T& t) = 0;
	virtual void pop() = 0;
};

template<typename T>
class queue : public Sequence<T>
{
private:
	deque<T> dq;
public:
	void push(T& t)
	{
		dq.push_back(t);
	}
	void pop()
	{
		dq.pop_front();
	}
	void show()
	{
		for (const T& t : dq)
		{
			cout << t << "\t";
		}
		cout << endl;
	}
};

template<typename T>
class stack : public Sequence<T>
{
private:
	deque<T> dq;
public:
	void push(T& t)
	{
		dq.push_front(t);
	}
	void pop()
	{
		dq.pop_front();
	}
	void show()
	{
		for (const T& t : dq)
		{
			cout << t << "\t";
		}
		cout << endl;
	}
};
int main()
{
	/*
	适配器模式将原本的接口，封装成与现在需要的接口兼容的类
	STL中的queue和stack就直接由双端队列deque封装而来 
	*/
	queue<string> q;
	string str = "A";
	q.push(str);
	q.push(str = "B");
	q.push(str = "C");
	q.pop();
	q.show();
	
	stack<int> s;
	int a = 1;
	s.push(a);
	s.push(a = 2);
	s.push(a = 3);
	s.pop();
	s.show();
	
	return 0;
} 
