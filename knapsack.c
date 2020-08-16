#include <stdio.h>
#include<stdlib.h>
int knapsack(int *,int *,int w,int n);
int max(int ,int);
int main(void) {
  int i,n,w;
  int row=n+1;
  int *wt;
  int *value;
  int col;

  scanf("%d",&n);
  wt = (int *)malloc(sizeof(int)*n);
  value=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&wt[i]);
      }
  for(i=0;i<n;i++)
  {
    scanf("%d",&value[i]);
  }
  scanf("%d",&w);
  col=w+1;
  int **t;
  t=(int **)malloc((row)*sizeof(int *));
  for(i=0;i<row;i++)
  {
    t[i]=(int *)malloc(col*sizeof(int));
  }
  int result;
  result = knapsack(wt,value,w,n);
  printf("%d",result);
  return 0;
}
int knapsack(int *wt,int *value,int w,int n)
{
  if(w==0 || n==0)
  {
    return 0;
  }
  if(wt[n-1]<=w)
  {
    return max(value[n-1]+knapsack(wt,value, w-wt[n-1],  n-1),
    (knapsack(wt,value,w,n-1)));
  }
  else
  {
   return knapsack(wt,value,w,n-1); 
  }
}
int max(int a , int b)
{
  if(a>b)
  {
    return a;

  }
  else
  return b;
}