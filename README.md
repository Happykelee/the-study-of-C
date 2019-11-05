 # the study of C/C++

**C/C++语言学习笔记**

主要学习资料如下：
* 程序员联盟-谢恩铭：https://www.jianshu.com/nb/4555196
* 北京大学Coursera课程-程序设计与算法：https://www.coursera.org/specializations/biancheng-suanfa

## 目录

* [变量](#变量)
* [运算](#运算)
* [分支结构](#分支结构)
* [循环结构](#循环结构)
* [数组&字符串](Array&String.md)
* [函数](Function.md)
* [练习小脚本](Scripts)

## [变量](#目录)

### 变量类型

![1-data-structure](./images/1-data-structure.jpeg)

* 整型
  * 基本型(int): 32bit(4Byte)
  * 短整型(short): 16bit(2Byte)
  * 长整型(long): 32bit(4Byte)
  * 说明: **C标准是short≤int≤long**, 以上按照VC++ IDE
  * 还可定义**有无符号**的整型，默认有符号
* 浮点型(实型)
  * float: 32bit(7位精度)
  表示方式：1位符号位+8位指数位(含1位符号位)+23位二进制小数位
  * double: 64位(15位精度)
  * long double: 64位(15位精度)
* 字符型
  * 一个字符型占一个字节，最多可以表示256个字符(ASCII)
  * 存储类型和整型相同，故可以和整型数据相互赋值和一起进行计算
* 布尔型(bool, C++)
  * 1(非零)代表True
  * 0代表False
* sizeof运算符
  用于计算某种类型的对象在内存中所占的字节数。

### 变量声明(标识符)
由字母、数字和下划线三种字符组成，且第一个字符必须位字母或下划线，且不可与保留字（关键字）相同。C++(63个)和C的保留字不同。
* **匈牙利命名法**
以一个或多个小写字母开头，来指定数据类型；其后市一个或多个第一个字母大写的单词，指出变量的用途，例：chGrade.
* **驼峰命名法(骆驼命名法)**
由一个或多个单词连接在一起，第一个单词以小写字母开始，第二个单词的首字母大写或每一个单词的首字母都采用大写字母，例：myFirstName.

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

### 常量(constant)

  * 字面常量
  * 符号常量：由const关键字修饰
  * 说明：常量类型由后缀定义，如果没有后缀则默认位整型和double双精度浮点数

```C
const double PI = 3.14159;
const int NUMBER_OF_DOGS = 7;
//在之后的程序中改变const变量的值，编译器会提示一个错误
```

### 显示和输入

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
* **C++： cin/cout**
  * **输入缓冲区**:键盘输出---->输入缓冲区---->程序从输入缓冲区读取输入，指针标定数据的读取位置，只能往后移动。
  * 另，字符和字符串的输入输出详情见[Array&String.md](Array&String.md)的“**字符/字符数组/字符串的输入与输出**”部分。
  ```C++
  #include <iostream>
  #include <iomanip>
  int main()
  {
      int a = 0,b,c,d;
      cout<<"a的初始值是"<<a<<endl;
      cout<<"请输入一个数"<<endl;
      cin>>a; //从键盘中输入abc（错误，存为0）
      cout<<"我刚刚给输入的a:"<<a<<endl;

      cout<<"请连续输入两个数据:";
      cin>>b>>c;
      d = b+c;
      cout<<"结果是"<<d<<endl;

      //打印一个数
      cout<<hex<<a<<endl; //十六进制
      cout<<oct<<a<<endl; //八进制
      cout<<dec<<a<<endl; //十进制

      # 输入一个十六进制或者八进制
      int a = 0x33; //十六进制
      cout<<dec<<a<<endl;
      cout<<hex<<a<<endl;
      int a = 033; //八进制
      cout<<dec<<a<<endl;
      cout<<oct<<a<<endl;

      float a = 3.14159265358979323846
      double b = 3.14159265358979323846
      long double float b = 3.14159265358979323846
      // cout输出默认六位精度, 提高输出精度使用setprecision
      cout << a << endl
      cout << setprecision(100)<<a<<endl
      cout << b << endl
      cout << setprecision(100)<<b<<endl
      cout << c << endl
      cout << setprecision(100)<<c<<endl

      float grade;
      while(cin>>grade){
        if(grade>=85)
        cout<<grade<<'GOOD'<<endl;
        if(grade<60)
        cout<<grade<<'fail'<<endl;
      }

      return 0;
  }
  ```

## [运算](#目录)

### 运算优先级
* 逻辑非>算数运算符>关系运算符>逻辑与和或>赋值运算符>逗号运算符

### 赋值运算

* **=** (赋值运算符)
  * 两边类型不同：等号右边要转换成左边的类型
  * 长数赋给短数：截取长数的低n位送给短数
  * 短数赋给长数：原来什么数，现在还是什么数
  * 符号位的赋值处理：直接赋值，不用管符号位还是数字位

* **表达式**
  * 赋值语句表达式是有“值”的
  * 复合的赋值运算
  * 连续的赋值运算：由右向左

### 算数运算

* **基本的算数运算**

  | 运算 | 符号 | 备注 |
  |-----|-----|-----|
  | 加 | + |
  | 减 | - |
  | 乘 | * |
  | 除 | / |整数相除和浮点数相除需要注意|
  | 取模 | % |

* **自增自减运算**
  * ++i/--i: 在使用i之前，先讲i的值加（减）1
  * i++/i--: 在使用i之后，先讲i的值加（减）1
  * ++/--不能用于表达式：(i+j)++ 错！！！
  * 输出自增自减：输出语句有多个表达式，优先计算右边（VC平台下）

```C++
int i=3,j;
j = ++i; //i=4,j=4
j = i++; //i=5,j=4
cout << ++i;
cout << i++;

int number = 2;
number++; //自增运算: 结果+1操作
number--; //自减运算

// 复合赋值运算
number += 4; // number变为6
number -= 3; // number变为3
number *= 5; // number变为15
number /= 3; // number变为5
number %= 3; // number变为2 （因为 5 = 1 * 3 + 2）
```

### 关系运算

  | 运算 | 符号 |
  |-----|-----|
  | 大于 | > |
  | 小于 | < |
  | 大于等于 | >= |
  | 小于等于 | <= |
  | 相等 | == |
  | 不等于 | != |

### 逻辑运算

* **三种逻辑运算符**
  * 逻辑与: &&
  * 逻辑或: ||
  * 逻辑非: ！
* **优先级**：非>与>或
* 逻辑运算符两侧可以是任何类型

### 其他运算

* **逗号运算符**：表达式1,表达式2,……,表达式n（用逗号将两个表达式连起来，从左往右求）
* **条件运算符**：表达式1?表达式2:表达式3（如果表达式1的值为真，则输出表达式2的值，否则输出表达式3的值）
* **强制类型转换**：(类型名)(表达式)
* **位运算**：指进行二进制位的运算（按位与&, 按位或|, 异或^, 按位取反~, 左移<<, 右移>>）

### 数学库

```C
# include <math.h> //调用数学包

//fabs: 返回绝对值
double absolut = 0, number = -29;
absolut = fabs(number); // absolut的值变为29

//ceil: 舍入紧邻的比参数大的整数
double above = 0, number = 34.81;
above = ceil(number); // above的值变为35

//floor: 舍入紧邻的比参数小的整数
double below = 0, number = 45.63;
below = floor(number); // below的值变为45

//pow: 计算数字的乘方,要给它两个参数：底数和指数
double result = 0, number = 2;
result = pow(number, 4); // result的值变为16 （2 ^ 4 = 16）

//sqrt: 返回平方跟
double result = 0, number = 100;
result = sqrt(number); // result的值变为10

//sin, cos, tan
//asin, acos, atan
//exp: 返回以e（自然对数的底数，近似等于2.7182）为底数的指数运算的值
//log: 返回以e为底的对数值（我们学数学时也写成ln）
//log10: 返回以10为底的对数值
```

## [分支结构](#目录)

### if-else语句

```C
if () //判断条件
{
  // 条件为真的时候，所要执行的操作
}
else // 如果上面()里的条件为假
{
  // 条件为假的时候，所要执行的操作
}
```

```C
#include <stdio.h>

int main(int argc, char *argv[])
{
  int age = 20;
  if (age >= 18) // 如果age变量的值大于或等于18
    printf ("你成年了!");
  else // 如果age变量的值小于18
    printf ("你还未成年，可以任性!");

  if (age >= 18) // 如果age（英语：年龄）变量的值大于或等于18
    printf ("你成年了 !");
  else if ( age > 4 )  // 如果age小于18但是大于4
    printf ("还好你不是太年幼");
  else // 如果age小于或等于4
    printf ("mama, guagua, blablabla...");  // 儿语，听不懂
}
```

### switch语句

```C
#include <stdio.h>

int main(int argc, char *argv[])
{
  int choiceMenu;
  printf("=== 菜单 ===\n\n");
  printf("1. 北京烤鸭\n");
  printf("2. 锅包肉\n");
  printf("3. 地三鲜n");
  printf("4. 梅菜扣肉\n");
  printf("\n您的选择是 ? ");
  scanf("%d", &choiceMenu);
  printf("\n");

  switch(choiceMenu)
  {
    case 1:
      printf("您选了北京烤鸭。这是本店的招牌菜 !");
      break;
    case 2:
      printf("您选了锅包肉。您是东北人吧?知道宋佳吗?她最喜欢吃锅包肉了!");
      break;
    case 3:
      printf("您选了地三鲜。实惠好吃，就是油有点多.");
      break;
    case 4:
      printf("您选了梅菜扣肉。嗯，那个味道很棒!");
      break;
    default:
      printf("您没有选择餐单上的数字，难道您要饿肚子吗 ?");
      break;
  }
  printf("\n");
  return 0;
}
```

## [循环结构](目录)

### while循环

```C
#include <stdio.h>

int main(int agrc, char *argv[]) {

  // 判断
  int number = 0;
  while (number != 27) {
    printf("请输入 27 ! ");
    scanf("%d", &number);
  }

   // 计数
  int counter = 0;
  while (counter< 10) {
    printf("你好 !\n");
    counter++;
  }

  return 0;
}
```

### do-while循环

这种类型和while循环非常类似，不过比较少用到。

```C
int counter = 0;
do {
  printf("你好 !\n");
  counter++;
} while (counter < 10);
```

### for循环

for循环可以实现我们想要的任何类型循环。

```C
int counter;

for(counter = 0 ; counter < 10 ; counter++) {
  printf("你好 !\n");
}

/* 括号中有三条指令，用分号(;)分隔：
   第一条指令用于初始化
   第二条指令用于规定条件
   第三句指令用于更新变量的值
*/
```

```C++
int i = 0;
char a[10]={'a','b','c','d','e','f','g','h','i','j'};
for(i=0;i<10;i=i+2)
{
  cout<<a[i]<<endl;
}
```

### Goto语句

  * 无条件转向语句
  * 不要在程序中使用goto

```C
int i=0,sum=0;
i=1;
loop:
  sum=sum+i;
  i++;
  goto loop;
  cout<<sum<<endl;
```
