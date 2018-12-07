// ArrayList.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "arraylist.h"
using namespace std;
void InitList(PSqList l); //˳���ĳ�ʼ������������һ���յ����Ա�
int Length(PSqList l);  //˳���ĳ���
int LocateElem(PSqList,int); //��ֵ���Ҳ���
int GetElem(PSqList l, int i); //���ҵ�i��λ�õ�Ԫ��
void ListInsert(PSqList l, int i, int e);//�ڵ�i��λ�ò���Ԫ��e
int ListDelete(PSqList l, int i, int &e); //ɾ����i��λ�õ�Ԫ�أ�����e����
void PrintList(PSqList l);//������Ա��Ԫ��
bool Empty(PSqList l);//�����п�
void DestroyList(PSqList l); //�������Ա�

void InitList(PSqList l)  //��ʼ�����Ա��β���ָ�����ͣ�Ӧ�ô���һ����ַ
{
	/*
	if (l == nullptr)    //���ܶԿ�ָ�����Ը�ֵ����Ϊ��ָ��û������
	{
		l->length = 0;
	}			*/
	if (l == nullptr)
		return;
	l->length = 0;
}

int Length(PSqList l)//˳���ĳ���
{
	if (l == nullptr)
		return 0;
	return l->length;
}

int LocateElem(PSqList l,int e) //��ֵ���Ҳ���
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

int GetElem(PSqList l, int i) //���ҵ�i��λ�õ�Ԫ��
{
	if (l->length<i||i<=0)
	{
		return -1;
	}
	return l->nums[i-1];
} 

void ListInsert(PSqList l, int i, int e)    //����Ԫ��
{
	if (i<1 || i>l->length + 1)
	{
		cout << "����λ�ò��Ϸ�"<< endl;
		return;
	}
	else if(l->length>=100)
	{
		cout << "���Ա�ռ�����" << endl;
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

int ListDelete(PSqList l, int i, int &e)  //ɾ����i��λ�õ�Ԫ��
{
	if (i<1 || i>l->length)
	{
		cout << "ɾ��λ�ò��Ϸ�" << endl;
		return 0;
	}
	else if (l == nullptr)
	{
		cout << "���Ա�Ϊ��" << endl;
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

void PrintList(PSqList l)//������Ա��Ԫ��
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

bool Empty(PSqList l)//�����п�
{
	if (l == nullptr)
		return true;
	else
		return false;
}

void ClearList(PSqList l)  //������Ա�
{
	if (l != nullptr)
	{
		l->length = 0;
	}
}

int DeleteMin(PSqList l)  //����2.2.1 ɾ��������СֵԪ�أ�Ȼ�������һ��Ԫ�ز�ȱ
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
int myswap(int &a, int &b)  //����������
{
	int t = a;
	a = b;
	b = t;
	return 0;
}

int ReverseList(PSqList l)   //����2.2.2 ��˳����Ԫ������
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
		cout << "����λ�ô���" << endl;
		return 0;
	}
	for (int i = left, j = right; i < j; ++i, --j)
	{
		myswap(l->nums[i], l->nums[j]);
	}
	return 0;
}

int DeleteAllx(PSqList l,int x)     //����2.2.3��ɾ��˳���������ֵΪx��Ԫ�أ�����һ�ֽⷨŶ 
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

int Delete_s_t(PSqList l, int s, int t)  //����2.2.5 ɾ����Χ��s��t֮���Ԫ��
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

PSqList MergeList(PSqList l1, PSqList l2)    //���Ǹ�����ĳ��򣡣������������˾ֲ�ָ�����
{
	if (l1 == nullptr)
		return l2;
	if (l2 == nullptr)
		return l1;
	IntSqList ll;
	InitList(&ll);    //��ʼ��ll�������
	PSqList l3 = &ll;   //��һ��ָ��l3ָ���������
	int i = 0, j = 0,k = 0;
	while (i < l1->length && j < l2->length)    //���������û�б�����
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
	while (i < l1->length)    //���l2���Ѿ���������
	{
		l3->nums[k++] = l1->nums[i++];
	}
	while (j< l2->length)    //���l1���Ѿ���������
	{
		l3->nums[k++] = l2->nums[j++];
	}
	l3->length = l1->length + l2->length;
	return l3;
	
}
void MergeList(PSqList l1, PSqList l2,PSqList l3)    //���Ǹ�����ĳ��򣡣������������˾ֲ�ָ�����
{
	if (l1 == nullptr)
		l3 = l2;
	if (l2 == nullptr)
		l3 = l1;
	//IntSqList ll;
	//InitList(&ll);    //��ʼ��ll�������
	//PSqList l3 = &ll;   //��һ��ָ��l3ָ���������
	int i = 0, j = 0, k = 0;
	while (i < l1->length && j < l2->length)    //���������û�б�����
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
	while (i < l1->length)    //���l2���Ѿ���������
	{
		l3->nums[k++] = l1->nums[i++];
	}
	while (j< l2->length)    //���l1���Ѿ���������
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
				cout << "Ҫ���ҵ��Ѿ������һ��Ԫ����" << endl;
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
	//cout << "----------���Ƿָ���-----------" << endl;
	//DeleteMin(&q);
	//PrintList(&q);
	//cout << "----------���Ƿָ���-----------" << endl;
	//ListInsert(&q, 1, 2);
	//ReverseList(&q);
	//PrintList(&q);           //7,5,4,6,3,2
	//ListInsert(&q, 2, 6);
	//ListInsert(&q, 2, 6);
	//cout << "----------���Ƿָ���-----------" << endl;
	//PrintList(&q);
	//cout << "----------���Ƿָ���-----------" << endl;
	//DeleteAllx(&q,6);
	         
	cout << "----------���Ƿָ���-----------" << endl;
	//Delete_s_t(&q, 2, 4);
	//PrintList(&q);
	ListInsert(&q, 1, 2);
	//ListInsert(&q, 1, 2);
	PrintList(&q);
	//DeleteChongFu(&q);
	cout << "----------���Ƿָ���-----------" << endl;

	ListInsert(&q2, 1, 1);
	ListInsert(&q2, 2, 3);
	ListInsert(&q2, 3, 5);
	PrintList(&q2);
	cout << "----------���Ƿָ���-----------" << endl;
	MergeList(&q, &q2,&q3);
	PrintList(&q3);
	cout << "----------���Ƿָ���-----------" << endl;
	//ExchangeList(&q3, 4, 4);
	//PrintList(&q3);
	cout << "----------���Ƿָ���-----------" << endl;
	Find_x(&q3, 9);
	PrintList(&q3);
	//PrintList(&q);
    return 0;
}

