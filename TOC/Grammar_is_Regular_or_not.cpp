#include <bits/stdc++.h>
using namespace std;

string substring(string s, int i, int j){
	string a = "";
	for(int k=i; k<j; ++k)
	a+=s[k];
	return a;
}

void isRegular(){
	fstream inputfile;
	inputfile.open("input.txt",ios::in);
    if (inputfile.is_open()){
    	string ls, rs, s;
    	int ll=0, rl=0;

		while(!inputfile.eof()){
			//sscanf(tp, "%s %s", ls, rs);
			inputfile>>ls>>rs;

			if(ls.size() != 1 || !(ls[0] >= 65 && ls[0] <= 90)){
				cout<<"It is not a Regular Grammar.\n";
				return;
			}

			rs = rs + "|";
			int p=0;
			for(int i=0; i<rs.size(); ++i){

				if(rs[i]=='|'){
					s=substring( rs, p, i);
					p = i+1;

					int vc=0;
					if(s.size() > 1 && s[0] >= 65 && s[0]<=90)
					ll++;
					else if(s.size() > 1 && s[s.size()-1] >= 65 && s[s.size()-1] <= 90)
					rl++;
					for(int j=0; j<s.size(); ++j){
						if(s[j] >= 65 && s[j] <= 90){
							vc++;

							if(vc > 1){
								cout<<"It is not a Regular Grammar.\n";
								return;
							}
						}
					}
				}
			}
		}
		if(ll > 0 && rl > 0)
		cout<<"It is not a Regular Grammar.\n";
		else
		cout<<"It is a Regular Grammar.\n";
    }else
    cout<<"Unable to open the file input.txt\n";
}

int main() {

	cout<<"OUTPUT:\n";

	isRegular();
	return 0;
}
