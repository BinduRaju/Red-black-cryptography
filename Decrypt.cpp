#include<bits/stdc++.h>
#include "LCG1.cpp"
#include "RBT1.cpp"
using namespace std;
int main()
{
    string d="!XINYZG!MAT M";
    cout<<"Sentence to be decrypted:"<<endl;
    cout<<d<<endl;
    int n=d.size();
    RedBlackTree rbTree;
    string de1="";
    string de2="";
    for(int i=1;i<=n;i++)
    {
        rbTree.insert(i);
        de2+='_';
        de1+='_';
    }
    vector<pair<int,Color>>rb=rbTree.level();
    for(int i=0;i<rb.size();i++)
    {
        if(rb[i].second==BLACK)
        {
            if(d[i]=='A')
            {
                d[i]='Z';
            }
            else{
                d[i]=d[i]-1;
            }
        }
        de1[i]=d[i];
        de2[rb[i].first-1]=d[i];   
    }
    LCG l(5,3,16);
    cout<<"After 1st Encryption"<<endl;
    cout<<de1<<endl;
    cout<<endl;
    cout<<"After 2nd Encryption"<<endl;
    cout<<de2<<endl;
    cout<<endl;
    cout<<"After 3rd Encryption"<<endl;
    string de3=l.encrypt(de2);
    cout<<de3<<endl;
    return 0;
}