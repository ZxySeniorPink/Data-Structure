#include "DynamicArray.h"

//��ʼ������
struct DynamicArray* init_DynamicArray(int capacity)
{	
	if (capacity <= 0)
	{
		return NULL;
	}

	//���������ռ�
	struct DynamicArray* dArray = malloc(sizeof(struct DynamicArray));
	if (dArray == NULL)
	{
		return NULL;
	}

	//������Ԫ�س�ʼ��
	dArray->addr = malloc(sizeof(void*) * capacity);
	dArray->capacity = capacity;
	dArray->size = 0;
	
	return dArray;
}

//����Ԫ��
void insert_DynamicArray(struct DynamicArray* dArray, int pos, void* data)
{
	if (dArray == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	//��Чλ�� -> β��
	if (pos < 0 || pos > dArray->size)
	{
		pos = dArray->size;
	}
	//�ж��Ƿ����ˣ�������� ����Ҫ��̬��չ
	if (dArray->capacity == dArray->size)
	{
		//1�������¿ռ�Ĵ�С
		int newCapacity = dArray->capacity * 2;
		
		//2�������¿ռ�
		void** newSpace = malloc(sizeof(void*) * newCapacity);

		//3����ԭ�����ݿ������¿ռ���
		memcpy(newSpace, dArray->addr, sizeof(void*) * dArray->capacity);

		//4���ͷ�ԭ�ڴ�ռ�
		free(dArray->addr);

		//5�������¿ռ�ָ��
		dArray->addr = newSpace;

		//6������������
		dArray->capacity = newCapacity;
	}
	//������Ԫ��

	//�ƶ�Ԫ��
	for (int i = dArray->size - 1; i >= pos; i--)
	{
		//��������ƶ�
		dArray->addr[i + 1] = dArray->addr[i];
	}

	//����Ԫ�ز��뵽ָ��λ����
	dArray->addr[pos] = data;
	
	//���´�С
	dArray->size++;

}

//��������
void foreach_DynamicArray(struct DynamicArray* dArray, void(*Print)(void*))
{
	if (dArray == NULL)
	{
		return;
	}
	if (Print == NULL)
	{
		return;
	}

	for (int i = 0; i < dArray->size; i++)
	{
		Print(dArray->addr[i]);
	}
}

//��λ��ɾ������Ԫ��
void removeByPos_DynamicArray(struct DynamicArray* dArray, int pos)
{
	if (dArray == NULL)
	{
		return;
	}
	if (pos < 0 || pos > dArray->size)
	{
		return;
	}

	//����ǰ��
	for (int i = pos; i < dArray->size; i++)
	{
		dArray->addr[i] = dArray->addr[i + 1];
	}

	//���������С
	dArray->size--;
}

//������ɾ������Ԫ��
void removeByData_DynamicArray(struct DynamicArray* dArray, void* data, int(*Compare)(void*, void*))
{
	if (dArray == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (Compare == NULL)
	{
		return;
	}

	for (int i = 0; i < dArray->size; i++)
	{
		if (Compare(dArray->addr[i], data))
		{
			removeByPos_DynamicArray(dArray, i);
			break;
		}
	}
}

//��������
void destroy_DynamicArray(struct DynamicArray* dArray)
{
	if (dArray == NULL)
	{
		return;
	}

	if (dArray->addr != NULL)
	{
		free(dArray->addr);
		dArray->addr = NULL;
	}

	free(dArray);
	dArray = NULL;
}