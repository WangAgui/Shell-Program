Linux Shell
====
shell是一个交互型的应用程序，它代表用户运行其他程序。最早的shell是sh程序，后面出现了一些变种，如bash。

本项目为一个简单的linux shell程序，等待用户在stdin上输入的命令行，对这个命令行进行处理。

## 笔者所使用的机器
Ubuntu-64
## 编译器
GCC-64
## 项目主要函数
* deal    处理std输入的字符串
* builtin_command  判断是否是内置的命令
* parseline   解析行，生成execve需要的argv参数

## 需要重点理解的知识点：
### fork
### execve
