#include "huffman.h"

void huffman(hufftree T, map<char, int> _map)
{
	int p1, p2;
	float min1, min2;

	int true_leaves = _map.size();
	int true_nodes = 2 * _map.size() - 1;

	for (unsigned int i = 0; i < _map.size(); i++)
	{
		T[i].parent = T[i].lchild = T[i].rchild = -1;
		T[i].weight = 0;
	}

	map<char, int>::iterator iter = _map.begin();
	for (unsigned int i = 0; i<_map.size(); i++)	//初始化叶子的值和权
	{
		T[i].value = iter->first;
		T[i].weight = float(iter->second);
		++iter;
	}

	for (unsigned int i = _map.size(); i<2 * _map.size() - 1; i++)	//进行 leaves-1 次合并，产生n-1个新节点
	{
		p1 = p2 = -1;	//书上说此句可不要，但这是必要的，是对变量的初始化
		min1 = min2 = FLT_MAX;	//FLT_MAX为float类型的最大值
		for (int j =0;j<true_nodes+1;j++)	//找到两个权值最小的根结点
		{
			if (T[j].parent!=-1)	//不考虑已合并过的结点
			{
				continue;
			}
			if (T[j].weight<min1)	//修改最小权，次小权及其位置
			{
				min2 = min1;
				min1 = T[j].weight;
				p2 = p1;
				p1 = j;
			}else if(T[j].weight<min2)	//修改次小权及位置
			{
				min2 = T[j].weight;
				p2 = j;
			}
		}
		T[p1].parent = T[p2].parent = i;
		T[i].parent = -1;					//新根
		T[i].lchild = p1;
		T[i].rchild = p2;
		T[i].weight = min1 + min2;
	}
}

void encode(codelist codes,hufftree T,int actual_leaves)
{
	int c, p, start;

	for (int i=0;i<actual_leaves;i++)	//从叶结点出发向上回溯
	{
		codes[i].ch = T[i].value;
		start = actual_leaves;			//获得结点的值
		c = i;
		p = T[i].parent;				//取出双亲
		while (p!=-1)
		{
			start--;
			if (T[p].lchild==c)
			{
				codes[i].bits[start] = 0;
			}
			else
			{
				codes[i].bits[start] = 1;
			}
			c = p;
			p = T[p].parent;
		}
		codes[i].start = start;
	}
}

void traverse_hufftree(hufftree T,int depth,int position)
{
	cout << depth << "\t" << T[position].weight << "\t" << T[position].parent << "\t" << T[position].value << "\t" << T[position].lchild << "\t" << T[position].rchild << endl;
	if (T[position].lchild != -1 && T[position].rchild != -1)
	{
		++depth;
		traverse_hufftree(T, depth, T[position].lchild);
		traverse_hufftree(T, depth, T[position].rchild);
	}
	
}

void print_huffcodes(codelist codes, int actual_leaves)
{
	//输出结果
	for (int i = 0; i<actual_leaves; i++)
	{
		cout << codes[i].ch << " : ";
		for (int j = codes[i].start; j<actual_leaves; j++)
			cout << codes[i].bits[j];
		cout << endl;
	}
}

void compress(string str,string &compressed, codelist codes, hufftree T, int actual_leaves) {
	int arr_length = str.length();                        //原文章的字符总数
	int codecount = 0;                                     //编码后的所有总数

	for (unsigned int i = 0; i<str.length(); i++) {
		for (int j = 0; j<actual_leaves; j++) {
			if (str[i] == T[j].value) {
				for (int k = codes[j].start; k < actual_leaves; k++) {
					compressed.push_back(codes[j].bits[k] + '0');
					codecount++;
				}
			}
		}
	}

	cout << "输出压缩后的文字: " << endl;
	cout << compressed << endl;
	cout << "压缩的效率为：" << endl;
	codecount = codecount / 8;                                              //计算编码后的字符串总数
	if (codecount % 8 != 0) {                                                 //除不完情况下，加一处理
		codecount++;
	}
	printf("%.2lf%%\n", (double)(arr_length - codecount) / arr_length * 100);          //输出压缩百分比
}

void decode(string str,codelist codes, hufftree T, int actual_nodes)
{
	int position = actual_nodes - 1;

	cout << "译码的结果：" << endl;
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] == '0') {
			position = T[position].lchild;
		}
		else if (str[i] == '1') {
			position = T[position].rchild;
		}
		if (T[position].lchild==-1)
		{
			cout << codes[position].ch;
			position = actual_nodes - 1;
		}
	}
	if (position != actual_nodes - 1)
	{
		cout << "编码有错！";
	}
	cout << endl;

}

int get_parent_position(hufftree T, int depth)
{
	int position;

	for (int i = 0; i < depth; i++)
	{
		if (T[i].parent == -1)
		{
			position = i;
			return position;
		}
	}

	return -1;
}