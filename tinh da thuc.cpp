# include <iostream>
# include <sstream>
# include <stack>
# include <vector>
# include <string>
# include <cmath>
using namespace std;
int char_to_int(char s)
{
 string sp=string(1,s);
 stringstream ss(sp);
  int x;
 ss>>x;
return x;
}
char int_to_char(int a)
{
 char x=a+'0';
return x;
}
bool isoperator(char op)
{
 return op=='+'||op=='-'||op=='*'||op=='/'||op=='^';
}
int priority(char op)
{
    if(op=='+'||op=='-')
         return 1;
    else if(op=='*'||op=='/')
           return 2;
   else if(op=='^')
          return 3;
   else return 0;
}
string convert(string infix)
{
    stringstream result;
    stack<char> operators;
    vector<string> operands;
    string token="";
    for(int ii=0;ii<infix.length();ii++)
   {
          char tmp(infix[ii]);
       if(tmp==' ')
           continue;
       else if(isdigit(tmp)||isalpha(tmp))
             token+=tmp;
       else if(isoperator(tmp))
           {
             if(!token.empty())
                    {
                      operands.push_back(token);
                       token.clear();
                    }
             while(!operators.empty() && priority(operators.top())>=priority(tmp))
                   {
                        operands.push_back(string(1,operators.top()));
                        operators.pop();
                   }   
            operators.push(tmp);       
            }
        else if(tmp=='(')
            {
             if(!token.empty())
                   {
                   operands.push_back(token);
                    token.clear();
                   }
             operators.push(tmp);
            }
        else if(tmp==')')
             {
                if(!token.empty())
                   {
                   operands.push_back(token);
                    token.clear();
                   }
                 if(operators.empty())
                   {
                    return "ERROR\n";
                  }
                else
                    {
                     while(!operators.empty() &&operators.top()!='(')
                         {
                          operands.push_back(string(1,operators.top()));
                          operators.pop();
                         }
                    if(operators.empty()|| operators.top()!='(')
                           return "ERROR\n";
                    }
                   operators.pop();       
             }
   }  
     if(!token.empty())
        {
          operands.push_back(token);
          token.clear();
       }
      while(!operators.empty())
         {
          operands.push_back(string(1,operators.top()));
           operators.pop();     
        }
      for (int i = 0; i < operands.size(); i++) 
        result << operands[i] ;
    return result.str();
}
 double math(char a,char b,char operators)
{
  int as=char_to_int(a);
  int bs=char_to_int(b);
  int tmp;
   switch(operators)
{
       case '+':
     {        
              tmp=as+bs;
              return tmp;
          break;
       }
         case '-':
     {
               tmp=bs-as;
               return tmp;
          break;
       }
           case '*':
     {        
              tmp=as*bs;
              return tmp;
          break;
       }
           case '/':
     {       
              tmp=bs/as;
              return tmp;
          break;
       }
           case '^':
     {
               tmp=pow(bs,as);
               return tmp;
          break;
       }   
            
}   
}
 string input_value(string s)
  {
      string tmp=convert(s);
      string token="";
      for(int i=0;i<=tmp.length();i++)
          {
             if(isalpha(tmp[i]))
               {
                 int value;
               cout<<"hay nhap gia tri cho "<<tmp[i]<<" :";
                   cin>>value;
                 token+=int_to_char(value);
                 
               }
             else 
               {
                    token+=tmp[i];
                    
}

        }
return token;
}
int result_value(string s)
{
    string tmp=input_value(s);
     stack<char> st;
    int result;
   for(int i=0;i<tmp.length();i++)
      {
        
        if(isdigit(tmp[i]))
          st.push(tmp[i]);
        else if(isoperator(tmp[i]))
         {
              char a=st.top();
               st.pop();
              char b=st.top();
               st.pop();
               st.push(int_to_char(math(a,b,tmp[i])));
         }
     
}
if(st.size()==1  )
  result=char_to_int(st.top());
 else
 {
 cout<<"ERROR\n";  
return 88888;
}
return result;
}
int main()
{
bool cmp=true;
while(cmp)
{
 cout<<"1 tinh bieu thuc\n";
 cout<<"2.thoat\n";
  int i;
 cout<<"nhap lua chon:";cin>>i;
 switch(i){
    case 1:
    {
       string s;
       cout<<"nhap bieu thuc so hoac tham so:";
       cin.ignore();
       getline(cin,s);
       cout<<"================================\n";
       cout<<s<<"="<<result_value(s)<<endl;
       cout<<"================================\n";
       break;
    
}
    case 2:
         {
         cmp=false;
        break;
}
}
}

}

