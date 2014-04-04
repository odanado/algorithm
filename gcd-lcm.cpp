#include<stdio.h>

// judge http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0005
// O(log max(a,b))
template <typename T>
T gcd(T a,T b) {
   if(b == 0) return a;
  return gcd(b,a%b); 
}
// オーバーフロー注意
template <typename T>
T lcm(T a,T b) {
    return a/gcd(a,b)*b;
}

// input(a,b) 
// output(x,y) ax+by=gcd(a,b)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
template <typename T>
void extendedEuclidAlgo(T a,T b,T& x,T &y) {
    T a0,a1,a2;
    T b0,b1,b2;
    T q1;
    T r0,r1,r2;

    a0 = 1;
    b0 = 0;
    a1 = 0;
    b1 = 1;

    r0 = a;
    r1 = b;

    while(r1 != 0) {
        r2 = r0 % r1;
        q1 = r0 / r1;
        a2 = a0 - q1 * a1;
        b2 = b0 - q1 * b1;

        r0 = r1;
        r1 = r2;

        a0 = a1;
        a1 = a2;
        b0 = b1;
        b1 = b2;
    }

    x = a0;
    y = b0;
}

// m を 法とする a の逆元 
// gcd(a,m) = 1 が条件
template <typename T>
T calcInverseElement(T a,T m) {
    int x,y;
    extendedEuclidAlgo(a,m,x,y);

    if(x < 0) x+=m;
    return x;
}

