#include<stdio.h>
#include<stdlib.h>

typedef struct ArrayList
{
	int * pDate;  //数据存放数据 
	int len;	  //数据长度 
	int cnt;	  //元素个数 
 }List;
 
 
 void init(List *l, int length)
{
	l->pDate=(int*)malloc(sizeof(List)*length);
	if(l->pDate==NULL)
	{
		printf("memory allcate failed!");
		exit(-1);
	}
	else
	{
		l->len=length;
		l->cnt=0;
		printf("init sussefull!\n");
	}
}

int isEmpty(List *l)
{
	if(l->cnt==0)
	{
		return 1;
	}
	return 0;
}

void show(List *l)
{
	if(isEmpty(l))
	{
		printf("数组元素为空！\n"); 
	}
	else
	{
		for(int i=0;i<l->cnt;i++)
		{
			printf("%d",l->pDate[i]);
			printf("\n"); 
		}
	 } 
}

int isFull(List *l)
{
	if (l->len==l->cnt)
	{
		return 1;
	}
	return 0;
}

void add(List *l,int val)
{
	if(isFull(l))
	{
		printf("数组已满\n");
		return ;
	}
	l->pDate[l->cnt]=val;
	l->cnt++;
}

void insert(List *l, int pos,int val)
{
	int i;
	if(isFull(l))
	{
		printf("数据已满\n");
		return;
	}
	if (pos<1||pos>l->cnt)
	{
		printf("invalid pos!\n");
		return; 
	}
	
	for(i=l->cnt;i>=pos;i--)
	{
		l->pDate[i]=l->pDate[i-1];
	}
	l->pDate[pos-1]=val;
	l->cnt++;
}

void Delete(List *l,int pos,int *pval)
{
	int i;
	if(isEmpty(l))
	{
		printf("数组为空！\n");
		return;
	}
	
	if (pos<1||pos>l->cnt)
	{
		printf("invalid pos!\n");
		return;
	}
	
	*pval =l->pDate[pos-1];
	for(i=pos;i<l->cnt;i++)
	
	{
		l->pDate[i-1]=l->pDate[i];
	}
	l->cnt--;
}

 int main()
 {
 	int val;
 	List l;
 	init(&l,5);
	add(&l,1);
	add(&l,1);
	add(&l,1);
	add(&l,1);
	insert(&l,3,5);
	show(&l);
	

	return 0;
  }























