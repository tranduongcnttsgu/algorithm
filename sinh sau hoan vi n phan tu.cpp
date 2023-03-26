# include <iostream>
using namespace std;
void inkq(int a[],int n)
{
      for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
     cout<<endl;
}
void startup(int a[],int used[],int n,int i)
{
     for(int j=1;j<=n;j++)
            {
             if(used[j]==0)
              {
                   a[i]=j;
                  used[j]=1;
           if(i==n)
               inkq(a,n);
            else 
                 startup(a,used,n,i+1);
               used[j]=0;
}
}           
}
        int main()
{
        int n;
         cin>>n;
         int a[n+1],used[n+1];
         fill(used,used+n+1,0);
         startup(a,used,n,1);
}
