# include <iostream>
using namespace std;
void insertionsort(int a[],int n)
{
  
 for(int i=1;i<n;i++)
        {
          int  value =a[i];
           int index=i-1;
           while(index >=0 && a[index] >value)
                 {
                     a[index+1]=a[index];
                    index--;
}
                
               a[index+1]=value;
}
}
int main()
{
 int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
insertionsort(a,n);
for(int i=0;i<n;i++)
 cout<<a[i]<<" ";
}
