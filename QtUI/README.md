# 项目介绍

此项目主要是为了使用Makefile编译运行cpp程序。

# 使用教程

## 下载项目

下载项目

```bash
$ git clone https://gitee.com/heal2017/cpp_template.git
```

## 重命名目录与初始化

重命名目录

```bash
$ mv cpp_template HelloWorld
```

初始化
```bash
$ cd HelloWorld
$ make init
```

## 创建cpp文件

新建 src/HelloWorld.cpp文件
```bash
#include<iostream>
using namespace std;
int main(void)
{
    cout << "Hello, World!" << "\n";
    return 0;
}
```

## 清理文件

只保留源文件

```shell
$ make clean
```

清除源文件与临时文件

```shell
$ make cleanall
```

## 编译运行

编译程序

```bash
$ make
```

运行程序

```bash
$ make run
```
