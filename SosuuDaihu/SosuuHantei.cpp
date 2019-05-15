#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
vector<ll> stc;
bool PrimeJudge(ll num){
  if(num%2==0) return false;
  for(ll i=3;i*i<num;i+=2){
    if(num%i==0) return false;
  }
  return true;
}
void Gousei(ll num){
  while(!PrimeJudge(num)){
    if(num%2==0){
      stc.push_back(2);
      num/=2;
    }else{
      for(ll i=3;i*i<num;i+=2){
        if(num%i==0){
          stc.push_back(i);
          num/=i;
          break;
        }
      }
    }
  }
  stc.push_back(num);
  for(ll i=0;i<stc.size()-1;i++){
    cout<<stc[i]<<"*";
  }
  cout<<stc[stc.size()-1]<<endl;
}
int main(){
  ll num;
  cin>>num;
  if(PrimeJudge(num)){
    cout<<"素数です!!"<<endl;
  }else{
    cout<<"素数ではありません"<<endl;
    Gousei(num);
  }
  return 0;
}
