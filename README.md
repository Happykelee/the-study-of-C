# the study of C

**C语言学习笔记**

主要学习资料如下：
* 程序员联盟-谢恩铭：https://www.jianshu.com/nb/4555196

## 目录

* [变量](#变量)
* [练习小脚本](Scripts)

## [变量](#目录)

### 变量类型

![1-data-structure](./images/1-data-structure.jpeg)

### 变量声明

```C
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int numberOfDogs;
    int growthOfEconomy;
    double averageSalary;
    unsigned int numberOfDogs;
    int numberOfCats, numberOfMouses;

    numberOfDogs = 7; // 有七条狗
    return 0;
}
```

### const关键字

constant（恒定的，不变的）变量由const关键字修饰

```C
const int NUMBER_OF_DOGS = 7;
//在之后的程序中改变const变量的值，编译器会提示一个错误
```

### 显示和输入变量

* **printf**: 显示变量

```C
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int numberOfDogs = 5, numberOfCats= 6; // 一开始，你有5只狗和6只猫

    printf("你有 %d 只狗，还有 %d 只猫\n", numberOfDogs, numberOfCats);
    printf("**** 跑了一只狗 ****\n");
    numberOfDogs= 4; // 刚跑了一只狗，只有4只了
    printf("啊呀，你只剩下 %d 只狗了\n", numberOfDogs);

    return 0;
}
```

* **scanf**: 提取用户输入的值，并将其储存到变量里面。  
Note: 对于float和double来说，printf里面他们的替代符号都是%f， 但是在scanf里面却不一样. 在scanf中，float是%f，而double是%lf.

```C
int main(int argc, char *argv[])
{
    int sum = 0; // 把钱数初始化为零

    printf("你身上有多少钱 ? ");
    scanf("%d", &sum); // 请求用户输入钱数
    printf("你有 %d 块钱啊，那还不快快地交出来 !\n", sum);

    return 0;
}
```
