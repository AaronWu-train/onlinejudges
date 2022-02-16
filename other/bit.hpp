//
//  bit.hpp
//  other
//
//  Created by Aaron Wu on 2021/10/29.
//

#ifndef bit_hpp
#define bit_hpp

#include <iostream>
void update(int x,int d){
    while(x<=N){
        b[x]+=d;
        x = x + (-x)&x;
    }
}
int query(int x){
    int sum = 0;
    while (x){
            sum += b[x];
            x -= x & (-x);
        }
        return sum;
}

#endif /* bit_hpp */
