#include<bits/stdc++.h>
#include "LCG1.cpp"
#include "RBT1.cpp"
using namespace std;
int main() 
{
    LCG l(5,3,16);
    string s="\'HELLO WORLD\'";
    cout<<"Given Sentence to Encrypt"<<endl;
    cout<<s<<endl;
    cout<<endl;
    string en1=l.encrypt(s);
    cout<<"After 1st Level of Encrytption"<<endl;
    cout<<en1<<endl;
    cout<<endl;
    int n=en1.size();
    RedBlackTree rbTree;
    for(int i=1;i<=n;i++)
    {
        rbTree.insert(i);
    }
    vector<pair<int,Color>>rb=rbTree.level();
    string en2="";
    string en3="";
    for(int i=0;i<rb.size();i++)
    {
        en2=en2+en1[rb[i].first-1];
        if(rb[i].second==BLACK)
        {
            if(en1[rb[i].first-1]=='Z')
            {
                en1[rb[i].first-1]='A';
            }
            else
            en1[rb[i].first-1]=en1[rb[i].first-1]+1;
        }
        en3=en3+en1[rb[i].first-1];
    }
    cout<<"After 2nd Encryption"<<endl;
    cout<<en2<<endl;
    cout<<endl;
    cout<<"After 3rd Encryption"<<endl;
    cout<<en3<<endl;
    return 0;
}
