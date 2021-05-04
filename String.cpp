//String class implementation
#include<iostream>
#include<cstring>
using namespace std;
class STRING
{
    char *str;
    public:
        STRING();
        STRING(const char *);
        STRING(STRING &); //copy constructor
        ~STRING(); //Destructor
        void print(void);
        void operator == (STRING &);
        void operator !=(STRING &);
        void operator >(STRING &);
        void operator <(STRING &);
        void operator +(STRING &);
        void operator =(STRING &);
        void operator >=(STRING &);
        void operator <=(STRING &);
        friend istream & operator >> (istream &, STRING &);
        friend ostream & operator << (ostream &, STRING &);
        void operator[] (int);
        friend int my_strlen(STRING &);
        friend void my_upper(STRING &);
        friend void my_lower(STRING &);
        friend void my_strcpy(STRING &, STRING &);
        friend void my_strncpy(STRING &, STRING &, int);
        friend void my_strcmp(STRING &, STRING &);
        friend void my_strncmp(STRING &, STRING &, int);
        friend void my_strcat(STRING &, STRING &);
        friend void my_strncat(STRING &, STRING &, int);
        friend char* my_strchr(STRING &, int);
        friend char * my_strrchr(STRING &, int);
        friend void my_strrev(STRING &);
};

STRING::STRING(){
    cout<<"default constructor"<<endl;
    const char *obj="ABC";
    str=new char[strlen(obj)+1];
    strcpy(str, obj);
}

STRING::STRING(const char *s)
{
    cout<<"Parameterised constructor"<<endl;
    str = new char[strlen(s)+1];
    strcpy(str, s);
}

STRING::STRING(STRING &s)
{
    cout<<"copy constructor"<<endl;
    str=new char[strlen(s.str)+1];
    strcpy(str, s.str);
}

void STRING::operator >= (STRING &obj)
{
    if(strcmp(str, obj.str)==1)
    cout<<"Greater"<<endl;
    else if(strcmp(str, obj.str)==0)
    cout<<"Equal"<<endl;
    
}

void STRING :: operator <=(STRING &obj)
{
    if(strcmp(str, obj.str)==0)
    cout<<"Equal"<<endl;
    else if(strcmp(str, obj.str)==-1)
    cout<<"Less"<<endl;
}

void STRING:: operator ==(STRING& obj)
{
    
    if(strcmp(str, obj.str)==0)
    cout<<"Equal Strings\n"<<endl;
}

void STRING :: operator != (STRING &obj)
{
    
    if(strcmp(str, obj.str)==1 || -1)
    cout<<"Strings not equal"<<endl;
}

void STRING :: operator > (STRING &obj)
{
    if(strcmp(str, obj.str)==1)
    cout<<"String 1 is greater than string 2"<<endl;
}

void STRING :: operator < (STRING &obj)
{
    if(strcmp(str, obj.str)==-1)
    cout<<"String 1 is less than String 2"<<endl;
}

void STRING:: operator +(STRING &obj)
{
    strcat(str, obj.str);
}

void STRING:: operator =(STRING &obj)
{
    strcpy(str, obj.str);
}

STRING :: ~STRING(){
    cout<<"Destructor"<<endl;
}

void STRING :: print()
{
    cout <<"String "<<str<<endl;
}

istream & operator >>(istream &in, STRING &obj)
{
    cout<<"Enter the string"<<endl;
    in>>obj.str;
    return in;
}

ostream & operator << (ostream &out, STRING &obj)
{
    
   out<<obj.str<<endl;
   return out;
    
}

void STRING :: operator [] (int index)
{
    str[index]='z';
    cout<<str[index]<<endl;
}

int my_strlen(STRING &obj)
{
    int i;
    for(i=0; obj.str[i]; i++);
    return i;
}

void my_upper(STRING &obj)
{
    int i;
    for(i=0; obj.str[i]; i++)
    if(obj.str[i]>='a' && obj.str[i]<='z')
    obj.str[i]=obj.str[i]-32;
    cout<<"STRING IN UPPER CASE "<<obj.str<<endl;
}

void my_lower(STRING &obj)
{
    int i;
    for(i=0; obj.str[i]; i++)
    if(obj.str[i]>'A' && obj.str[i]<'Z')
    obj.str[i]=obj.str[i]+32;
    cout<<"string in lower case "<<obj.str<<endl;
}

void my_strcpy(STRING &obj1, STRING &obj2)
{
    int i;
    for(i=0; obj2.str[i]; i++)
    obj1.str[i]=obj2.str[i];
    obj1.str[i]=obj2.str[i];
    cout<<"Copy String"<<obj1.str<<endl;
}

void my_strncpy(STRING &obj1, STRING &obj2, int num)
{
    int i;
    for(i=0; i<num; i++)
    obj1.str[i]=obj2.str[i];
    obj1.str[i]='\0';
    cout<<"String copied "<<obj1.str<<endl;
}

void my_strncmp(STRING &obj1, STRING &obj2, int n)
{
    int i=0;
    for(i=0; i<n; i++)
    {
        if(obj1.str[i]!=obj2.str[i])
        break;
    }
    if(obj1.str[i]==obj2.str[i])
    cout<<"Strings are equal"<<endl;
    else if(obj1.str[i]>obj2.str[i])
    cout<<"String 1 is greater than string 2"<<endl;
    else 
    cout<<"String 1 is smaller than string 2"<<endl;
}

void my_strcmp(STRING &obj1, STRING &obj2)
{
    int i;
    for(i=0; obj1.str[i]; i++)
    {
        if(obj1.str[i]!=obj2.str[i])
        break;
    }
    if(obj1.str[i]==obj2.str[i])
    cout<<"Strings are equal"<<endl;
    else if(obj1.str[i]>obj2.str[i])
    cout<<"String1 is greater than String2"<<endl;
    else
    cout<<"String1 is smaller than string2"<<endl;
}

void my_strcat(STRING &obj1, STRING &obj2)
{
    int i, j;
    cout<<"strncat result ";
    for(i=0; obj1.str[i]; i++);
    for(j=0; obj2.str[j]; j++, i++)
    obj1.str[i]=obj2.str[j];
    obj1.str[i]='\0';
    cout<<"Concatenated string - "<<obj1.str<<endl;

}


void my_strncat(STRING &obj1, STRING &obj2, int num)
{
    int i, j;
    for(i=0; obj1.str[i]; i++);
    for(j=0; j<=num; j++, i++)
    obj1.str[i]=obj2.str[j];
    obj1.str[i]='\0';
    cout<<"Concatenated string - "<<obj1.str<<endl;
    
}

char* my_strchr(STRING &obj, int ch)
{
    int i;
    for(i=0; obj.str[i]; i++)
    {
        if(obj.str[i]==ch)
        return obj.str+i;
        break;
    }
    return 0;
}

char * my_strrchr(STRING &obj, int c)
{
    int i;
    for(i=0; obj.str[i]; i++);
    for(i=i-1; i>0; i--)
    {
        if(obj.str[i]==c)
        return obj.str+i;
        break;
    }
    return 0;
}

void my_strrev(STRING &obj)
{
    char i, j, t;
    i= strlen(obj.str);
    for(j=0, i=i-1; i>j; i--, j++)
    {
        t=obj.str[j];
        obj.str[j]=obj.str[i];
        obj.str[i]=t;
    }
cout<<"Reversed string - "<<obj.str<<endl;

    
}

int main()
{
    STRING s1;
    STRING s2("VECTOR");
    STRING s3(s2);
    s1.print();
    s2.print();
    s3.print();
    s1>=s3;
    s1<=s2;
    s1!=s2;
    s2==s3;
    s1<s2;
    s1>s2;
    s1+s2;
    s1.print();
    s1=s2;
    s1.print();
    
    cin>>s1;
    cout<<s1;
    s2[0];
    
    int len=my_strlen(s2);
    cout<<"String length : "<<len<<endl;
    
    my_upper(s3);
    
    my_lower(s2);
    
    my_strcpy(s2, s3);
    
    cout<<"strncpy results "<<endl;
    
    my_strncpy(s2, s1, 4);
    
    my_strcmp(s1, s2);
    
    my_strncmp(s1, s2, 3);
    
    my_strcat(s1, s2);
    
    my_strncat(s1, s2, 3);
    
    char *q=my_strchr(s1, 's');
    if(q==0)
    cout<<"Character not present "<<endl;
    else
    cout<<"s present in"<<q<<" "<<"@"<<&q<<endl;
    
    char *r=my_strrchr(s1, 'a');
    if(r==0)
    cout<<"Character not present "<<endl;
    else
    cout<<"a present in"<<r<<" "<<"@"<< &r<<endl;
    
    my_strrev(s3);
    
    
}
