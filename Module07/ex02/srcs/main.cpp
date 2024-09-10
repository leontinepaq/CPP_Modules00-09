#include <iostream>
#include <Array.hpp>

#include <cstdlib>
#include <ctime>

#define MAIN_NB 0

#define MAX_VAL 750
#define RAND_VALUE 42

class TestClass
{
	public:
		TestClass() : _value(0) {}
		TestClass(int value) : _value(value) {}
		TestClass(TestClass const &src) : _value(src._value) {}
		void operator=(TestClass const &src) { _value = src._value; }
		~TestClass() {}
		int getValue(void) const { return _value; }
		void setValue(int value) { _value = value; }
	private:
		int _value;
};

#if MAIN_NB == 0
int main(int, char**)
{

	std::cout << ORANGE "TEST WITH INT ARRAY" RESET << std::endl;
	std::cout << YELLOW "> Creating a new Array<int> with a size of " << MAX_VAL << RESET << std::endl;
	Array<int> array1(MAX_VAL);
	std::cout << YELLOW "> Creating an array of int with a size of " << MAX_VAL << RESET << std::endl;
	int* intTab = new int[MAX_VAL];
	std::cout << YELLOW "> Filling the Array<int> and the int array with random values" << RESET << std::endl;
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		array1[i] = value;
		intTab[i] = value;
	}
	std::cout << YELLOW "> Comparing the values of the Array<int> and the int array" << RESET << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (intTab[i] != array1[i])
		{
			std::cerr << RED "didn't save the same value!!" RESET << std::endl;
			return 1;
		}
	}
	std::cout<< GREEN "All values are the same" RESET << std::endl;
	std::cout << YELLOW "> Deleting the int array" << RESET << std::endl;
	delete [] intTab;
	std::cout << std::endl;
	
	std ::cout << std::endl;
	
	{
		std::cout << YELLOW "> Creating a second Array<int> by default" << RESET << std::endl;
		Array<int> array2;
		std::cout << YELLOW "> Size of the second Array<int>" RESET << std::endl;
		std::cout << WHITE "array2.size() = " << array2.size() << RESET << std::endl;
		std::cout << YELLOW "> Try to access any value" RESET << std::endl;
		try
		{
			array2[0] = 0;
			std::cout << GREEN "array2[0] = " << array2[0] << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		std::cout << YELLOW "> Use the assignation operator to copy the first Array<int>" RESET << std::endl; 
		array2 = array1;
		std::cout << YELLOW "> Create a third new Array<int> using the copy constructor" << RESET << std::endl;
		Array<int> array3(array2);
		std::cout << YELLOW "> Modify the value of the third element of the first Array<int>" RESET << std::endl;
		array1[2] = RAND_VALUE;
		if (array3[2] == RAND_VALUE || array2[2] == RAND_VALUE)
		{
			std::cerr << RED "It modified another array !!" RESET << std::endl;
			return 1;
		}
		std::cout << GREEN "The value of the third element of the second and third arrays have note been modified" RESET << std::endl;		
	}
	std::cout << std::endl;

	std::cout << YELLOW "> Trying to access an out of range value (under 0)" << RESET << std::endl;
	try
	{
		array1[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << YELLOW "> Trying to access an out of range value (over max value)" << RESET << std::endl; 
	try
	{
		array1[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW "> Modifying values of the Array<int>" << RESET << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		int tmp = array1[i];
		array1[i] = rand();
		if (tmp == array1[i])
		{
			std::cerr << RED "didn't modify the value!!" RESET << std::endl;
			return 1;
		}
	}
	std::cout << GREEN "All values have been modified" RESET << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW "> Deleting the Array<int>" << RESET << std::endl;
}
#endif

#if MAIN_NB == 1
int main(void)
{
	std::cout << ORANGE "SAME TEST WITH CLASS ARRAY" RESET << std::endl;
	std::cout << YELLOW "> Creating a new Array<TestClass> with a size of " << MAX_VAL << RESET << std::endl;
	Array<TestClass> array4(MAX_VAL);
	std::cout << YELLOW "> Creating an array of TestClass with a size of " << MAX_VAL << RESET << std::endl;
	TestClass* classTab = new TestClass[MAX_VAL];
	std::cout << YELLOW "> Filling the Array<TestClass> and the TestClass array with random values" << RESET << std::endl;
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		array4[i] = TestClass(value);
		classTab[i] = TestClass(value);
	}
	std::cout << YELLOW "> Comparing the values of the Array<TestClass> and the TestClass array" << RESET << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (classTab[i].getValue() != array4[i].getValue())
		{
			std::cerr << RED "didn't save the same value!!" RESET << std::endl;
			return 1;
		}
	}
	std::cout<< GREEN "All values are the same" RESET << std::endl;
	std::cout << YELLOW "> Deleting the TestClass array" << RESET << std::endl;
	delete [] classTab;
	std::cout << std::endl;
	
	{
		std::cout << YELLOW "> Creating a second Array<TestClass> by default" << RESET << std::endl;
		Array<TestClass>	 array5;
		std::cout << YELLOW "> Size of the second Array<TestClass>" RESET << std::endl;
		std::cout << WHITE "array5.size() = " << array5.size() << RESET << std::endl;
		std::cout << YELLOW "> Try to access any value" RESET << std::endl;
		try
		{
			array5[0] = 0;
			std::cout << GREEN "array5[0] = " << array5[0].getValue() << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		std::cout << YELLOW "> Use the assignation operator to copy the first Array<TestClass>" RESET << std::endl; 
		array5 = array4;
		std::cout << YELLOW "> Create a third new Array<TestClass> using the copy constructor" << RESET << std::endl;
		Array<TestClass>	 array6(array4);
		std::cout << YELLOW "> Modify the value of the third element of the first Array<TestClass>" RESET << std::endl;
		(array4[2]).setValue(RAND_VALUE);
		if (array5[2].getValue() == RAND_VALUE || array6[2].getValue() == RAND_VALUE)
		{
			std::cerr << RED "It modified another array !!" RESET << std::endl;
			return 1;
		}
		std::cout << GREEN "The value of the third element of the second and third arrays have note been modified" RESET << std::endl;		
	}
	std::cout << std::endl;

	std::cout << YELLOW "> Trying to access an out of range value (under 0)" << RESET << std::endl;
	try
	{
		array4[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << YELLOW "> Trying to access an out of range value (over max value)" << RESET << std::endl; 
	try
	{
		array4[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << YELLOW "> Modifying values of the Array<TestClass>	" << RESET << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		TestClass tmp = array4[i];
		array4[i].setValue(rand());
		if (tmp.getValue() == array4[i].getValue())
		{
			std::cerr << RED "didn't modify the value!!" RESET << std::endl;
			return 1;
		}
	}
	std::cout << GREEN "All values have been modified" RESET << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW "> Deleting the Array<TestClass>	" << RESET << std::endl;
}
#endif
