# -*- coding: utf-8 -*-

import sys


def minDistance(a):
    dmin = sys.maxsize
    n = len(a)

    for i in range(n-1):
        for j in range(i+1,n):
            tmp = abs(a[i]-a[j])
            if tmp < dmin:
                dmin  = tmp
    return dmin


if __name__ == '__main__':
    dist = minDistance([9,1,2,3,4,5])
    print(dist)
