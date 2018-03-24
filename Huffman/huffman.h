#ifndef HUFFMAN_H	//作用：防止head.h被重复引用
#define HUFFMAN_H

#include <string>
#include <map>
#include <iostream>

using namespace std;

typedef char datatype;	//定义元素的数据类型

const int leaves = 256;	//叶子节点数，假设为30

const int nodes = 2 * leaves - 1;	//节点总数

/*
 * 构造哈夫曼树的节点的结构体(节点类型)
 */
typedef struct
{
	datatype value;
	float weight;
	int parent, lchild, rchild;
} huffnode;

typedef huffnode hufftree[nodes];	//哈夫曼树类型，数组从0号单元开始使用

/*
 * 编码的结构体类型
 */
typedef struct
{
	int bits[leaves];	//位串，存放编码	
						//书上使用char类型的数组来存放编码，但不管怎么样都会输出“烫”，改用int型解决此问题
	datatype ch;		//字符
	int start;			//编码在位串中的起始位置
}codetype;				//编码结点类型

typedef codetype codelist[leaves];	//编码表类型

void huffman(hufftree T, map<char, int> _map);	//构建哈夫曼树的函数

void encode(codelist codes, hufftree T, int actual_leaves);	//编码算法

void traverse_hufftree(hufftree T, int depth);	//遍历哈夫曼树的算法

void print_huffcodes(codelist codes, int actual_leaves);	//输出哈夫曼编码的函数

void compress(string str, string &compressed, codelist codes, hufftree T, int actual_leaves);	//压缩的算法

void decode(string str,codelist codes, hufftree T, int actual_nodes);

#endif // !HUFFMAN_H