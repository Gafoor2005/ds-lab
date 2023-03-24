#include<stdio.h>
#include<conio.h>
void bubbleSort(int a[],int);
void main()
{
  int i,n,a[100];
  clrscr();
  printf("enter size of array\n");
  scanf("%d",&n);
  printf("enter the elements of array: \n");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  bubbleSort(a,n);
  printf("after sorting elements are :\n");
  for(i=0;i<n;i++)
    printf("%d\t",a[i]);
  getch();
}
void bubbleSort(int a[],int n)
{
  int i,j,temp;
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-1-i;j++)
    {
      if(a[j]>a[j+1])
      {
	temp = a[j];
	a[j] = a[j+1];
	a[j+1] = temp;
      }
    }
  }
}