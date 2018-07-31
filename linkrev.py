# -*- coding: utf-8 -*-

class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

link = Node(1, Node(2, Node(3, Node(4, Node(5, Node(6, Node(7, Node(8, Node(9)))))))))
link = Node(1,Node(2))

def rev(link):
    p = link
    q = link.next
    p.next = None
    while q:
        r = q.next
        q.next = p
        p = q
        q = r
    return p

root = rev(link)
while root:
    print(root.data)
    root = root.next

