#include<iostream>
#include<cstdio>
using namespace std;
int  work(int   x){
  int reverse = ((x>>16)&0xffff)|((x<<16)&0xffff0000);
    reverse = ((reverse>>8)&0xff00ff)|((reverse<<8)&0xff00ff00);
    reverse = ((reverse>>4)&0xf0f0f0f)|((reverse<<4)&0xf0f0f0f0);
    reverse = ((reverse>>2)&0x33333333)|((reverse<<2)&0xcccccccc);
    reverse = ((reverse>>1)&0x55555555)|((reverse<<1)&0xaaaaaaaa);
    return !(reverse^x);
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",int(work(a)));
	return 0;
}