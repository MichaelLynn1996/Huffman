#ifndef HUFFMAN_H	//���ã���ֹhead.h���ظ�����
#define HUFFMAN_H

#include <string>
#include <map>
#include <iostream>

using namespace std;

typedef char datatype;	//����Ԫ�ص���������

const int leaves = 256;	//Ҷ�ӽڵ���������Ϊ30

const int nodes = 2 * leaves - 1;	//�ڵ�����

/*
 * ������������Ľڵ�Ľṹ��(�ڵ�����)
 */
typedef struct
{
	datatype value;
	float weight;
	int parent, lchild, rchild;
} huffnode;

typedef huffnode hufftree[nodes];	//�����������ͣ������0�ŵ�Ԫ��ʼʹ��

/*
 * ����Ľṹ������
 */
typedef struct
{
	int bits[leaves];	//λ������ű���	
						//����ʹ��char���͵���������ű��룬��������ô������������̡�������int�ͽ��������
	datatype ch;		//�ַ�
	int start;			//������λ���е���ʼλ��
}codetype;				//����������

typedef codetype codelist[leaves];	//���������

void huffman(hufftree T, map<char, int> _map);	//�������������ĺ���

void encode(codelist codes, hufftree T, int actual_leaves);	//�����㷨

void traverse_hufftree(hufftree T, int depth);	//���������������㷨

void print_huffcodes(codelist codes, int actual_leaves);	//�������������ĺ���

void compress(string str, string &compressed, codelist codes, hufftree T, int actual_leaves);	//ѹ�����㷨

void decode(string str,codelist codes, hufftree T, int actual_nodes);

#endif // !HUFFMAN_H