# include <iostream>
# include <stack>
# include <vector>
using namespace std;

int main()
{
int n;
cin>>n;
stack<int> s;
vector<int> in (n);
vector<int> out (n);
for(int i=0;i<n;i++)
{
 cin>>in[i];
}

for(int i=0;i<in.size();i++)
{
    if(s.empty())
         s.push(i);
     else
         {
          while(!s.empty() && in[s.top()]<in[i])
{
               out[s.top()]=in[i];
                     s.pop();
} 
           s.push(i);       
}

}
  while(!s.empty())
    {
        out[s.top()]=-1;
          s.pop();
}
for(int i=0;i<n;i++)
 cout<<out[i]<<" ";
 
 
}


