#ifndef MAIN_H	//作用：防止head.h被重复引用
#define MAIN_H

#include <iostream>	//<>引用标准库的头文件
#include <string>
#include <map>
#include <fstream>

using namespace std;	//指明下面的程序使用命名空间std

void menu();

map<char, int> calculate_char_count(string str);

void iterate_map(map<char, int> _map);

#endif // !MAIN_H

/*
* CSting:CString是MFC或者ATL中的实现，是MFC里面封装的一个关于字符串处理的功能很强大的类,只有支持MFC的工程才可以使用。
* 如在linux上的工程就不能用CString了，只能用标准C++中的string类了。
* 在MFC中使用不需要自己加，但在另外的程序中需要加入#include<CString>。

* string：string类既是一个标准c++的类库，同时也是STL（Standard Template Library,标准模版库）中的类库，已经纳入C++标准之中。
* 它和CString有本质的区别。

* string.h:C语言里面关于字符数组的函数定义的头文件，常用函数有strlen、strcmp、strcpy等等，这个头文件跟C++的string类半点关系也没有，
* 所以 <string>并非 <string.h>的“升级版本”，他们是毫无关系的两个头文件。
*/