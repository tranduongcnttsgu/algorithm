# include <iostream>
using namespace std;
int cnt=0;
void inkq(int a[],int n)
{
  for(int i=1;i<=n;i++)
    cout<<"quan hau tai hang "<<i<<" va co "<<a[i]<<endl;
    
}

void  Try(int a[],int d1[],int d2[],int cot[],int n,int i)
{

       
  for(int j=1;j<=n;j++)
   {
        if(cot[j] ==1 && d1[i-j+n]==1 && d2[i+j-1]==1)
{
           a[i]=j;
         cot[j]=d1[i-j+n]=d2[i+j-1]=0;

        if(i==n)
            cnt++;
          else
             Try(a,d1,d2,cot,n,i+1); 
          cot[j]=d1[i-j+n]=d2[i+j-1]=1;
}
}
}
int main()
{

  int n;
cin>>n;
int a[100],d1[100],d2[100],cot[100];
for(int i=0;i<100;i++)
{
d1[i]=1;
d2[i]=1;
cot[i]=1;
}
Try(a,d1,d2,cot,n,1);
cout<<cnt;
}
