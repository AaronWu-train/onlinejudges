#ifndef LIB1926_H_INCLUDED
#define LIB1926_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long _N, _M;
long long** _d;
const long long _INF = LLONG_MAX;

void Init(long long* N, long long* M)
{
    scanf("%lld%lld", &_N, &_M);
    *N = _N, *M = _M;
    _d = (long long**)malloc(sizeof(long long) * _N);
    for (long long i = 0; i < _N; i++) {
        _d[i] = (long long*)malloc(sizeof(long long) * _M);
        for (long long j = 0; j < _M; j++) scanf("%lld", _d[i] + j);
    }
}

long long _D(long long x, long long y)
{
    if (x < 0 || x >= _N || y < 0 || y >= _M) return _INF;
    return _d[x][y];
}

int Oshietekudasai(long long x1, long long y1, long long x2, long long y2)
{
    if (x1 < 0 || x1 >= _N || y1 < 0 || y1 >= _M || x2 < 0 || x2 >= _N || y2 < 0 || y2 >= _M) {
        puts("out of range");
        exit(0);
    }
    return _D(x1, y1) < _D(x2, y2);
}

void Report(long long x, long long y)
{
    printf("Report: %lld %lld\n", x, y);
    exit(0);
}

#endif // LIB1926_H_INCLUDED
