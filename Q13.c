#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int htable[50], h, ch, k, m = 10, i, pos, count = 0, flag;
void insert(int);
int search(int);
void display();
void delete(int);
void main()
{
    // clrscr();
    printf("HASH FUNCTIONS");
    printf("\n[1].Division \n[2].Multiplication\n:");
    printf("\nchoose Hash funtion:");
    scanf("%d", &h);
    while (1)
    {
        printf("\n Enter choise of operation :");
        printf("\n[1].Insert\t[2].Search\t[3].Display\t 4.Delete \t[0].Exit:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (count >= m)
                printf("\n Hash Table is full,so insertion not possible");
            else
            {
                printf("enter key to be inserted:");
                scanf("%d", &k);
                insert(k);
            }
            break;
        case 2:
            if (count == 0)
            {
                printf("\n Hash Table is Empty");
            }
            else
            {
                printf("enter key to search:");
                scanf("%d", &k);
                pos = search(k);
                if (htable[pos] == k)
                {
                    printf("\n Key fount at location :%d", pos);
                }
                else
                {
                    printf("\n key not found in the Hash table");
                }
            }
            break;
        case 3:
            if (count == 0)
            {
                printf("\nHash Table is Empty");
            }
            else
            {
                display();
            }
            break;
        case 4:
            printf("enter key u want to delete:");
            scanf("%d", &k);
            delete (k);
            break;
            default:exit(0);
        }
    }
}
int division(int k)
{
    return (k % m);
}
int multiply(int k)
{
    float A = 0.61804, t2, fa;
    int t1;
    t1 = (k * A);
    t2 = (k * A);
    fa = t2 - t1;  // h(K) = floor(m*( (k*a) % m ))
    return fa * m;
}
void insert(int k)
{
    pos = search(k);
    if (htable[pos] == k)
    {
        printf("\n key already found in hash table");
    }
    else
    {
        htable[pos] = k;
        printf("\nkey inserted at location:%d", pos);
        count++;
    }
}
int search(int k)
{
    int tc;
    if (h == 1)
        pos = division(k);
    else if (h == 2)
        pos = multiply(k);
    if (ch == 1)
    {
        flag = 0;
        while (flag == 0)
        {
            if (htable[pos] == k || htable[pos] == 0)
            {
                flag = 1;
                break;
            }
            else
            {
                printf("\n Collision occured at location :%d", pos);
                pos = (pos + 1) % m;
            }
        }
    }
    else
    {
        flag = 0;
        tc = 0;
        while (flag == 0)
        {
            if (htable[pos] == k || tc == m)
            {
                flag = 1;
                break;
            }
            else
            {
                pos = (pos + 1) % m;
                tc++;
            }
        }
    }
    return pos;
}
void display()
{
    printf("n elements in the Hash Table : \n");
    printf("\n Index \t key");
    for (i = 0; i < m; i++)
    {
        printf(" \n%d\t %d", i, htable[i]);
    }
}
void delete(int k)
{
    pos = search(k);
    if (htable[pos] == k)
    {
        htable[pos] = 0;
        count--;
        printf("\n %d key deleted from hash table", k);
    }
    else
    {
        printf("\nkey not exist in the hash table\n");
    }
}
// output:
// HASH FUNCTIONS
// [1].Division 
// [2].Multiplication
// :
// choose Hash funtion:1

//  Enter choise of operation :
// [1].Insert      [2].Search      [3].Display      4.Delete       [0].Exit:1
// enter key to be inserted:10

// key inserted at location:0
//  Enter choise of operation :
// [1].Insert      [2].Search      [3].Display      4.Delete       [0].Exit:1
// enter key to be inserted:26

// key inserted at location:6
//  Enter choise of operation :
// [1].Insert      [2].Search      [3].Display      4.Delete       [0].Exit:1
// enter key to be inserted:45

// key inserted at location:5
//  Enter choise of operation :
// [1].Insert      [2].Search      [3].Display      4.Delete       [0].Exit:3
// n elements in the Hash Table :

//  Index   key
// 0        10
// 1        0
// 2        0
// 3        0
// 4        0
// 5        45
// 6        26
// 7        0
// 8        0
// 9        0
//  Enter choise of operation :
// [1].Insert      [2].Search      [3].Display      4.Delete       [0].Exit:0