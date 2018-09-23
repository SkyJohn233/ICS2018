#include<iostream>
#include<climits>
#include<iomanip>
using namespace std;
int divSix(int x) {
  int a,b,c,res,d;
  //int cont = ~(0x7<<29);
  int sign = (x >> 31)&1;
  int add;
  x = 0x800181a0;
 // x = x ^ sign;
 // x = x + (~sign) + 1;
  a = x;
  b = (a>>3);
 // b = (a >> 3) & cont;
  b = b + (b >> 2);
  b = b + (b >> 4);
  b = b + (b >> 8);
  b = b + (b >> 16);
  c = (b<<2)+(b<<1);
  a = a + (~c) + 1;
  res = b;
  b = (a >> 3);
 /* b = b + (b >> 2);
  b = b + (b >> 4);
  b = b + (b >> 8);
  b = b + (b >> 16);8*/
  c = (b<<2)+(b<<1);
  a = a + (~c) + 1;
  res = res + b;
  d = a + (~5 );
  cout<<d<<endl;
  add = !(d>>31);
  cout<<add<<endl;
  res = res + add;
  cout<<res<<endl;
  return res + (sign&!!(d));
  //return (res&(~sign))|((~res+1)&sign);
}
int divSix2(int a){
	a = INT_MAX;
	int sign = a >> 31;
	unsigned long long cont = (0x20<<24);
	//const unsigned long long cont2 = (0x20<<24)+0xb;
	//cout<<cont<<endl;
  	a = ((unsigned long long )a * cont)>>32;
  	//int b = ((unsigned long long)a * cont)>>32;
  	cout<<hex<<a<<endl;
  	return a - sign;
}
int main(){
	int a;cin>>hex>>a;
	divSix(a);
	return 0;
}