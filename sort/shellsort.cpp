# include <iostream>
# include <cstdlib>
using namespace std;
void shellsort(int a[],int n)
{

int h=1,value,j;
while(h<n/3)
h=3*h+1;

while(h>0)
{
      for(int i=h;i<n;i++)
          {
            value=a[i];
                j=i;
             while(j>h-1&& a[j-h]>value)
{

                           a[j]=a[j-h];
                         j-=h;
}
              a[j]=value;          
} 
 h=(h-1)/3;                 
}

}
int main()
{
 int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
shellsort(a,n);
for(int i=0;i<n;i++)
cout<<a[i]<<" ";
}
