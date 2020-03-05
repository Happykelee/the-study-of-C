# [the study of C/C++](README.md)

**C/C++语言学习笔记**

## 数组

### 一维数组

  * 基本格式：类型 数据名[常量表达式]
  * 例子：```float sheep[10]```;
  * **再次强调**：数组下标从0开始。

```C++
int a[10] = {0,1,2,3,4,5,6,7,8,9};
int a[4]; //VC中会自动赋值为很大的负数
int a[] = {1,2,3,4};
int a[4] = {1,2}; //剩下的元素指定为0
int a[3] = {1,2,3,4}; //报错

const int i=4;
int a[i] = {0,1,2,3}

# define N 4 //预定义
int a[N] = {1,3,4,5};

/*
int n = 10;
int a[n] = {0}; //错误，中括号内必须为u常量表达式
*/
```

### 二维数组

  * 存储：二维数组为多行一维数组，依次存储

```C++
int a[3][4]; //三行四列
int a[3][4] = {0};
int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12}; //正确
int a[][4] = {1,2,3,4,5,6,7,8,9,10,11,12}; //正确
int a[][4] = {{1},{5,6,},{9,10,11}}; //正确

for(int i=0;i<3;i++){
  for(int j=0;j<4;j++){
    cout<<setw(3)<<a[i][j]; //setw保证输出的字符宽度
  }
}
```

### 高维数组

```C++
//三维数组
int[5][3][4]; //五个三行四列的数组（片/行/列）
```

### 数组的作用

* **数字统计**
  * 例题：输入20个0-9的整数，统计每个数出现的次数。
  ```C++
  int count[10]={0};
  for(int i=0;i<20;i++){
    cin>>num;
    count[num]++;
  }
  ```
  * 例题：某学校有1000位老师，分布在20个不同的学院中，每个学院最多有12个系，输入每位老师的所在院、系的编号（院编号1-20，系编号1-12），打印出各个系老师的数量。
  ```C++
  int teacher[21][13] = {0};
  int school,department;
  char name[30];
  for(int i=0;i<1000;i++){
    cin>>name>>shcool>>department;
    teacher[school][department]++;
  }
  ```

* **下标做数轴**
  * 例题：输出100以内的素数
  ```C++
  #include<cmath>
  const double C=sqrt(100.0); //根据初等数论，只需要小于sqrt(100.0)
  int a[100]={0},sum=0;
  for(int i=2;i<C;i++){
    sum = i;
    if(a[sum]==0){
    //吐过自身已经被标定，就不需要用于叠加求合数
      while(sum < 100){
        sum += i;
        if(sum<100) a[sum] = 1;
      }
    }
  }
  for(int i=2;i<100;1++){
    if(a[i]==0) cout<<i<<"";
  }
  ```

## 字符串

### 字符数组和字符串

* 所有以\0为结尾的字符数组都可以被看作是字符串，同理，所有字符串都可以被看作是以\0为结尾的字符数组。
* 在数组定义并初始化的时候：```char c[6] = "China"```
  但**不能**用赋值语句将一个字符串常量或字符数组**直接赋给另一个字符数组**。

```C++
char a[10] = {'a','b','c','d','e'};
// 未定义的元素会被定义为/0
char c[]={'C','h','i','n','a'};
char c[]="China"; // 有六个元素，最后一个是\0

char str1[]="C++",str2[4];
while i = 0;
while(str1[i] != "\0"){
  str2[i]=str[i];
  i++;
}
str2[i]="\0";
cout<<"String1:"<<str1<<endl; //字符数组可以直接输出，其他数组不行
cout<<"String2:"<<str1<<endl;

char weekday[7][11] = {'Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday'};
```

### 字符/字符数组/字符串的输入与输出

* 一个字符的输入
  * cin: 不会读取空格和回车
  * cin.get()函数: cin.get()/cin.get(char)，将空格和回车当作字符进行读取
  * getchar()函数：^Z也能读进来
  * ^Z: 终止字符读取

  ```C++
  char c;
  cout<<'enter a sentence:'<<endl;
  while(cin>>c) //不会读取空格和回车
    cout<<c;
    //^Z 终止字符读取

  while((c=cin.get())!=EOF) // EOF:end of file (文件结束标志)
    cout<<c;

  while(cin.get(c)) //读取一个字符赋给字符变量c
    cout<<c;

  while(c=getchar())
    cout<<c;
  ```
* 一串字符的输出输入
  * cin;
  * cin.get(): ```cin.get(ch,10,'\n') //第三个参数为指定终止符，默认为\n```
  * cin.getline(): 用法类似
  * cin.get()和cin.getline()的区别：getline遇到终止标识符结束，缓冲区指针移到终止标识符之后；get遇到终止字符是停止读取，指针不移动

  ```C++
  char a[10]="Computer";
  cout<<a; //程序从开始一直输出直至遇到/0

  int a[8] = {1,2,3,4,5,6,7,8};
  cout<<a; //输出数组的起始地址

  char a[8]={'C','o','m','p','u','t','e','r'};
  cout<<a; //会输出乱码

  char weekday[7][11] = {'Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday'};
  for(int i=0;i<7;i++){
    cout<<weekday[i]<<endl;
  }

  char str[10];
  while(cin>>str)
    cout<<str<<endl;

  char ch[20];
  cin.get(ch,10,'o');
  cin.getline(ch,10,'o')
  ```

  ### 字符串的应用

  * 例题：输入一个字符串，把每个字符变成它的后续字符。
  ```C++
  char str[200];
  while(cin.getline(str,200)){
    for(int i=0;str[i]!='\0';i++){
      if(str[i]=='Z'){
        str[i] == 'A';continue;  
      }
      if(str[i]=='z'){
        str[i]=='a';continue;
      }
      if(str[i]=='')
        continue;
      str[i]++;
    }
    cout<<str<<endl;
  }
  ```

  * 输入两个字符串，将其中较短的串接到长的串后面。有很多系统函数 ```#include <string>```.
  ```C++
  char str1[40],str2[40];
  cin.getline(str1,20);
  cin.getline(str2,20);
  int len1=0,len2=0;
  for(len1=0;str1[len1]!='\0';len1++);
  for(len2=0;str2[len2]!='\0';len2++);
  if(len1>=len2){
    for(len2=0;str2[len2]!='\0';len2++){
      str1[len1++] = str2[len2];
    }
    str1[len1]='\0';
    cout<<str1<<endl;
  }
  else{    
    for(len1=0;str1[len1]!='\0';len1++){
        str2[len2++] = str1[len1];
      }
      str2[len2]='\0';
      cout<<str2<<endl;
  }
  ```

  * 例题：输入一个英文句子（不超过80个单词），统计单词数，单词间用空格隔开。
  ```C++
  \\ 单词开始前是一个空格
  int num=0,flag=0;
  char str[80];
  cin.getline(str,80);
  for(int i=0;str[i]='\0';i++){
    if(str[i]==' ')
      flag=0;
    else if(flag==0){
      flag=1;
      num++;
    }
  }
  cout<<num<<endl;
  ```
