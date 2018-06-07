# -*- coding: utf-8 -*-

def openorclosed(n):
    init = [False]*n
    count = 1
    while count <= n:
        for i in range(n):
            if (i+1) % count == 0:
                init[i] = not init[i]
        count += 1
    return init




if __name__ == "__main__":
    print(openorclosed(4))
        
        
