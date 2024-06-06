#include<stdio.h>
#include<time.h>
void bfs(int a[10][10],int n,int source)
{
int s[10],q[10],f=0,r=-1,t,v; 
 for(v=0;v<n;v++)
{
s[v]=0;
}
q[++r]= source; 
s[source]=1; 
while(f<=r)
{ 
  t=q[f++];
  for(v=0; v<n; v++)
if(a[t][v]==1 && s[v]==0)
{
  q[++r]=v;
  printf("The BFS traversal is:\n %d %d", t, v);
  s[v]=1;
}
} 
 }
 
 
main()
{
int a[10][10],n,i,j,s; 
     double clk;
     clock_t starttime,endtime;
printf("\n Enter the number of cities\n");
scanf("%d",&n); 
printf("\nEnter the matrix represention:");
for(i=0;i<n;i++) 
for(j=0;j<n;j++) 
  scanf("%d",&a[i][j]);
printf("\nEnter the source city"); 
scanf("%d",&s); 
     starttime=clock(); 
bfs(a,n,s); 
     endtime=clock();
     clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
     printf("\nThe run time is %f\n",clk);
 
}

df
#include<stdio.h>
#include<time.h>
int n,a[50][50],i,j,count=0,reach[50],pos[50];
int main()
{
       int v;
       double clk;
       clock_t starttime,endtime;
       printf("\n\t\t\t DEPTH FIRST SEARCH \n");
       printf("\n Enter number of Lands to be surveyed:");
       scanf("%d",&n);
       for(i=1;i<=n;i++)
      {
          pos[i]=0;
      }
       read_matrix();
       printf("\n Enter the starting Land number:");
       scanf("%d",&v);
       starttime=clock();
       dfs(v);
       endtime=clock();
       clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
       printf("\n Vertices reached from the given vertex are...\n");
      for(i=1;i<=count;i++)
      {
printf("%d\t",reach[i]);
      }
       printf("\nThe run time is %f\n",clk);
}
 
read_matrix()
{
printf("\n Enter the adjacency matrix (Enter 0/1)\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(i!=j)
{
printf("(%d,%d):",i,j);
scanf("%d",&a[i][j]);
}
}
 
dfs(int v)
{
int u;
reach[++count]=v;
u=adjacent(v);
while(u)
{
if(checkreach(u)==0) dfs(u);
u=adjacent(v);
}
}
adjacent(int i)
{
for(j=pos[i]+1;j<=n;j++)
if(a[i][j]==1)
{
pos[i]=j;
return j;
}
pos[i]=n+1;
return 0;
}
checkreach(int u)
{
for(i=1;i<=count;i++)
if(reach[i]==u)
return 1;
return 0;
}
 PROGRAM
#include<stdio.h>
#include<time.h>
int main()
{
   int i,n,a[1000],key,bottom,top,mid,j,temp;
   double clk;
   clock_t starttime,endtime;
     printf("Enter the number of Products\n");
   scanf("%d",&n);   
    for(i=0;i<n;i++) 
    {
      a[i]=rand()%100;
      printf("The Product ID are: \t%d",a[i]);
     }
for(i=0;i<n-1;i++)
   {
    for(j=0;j<n-i-1;j++)
      {
       if(a[j]>a[j+1]) 
      {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
      } 
}
printf("\n Sorted Product ID List is : \n");
for(i=0;i<n;i++)
{
  printf("\t%d",a[i]);
}
printf("Enter the Product ID to be searched: \n");
scanf("%d",&key); 
starttime=clock();
bottom = 1;
top = n;
do 
{
 mid = (bottom + top) / 2; 
  if (key < a[mid])
   top = mid - 1;
  else if (key > a[mid])
   bottom = mid + 1;
} while (key != a[mid] && bottom <= top);
 
if (key == a[mid]) 
 {
    printf("Product found!!\n");
    printf("\n Product %d found in position: %d\n", key, mid + 1);
 } 
else 
{
 printf("\n  Search failed\n %d not found\n", key);
}
endtime=clock();
clk=(double)(endtime-starttime)/CLOCKS_PER_SEC; 
printf("%f\n",clk);
}

