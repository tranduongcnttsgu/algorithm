# include <iostream>
using namespace std;
void inkq(int a[],int k)
{
 for(int i=1;i<=k;i++)
   cout<<a[i]<<" ";
cout<<endl;
}
void startup(int a[],int n,int i,int k)
{
    for(int j=a[i-1]+1;j<=n-k+i;j++)
{

          a[i]=j;
        if(i==k)
          inkq(a,k);
        else
        startup(a,n,i+1, k);
}
} 
int main()
{
 int n,k;
cin>>n>>k;
int a[n+1];
fill(a,a+n,0);
startup(a,n,1,k);
}        
