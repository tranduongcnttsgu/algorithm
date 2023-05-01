# include <iostream>
using namespace std;
void merge(int a[],int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int Larr[n1],Rarr[n2];
    for(int i=0;i<n1;i++)
      Larr[i]=a[l+i];
    for(int i=0;i<n2;i++)
      Rarr[i]=a[m+1+i];
    i=j=0;
    k=l;
    while(i<n1 && j<n2)
       if(Larr[i]<=Rarr[j])
        a[k++]=Larr[i++];
        else
        a[k++]=Rarr[j++];
   while(i<n1)
     a[k++]=Larr[i++];
   while(j<n2)
     a[k++]=Rarr[j++];

}
void mergesort(int a[],int l,int r)
{
    if(l<r)
    {
         int m=l+(r-l)/2;
         mergesort(a,l,m);
         mergesort(a,m+1,r);
         merge(a,l,m,r);

    }
}
int main()
{
    int n;
  
    cout<<"nhap n:";cin>>n;
      int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";

}
