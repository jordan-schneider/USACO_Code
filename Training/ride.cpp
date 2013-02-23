/*
ID:skinnersboxy
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");

    string comet, group;

    fin >> comet >> group;

    cout << comet << " " << group << "||\n";

    int comet_value = 1;
    int group_value = 1;

    for(int i=0;i<comet.size();i++)
    {
    	comet_value *= (comet[i]-'A'+1);
    }

    for(int i=0;i<group.size();i++)
    {
    	group_value *= (group[i]-'A'+1);
    }

    comet_value = comet_value % 47;
    group_value = group_value % 47;

    fout << (comet_value==group_value?"GO":"STAY") << "\n";

    return 0;
}
