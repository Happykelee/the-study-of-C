# [the study of C/C++](README.md)

**C/C++语言学习笔记**

## 函数

### 函数的定义

具体定义参看代码实例。

**注：函数定义在main函数之后，需要在main函数之前用函数原型进行声明(Signature)。**

**函数的类型：由函数的返回值的数据类型决定**

**函数调用的方式**

* 作为独立语句，例如：```stringPrint()```;
* 作为表达式的一部分，例如：```num=max(numA,numB)/2```;
* 以实参形式出现在其他函数的调用中，例如：```number=max(sum(-5,100),numC)```;

**函数是C程序的基本构成单元**

* 一个C程序由一个或多个源程序文件组成。
* 一个源程序文件可以由一个或多个函数组成。
* 函数可以保存在头文件中，例如：```#include "max.h"```。另外，在VC环境下<>框定的文件名优先搜索系统目录，“”框定下的文件名优先搜索当前目录。

```C++
#include<iostream>
using namespace std;

float max(float, float); //声明函数原型=返回值类型+函数名+参数类型

//Ex1: ONE INPUT
int absolute(int n) //此处n为形参
{
  if(n<0)
    return(-n);
  else
    return(n);
}
// Ex3: NO INPUT
int get_int()
{
  int n=0;
  cout<<"Please input an integer:"<<endl;
  cin>>n;
  return n;
}
// Ex4: NO OUTPUT
void delay(int n)
{
  for(int i=0;i<n*10000;i++)
  //return;
}
// Ex5: NO INPUT AND OUTPUT
void show()
{
  cout<<"hahahha kidding"<<endl'  
}

int main()
{
  int m=-123,result=0;
  result = absolute(m); //此处m为实参
  cout<<result;

  cout<<max(3,4);

  result = get_int();
  cout<<result;

  for(int j=0;j<100;j++)
  {
    cout<<j<<endl;
    delay(1000);
  }
  return 0;
}

//Ex2: TWO INPUT
float max(float a, float b)
{
  if(a>b)
    return a;
  else
    return b;
}
```

### 函数的执行

**函数执行过程**
* 开辟空间存放main()函数。
* 执行到指定函数func()：
  1. 初始化新函数func():新开辟空间存储相应func();
  2. 传递参数;
  3. 保存当前现场;
* func()执行完并返回结果,**相应空间被释放**。
* func()执行完后，main()函数会：
  1. 接收函数的返回值;
  2. 恢复现场，从断点处进行执行。

**函数参数传递**

  * 实参和形参具有**不同存储的存储单元**，实参与形参变量的数据传递时“值传递”；
  * 函数调用时，系统给形参分配存储单元，并将实参对应的**值**传递给形参；
  * 实参和形参的**类型必须相同或者可以兼容**.

```C++
#include<iostream>
using namespace std;
void change(int a,int b)
{
  a=30;b=50;
}
void exchange(int a,int b)
{
  int p;
  if(a<b)
  {
    p=a;a=b;b=p;
  }
}
int main()
{
  int a=3,b=5;
  change(a,b);
  cout<<a<<" "<<b<<endl; //其实a和b的值不变
  exchange(a,b)；
  cout<<a<<" "<<b<<endl; //a和b的值还是不变
  return 0;
}
```

### 变量的作用域

根据变量在程序中的作用范围不同，可以分成：
  * **局部变量**：在函数内或块内定义，旨在这个函数或者块内起作用的变量；
  * **全局变量**：在所有函数外定义的变量，它的作用域从定义变量的位置开始到本程序文件结束。**全局变量不定义在main函数开辟的内存空间中。**

```C++
#include<iostream>
using namespace std;
int excel_number=0; //全局变量
void excel_count(float score) //形参score在excel_count函数内，也是局部变量
{
  if(score>85)
    excel_number++;
}
int main()
{
  float score=0; //定义在main函数内，为局部变量
  for(int i-0;i<00;i++) //i为局部变量，只作用于for循环内
  {
    cin>>score;
    excel_count(score);
  }
}
```
```C++
#include<iostream>
using namespace std;
int a=0,b=0;
void exchange()
{
  int p;
  if(a<b)
  {
    p=a;a=b;b=p;
  }
}
int main()
{
  cin>>a>>b;
  exchange()；
  cout<<a<<" "<<b<<endl; //这个时候a和b的值发生了替换
  return 0;
}
```
```C++
#include<iostream>
using namespace std;
int a=0,b=0;
void exchange(int a,int b) //不同之处
{
  int p;
  if(a<b) // 局部变量和全部变量冲突，在局部变量作用域内将屏蔽同名的全局变量。
  {
    p=a;a=b;b=p;
  }
}
int main()
{
  cin>>a>>b;
  exchange(a,b)；
  cout<<a<<" "<<b<<endl; //这个时候a和b的值就不变了
  return 0;
}
```
### 数组与函数

* **数组元素做函数参数**：无明显差异
  ```C++
  #include<iostream>
  using namespace std;
  void change(int a,int b)
  {
    a=30;b=50;
  }
  int main()
  {
    int a[2] = {3,5};
    change(a[0],a[1])；
    cout<<a[0]<<" "<<a[1]<<endl; //a b不变
    return 0;
  }
  ```
* **数组名做函数参数**：main()传递给函数形参的是**数组在内存中的地址**。
  ```C++
  #include<iostream>
  using namespace std;
  void change(int a[]) //注意格式后面带中括号
  {
    a[0]=30;b[1]=50;
  }
  int main()
  {
    int a[2] = {3,5};
    change(a)；
    cout<<a[0]<<" "<<a[1]<<endl; //a b变化
    return 0;
  }
  ```
### 函数作用和示例

* **问题描述：** 给定从公元2000年1月1日开始逝去的天数，请你编写程序给出当前的这一天 是哪年哪月哪日星期几呢？
  * 注意闰年
  * 注意每个月的天数也不一样
* **输入输出要求**
  * 输入多组数据，每一组一个正整数。 这个正整数表示从2000年1月1号开始已经过去的天数。
  * 对于输入的每个天数都输出一行，这一行里头包含了对应的日期和星期几。它的格式为'YYYY-MM-DD DayOfWeek'.
  * 输入最后一行是-1，不必处理。假设结果的年份不会超过9999.
* 思路
  * 基于日期计算出星期几
  * 减掉每年的天数，直至得到年份
  * 减掉每月的天数，直至得到月份
  * 最后得到日
```C++
#include<iostream>
using namespace std;
int days; //gloval variable
int get_dayofweeks();
int get_year();
int get_month(int);

int main()
{
  int year,month,dayofweek;
  int leap_year;
  char week[7][10]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
  while((cin>>days)&&days!=-1){
    dayofweek = get_dayofweeks();
    year = get_year();
    leap_year = (year%4==0&&year%100!=0||year%400==0);
    month = get_month(leap_year);
    cout<<year<<"-"<<month<<"-"<<++days<<" "<<week[dayofweek]<<endl;
  }
  return 0;
}

int get_dayofweeks(){
  int dayofweek;
  dayofweek = days%7;
  return dayofweek;
}

int get_year(){
  int i=2000,leap_year;
  while(true){
    leap_year = (i%4==0&&i%100!=0||i%400==0);
    if(leap_year==1&&days>=366){
      days=days-366;
      i++;
      continue;
    }
    else if(leap_year==0&&days>=365){
      days=days-365;
      i++;
      continue;
    }
    else
      break;
  }
  return i;
}

int get_month(int leap_year){
  int pmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31} ;
  int rmonth[12] = {31,29,31,30,31,30,31,31,30,31,30,31} ;
  int j=0;
  while(true){
    if(leap_year==1&&days>=rmonth[j]){
      days = days-rmonth[j];
      j++;
    }
    else if(leap_year==0&&days>=pmonth[j]){
      days = days - pmonth[j];
      j++;
    }
    else
      break;
  }
  return ++j;
}
```

## 递归

### 什么是递归

**函数的嵌套调用**
  * 函数不能嵌套定义：所有函数一律平等
  * 函数可以嵌套调用：无论嵌套多少层原理上是一样的
  * 函数能不能调用自己？
  ```C++
  \\阶乘
  #include<iostream>
  using namespace std;
  int fact(int n)
  {
    if(n==1)
      return 1;
    else
      return n*fact(n-1);
  }
  int main(){
    cout<<fact(4)<<endl;
    return 0;
  }
  ```

**递归定义**
  * 一个函数在其定义中直接或间接调用自身的一种方法；
  *  递归调用与普通嵌套调用没有区别！！！！!

### 深入理解递归的过程

```C++
\\简单例子
#include<iostream>
using namespace std;
int recur()
{
  char c;
  c = cin.get();
  if(c!='\n')
    recur();
  cout<<c;
  return 0;
}
int main(){
  recur();
  return 0;
}
```

### 递归的作用

**用递归来完成递推**
  * 不同：递推的关注点放在起始点条件，而递归的关注点放在求解目标上；
  * 相同：重在表现第i次与第i+1次的关系。
  * 方法
    * 把关注点放在要求解的目标上；
    * 找到第n次做与第n-1次做之间的关系；
    * 确定第1次的返回结果。
  ```C++
  /*切饼
  q(n) = q(n-1)+n;
  */
  #include<iostream>
  using namespace std;
  int q(int n)
  {
    if(n==0)
      return 1;
    else
      return(n+q(n-1));
  }
  int main(){
    cout<<q(4)<<endl;
    return 0;
  }
  ```
  ```C++
  /*斐波那契数列
  fab(n) = fab(n-1)+fab(n-2);
  */
  #include<iostream>
  using namespace std;
  int fab(int n)
  {
    if(n==1)
    return 1;
    if(n==2)
    return 1;
    else
      return(fab(n-1)+fab(n-2));
  }
  int main(){
    cout<<fab(4)<<endl;
    return 0;
  }
  ```

**模拟连续发生的动作**

  * 方法
    * 搞清楚连续发生的动作是什么；
    * 搞清楚不同次动作之间的关系；
    * 搞清楚边界条件是什么。

```C++
//将123转换成等值的二进制数
void convert(int x)
{
  if((x/2)!=0)
  {
    convert(x/2);
    cout << x%2; //逆序打印
  }
  else
    cout<<x;
}
int main()
{
  int x;
  cin>>x;
  convert(x);
  return 0;
}
```
```C++
/*汉诺塔问题
要实现: move(n,A,B,C)
需进行(简化成两次移动n-1个盘子)：
        move(n-1,A,C,B)
        move n from A to C
        move(n-1,B,A,C)
*/
void move(int m,char x,char y,char z)
//将m个盘子从A经过B移动到C
{
  if(m==1)
    cout<<"把一个盘子从"<<x<<"移动到"<<z<<endl;
  else
  {
    move(m-1,x,z,y);
    cout<<"把一个盘子从"<<x<<"移动到"<<z<<endl;
    move(m-1,y,x,z);
  }
}
int main(){
  int n;
  cout<<"请输入盘数n=";
  cin>>n;
  cout<<"在3根柱子上移"<<n<<"只盘的步骤为："<<endl;
  move(n,'A','B','C');
  return 0;
}
```
```C++
/*
【放苹果】
把M个同样的苹果放到N个同样的盘子里，允许有的盘子不放，问共有多少种不同的分法？（和顺序无关）
【分析】
1、如果：盘子数＞苹果数
  if(n>m) f(m,n)=f(m,m)
2、如果：苹果数＞=盘子数
  下面两种情况下放置方式的和
  ① 有盘子空着: f(m,n)=f(m,n-1)
  ② 没盘子空着: f(m,n)=f(m-n,n)
*/
int count(int m, int n){
  if(m==0||n==1) return 1;
  //递归出口：当只有0个苹果或者只有1个盘子
  //也可以写成(m<=1||n<=1)
  if(m<n)
    return count(m,m);
  else
    return count(m,n-1)+count(m-n,n);
}
int main(){
  int apples, plates;
  cin>>apples>>plates;
  cout<<count(apples,plates);
  return 0;
}
```

**进行“自动的分析”**

```C++
/*
【逆波兰表达式】
逆波兰表达式是一种把运算符前置的算术表达式：
  如2+3的逆波兰表达式为+23
  如(2+3)*4的逆波兰表达式为*+234
编写程序求解任一仅包 + - * / 四个双目运算符的逆波兰表达式的值。
【分析】
读取运算符，将后面的表达式分成前后两个独立部分，且分别都是独立的逆波兰表达式；
第一个独立部分继续上述分析
*/

double notation(){
  char str[10];
  cin>>str;
  switch(str[0])
  {
    case '+': return notation() + notation();
    case '-': return notation() - notation();
    case '*': return notation() * notation();
    case '/': return notation() / notation();
    default: return atof(str); //把一个字符串转换成相应的 float类型
  }
}
int main(){
  cout<<notation();
  return 0;
}
```
