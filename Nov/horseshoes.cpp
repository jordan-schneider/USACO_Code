#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

bool check_left(char data[], int len, int x, int y, char c)
{
    try
  {
      if(data[(x-1)*len+y]==c){return true;}
  }
  catch(exception& e)
  {
      return false;
  }
  return false;
}

bool check_right(char data[], int len, int x, int y, char c)
{
    try
  {
      if(data[(x+1)*len+y]==c){return true;}
  }
  catch(exception& e)
  {
      return false;
  }
  return false;
}
bool check_up(char data[], int len, int x, int y, char c)
{
    try
  {
      if(data[x*len+y-1]==c){return true;}
  }
  catch(exception& e)
  {
      return false;
  }
  return false;
}
bool check_down(char data[], int len, int x, int y, char c)
{
    try
  {
      if(data[x*len+y+1]==c){return true;}
  }
  catch(exception& e)
  {
      return false;
  }
  return false;
}

int num_of_adj(char data[], int len, int x, int y, char c)
{
    int adj=0;

  if(check_left(data,len,c,y,c))
  {
      adj++;
  }
  if(check_right(data,len,c,y,c))
  {
      adj++;
  }
  if(check_up(data,len,c,y,c))
  {
      adj++;
  }
  if(check_down(data,len,c,y,c))
  {
      adj++;
  }
    return adj;
}


int longestpath(char (&data)[], int len,int &x, int &y, char c)
{
    if(num_of_adj(*data)==0){
    return 1;
    }

    int lmax = 0;
    char final[*data.size()];
    int finalx;
    int finaly;
    if(check_left(*data,*x,*y,c))
       {
        char temp[] = *data;
        temp[x*len+y] = 0;
        int lcurrent = longestpath(temp,len,x-1,y);
        if(lmax < lcurrent)
        {
            lmax=lcurrent;
            final = temp;
            finalx=x-1;
        }
       }
    if(check_right(*data,*x,*y,c))
       {
        char temp[] = *data;
        temp[x*len+y] = 0;
        int lcurrent = longestpath(temp,len,x+1,y);
        if(lmax < lcurrent)
        {
            lmax=lcurrent;
            final = temp;
            finalx=x+1;
        }
       }
    if(check_up(*data,*x,*y,c))
       {
        char temp[] = *data;
        temp[x*len+y] = 0;
        int lcurrent = longestpath(temp,len,x,y-1);
        if(lmax < lcurrent)
        {
            lmax=lcurrent;
            final=temp;
            finaly=y-1;
        }
       }
    if(check_down(*data,*x,*y,c))
       {
        char temp[] = *data;
        temp[x*len+y] = 0;
        int lcurrent = longestpath(temp,len,x,y+1);
        if(lmax < lcurrent)
        {
            lmax=lcurrent;
            final = temp;
            finaly=y+1;
        }
       }
       *data = final;
        *x = finalx;
        *y = finaly;
       return lmax+1;
    }


int main(int argc, char *argv[])
{
    ifstream myfile;
    myfile.open("hshoe.in");
    string data;
    if(myfile.is_open())
    {
     getline(myfile,data);
     char left[data[0]];
     for(int i=0;i<data[0];i++)
     {
         string temp;
         getline(myfile,temp);
        for(int j=0;j<data[0];j++)
        {
            data[i*data[0]+j] = temp[j];
        }
     }
    }
    myfile.close();
    int x=0;int y=0;

    ofstream anotherfile;
    anotherfile.open("cowfind.out");
    if(anotherfile.is_open())
    {
    anotherfile << (longestpath(left,data[0],x,y,'(') + longestpath(left,data[0],x,y,')'));
    }
    anotherfile.close();
    return 0;

}
