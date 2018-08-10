# -*- coding: utf-8 -*-

class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

class BSTree:
    lst = []
    def insert(self, T, data):
        if T == None:
            T = Node(data)
        else:
            if data < T.data:
                T.left = self.insert(T.left, data)
            else:
                T.right = self.insert(T.right, data)
        return T
    def inOrderTra(self, T):
        if T:
            self.inOrderTra(T.left);
            self.lst.append(T.data)
            self.inOrderTra(T.right);
            return self.lst
    # 判断是否是二叉搜索树
    def isSearchTree(self, lst):
        for i in range(len(lst)-1):
            if(lst[i] > lst[i+1]):
                return False
        return True


if __name__ == "__main__":
    T = None
    btree = BSTree()
    for i in range(6):
        T = btree.insert(T,i)
    lst =  btree.inOrderTra(T)
    print(btree.isSearchTree(lst))


