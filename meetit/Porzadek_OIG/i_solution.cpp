#include <iostream>
using namespace std;
#include <vector>


int solution(int n, char desc[], int a, int b){

  for (int i=a; i<b; i++){
    if(a==b) {
      return 0;
    }
    if(desc[i]=='R'){
      a=i;
      break;
    }else {
      a++;
    }
  }

  vector<int> pref;
  pref.push_back(0);

  for (int i=a+1; i<=b; i++){
    if (desc[i]=='N'){
      for (int &v : pref) {
        v++;
      }
    }else{
      pref.push_back(0);
    }
  }


  int s=0;
  for (int &v : pref) {
    s+=v;
  }

  return s;


}


int main(){
  int n,t;
  char * desc = new char[n];

  cin>>n;
  for (int i=0; i<n; i++) cin>>desc[i];
  cin>> t;
  while (t--){
    int a,b;
    cin>>a>>b;
    a--;
    b--;

    cout<<solution(n,desc,a,b);
  }
}