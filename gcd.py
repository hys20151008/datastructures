# -*- coding: utf-8 -*

def gcd(m, n):
    while n:
        r = m % n
        m = n
        n = r
    return m


def gcd2(m, n):
    while n:
        if m < n:
            m,n = n,m
        m = m - n
    return m

if __name__ == '__main__':
    print(gcd(31415, 14142))
    print(gcd2(35, 14))
