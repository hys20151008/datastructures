# -*- coding: utf-8 -*-

class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

tree = Node(1,Node(3, Node(7, Node(0)), Node(6)), Node(2, Node(5), Node(4)))

def pre_visit(root):
    print(root.data)
    if root.left is not None:
        pre_visit(root.left)
    if root.right is not None:
        pre_visit(root.right)


def mid_visit(root):
    if root.left is not None:
        mid_visit(root.left)
    print(root.data)
    if root.right is not None:
        mid_visit(root.right)


def post_visit(root):
    if root.left is not None:
        post_visit(root.left)
    if root.right is not None:
        post_visit(root.right)
    print(root.data)


def max_depth(root):
    if not root:
        return 0
    return max(max_depth(root.left),max_depth(root.right)) + 1
post_visit(tree)
print(max_depth(tree))
