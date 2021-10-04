#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef long double ld;

int k,n,m;
map<string, int> mp;
bool success = true;

string mn(string s1, string s2)
{
	string s= s1+s2;
	string ans=s;
	for(int i=0;i<3;i++)
	{
		swap(s[0],s[1]);
		swap(s[1],s[3]);
		swap(s[2],s[3]);
		ans = min(ans, s);
	}
	return ans;
}

bool check(string &s1, string &s2)
{
	int pos = 0;
	while(pos<s1.size())
	{
		string a = s1.substr(pos,2);
		string b = s2.substr(pos,2);
		string s = mn(a,b);
		if(mp.count(s) && mp[s]>0)
			mp[s]--;
		else
		{
			success = false;
			return false;
		}
		pos+=2;
	}
	return true;
}

void solve()
{
	cin>>k;
	for(int i=0;i<k;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		mp[mn(s1,s2)]++;
	}

	cin>>n>>m;
	for(int i=0;i<n/2;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		if(!check(s1,s2))
			break;
	}
	cout<<(success ? "Yes":"No");
}

int main()
{
	solve();
    return 0;
}
