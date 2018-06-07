# -*- coding: utf-8 -*-

def findcom(x, y):
    ret = []
    for i in range(len(x)):
        if x[i] in y:
            ret.append(x[i])
            y.remove(x[i])
    return ret


if __name__ == '__main__':
    print(findcom([2, 5, 5, 5], [2, 2, 3, 5, 5, 7]))
