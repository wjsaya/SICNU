#!/usr/bin/env python3
# @Author: wjsaya
# https://github.com/wjsaya/

def converate(strings):
    q2_list = list(strings)
    q2_tuple = tuple(strings)
    q2_dict = {'输入' : strings}
    print('这是一个分割后的列表,分隔符为$:\t', end='')
    print(q2_list)
    print('这是一个元组:\t', end='')
    print(q2_tuple)
    print('这是一个字典:\t', end='')
    print(q2_dict)

if __name__ == '__main__':
    input_value = input('请输入任意字符串:')
    if len(input_value) == 0:
        print("没有输入内容?")
    else:
        print("输入的内容为:", input_value)
        converate(input_value)
