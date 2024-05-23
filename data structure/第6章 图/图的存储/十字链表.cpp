/**
 * @file 十字链表.cpp
 * @author horiki
 * @version 0.1
 * @date 2024-05-23
 * @copyright Copyright (c) 2024
 * 
 * @brief 
 * 
 */

#include<iostream>
using namespace std;

const int maxNum = 100;
typedef struct arcNode {    //弧结点类型
	int tail;				//弧尾下标
	int head;				//弧头下标
	struct arcNode*hlink;	//指针，指向同弧头的弧
	struct arcNode*tlink;	//指针，指向同弧尾的弧
}arcNode;

typedef struct vexNode
{
	char data;				//指点数据
	arcNode *firstIn;		//指针，指向第一个入弧
	arcNode *firstout;		//指针，指向第一个出弧
};

typedef struct {
	vexNode vex[maxNum];
	int vexnum, edgenum;	//顶点数量，边数量
}OLGraph;

OLGraph g;

int LocateVex(char c)
{
	for (int i = 0; i < g.vexnum; i++)
	{
		if (g.vex[i].data == c)
		{
			return i;
		}
	}
	return -1;
}

void insertedge(char a, char b)
{
	int ai = LocateVex(a);
	int bi = LocateVex(b);
	arcNode* an = new arcNode;  // 生成一条新弧
	an->tlink = g.vex[ai].firstout;		
	an->head = bi;						//由ai->bi
	an->tail = ai;
	g.vex[ai].firstout = an;			//顶点第一个出弧更新，头插入
	an->hlink = NULL;
	if (g.vex[bi].firstIn == NULL)
	{
		g.vex[bi].firstIn = an;
	}
	else 
	{
		arcNode* curArc = g.vex[bi].firstIn;		//找到最后一个入弧,尾插入
		while (curArc->hlink != NULL)
		{
			curArc = curArc->hlink;
		}
		curArc->hlink = an;
	}
}

void CreateOLGraph() {
	cout << "请输入顶点数量和边数：" << endl;
	cin >> g.vexnum >> g.edgenum;
	cout << "输入对应的顶点:" << endl;
	for (int i = 0; i < g.vexnum; i++)
	{
		cin >> g.vex[i].data;
		g.vex[i].firstIn = NULL; 
		g.vex[i].firstout = NULL;
	}
	cout << "输入要插入的边" << endl;
	int m = g.edgenum;
	while (m > 0)
	{
		char a, b;
		cin >> a >> b;
		insertedge(a, b);
		m--;
	}
}
void GetOLVexDu() {			//获得十字链表中某一个点的入度和出度
	for (int i = 0; i < g.vexnum; i++)
	{
		vexNode n = g.vex[i];
		cout << n.data << "的出度有" << " : ";
		arcNode* outArc = n.firstout;
		while (outArc != NULL)
		{
			cout << outArc->head << " ";
			outArc = outArc->tlink;
		}
		cout << endl;
		cout << n.data << "的入度有" << " : ";
		arcNode* inArc = n.firstIn;
		while (inArc != NULL)
		{
			cout << inArc->tail << " ";
			inArc = inArc->hlink;
		}
		cout << endl;
	}
}
int main()
{
	CreateOLGraph();
	GetOLVexDu();
	return 0;
}
