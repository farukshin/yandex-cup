#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
typedef long double ld;

string check(string &s)
{
	string ans="";
	int pos=0;
	while(pos != s.size())
		if(s.substr(pos, 3) == "one")
			pos+=3, ans = ans + "1";
		else if(s.substr(pos, 4) == "zero")
			pos+=4, ans= ans+ "0";
	return ans;
}

void solve()
{
	string s1,s2;
	cin>>s1>>s2;
	string a=check(s1), b=check(s2);
	int mx = max(int(a.size()), int(b.size()));
	a = string(mx-a.size(), '0') + a;
	b = string(mx-b.size(), '0') + b;
	cout<<(a>b ? ">": a==b ? "=":"<");
}

int main()
{
	solve();
    return 0;
}
