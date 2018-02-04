/* 
 * CS:APP Data Lab 
 * 
 * <Name: Wing Yi Wong      User ID: wongx596>
 * 
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
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */

/*
 * bitXor comments:
 * exclusive or = negation of x and y and negation of negation x and negation y
 * since it opt out the possibility of having both x and y are T and F
 */
int bitXor(int x, int y) {
       return ~(x & y) & ~(~x & ~y);
}
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */

/*
 * evenBits comments:
 * assign a 32bits with all even-numbered bits set to 1, i.e. 01010101
 * x or bits 8 to 15 or bits 16 to 23 or 24 to 31.
 * in this case if odd-numbered bits are 1, they will remains 1 if using or
 */
int evenBits(void) {
  int x = 0x55;
    x = x | (x << 8) | (x << 16) | (x << 24);
  return x;
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */

/*
 * leastBitPos comments:
 * if we do negation of x, all the bits will have opposite 0/1 than x
 * if we add one to the negation, it will have a 1 in the same position as the original x
 * example: x = 1101, ~x = 0010, ~x+1=0011 , if we do x & ~x+1, we can locate the least significant 1 bit
 * example: x = 1100, ~x = 0011, -x+1=0100 , also works
 * example: x = 0000, ~x = 1111, ~x+1=0000 , return 0
 */
int leastBitPos(int x) {
    x = x & ((~x) + 1);
    return x;
}
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */

/* 
 * isEqual comments:
 * To find if x and y is either equal to each other or not, we can reuse the Xor function here
 * Since the Xor function opt out the possiblity of both equal and both different
 * If we the logical negation operator on the Xor function with input x,y, 
 * it returns 1 for both equal and 0 for both different
 */

int isEqual(int x, int y) {
  return !bitXor(x,y);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */

/*
 * fitBits comments:
 * First left shift (32 - n) bits, then right shift (32 - n) bits
 * (32 - n) = 32 + (~n +1)
 * It can keep the nth bits of x
 * Use bitXor and negation to see if x can be represented as an n-bit
 */
int fitsBits(int x, int n) {
  
    return !(x ^ (x << (32 + ((~n) + 1))) >> (32 + ((~n) + 1)));
}
/* 

 * reverseBytes - reverse the bytes of x

 *   Example: reverseBytes(0x01020304) = 0x04030201

 *   Legal ops: ! ~ & ^ | + << >>

 *   Max ops: 25

 *   Rating: 3

 */

/*
 * reverseBytes comments:
 * Divide the 32 bits into 4
 * First part return x with the 24th bit set
 * Second part copy the 8 rightmost set bits to the adjacent right, and then return the 16th bit set
 * Third part copy the 16 right most set bits to the adjacent right, and then return the 8th bit set
 * Forth part copy the 24 right most set bits to the adjacent right
 * at the end first | second | third | fourth return all the four part combine together
 */
int reverseBytes(int x) {
    int first = (x & 0xFF) <<24;
    int second = ((x >> 8) & 0xFF) <<16;
    int third = ((x >> 16) & 0xFF) << 8;
    int fourth = (x >> 24) & 0XFF;
    
  return first|second|third|fourth;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */

/*
 * isPositive Comments:
 * 1<<31 gives one at the leftmost bits and all 0 on the right
 * if x = negative, the leftmost bit will be 1 and the remaining will be the same and x and tmin=(1<<31) will start with one
 * when we do exclusive or the negation of !x and the x&(1<<31) it will return 0
 * if x = positive, it will return 1
 */
int isPositive(int x) {
    return (!x)^!(x & (1<<31));

}
/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*5/8),
 *   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */

/* multFiveEighths Comments:
 * x<<2 + x is x*5
 * sign = (result >> 31) & 1 is to check the sign bit
 * result >> 3 is x/8, where the function return x*5/8
 */
int multFiveEighths(int x) {
    int result = (x << 2) + x;
    int sign = (result >> 31) & 1;
    result = (result + (sign << 3) + (~sign+1));
    return result >> 3;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */

/*
 * isLessOrEqual Comments:
 * check the difference if x and y have same sign
 * if x and y have different sign, if x is positive, y will be negative and x is not less than y , return 0
 * if x is negative, y will be positive, return 1
 */
int isLessOrEqual(int x, int y) {
    int sign = (x^y) & x;
    
    int less = ~(x^y);
    int diff = y + (~x + 1);
    int equal = !diff;
    
    int mask = 1 << 31;
    
    less = (less & ~diff) | sign;
    less = less & mask;
    
    return (!(!(less))) | equal;
    
    
    
//    int compareDiff = (x >> 31) & !(y >> 31);
//    int similar = ((x + ~y) >> 31) & (!bitXor(x >> 31, y >> 31));
//    return compareDiff | similar;
}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */

/*
 * logicalNeg Comments:
 * Divide 32 bits into 2 by right shift 16, check if x inside first or second half of it
 * Repeat dividing and checking for x until it check for the last two bits
 * if 1 exist, it will return 0. Otherwise, it will return 1;
 */
int logicalNeg(int x) {
    int half = x >> 16;
    int checkX = x | half;
    
    half = checkX >> 8;
    checkX = checkX | half;
    
    half = checkX >> 4;
    checkX = checkX | half;
    
    half = checkX >> 2;
    checkX = checkX | half;

    half = checkX >> 1;
    checkX = checkX | half;

    return (~checkX & 1);

}
/* 
 * tc2sm - Convert from two's complement to sign-magnitude 
 *   where the MSB is the sign bit
 *   You can assume that x > TMin
 *   Example: tc2sm(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */

/*
 * tc2sm Comments:
 * Convert the bit of positive number into 1 to get its opposite number
 */
int tc2sm(int x) {

    int mask = x >> 31;
    int sign = mask & 0x1;
    return ((x^mask) + sign) + (sign << 31);
}
/*
 * leftBitCount - returns count of number of consective 1's in
 *     left-hand (most significant) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */

/*
 * leftBitsCount Comments:
 * First check the first 16 bits.
 * Then shift to the remaining 8 bits, and keep shifting to the next half until 1 bit left
 * !(~x) is added in the end as it is 0xFFFFFFFF (32 bits)
 */
int leftBitCount(int x) {

    //check the first 16 bits
    int check = !(~(x >> 16)) << 4;
    //move to the original topmost 8 bits in x
    int tempX = x << check;

    //check the 8 bits
    int shift = ! (~(tempX >> 24)) <<3;  
    check |= shift;
    //move to the original top 4 bits
    tempX = tempX << shift;

    //4 bits
    shift = !(~(tempX >> 28)) <<2;
    check |= shift;
    //move to the original top 2 bits
    tempX = tempX << shift;

    //2 bits
    shift = !(~(tempX >> 30)) <<1;
    check |= shift;
    //move to the original top 1 bit
    tempX = tempX << shift;

    //already checked for 16+8+4+2+1 bits = 31 bits
    //plus 1
    check = check ^ ((tempX >> 31) & !(0));
    return check + !(~x); 
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */


unsigned float_neg(unsigned uf) {
    unsigned result = uf ^ 0x80000000;
    
    //when argument = NaN, return argument.
    if ((uf & 0x7FFFFFFF) > 0x7F800000)
        result = uf;
    
    return result;
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
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
    unsigned maskOfSign = 0x80000000;
    unsigned maskOfExp = 0x7F800000;
    unsigned maskOfFrac = 0x007FFFFF;
    
    unsigned sign = uf & maskOfSign;
    unsigned exp =(uf & maskOfExp) >> 23;
    unsigned frac = uf & maskOfFrac;
    
    // return uf if its NaN or infinity
    if (exp == 0xFF)
        return uf;
    
    //round will be added in special case and denormalized case
    //unsigned round = !((uf & 3)^3);
    //cannot use variable round here due to a warning, use !((uf & 3)^3) instead
    
    if ((uf & maskOfExp) == 0x00800000)
      return (sign | (((uf & 0x7FFFFFFF) + (!((uf & 3)^3))) >> 1));
    
    //Denormalizerd case
    if ((uf & maskOfExp) == 0x00000000){
        unsigned denormTemp = (frac >> 1);
        return (sign | (denormTemp + !((uf & 3)^3)));
    }
    
    //others -> which refers to the normalized case
    return ((exp -1) << 23) | sign | frac;
    
}
