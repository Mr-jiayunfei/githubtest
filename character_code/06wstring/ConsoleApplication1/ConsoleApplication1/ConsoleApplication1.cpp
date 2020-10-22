// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


int main()
{
	//strlen返回s的长度，不包括结束符NULL
	/*strlen interprets the string as a single-byte 
	character string, so its return value is always equal to the number of bytes, 
	even if the string contains multibyte characters. wcslen is a wide-character version of strlen;
	the argument of wcslen is a wide-character string and the count of characters is in wide (two-byte) characters.
	wcslen and strlen behave identically otherwise.
	参考：
	https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l?view=vs-2019
	*/
	const wchar_t ch[100] = L"你好世界";
	int len = wcslen(ch);
	std::cout << len << std::endl;

	const char ch1[100] = "你好世界";
	len = strlen(ch1);
	std::cout << len << std::endl;

	const char ch2[100] = u8"你好世界";
	len = strlen(ch2);
	std::cout << len << std::endl;

    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
