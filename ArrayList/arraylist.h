#pragma once
typedef struct //静态分配的顺序表
{
	int nums[100]; //顺序表的元素
	int length;  //顺序表的当前长度
}IntSqList, *PSqList;
