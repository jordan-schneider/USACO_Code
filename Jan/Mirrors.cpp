#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Fence {
	long x;
	long y;
	bool right;
	Fence(long x,long y,bool right)
		:x(x),y(y),right(right) {}
};

vector<Fence> fences;using namespace std;
ifstream myfile;

void readFence(int n){
	string s;
	for(int i=0;i<n;i++){
		getline(myfile,s);
		fences.push_back(Fence(s[0]-'0',s[2]-'0',s[4]=='/'));
	}
}

Fence look_up(long x,long y){
	Fence min = Fence(1000001,1000001,true);
	for(int i = 0;i<fences.size();i++){
		if(fences[i].x==x&&fences[i].y<min.y&&fences[i].y>y){
			min = fences[i];
		}
	}
	return min;
}
Fence look_down(long x,long y){
	Fence max = Fence(-1000001,-1000001,true);
	for(int i = 0;i<fences.size();i++){
		if(fences[i].x==x&&fences[i].y>max.y&&fences[i].y<y){
			max = fences[i];
		}
	}
	return max;
}
Fence look_right(long x,long y){
	Fence min = Fence(1000001,1000001,true);
	for(int i = 0;i<fences.size();i++){
		if(fences[i].y==y&&fences[i].x<min.x&&fences[i].x>x){
			min = fences[i];
		}
	}
	return min;
}
Fence look_left(long x,long y){
	Fence max = Fence(-1000001,-1000001,true);
	for(int i = 0;i<fences.size();i++){
		if(fences[i].y==y&&fences[i].x>max.x&&fences[i].x<x){
			max = fences[i];
		}
	}
	return max;
}

Fence look(int dir,long x,long y){
	switch(dir){
	case 0:
		return look_up(x,y);
		break;
	case 1:
		return look_right(x,y);
		break;
	case 2:
		return look_down(x,y);
		break;
	default:
		return look_left(x,y);
	}
}

bool traverse(long final_x,long final_y){

	long x=0;
	long y=0;
	int dir=1;



	while(x!=final_x||y!=final_y){

		Fence temp = look(dir,x,y);

		if((temp.x==-1000001)||(temp.y==-1000001)||(temp.x==1000001)||(temp.y==1000001)){
			cout << "NOPE\n";
			return false;
		}

		//deciding direction
		if(temp.right){
			if(dir%2 == 1){
				dir--;
			}
			else if(dir%2 ==0){
				dir++;

			}
		}
		else{
			if(dir%2 == 1){
				dir++;
			}
			else if(dir%2 ==0){
				dir--;

			}
		}

		if(dir == -1){
			dir = 3;
		}

		dir = dir%4;

		cout<<dir<<"\n";

		x = temp.x;
		y = temp.y;

	}
	cout << "WORKS\n";
	return true;

}


int main(int argc, char *argv[])
{
    myfile.open("mirrors.in");

    ofstream anotherfile;
    anotherfile.open("mirrors.out");

    string sizes;

    if(myfile.is_open())
    {
    	getline(myfile,sizes);
    }

	readFence(sizes[0]-'0');

	fences.push_back(Fence(sizes[2]-'0',sizes[4]-'0',true));

	int num_fence=0;

	if(!traverse(sizes[2]-'0',sizes[4]-'0')){
		cout << "TEST";
		num_fence = -1;
		for(int i=0;i<fences.size()-1;i++){
			fences[i].right = !fences[i].right;
			if(traverse(sizes[2]-'0',sizes[4]-'0')){
				anotherfile << (i+1);
				break;
			}
			fences[i].right = !fences[i].right;
		}

	}

	//anotherfile << num_fence;

}
