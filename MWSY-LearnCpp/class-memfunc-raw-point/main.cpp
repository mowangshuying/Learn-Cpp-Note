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
	// �������Ա�ĺ���ָ��
	std::string (ClassObject::*rawGetFuncPtr)() = &ClassObject::getName;
	std::cout<<"rawGetFuncPtr:"<<(co.*rawGetFuncPtr)() << std::endl;

	//(co.*rawGetFuncPtr)();

	// ͨ��ʹ��using���庯���ı���
	using UsingGetFuncPtr = std::string(ClassObject::*)();
	UsingGetFuncPtr usingGetFuncPtr = &ClassObject::getName;
	std::cout << "usingGetFuncPtr call:"<<(co.*usingGetFuncPtr)() << std::endl;

	// ͨ��auto�Զ��Ƶ���������
	auto autoGetFuncPtr = &ClassObject::getName;
	std::cout << "autoGetFuncPtr call:" << (co.*autoGetFuncPtr)() << std::endl;


	auto autoSetFuncPtr = &ClassObject::setName;
	// ͨ�������Ա����(setName)�����ô˺���
	(co.*autoSetFuncPtr)("newNameOfClassObject");
	std::cout << "After autoSetFuncPtr call:co.getName()=" << co.getName() << std::endl;

	return 0;
}