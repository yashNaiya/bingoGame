#include<iostream>
#include<fstream>
#include<unistd.h>
#include<windows.h>
#include<string.h>
using namespace std;
/*i am doing some changes from github*/
class page1
{
    char username[20];
    char password[20];
public:
    int c=0;
    page1()
    {
        system("cls");
        cout<<"\n1.login\n2.signin\n3.exit\n";
        int choice;
        cin>>choice;
        if(choice==1)
            login();
        else if(choice==2)
            signin();
        else if(choice==3){}
            /*else if(choice==4)
        {
            fstream fin;
            int pos=c*2;
            int w;
            fin.open("wins.txt",ios::in);
            w=fin.get(pos,ios::beg);
            cout<<w;
            fin.close();
        }
            exit(0);*/
        else
        {cout<<"\nenter proper input";
         page1();}

    }
    void login()
    {
        char un[20],pw[20];
        ifstream fin;
        fin.open("logs.txt",ios::app);
        cout<<"\n--------------\n";
        cout<<"username :";
        cin>>un;
        cout<<"\npassword :";
        cin>>pw;
        fin.seekg(0);
        while(fin)
        {
            fin>>username>>password;
            c++;
             if(strcmp(un,this->username)==0 && strcmp(pw,this->password)==0)
                break;
            if(fin.eof())
                {cout<<"\nwrong username or password\n";
                 usleep(2000000);
                 page1();
                }

        }
        fin.close();

    }
    void signin()
    {
        ofstream fout;
        fout.open("logs.txt",ios::app);
        cout<<"\n--------------\n";
        cout<<"username :";
        cin>>username;
        cout<<"\npassword :";
        cin>>password;
        fout<<username<<" "<<password<<" ";
        fout.close();
        page1();
    }
};
class page2:public page1
{
public:
    page2()
    {
        int choice;
        p:
        system("cls");
        cout<<"\n1.new game\n2.about game\n3.exit\n";
        cin>>choice;
        if(choice==3)
            page1();
        else if(choice==2)
           {
               //string st;
               ifstream ab;
               char c,e;
               ab.open("about.txt",ios::in);
               /*while (!ab.fail() && !ab.eof() )
                    {
                        ab >> st ;
                        cout << st << endl;
                    }
               cout<<st<<endl;*/
               while(!ab.fail() && !ab.eof())
               {
                   c=ab.get();
                   cout<<c;
               }
               ab.close();
               cout<<"\n\npress e to exit\n";
               j:
               cin>>e;
               if(e=='e')
                goto p;
               else
                goto j;
           }
        else if(choice==1)
        {}
        else
            cout<<"\nenter proper value";
    }
    void display(int a[5][5])   //fun
    {
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {cout<<"\t"<<a[i][j];
        }cout<<endl;
}}
};
class page3:public page2
{
    int win=0;
public:
    page3()
    {
        game();
    }
int chkh(int a[5][5])   //fun
{int c=0,d=0;
for(int i=0;i<5;i++)
{
for(int j=0;j<5;j++)
{
if(a[i][j]==0)
{c++;
}
if(c==5)
{
d++;
c=0;
}}c=0;}
return d;
}

int chkv(int a[5][5])   //fun
{int c=0,d=0;
for(int i=0;i<5;i++)
{
for(int j=0;j<5;j++)
{
if(a[j][i]==0)
{c++;
}
if(c==5)
{
d++;
c=0;
}}c=0;}
return d;
}
int chkd1(int a[5][5])  //diagonal
{int c=0,d=0;
for(int i=0;i<5;i++)
{
if(a[i][i]==0)
{c++;
}
}
if(c==5)
{
d++;
}return d;
}
/*void save_win()
{
    fstream fout;
    int pos=c*2;
    fout.open("wins.txt",ios::out | ios::ate);
    fout.seekp(pos,ios::beg);
    fout.put(win);
    fout.close();
}*/
int chkd2(int a[5][5])   //diagonal2
{int c=0,d=0;
for(int i=0;i<5;i++)
{for(int j=(4-i);j>=(4-i);j--)
{
if(a[i][j]==0)
{c++;
}
}
if(c==5)
{
d++;
}}return d;
}



void game()
{
system("cls");
int n,i,j,q,w,x,y,e,r,t=0;
int a[5][5];
cout<<"\nEnter no.s for 5x5 bingo table:\n";
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
cin>>a[i][j];
if(a[i][j]>25 || a[i][j]<1)
{
    cout<<"\nenter number which is between 25 numbers\n";
    cin>>a[i][j];
}

}}
display(a);
while(t!=5)
{
cout<<"Enter no.";
cin>>n;
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
if(a[i][j]==n)
{
a[i][j]=0;
}}}

display(a);
 q=chkv(a);
 w=chkh(a);
 e=chkd1(a);
 r=chkd2(a);
 t=q+w+e+r;
 if(t==5) {
        win++;
// save_win();
 cout<<"Bingo!!";
 }   }
	  }
};

int main()
{
    page3 m;
    return 0;
}
