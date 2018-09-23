/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * name QianHao 
 * userid 1500012775
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/*
 * changeHigh : if low 16-bit of x == y, then let high 16-bit of z = x, otherwise let
 *     high 16-bit of z = y. return z.
 *   Example: changeHigh(0xaaaabbbb, 0xbbbbaaaa, 0xcccccccc) = 0xbbbbcccc,
 *   changeHigh(0xaaaabbbb, 0xddddbbbb, 0xcccccccc) = 0xaaaacccc
 *   Legal ops: ! ~ & ^ | << >>
 *   Max ops: 24
 *   Rating: 1
 */
int changeHigh(int x, int y, int z) {
  int cont = (0xff<<8)|0xff;
  //int lowx = x&cont,lowy = y&cont;
  int op = !((x^y)&cont),op2;
  z = z & cont;
  op = (op << 31) >> 31;
  cont = cont <<16;
  op = op & cont;
  op2 = (~op) & cont;
  return z | (x&op) | (y&op2);
}
/* 
 * newOp - define a new bit-wise opertor PKU : 1PKU1 = 1, 1PKU0 = 1, 0PKU1 = 0, 0PKU0 = 1
 *   input int x, y return xPKUy(bit-wise)
 *   Legal ops: ! ~ & ^ |
 *   Max ops: 6
 *   Rating: 1
 */
int newOp(int x, int y) {
  return x | (~y);
}
/* 
 * onlyOne - input x, y return 1 if only one bit of the two numbers is different, return 0 otherwise
 *   Examples onlyOne(12, 14) = 1, onlyOne(12, 15) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int onlyOne(int x, int y) {
  int res = x^y;
  int t = ~0;
  return (!!res)&(!(res&(res+t)));
}
/*
 * truncAvg - Compute the average of the two numbers rounded toward 0
 *          without causing overflow
 *   Example: truncAvg(1, 10) = 5,
 *            truncAvg(-3, 6) = 1,
 *            truncAvg(-3, -4) = -3,
 *            truncAvg(0x7fffffff, 0x7fffffff) = 0x7fffffff
 *   Legal ops: ! ~ & | ^ + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int truncAvg(int x, int y) {
    int tag;
    int a = x^y;
    int avg = (x&y)+(a>>1);
    tag = ((avg>>31)&a)&1;
    //int op3 = (sum>>31)&1;
    return avg+tag;
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 2
 */
int absVal(int x) {
    int cont = x >> 31;
    int neg = ~x+1;
    return (x&(~cont))|(neg&cont);
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 2
 */
int subOK(int x, int y) {
  int maxbit = 1 << 31;
  //int xsign = x & maxbit, ysign = y & maxbit;
  int result = x + ~y + 1;
  //int ressign = result & maxbit;
  int ans = (x^y)&(result ^x);
  return !(ans  & maxbit);
}
/*
 * fullAdd - 4-bits add using bit-wise operations only.
 *   (0 <= x, y < 16) 
 *   Example: fullAdd(12, 7) = 3,
 *            fullAdd(7, 8) = 15,
 *   Legal ops: ~ | ^ & << >>
 *   Max ops: 30
 *   Rating: 2
 */
int fullAdd(int x, int y) {
    int nor = x ^ y, and = x & y;
    int t ,flow;
    int bit_1 = nor & 1,bit_2,bit_3,bit_4;
    flow = and & 1;
    t = nor & 2; 
    flow = flow << 1;
    bit_2 = t ^ flow; 
    flow = (and & 2) | (x & flow) | ( y & flow);
    t = nor & 4; flow = flow << 1;
    bit_3 = t ^ flow; 
    flow = (and & 4) | (x & flow) | ( y & flow);
    t = nor & 8; 
    flow = flow << 1;
    bit_4 = t ^ flow;
    return  bit_4 | bit_3 | bit_2 | bit_1;
}
/* 
 * theMax - the same as max(x, y) 
 *   Example: max(4,5) = 5, max(6,3) = 6
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 28
 *   Rating: 3
 */
int theMax(int x, int y) {
  int res = x + ~y + 1;
  int flag = (x ^ y);
  int tag = ((~flag)&(~res))|(flag&y);
  tag = tag >> 31; // 1 take x 0 take y
  return (x&tag)|(y&(~tag));
}
/*
 * palindrome - return 1 if x is palindrome in binary form,
 *   return 0 otherwise
 *   A number is palindrome if it is the same when reversed
 *   YOU MAY USE BIG CONST IN THIS PROBLEM, LIKE 0xFFFF0000
 *   YOU MAY USE BIG CONST IN THIS PROBLEM, LIKE 0xFFFF0000
 *   YOU MAY USE BIG CONST IN THIS PROBLEM, LIKE 0xFFFF0000
 *   Example: palindrome(0xff0000ff) = 1,
 *            palindrome(0xff00ff00) = 0
 *   Legal ops: ~ ! | ^ & << >> +
 *   Max ops: 40
 *   Rating: 4
 */
int palindrome(int x) {
    int reverse = ((x>>16)&0xffff)|((x<<16)&0xffff0000);
    reverse = ((reverse>>8)&0xff00ff)|((reverse<<8)&0xff00ff00);
    reverse = ((reverse>>4)&0xf0f0f0f)|((reverse<<4)&0xf0f0f0f0);
    reverse = ((reverse>>2)&0x33333333)|((reverse<<2)&0xcccccccc);
    reverse = ((reverse>>1)&0x55555555)|((reverse<<1)&0xaaaaaaaa);
    return !(reverse^x);
}
/*
 * distance - calculate how many bits are different between x and y
 *   Example: distance(0xabcdabcd, 0xabcddcba) = 12,
 *            distance(0x0000ffff, 0xffff0000) = 32,
 *   Legal ops: ~ ! | ^ & << >> +
 *   Max ops: 40
 *   Rating: 4
 */
int distance(int xx, int y) {
  int x = xx ^ y;
  int mask1 = 0x55;
  int mask2 = 0x33;
  int mask3 = 0x0f;
  int mask = 0xff,mask4,mask5;
  mask1 = mask1 | (mask1<<8);
  mask1 = mask1 | (mask1<<16);
  mask2 = mask2 | (mask2<<8);
  mask2 = mask2 | (mask2<<16);
  mask3 = mask3 | (mask3<<8);
  mask3 = mask3 | (mask3<<16);
  mask4 = mask|(mask<<16);
  mask5 = mask|(mask<<8);
  x = ((x>>1)&mask1)+(x&mask1);
  x = ((x>>2)&mask2)+(x&mask2);
  x = (x>>4)+x;x = x & mask3;
  x = (x>>8)+x;x = x & mask4;
  x = (x>>16)+x;x = x & mask5;
  return x;
}
/*
 * divSix - calculate x / 6 without using /
 *   Example: divSix(6) = 1,
 *            divSix(2147483647) = 357913941,
 *   Legal ops: ~ ! | ^ & << >> +
 *   Max ops: 40
 *   Rating: 4
 */
int divSix(int x) {
  int a,b,c,res,d;
  //int cont = ~(0x7<<29);
  int sign = x >> 31;
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
  res = res + !(d>>31);
  return res + (sign&!!d&!!a);
  //return (res&(~sign))|((~res+1)&sign);
}
/*
 * modThree - calculate x mod 3 without using %.
 *   Example: modThree(12) = 0,
 *            modThree(2147483647) = 1,
 *            modThree(-8) = -2,
 *   Legal ops: ~ ! | ^ & << >> +
 *   Max ops: 60
 *   Rating: 4
 */
int modThree(int x) {
    int sign= x>>31,cont,tmp,ans,pos,cont2;
    x = x ^ sign;
    x = x + ~sign + 1;
    cont = 0xff;
    cont2 = (cont << 8) | cont;
    x = ((x >> 16) & cont2) + (x & cont2);
    x = (x >> 8) + (x & cont);
    x = (x >> 4) + (x & 0xf);
    x = (x >> 4) + (x & 0xf);
    x = (x >> 2) + (x & 0x3);
    x = (x >> 2) + (x & 0x3);
    //ans = x & 0x3;
    pos = !(x^3);
    pos = (pos << 1) | pos;
    pos = ~pos;
    ans = (x & pos) & 3;
    return (ans&(~sign))|((~ans+1)&sign);
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 3
 */
int float_f2i(unsigned uf) {
  unsigned sign_ = uf & 0x80000000;
  unsigned char exp_ = uf >> 23;
  unsigned frac_ = uf << 8 | 0x80000000;
  unsigned ret_ = 0;
  if (exp_ < 127) return 0;
  if (exp_ >= 158) return 0x80000000;
  ret_ = frac_ >> (158 - exp_);
  if (sign_) ret_ = -ret_;
  return ret_;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 3
 */
unsigned float_half(unsigned uf) {
  unsigned half = uf >> 1;
  unsigned sign = 0;
  switch(uf >> 23) {
    case(0x000):break;
    case(0x001):break;
    case(0x100):sign=0xc0000000;break;
    case(0x101):sign=0xc0000000;break;
    case(0x0ff):return uf;
    case(0x1ff):return uf;
    default:return uf-0x800000;
  }
  return sign^(half+((uf&half)&1));
}
/* 
 * float_construct - Return bit-level equivalent of expression float(x*2^y),
 *   you should treat the input as integers: if x = 2, y = 3, you should return a float value of 16  
 *   we ensure the constructed number can be represented in float: X[-65535, 65535], y[-160, 60]
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 90
 *   Rating: 4
 */
unsigned float_construct(int x, int y) {
  unsigned expbase = 0x7f800000;
  unsigned fracbase = 0x7fffff;
  unsigned signbase = 0x80000000;
  unsigned sign = x & signbase,frac,exp;
  int num,x_num,tmp; // x_num x bits num
  unsigned a, k;
  unsigned b,half,half_after,half_before;
  int saved,saved2;
  if(x<0) 
    x=-x;
  if(x){
     x_num = 0xffffffff;
     a = x;
     //b = 1;
     while(a){
      x_num++;
      a >>= 1;
     // b <<= 1;
     }
     //b >>= 1;
     num = x_num + y;
     saved = 22 - x_num;
     saved2 = num + 127;
     if(num>-127){
       exp = saved2 << 23;
       frac = x << (saved+1);
       frac &= fracbase;
     }
     else if(num==-127){
      exp = 0;
      frac = x << saved;
     }
     else {
      exp = 0;
      a = x;
      a <<= saved;
      k = -saved2; // kk [1,33]
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
