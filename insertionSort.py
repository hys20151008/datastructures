# -*- coding: utf-8 -*-

def insertion_sort(lst):
    for j in range(1,len(lst)):
        key = lst[j]
        i = j - 1
        while i >= 0 and lst[i]>key:
            lst[i+1] = lst[i]
            i = i -1
        lst[i+1] = key
    return lst

if __name__ == '__main__':
    print(insertion_sort([9,8,7,6,5,4,3,2,1]))
        
