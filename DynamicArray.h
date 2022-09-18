#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DynamicArray
{
	void** addr;     //ά����ʵ�����ڶ����������ָ��
	
	int capacity;   //��������
	
	int size;       //�����С
};

//��ʼ������
struct DynamicArray* init_DynamicArray(int capacity);

//����Ԫ��
void insert_DynamicArray(struct DynamicArray* array, int pos, void* data);

//��������
void foreach_DynamicArray(struct DynamicArray* array, void(*Print)(void*));

//��λ��ɾ������Ԫ��
void removeByPos_DynamicArray(struct DynamicArray* array, int pos);

//������ɾ������Ԫ��
void removeByData_DynamicArray(struct DynamicArray* array, void* data, int(*Compare)(void*, void*));

//��������
void destroy_DynamicArray(struct DynamicArray* array);