#include <iostream>

class ClassObject
{
public:
	std::string getName()
	{
		return name_;
	}

	void setName(const std::string& name)
	{
		name_ = name;
	}
private:
	std::string name_ = "ClassObject";
};

int main(int argc, char** argv)
{
	ClassObject co;
	// 声明类成员的函数指针
	std::string (ClassObject::*rawGetFuncPtr)() = &ClassObject::getName;
	std::cout<<"rawGetFuncPtr:"<<(co.*rawGetFuncPtr)() << std::endl;

	//(co.*rawGetFuncPtr)();

	// 通过使用using定义函数的别名
	using UsingGetFuncPtr = std::string(ClassObject::*)();
	UsingGetFuncPtr usingGetFuncPtr = &ClassObject::getName;
	std::cout << "usingGetFuncPtr call:"<<(co.*usingGetFuncPtr)() << std::endl;

	// 通过auto自动推导函数类型
	auto autoGetFuncPtr = &ClassObject::getName;
	std::cout << "autoGetFuncPtr call:" << (co.*autoGetFuncPtr)() << std::endl;


	auto autoSetFuncPtr = &ClassObject::setName;
	// 通过绑定类成员函数(setName)，调用此函数
	(co.*autoSetFuncPtr)("newNameOfClassObject");
	std::cout << "After autoSetFuncPtr call:co.getName()=" << co.getName() << std::endl;

	return 0;
}