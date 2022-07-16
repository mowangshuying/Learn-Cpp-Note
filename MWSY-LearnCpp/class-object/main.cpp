#include <iostream>

class Student
{
public:
	Student() = default;

	Student(const std::string& name, int age) : m_name(name), m_age(age)
	{
		std::cout <<"funcname:" << "Student(const std::string& name, int age)" << " linenum:" << __LINE__ << std::endl;
	}

	// 拷贝构造函数
	// 如下情况将会调用拷贝构造函数
	// Student stu2(stu1);
	// Student stu2{stu1};
	Student(const Student& stu)
	{
		this->m_age = stu.getAge();
		this->m_name = stu.getName();
		std::cout << "funcname:" << "Student(const Student& stu)" << " linenum:" << __LINE__ << std::endl;
	}

	//转换构造函数
	//如下情况将会调用转换构造函数
	//Student stu{ 1 }
	//Student stu = 1;
	Student(int age) : m_age(age)
	{
		std::cout << "funcname:" << "Student(int age)" << " linenum:" << __LINE__ << std::endl;
	}

	//显式构造函数
	// 如下情况将会调用显式构造函数
	// Student stu{1}
	// 下面情况将不可调用
	// Student stu = 1
	//explicit Student(int age) : m_age(age)
	//{

	//}

	// 赋值构造
	Student& operator=(const Student& stu)
	{
		this->m_age = stu.m_age;
		this->m_name = stu.m_name;
		std::cout << "funcname:" << "Student& operator=(const Student& stu)" << " linenum:" << __LINE__ << std::endl;
		return *this;
	}

	~Student() 
	{
		std::cout << "funcname:" << "~Student() " << " linenum:" << __LINE__ << std::endl;
	}


	std::string getName() const
	{
		return m_name;
	}

	void setName(std::string& name)
	{
		m_name = name;
	}

	int getAge() const
	{
		return m_age;
	}

	void setAge(int age)
	{
		m_age = age;
	}

private:
	std::string m_name{ "" };
	int m_age{ 0 };
};

int main(int argc, char** argv)
{
	Student stu1{ "xiaohong",18 };
	// 会调用转换构造函数
	Student stu2 = 18;
	
	// 会调用拷贝构造函数
	// 而不是赋值操作
	Student stu3 = stu1;
	
	//会调用赋值操作
	Student stu4;
	stu4 = stu3;

	return 0;
}