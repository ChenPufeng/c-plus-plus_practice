#include<iostream>
using namespace std;
void temperature(int t)
{
    try{
        if(t==100) throw "�е㣡";
        else if(t==0) throw "���㣡";
        else cout<<"the temperature is OK..."<<endl;
    }
    catch(int x){cout<<"temperatore="<<x<<endl;}
    catch(char const*s){cout<<s<<endl;}
}
int main(){
    temperature(0);						//L1
    temperature(10);						//L2
    temperature(100);						//L3
    system("pause");
    return 0;
}