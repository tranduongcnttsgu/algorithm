# include <iostream>
# include <cstdlib>
using namespace std;
int partition(int a[],int l,int r)
{
   int pivot=a[l];
   int i=l-1;
     int j=r+1;
    while(true)
         {
               do{
                 ++i;
} while(pivot >a[i]);
                     do{
                     --j;
}
                 while(pivot<a[j]);
           if(i<j)
              swap(a[i],a[j]);
            else return j;
}
}
void qicksort(int a[],int l,int r)
{
if(l>=r) return;
int p=partition(a,l,r);
qicksort(a,l,p);
qicksort(a,p+1,r);
}
int main()
{
int n;
 cin>>n;
int a[n];
for(int i=0;i<n;i++)
a[i]=rand()%100;
qicksort(a,0,n-1);
for(int i=0;i<n;i++)
cout<<a[i]<<" ";
}
