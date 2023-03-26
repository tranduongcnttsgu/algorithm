# include <iostream>
using namespace std;
void inkq(int a[],int n)
{
  for(int i=1;i<n+1;i++)
      cout<<a[i]<<" ";
   cout<<endl;
}
void startup(int x[],int n,int i)
{
  for(int j=0;j<=1;j++)
       {
        x[i]=j;
if(i==n)
    inkq(x,n);
else
startup(x,n,i+1);
}
}
int main()
{
 int n;
cin>>n;
int x[n+1];
startup(x,n,1);
}
