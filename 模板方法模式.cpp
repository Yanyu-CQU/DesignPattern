#include <iostream>
#include <string>
#include <string.h> 
using namespace std;


//父类
class Resume
{
protected:
	char *name;
public:
	Resume() {}
	virtual ~Resume() {}
	virtual Resume* Clone() { return NULL; }
	virtual void Set(char *n) {}
	virtual void Show() {}
};
class ResumeA : public Resume
{
public:
	ResumeA(const char *str);  //构造函数
	ResumeA(const ResumeA &r); //拷贝构造函数
	~ResumeA();                //析构函数
	ResumeA* Clone();          //克隆，关键所在
	void Show();               //显示内容
};
ResumeA::ResumeA(const char *str) 
{
	if(str == NULL) {
		name = new char[1]; 
		name[0] = '\0'; 
	}
	else {
		name = new char[strlen(str)+1];
		strcpy(name, str);
	}
}
ResumeA::~ResumeA() { delete [] name;}
ResumeA::ResumeA(const ResumeA &r) {
	name = new char[strlen(r.name)+1];
	strcpy(name, r.name);
}
ResumeA* ResumeA::Clone() {
	return new ResumeA(*this);
}
void ResumeA::Show() {
	cout<<"ResumeA name : "<<name<<endl; 
}

class ResumeB : public Resume
{
public:
	ResumeB(const char *str);  //构造函数
	ResumeB(const ResumeB &r); //拷贝构造函数
	~ResumeB();                //析构函数
	ResumeB* Clone();          //克隆，关键所在
	void Show();               //显示内容
};
ResumeB::ResumeB(const char *str) 
{
	if(str == NULL) {
		name = new char[1]; 
		name[0] = '\0'; 
	}
	else {
		name = new char[strlen(str)+1];
		strcpy(name, str);
	}
}
ResumeB::~ResumeB() { delete [] name;}
ResumeB::ResumeB(const ResumeB &r) {
	name = new char[strlen(r.name)+1];
	strcpy(name, r.name);
}
ResumeB* ResumeB::Clone() {
	return new ResumeB(*this);
}
void ResumeB::Show() {
	cout<<"ResumeB name : "<<name<<endl; 
}
int main()
{
	/*
	用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。
	其中有一个词很重要，那就是拷贝。可以说，拷贝是原型模式的精髓所在。
	举个现实中的例子来介绍原型模式。找工作的时候，我们需要准备简历。
	假设没有打印设备，因此需手写简历，这些简历的内容都是一样的。这样有个缺陷，
	如果要修改简历中的某项，那么所有已写好的简历都要修改，工作量很大。
	随着科技的进步，出现了打印设备。我们只需手写一份，然后利用打印设备复印多份即可。
	如果要修改简历中的某项，那么修改原始的版本就可以了，然后再复印。原
	始的那份手写稿相当于是一个原型，有了它，就可以通过复印（拷贝）创造出更多的新简历。
	*/
	Resume *r1 = new ResumeA("A");
	Resume *r2 = new ResumeB("B");
	Resume *r3 = r1->Clone();
	Resume *r4 = r2->Clone();
	r1->Show(); r2->Show();
	//删除r1,r2
	delete r1; delete r2;	
	r1 = r2 = NULL;
	//深拷贝所以对r3,r4无影响
	r3->Show(); r4->Show();
	delete r3; delete r4;
	r3 = r4 = NULL;
	return 0;
}
