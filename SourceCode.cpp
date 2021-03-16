/*   LIBRARY MANAGEMENT SYSTEM (SOURCE CODE)  */

#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

void fun();
class book
{
private:
    int isbn;
    int quantity;
    int id;
    char name[20];
    char branch [20];
    char title[20];
    char writer[20];
public:
    book()
    {
        isbn=0;
        strcpy(writer,"no writer");
        strcpy(title,"no title");
        quantity=0;
    }

   void showbookdata()
   {
       cout<<"\n"<<isbn<<""<<title<<""<<""<<writer<<"\t\t\t"<<quantity;
   }
   void showmember()
   {
       cout<<"\n\n"<<id<<"\t\t"<<name<<"\t\t"<<branch;
   }
   void issue()
   {
       cout<<"\n"<<""<<id;
   }
   void issue1()
   {
       cout<<""<<title;
   }
   void getdata();
   int storebook();
   void viewallbooks();
   void searchbook(int);
   void deletebook(int);
   void getmemberdata();
   int storememberdata();
   void showmemberdata();
   void deletememberdata(int);
   void issuebook(int,int);
   void update(int);
   void ammend(int);
   void listofissuedbooks();
   void depositbook(int,int);
};
void book::getdata()
{
        cout<<"Enter ISBN no.";
        cin>>isbn;
        cout<<"\nEnter Book Name ";
        cin.ignore();
        cin.getline(title,19);
        cout<<"\nEnter Writer Name ";
        cin.getline(writer,19);
        cout<<"\nEnter Quantity ";
        cin>>quantity;
        cout<<"\n\nBOOK HAS BEEN ADDED SUCCESSFULLY\n";
}

void book::getmemberdata()
{
  cout<<"Enter Member ID ";
  cin>>id;
  cout<<"\nEnter Member Name ";
  cin.ignore();
  cin.getline(name,19);
  cout<<"\nEnter Member Branch ";
  cin.getline(branch,19);
  cout<<"\nMember Has Addded Successfully ";
}

int book::storememberdata()
{
 if(id==0)
    {
         cout<<"not initialized";
         return 0;
    }
    else
    {
    ofstream fout;
    fout.open("file2.txt",ios::app|ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
    return 1;
    }
}

void book::deletememberdata(int t)
{
    ifstream fin;
    ofstream fout;
    fin.open("file2.txt",ios::in|ios::binary);
    fout.open("temp.txt",ios::out|ios::binary);
    fin.read((char*)this,sizeof(*this));
       while(!fin.eof())
       {
        if ((id!=t))
            fout.write((char *)this,sizeof(*this));
        fin.read((char*)this,sizeof(*this));
       }
    fin.close();
    fout.close();
    remove("file2.txt");
    rename("temp.txt","file2.txt");
}

void book::showmemberdata()
{
    ifstream fin;
    fin.open("file2.txt",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
      while(!fin.eof())
      {
      showmember();
      fin.read((char*)this,sizeof(*this));
      }
   fin.close();
}

int book::storebook()
{
    if(isbn==0&&quantity==0)
    {
        cout<<"not initialized";
         return 0;
    }
    else
    {
    ofstream fout;
    fout.open("file1.txt",ios::app|ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
    return 1;
    }
}

void book::viewallbooks()
{
    ifstream fin;
    fin.open("file1.txt",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
      while(!fin.eof())
      {
      showbookdata();
      fin.read((char*)this,sizeof(*this));
      }
   fin.close();
}

void book::searchbook(int t)
{
    int counter=0;
   ifstream fin ;
   fin.open("file1.txt",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
      while(!fin.eof())
      {
        if ((t==isbn))
       {
        showbookdata();
        counter++;
       }
        fin.read((char*)this,sizeof(*this));
      }
      if(counter==0)
        cout<<"Record Not Found";
    fin.close();
}

void book::deletebook(int t)
{
    ifstream fin;
    ofstream fout;
    fin.open("file1.txt",ios::in|ios::binary);
    fout.open("temp.txt",ios::out|ios::binary);
    fin.read((char*)this,sizeof(*this));
       while(!fin.eof())
       {
        if ((isbn!=t))
            fout.write((char *)this,sizeof(*this));
        fin.read((char*)this,sizeof(*this));
       }
    fin.close();
    fout.close();
    remove("file1.txt");
    rename("temp.txt","file1.txt");
}

void book::issuebook(int t,int r)
{
ofstream fout;
fout.open("file3.txt",ios::app|ios::binary);
fout<<""<<t<<"\t\t\t";
fout.close();
 ifstream fin ;
   fin.open("file1.txt",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
      while(!fin.eof())
      {
        if (r==isbn)
       {
         ofstream fout1;
         fout1.open("file3.txt",ios::app|ios::binary);
         fout1<<isbn<<"\t\t\t"<<title;
         fout1<<"\n";
         fout1.close();
       }
        fin.read((char*)this,sizeof(*this));
      }
 fin.close();
}

void book::ammend(int t)
{
  fstream file;
  file.open("file1.txt",ios::in|ios::out|ios::ate|ios::binary);
  file.seekg(0);
  file.read((char*)this,sizeof(*this));
  while(!file.eof())
  {
      if(t==isbn)
      {
         quantity--;
        file.seekp(file.tellp()-sizeof(*this));
        file.write((char*)this,sizeof(*this));
      }
      file.read((char*)this,sizeof(*this));
  }
  file.close();
}

void book::listofissuedbooks()
{
cout<<" ****************LIST OF ISSUED BOOKS****************\n\n\n";
cout<<" Member ID "<<"\t\t"<<"ISBN"<<"\t\t\t"<<"Book Name \n\n";
ifstream fin;
fin.open("file3.txt");
char ch;
while(!fin.eof())
{
   ch=fin.get();
   cout<<ch;
}
fin.close();
}


int main()

{
    book b1,b2;
   int a,b,c,d,p,k1,k2;
    s2:
    system("cls");
    cout <<"\t\t**********CENTRE LIBRARY**********"<< endl;
    cout<<"\t\t\tAddress-Civil lines"<<endl<<"\t\t     PinCode-273004 Gorakhpur"<<endl<<endl;
    cout<<"Enter Password-";
    cin>>p;
    if(p==1020)
       {
        cout<<"Access Granted";
        loot:
                system("cls");
        cout <<"\t\t**********CENTRE LIBRARY**********"<< endl;
        cout<<"\t\t\tAddress-Civil lines"<<endl<<"\t\t     PinCode-273004 Gorakhpur"<<endl<<endl;
        cout<<"1. Add new books"<<endl;
        cout<<"2. Add new members"<<endl;
        cout<<"3. Remove a book"<<endl;
        cout<<"4. Remove a member"<<endl;
        cout<<"5. Issue a book"<<endl;
        cout<<"6. View members account"<<endl;
        cout<<"7. View stock"<<endl;
        cout<<"8. List of books issued"<<endl;
        cout<<"9. Exit\n\n";
        cout<<"Enter Your Choice ";
        cin>>b;
        switch(b)
        {

  case 1:
{
    s1:
    fun();
    b1.getdata();
    b1.storebook();
    cout<<"\n Press 1 to add more books";
    cout<<"\n press 2 to go main menu\n";
    cin>>k1;
    if(k1==1)
         {goto s1;}
    if(k1==2)
        {goto loot;}
    break;
}

  case 2:
{
fun();
b1.getmemberdata();
b1.storememberdata();
cout<<"\n\n press 1 to add more members";
cout<<"\n press 2 to go main menu\n";
    cin>>k1;
    if(k1==1)
       goto s1;
    if(k1==2)
        goto loot;
    break;
}
  case 3:
{
    fun();
     cout<<"Enter ISBN Number ";
   int m;
   cin>>m;
   b1.deletebook(m);
   cout<<"\nBook Has Been Deleted";
   cout<<"\n\n press 1 to go main menu\n";
    cin>>k1;
    if(k1==1)
        goto loot;
   break;

}

case 4:
 {
  fun();
   cout<<"Enter Member ID ";
   int n;
   cin>>n;
   b1.deletememberdata(n);
   cout<<"\nMember Has Been Deleted";
   cout<<"\n\n press 1 to go main menu\n";
    cin>>k1;
    if(k1==1)
        goto loot;

}
 case 5:
{
fun();
 cout<<"************************LIST OF BOOKS************************"<<endl<<endl<<endl;
    cout<<"ISBN NO.    "<<"BOOK NAME          "<<"WRITER NAME         "<<"QUANTITY\n";
    b1.viewallbooks();
    int r;
    cout<<"\n\nEnter Member ID Number ";
    cin>>r;
     cout<<"\n\nEnter Book ISBN number ";
    int q;
    cin>>q;
    b1.issuebook(r,q);
    b1.ammend(q);
    cout<<"\n\n BOOK HAS BEEN ISSUED SUCCESSFULLY";
    cout<<"\n\n press 1 to go main menu\n";
    cin>>k1;
    if(k1==1)
        goto loot;
break;
}

  case 6:
{
fun();
cout<<"*************** Member Account *****************";
cout<<endl<<"\nMember ID"<<""<<"Member Name"<<""<<"Member Branch";
b1.showmemberdata();
cout<<"\n\n press 1 to go main menu\n";
    cin>>k1;
    if(k1==1)
        goto loot;
break;
}
  case 7:
{
    loop:
    fun();
    cout<<"1. Search all books\n"<<endl;
    cout<<"2. Search particular book"<<endl;
    int s;
    cin>>s;
    switch(s)
    {
    case 1:
     {
     fun();
    cout<<"************************LIST OF BOOKS************************"<<endl<<endl<<endl;
    cout<<"ISBN NO.    "<<"BOOK NAME          "<<"WRITER NAME         "<<"QUANTITY\n";
    b1.viewallbooks();
    cout<<"\n\nPress 1 to go back or Press 2 to go to main menu ";
    int z;
    cin>>z;
    if(z==1)
        goto loop;
     else
        goto loot;
    }
      case 2:
      {
     cout<<"\nEnter ISBN Number To Search";
      int n;
      cin>>n;
      cout<<"\n"<<"ISBN NO.  "<<"BOOK NAME        "<<"WRITER NAME          "<<"QUANTITY\n";
      b1.searchbook(n);
      cout<<"\n\nBOOK HAS BEEN FOUND";
      }
    }
cout<<"\n\n press 1 to go main menu\n";
    cin>>k1;
    if(k1==1)
        goto loot;
break;
}

  case 8:
{
fun();

    b1.listofissuedbooks();
    cout<<"\n\n press 1 to go main menu\n";
    cin>>k1;
    if(k1==1)
        goto loot;
break;
}

  case 9:
    return 0;
}
 }  else
    {
    cout<<"\nAccess Denied.Try Again.";
    getch();
    goto s2;
    }
    return 0;
}

 void fun()
 {
      system("cls");
      cout <<"\t\t**********CENTRE LIBRARY**********"<< endl;
      cout<<"\t\t\tAddress-Civil lines"<<endl<<"\t\t     PinCode-273004 Gorakhpur"<<endl<<endl;
 }


