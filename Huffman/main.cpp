#include"main.h"	//""引用非标准库的头文件
#include"huffman.h"

int main()
{
	int choice;
	string str,temp;
	map<char, int> char_count;

	ifstream infile;    // fileName内容读取到file中 （按照实际情况修改)

	bool endflag = true;	//判断是否退出程序

	while (endflag)
	{
		menu();
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "请输入一个字符串：" << endl;
			cin >> str;

			cout << "你所输入的字符串：" << endl;
			cout << str << endl;

			break;
		case 2:
			temp = "";
			infile.open("Text.txt", ios::in);
			while (getline(infile, temp))
			{
				str = str + temp + "\n";
			}
			infile.close();

			cout << "文本：" << endl;
			cout << str << endl;
			break;
		case 3:
			endflag = false;
			break;
		default:cout << "输入错误！" << endl;
			break;
		}

		if (!endflag)
		{
			break;
		}

		char_count = calculate_char_count(str);
		cout << "每个字符出现的次数：" << endl;
		iterate_map(char_count);

		hufftree T;
		huffman(T, char_count);
		cout << "遍历哈夫曼树：" << endl;
		traverse_hufftree(T, 2 * char_count.size() - 1);

		codelist codes;
		encode(codes, T, char_count.size());
		cout << "输出每个字符的编码：" << endl;
		print_huffcodes(codes, char_count.size());

		string compressed;
		compress(str,compressed, codes, T, char_count.size());
		cout << "对编码后的文字进行解码：" << endl;
		decode(compressed, codes, T, 2 * char_count.size() - 1);

		cout << endl;
	}

	return 0;
}

void menu()
{
	cout << "请选择需要的功能：" << endl;
	cout << "1.输入一段字符串进行编码译码。" << endl;
	cout << "2.对文本文件进行编码译码。(需要将文本该名称“text.txt”放到目录下。)" << endl;
	cout << "3.退出" << endl;
	cout << "选择：\t";
}

map<char, int> calculate_char_count(string str)
{
	map<char, int> char_count;

	for (char c : str)	//foreach
	{
		char_count[c]++;
	}

	return char_count;
}

void iterate_map(map<char, int> _map)
{
	map<char, int>::iterator iter;
	for (iter = _map.begin(); iter != _map.end(); ++iter)
	{
		cout << iter->first << " : " << iter->second << "\t";
	}
	cout << endl;
}

