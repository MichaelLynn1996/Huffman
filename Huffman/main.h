#ifndef MAIN_H	//���ã���ֹhead.h���ظ�����
#define MAIN_H

#include <iostream>	//<>���ñ�׼���ͷ�ļ�
#include <string>
#include <map>
#include <fstream>

using namespace std;	//ָ������ĳ���ʹ�������ռ�std

void menu();

map<char, int> calculate_char_count(string str);

void iterate_map(map<char, int> _map);

#endif // !MAIN_H

/*
* CSting:CString��MFC����ATL�е�ʵ�֣���MFC�����װ��һ�������ַ�������Ĺ��ܺ�ǿ�����,ֻ��֧��MFC�Ĺ��̲ſ���ʹ�á�
* ����linux�ϵĹ��̾Ͳ�����CString�ˣ�ֻ���ñ�׼C++�е�string���ˡ�
* ��MFC��ʹ�ò���Ҫ�Լ��ӣ���������ĳ�������Ҫ����#include<CString>��

* string��string�����һ����׼c++����⣬ͬʱҲ��STL��Standard Template Library,��׼ģ��⣩�е���⣬�Ѿ�����C++��׼֮�С�
* ����CString�б��ʵ�����

* string.h:C������������ַ�����ĺ��������ͷ�ļ������ú�����strlen��strcmp��strcpy�ȵȣ����ͷ�ļ���C++��string�����ϵҲû�У�
* ���� <string>���� <string.h>�ġ������汾���������Ǻ��޹�ϵ������ͷ�ļ���
*/