#include<stdio.h>
#include<conio.h>
void insertionSort(int a[],int);
void main()
{
  int i,n,a[100];
  clrscr();
  printf("enter size of array\n");
  scanf("%d",&n);
  printf("enter the elements of array: \n");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  insertionSort(a,n);
  printf("after sorting elements are :\n");
  for(i=0;i<n;i++)
    printf("%d\t",a[i]);
  getch();
}
void insertionSort(int a[],int n)
{
  int i,j,temp;
  for(i=1;i<n;i++)
  {
    temp = a[i];

    j=i;
    while(j>0&&a[j-1]>temp)
    {
      if(a[j-1]>a[j])
      {

	a[j] = a[j-1];
	j--;
      }
      a[j] = temp;

    }
  }
}