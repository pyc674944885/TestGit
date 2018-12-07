// ArrayList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "arraylist.h"
using namespace std;
void InitList(PSqList l); //顺序表的初始化操作，构造一个空的线性表
int Length(PSqList l);  //顺序表的长度
int LocateElem(PSqList,int); //按值查找操作
int GetElem(PSqList l, int i); //查找第i个位置的元素
void ListInsert(PSqList l, int i, int e);//在第i个位置插入元素e
int ListDelete(PSqList l, int i, int &e); //删除第i个位置的元素，并用e返回
void PrintList(PSqList l);//输出线性表的元素
bool Empty(PSqList l);//链表判空
void DestroyList(PSqList l); //销毁线性表

void InitList(PSqList l)  //初始化线性表，形参是指针类型，应该传入一个地址
{
	/*
	if (l == nullptr)    //不能对空指针属性赋值，因为空指针没有属性
	{
		l->length = 0;
	}			*/
	if (l == nullptr)
		return;
	l->length = 0;
}

int Length(PSqList l)//顺序表的长度
{
	if (l == nullptr)
		return 0;
	return l->length;
}

int LocateElem(PSqList l,int e) //按值查找操作
{
	if (l == nullptr)
		return -1;
	for (int i = 0; i < l->length; ++i)
	{
		if (l->nums[i] == e)
		{
			return i;
		}
	}
	return -1;
}

int GetElem(PSqList l, int i) //查找第i个位置的元素
{
	if (l->length<i||i<=0)
	{
		return -1;
	}
	return l->nums[i-1];
} 

void ListInsert(PSqList l, int i, int e)    //插入元素
{
	if (i<1 || i>l->length + 1)
	{
		cout << "插入位置不合法"<< endl;
		return;
	}
	else if(l->length>=100)
	{
		cout << "线性表空间已满" << endl;
		return;
	}
	else
	{
		for (int j = l->length-1 ; j >= i - 1;--j)
		{
			l->nums[j + 1] = l->nums[j];
		}
		l->nums[i - 1] = e;
		l->length++;
		return;
	}

}

int ListDelete(PSqList l, int i, int &e)  //删除第i个位置的元素
{
	if (i<1 || i>l->length)
	{
		cout << "删除位置不合法" << endl;
		return 0;
	}
	else if (l == nullptr)
	{
		cout << "线性表为空" << endl;
		return 0;
	}
	else
	{
		e = l->nums[i - 1];
		for (int j = i; j <= l->length - 1; ++j)
		{
			l->nums[j - 1] = l->nums[j];
		}
		l->length--;
		return 0;
	}
	
}

void PrintList(PSqList l)//输出线性表的元素
{
	if (l == nullptr||l->length==0)
	{
		cout << "List is null" << endl;
	}
	else
	{
		for (int i = 0; i <= l->length - 1; ++i)
		{
			cout << l->nums[i] << endl;
		}
	}
}   

bool Empty(PSqList l)//链表判空
{
	if (l == nullptr)
		return true;
	else
		return false;
}

void ClearList(PSqList l)  //清空线性表
{
	if (l != nullptr)
	{
		l->length = 0;
	}
}

int DeleteMin(PSqList l)  //王道2.2.1 删除链表最小值元素，然后用最后一个元素补缺
{
	if (l == nullptr || l->length == 0)
	{
		cout << "List is empty" << endl;
		return 0;
	}
	int min = l->nums[0];
	int minpos = 0;
	for (int i = 1; i < l->length; ++i)
	{
		if (min > l->nums[i])
		{
			min = l->nums[i];
			minpos = i;
		}
	}
	l->nums[minpos] = l->nums[l->length - 1];
	l->length--;
	return 0;

}
int myswap(int &a, int &b)  //交换两个数
{
	int t = a;
	a = b;
	b = t;
	return 0;
}

int ReverseList(PSqList l)   //王道2.2.2 将顺序表的元素逆置
{
	if (l == nullptr || l->length == 0)
	{
		cout << "List is empty" << endl;
		return 0;
	}
	for (int i = 0, j = l->length - 1; i < j; ++i, --j)
	{
		myswap(l->nums[i], l->nums[j]);
	}
	return 0;

}  

int ReverseList(PSqList l, int left, int right)
{
	if (l == nullptr || l->length == 0)
	{
		cout << "List is empty" << endl;
		return 0;
	}
	if (left<0 || right>l->length)
	{
		cout << "输入位置错误" << endl;
		return 0;
	}
	for (int i = left, j = right; i < j; ++i, --j)
	{
		myswap(l->nums[i], l->nums[j]);
	}
	return 0;
}

int DeleteAllx(PSqList l,int x)     //王道2.2.3，删除顺序表中所有值为x的元素，还有一种解法哦 
{
	if (l == nullptr || l->length == 0)
	{
		cout << "List is empty" << endl;
		return 0;
	}
	int countx = 0;
	for (int i = 0; i < l->length; ++i)
	{
		if (l->nums[i] == x)
		{
			countx++;
		}
		else
		{
			l->nums[i - countx] = l->nums[i];
		}
	}
	l->length -= countx;
	return 0;
}   

int Delete_s_t(PSqList l, int s, int t)  //王道2.2.5 删除范围在s到t之间的元素
{
	if (l == nullptr || l->length == 0)
	{
		cout << "List is empty" << endl;
		return 0;
	}
	if (s >= t)
	{
		cout << "s and t is illegal!" << endl;
		return 0;
	}
	int j = 0;
	for (int i = 0; i < l->length; ++i)
	{
		if (l->nums[i] < s || l->nums[i] > t)
		{
			l->nums[j] = l->nums[i];
			++j;
		}
	}
	l->length = j ;
	return 0;

}

int DeleteChongFu(PSqList l)
{
	if (l == nullptr || l->length == 0)
	{
		cout << "List is empty" << endl;
		return 0;
	}
	int i, j=1;
	for (i = 1; i<l->length; ++i)
	{
		if (l->nums[i] != l->nums[i - 1])
		{
			l->nums[j] = l->nums[i];
			++j;
		}
	}
	l->length = j;
	return 0;
}

PSqList MergeList(PSqList l1, PSqList l2)    //这是个错误的程序！！！！！返回了局部指针变量
{
	if (l1 == nullptr)
		return l2;
	if (l2 == nullptr)
		return l1;
	IntSqList ll;
	InitList(&ll);    //初始化ll这个链表
	PSqList l3 = &ll;   //用一个指针l3指向这个链表
	int i = 0, j = 0,k = 0;
	while (i < l1->length && j < l2->length)    //如果两个表都没有遍历完
	{
		if (l1->nums[i] <= l2->nums[j])
		{
			l3->nums[k++] = l1->nums[i++];
		}
		else
		{
			l3->nums[k++] = l2->nums[j++];
		}
	}
	while (i < l1->length)    //如果l2表已经遍历完了
	{
		l3->nums[k++] = l1->nums[i++];
	}
	while (j< l2->length)    //如果l1表已经遍历完了
	{
		l3->nums[k++] = l2->nums[j++];
	}
	l3->length = l1->length + l2->length;
	return l3;
	
}
void MergeList(PSqList l1, PSqList l2,PSqList l3)    //这是个错误的程序！！！！！返回了局部指针变量
{
	if (l1 == nullptr)
		l3 = l2;
	if (l2 == nullptr)
		l3 = l1;
	//IntSqList ll;
	//InitList(&ll);    //初始化ll这个链表
	//PSqList l3 = &ll;   //用一个指针l3指向这个链表
	int i = 0, j = 0, k = 0;
	while (i < l1->length && j < l2->length)    //如果两个表都没有遍历完
	{
		if (l1->nums[i] <= l2->nums[j])
		{
			l3->nums[k++] = l1->nums[i++];
		}
		else
		{
			l3->nums[k++] = l2->nums[j++];
		}
	}
	while (i < l1->length)    //如果l2表已经遍历完了
	{
		l3->nums[k++] = l1->nums[i++];
	}
	while (j< l2->length)    //如果l1表已经遍历完了
	{
		l3->nums[k++] = l2->nums[j++];
	}
	l3->length = l1->length + l2->length;

}

void ExchangeList(PSqList l, int m, int n)
{
	ReverseList(l, 0, m-1);
	ReverseList(l, m,m+n-1);
	ReverseList(l, 0, m+n-1);
}

void Find_x(PSqList l,int x)
{
	int low = 0;
	int high = l->length - 1;
	int mid ;
	int pos;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x > l->nums[mid])
		{
			low = mid + 1;
		}
		else if(x < l->nums[mid])
		{
			high = mid - 1;
		}
		else
		{
			pos = mid;
			if (pos < l->length - 1)
			{
				myswap(l->nums[pos], l->nums[pos + 1]);
			}
			else
			{
				cout << "要查找的已经是最后一个元素了" << endl;
			}
			return;
		}
	}
	ListInsert(l, low + 1, x);

}
int main()
{
	int e;
	IntSqList q,q2,q3;
	InitList(&q);
	InitList(&q2);
	InitList(&q3);
	ListInsert(&q, 1, 8);
	//ListInsert(&q, 1, 7);
	ListInsert(&q, 1, 7);
	ListInsert(&q, 1, 6);
	//ListInsert(&q, 1, 4);
	ListInsert(&q, 1, 4);
	//ListDelete(&q, 1, e);
	//ListDelete(&q, 5, e);
	//PrintList(&q);
	//ClearList(&q);
	//PrintList(&q);
	//e = 3;
	//cout << LocateElem(&q,e)<< endl;
	//cout << GetElem(&q, 1) << endl;
	//cout << "----------我是分割线-----------" << endl;
	//DeleteMin(&q);
	//PrintList(&q);
	//cout << "----------我是分割线-----------" << endl;
	//ListInsert(&q, 1, 2);
	//ReverseList(&q);
	//PrintList(&q);           //7,5,4,6,3,2
	//ListInsert(&q, 2, 6);
	//ListInsert(&q, 2, 6);
	//cout << "----------我是分割线-----------" << endl;
	//PrintList(&q);
	//cout << "----------我是分割线-----------" << endl;
	//DeleteAllx(&q,6);
	         
	cout << "----------我是分割线-----------" << endl;
	//Delete_s_t(&q, 2, 4);
	//PrintList(&q);
	ListInsert(&q, 1, 2);
	//ListInsert(&q, 1, 2);
	PrintList(&q);
	//DeleteChongFu(&q);
	cout << "----------我是分割线-----------" << endl;

	ListInsert(&q2, 1, 1);
	ListInsert(&q2, 2, 3);
	ListInsert(&q2, 3, 5);
	PrintList(&q2);
	cout << "----------我是分割线-----------" << endl;
	MergeList(&q, &q2,&q3);
	PrintList(&q3);
	cout << "----------我是分割线-----------" << endl;
	//ExchangeList(&q3, 4, 4);
	//PrintList(&q3);
	cout << "----------我是分割线-----------" << endl;
	Find_x(&q3, 9);
	PrintList(&q3);
	//PrintList(&q);
    return 0;
}

