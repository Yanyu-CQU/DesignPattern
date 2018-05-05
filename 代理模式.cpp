#include <iostream>
#include <string>
using namespace std;

class Image
{
public:
	Image(string name): m_imageName(name) {}
	virtual ~Image() {}
	virtual void Show() {}
protected:
	string m_imageName;
};
class BigImage: public Image
{
public:
	BigImage(string name):Image(name) {}
	~BigImage() {}
	void Show() { cout<<"Show big image : "<<m_imageName<<endl; }
};
class BigImageProxy: public Image
{
private:
	BigImage *m_bigImage;
public:
	BigImageProxy(string name):Image(name),m_bigImage(0) {}
	~BigImageProxy() { delete m_bigImage; }
	void Show() 
	{
		if(m_bigImage == NULL)
			m_bigImage = new BigImage(m_imageName);
		m_bigImage->Show();
	}
};

int main()
{
	/*
	考虑一个可以在文档中嵌入图形对象的文档编辑器。有些图形对象的创建开销很大。但是打开文档必须很迅速，
	因此我们在打开文档时应避免一次性创建所有开销很大的对象。这里就可以运用代理模式，在打开文档时，并不打开图形对象，
	而是打开图形对象的代理以替代真实的图形。待到真正需要打开图形时，仍由代理负责打开。
	*/ 
	Image *image = new BigImageProxy("proxy.jpg"); //代理
	image->Show(); //需要时由代理负责打开
	delete image;
	return 0;
}
