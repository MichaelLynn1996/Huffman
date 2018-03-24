#include"main.h"	//""���÷Ǳ�׼���ͷ�ļ�
#include"huffman.h"

int main()
{
	int choice;
	string str,temp;
	map<char, int> char_count;

	ifstream infile;    // fileName���ݶ�ȡ��file�� ������ʵ������޸�)

	bool endflag = true;	//�ж��Ƿ��˳�����

	while (endflag)
	{
		menu();
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "������һ���ַ�����" << endl;
			cin >> str;

			cout << "����������ַ�����" << endl;
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

			cout << "�ı���" << endl;
			cout << str << endl;
			break;
		case 3:
			endflag = false;
			break;
		default:cout << "�������" << endl;
			break;
		}

		if (!endflag)
		{
			break;
		}

		char_count = calculate_char_count(str);
		cout << "ÿ���ַ����ֵĴ�����" << endl;
		iterate_map(char_count);

		hufftree T;
		huffman(T, char_count);
		cout << "��������������" << endl;
		traverse_hufftree(T, 2 * char_count.size() - 1);

		codelist codes;
		encode(codes, T, char_count.size());
		cout << "���ÿ���ַ��ı��룺" << endl;
		print_huffcodes(codes, char_count.size());

		string compressed;
		compress(str,compressed, codes, T, char_count.size());
		cout << "�Ա��������ֽ��н��룺" << endl;
		decode(compressed, codes, T, 2 * char_count.size() - 1);

		cout << endl;
	}

	return 0;
}

void menu()
{
	cout << "��ѡ����Ҫ�Ĺ��ܣ�" << endl;
	cout << "1.����һ���ַ������б������롣" << endl;
	cout << "2.���ı��ļ����б������롣(��Ҫ���ı������ơ�text.txt���ŵ�Ŀ¼�¡�)" << endl;
	cout << "3.�˳�" << endl;
	cout << "ѡ��\t";
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

