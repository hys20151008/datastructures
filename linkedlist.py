# -*- coding: utf-8 -*-

class List:
    def __init__(self, data,next=None):
        self.data = data
        self.next = next

link = List(1,List(2,List(3,List(4,List(5)))))

def isEmpty(lst):
    return lst.next == None


def isLast(p, lst):
    return p.next == None


def find(lst, x):
    p = lst
    while p != None and p.data != x:
        p = p.next
    return p

def findPrevious(lst, x):
    p = lst
    while p.next != None and p.next.data != x:
        p = p.next
    return p


def delx(lst, x):
    p = findPrevious(lst,x)
    if not isLast(p, lst):
        p.next = p.next.next
    return lst

lst = delx(link,4)
while lst:
    print(lst.data)
    lst = lst.next

