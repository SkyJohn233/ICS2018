#include<iostream>
#include<iomanip>
using namespace std;
unsigned float_construct(int x, int y) {
  x = -3,y=-160;
  unsigned expbase = 0x7f800000;
  unsigned fracbase = 0x7fffff;
  unsigned signbase = 0x80000000;
  unsigned sign = x & signbase,frac,exp;
  int num,x_num,tmp; // x_num x bits num
  unsigned a, k;
  unsigned b,half,half_after,half_before;
  if(x<0) 
    x=-x;
  cout<<x<<endl;
  if(x){
     x_num = -1;
     a = x;
     //b = 1;
     while(a){
      x_num++;
      a >>= 1;
     // b <<= 1;
     }
     cout<<"x_num:"<<x_num<<endl;
    // b >>= 1;
     num = x_num + y;
     if(num>-127){
       exp = (num + 127) << 23;
       frac = x << (23 - x_num)&fracbase;
       cout<<"hex:"<<hex<<exp<<endl;
     }
     else if(num==-127){
      exp = 0;
      frac = x << (22 - x_num);
     }
     else if(num<-127){
      exp = 0;
      a = x;
      a <<= (22-x_num);
      k = -127-num; // kk [1,33]
      cout<<hex<<"a:"<<a<<endl;
      cout<<dec<<"k:"<<k<<endl;
      half=half_after=0;
      if(k<33)
        half = (a>>(k-1))&1;
      if(k>2)
        half_after = a << (33-k);
      if(k<32)
        a >>= k;
      else a = 0; 
      half_before = a & 1;
      if(half){
        if((!!half_after)||half_before)
          frac = a + 1;
        else
          frac = a;
      }
      else frac = a;
     }
     return sign|exp|frac;
  }
  else
    return 0;
}
int main(){
  unsigned res = float_construct(1,1);
  cout<<hex<<res<<endl;
  return 0;
}