#include<stdio.h>
#include<conio.h>
void selectionSort(int a[],int);
void main()
{
  int i,n,a[100];
  clrscr();
  printf("enter size of array\n");
  scanf("%d",&n);
  printf("enter the elements of array: \n");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  selectionSort(a,n);
  printf("after sorting elements are :\n");
  for(i=0;i<n;i++)
    printf("%d\t",a[i]);
  getch();
}
void selectionSort(int a[],int n)
{
  int i,j,temp;
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
      if(a[i]>a[j])
      {
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
      }
}