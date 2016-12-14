
#include "stack.h"
#include <iostream>


int main()
{
	stack<int> s;
	std::cout << s.empty() << std::endl;
	for (int i = 0; i < 6; ++i)
	{
		s.push(i);	//inserting...
	}
	for (int i = 0; i < 6; ++i)
	{
		std::cout << s.top() << std::endl;
		s.pop();
		if (!s.empty()) std::cout << "Now top is: " << s.top() << std::endl;
		//deleting...
	}
	std::cout << s.empty() << std::endl;
 
	system("pause");
	return 0;
}
