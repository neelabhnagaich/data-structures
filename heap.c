#include<stdio.h>
#define MAX 999

void insert(int num,int arr[],int *phsize)
{
	(*phsize++);
	arr[*phsize] = num;
	restoreup(arr,*phsize);
}
void restoreup(int arr, int i)
{
	int par =i/2;
	int temp = arr[i];
	while(arr[par]<temp)
	{
		arr[i]= arr[par];
		i=par;
		par=i/2;
	}
	arr[i]=temp;
}

int delete(int arr[],int *phsize)
{
	int max = arr[1];
	arr[1] = arr[*phsize];
	(*phsize--);
	restoredown(arr,1,*phsize);
}
void restoredown(int arr[],int i,int j)
{
	int lchild = 2*i;
	int rchild = 2*i+1;
	int temp = arr[i];
	while(rchild<=j)
	{
		if(arr[lchild]<temp && arr[rchild]<temp)
		{
			arr[i]=temp;
			return;
		}
		else if (arr[lchild]>arr[rchild])
		{
			arr[i] = arr[lchild];
			i=lchild;
		}
		else 
		{
			arr[i] = arr[rchild];
			i = rchild;
        }
    }
    if(lchild==j && temp<arr[lchild])
    {
    	arr[i]=arr[lchild];
    	i=lchild;
    }

    arr[i]=temp;

}
void display(int arr[],int hsize)
{
	int i;
	for(i=0;i<hsize;i++)
	printf("%d\t",arr[i] );



}

///// main method ///////
void main()
{
	int num,del;
	int arr[100];
	arr[0]= MAX;
	int choice;
	int hsize;
while(1)
	{
		printf("enter the choice");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1: printf("insertion");
		        printf("enter the no\n");
		        scanf("%d",&num);
		        insert(num,arr,&hsize);
		        break;
		case 2: printf("deletion");
		        printf("enter the no to be deleted");
		        del=delete(arr,&hsize);
		        printf("deleted element is %d",&del);
		        break;
		case 3:  display(arr,hsize);
		         break;
		 case default: exit();               
		}
    }









}