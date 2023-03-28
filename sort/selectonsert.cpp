# include <iostream>
using namespace std;
void selectionsort(int a[],int n)
{
       for(int i=0;i<n;i++)
          {
              int index=i;
             for(int j=i+1;j<n;j++)
                if(a[j]<a[index])
                      index=j;
            if( index !=i)
                swap(a[index],a[i]);
}
  
}
int main()
{
     int n;
       cin>>n;
int a[n];
 for (int i=0;i<n;i++)
    cin>>a[i];
selectionsort(a,n);
for(int i=0;i<n;i++)
cout<<a[i]<<" ";
}
