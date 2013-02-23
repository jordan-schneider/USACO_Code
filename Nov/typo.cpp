#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool check(string data){
     int left = 0;

     if(data[0]==')'||data[data.size()-1]=='(')
     {
            return false;
     }
     for(int i=0;i<data.size();i++)
     {
             if(data[i]=='(')
             {
                             left++;
             }
             else
             {
                 left--;
             }
             if(left<0)
             {
                return false;
             }
     }
     return left==0;
}

int main(int argc, char *argv[])
{
    ifstream myfile;
    myfile.open("typo.in");
    string data;
    if(myfile.is_open())
    {
     getline(myfile,data);
    }
    myfile.close();
    string stuff = "  asdf:";
    int valid = 0;
    for(int i=0;i<data.size()-1;i++)
    {
        string temp = data + "";
        if(temp[i]=='(')
        {
           temp[i] = ')';
        }
        else
        {
        temp[i] = '(';
        }
        if(check(temp))
        {
            valid++;
        }
    }
    ofstream outfile("typo.out");
    if(outfile.is_open())
    {
           outfile << valid;
    }
    outfile.close();
    return 0;

}

