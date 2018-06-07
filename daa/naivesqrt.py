# -*- coding: utf-8 -*-

#introduction to the design and analysis of algorithms excise1.1 4
def naivesqrt(n):
    for i in range(n):
        if i * i > n:
            return i-1
        elif i * i == n:
            return i




if __name__ == '__main__':
    print(naivesqrt(10))
