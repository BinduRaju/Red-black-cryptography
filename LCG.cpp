#include<bits/stdc++.h>
using namespace std;

class LCG
{
    public:
    map<char,char>Encryption;
    LCG(int a,int b,int c)
    {
        char mp1[16] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};//1st set of 16 elements
        char mp2[16] = {'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '.', ',', '?', '@', '\''};//2nd set of 16 elements
        for(int i=0;i<16;i++)
        {
            int m=((a*i)+b)%c;
            Encryption[mp1[i]]=mp2[m];
            Encryption[mp2[m]]=mp1[i];//mapping 1set letters to 2nd set and viceversa
        }
    }
    string encrypt(string& s)
    {
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            ans+=Encryption[s[i]];
        }
        return ans;
    }
};
