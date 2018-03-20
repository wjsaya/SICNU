#!/usr/bin/env python3
# author: wjsaya

num = int(input("输入个数"))
li = input("输入数字")
this_sum = 0
max_sum = 0
li = li.split( )
for i in range(0, num):
    for j in range(i, num):
        this_sum = 0
        for k in range(i, j):
            this_sum += int(li[k])
            print(int(li[k]))

        if (this_sum >= max_sum):
            max_sum = this_sum
print(max_sum)
    
