# [the study of C/C++](../README.md)

**C/C++语言学习笔记**

## 指针

### 指针的概念

**指针**

* **变量的地址：称为指向该变量的指针**
* 可以用取地址运算符"&"实现：```int c; cout<<&c<<endl;```
* 指针的大小（字节数）用sizeof()获取
* 计算机通过变量的地址（指针）和指针运算符"*"访问变量

**指针变量**

* 专门用于存放变量的地址（指针）的变量，称为指针变量
* 定义指针变量： ```int *pointer;``` (int:指针变量的基类型，\*：指针运算符pointer的类型，pointer:指针变量的名字)，**基类型：指针变量指向的变量的类型**
* 指针变量赋值：```pointer = &c;```, 绝对不能写成：```pointer = c; // 错误！！！```
* 通过指针变量访问指向的变量：```*pointer;```，pointer所指向的存储单元的内容是变量```c```
* ```&*pointer=&(*pointer)```
* ```*&a=*(&a)``` 
* ```(*pointer)++```不等于```*pointer++```，其中```pointer++```的含义是：pointer地址增加一个基类型长度(字节数)
* 对同一个基类型的两个指针向量，“+”运算没有意义
```C
#include <iostream>
using namespace std;
// 例子1
int main(){
    int c;
    int *pointer = &c;
    *pointer = 58;
    cout << c << endl;
    cout << pointer << endl;
    cout << &c << endl;
    cout << *pointer << endl;
    cout << &pointer << endl;
    return 0;
    /*
    结果：
    58
    0x61fe1c
    0x61fe1c
    58
    0x61fe10
    */
}
```
```C
#include <iostream>
using namespace std;
// 例子2: 指针对应的变量值互换
int main(){
    int a=0,b=0,temp;
    int *p1 = NULL, *p2 = NULL;
    // atention to the initialization of pointers

    cin >> a >> b;
    p1 = &a;
    p2 = &b;
    if (*p1<*p2)
    {
        temp=*p1;*p1=*p2;*p2=temp;
    }
    cout << "max=" <<*p1 << ",min=" << *p2 << endl;
    return 0;
    /*
    结果：
    2 3
    max=3,min=2
    */
}
```
```C

#include <iostream>
using namespace std;
// 例子3：指针对应的变量地址互换
int main(){
    int a=0,b=0;
    int *p1 = NULL, *p2 = NULL;
    int *temp = NULL;
    // atention to the initialization of pointers

    cin >> a >> b;
    p1 = &a;
    p2 = &b;
    if (*p1<*p2)
    {
        temp=p1; p1=p2; p2=temp;
    }
    cout << "max=" <<*p1 << ",min=" << *p2 << endl;
    return 0;
    /*
    结果：
    2 3
    max=3,min=2
    */
}
```

### 一维数组与指针

指针很大的用途是和数组一起使用。

* 指向数组元素的指针

    当指针指向数组元素时候，和指向普通的变量没有任何区别。

* 数组名时数组首元素的地址

    数组名相当于指向数组第一个元素的指针。

* 用指针访问数组
  
    用指针变量代替数组名。

* **定义一个指向“包含4个int型元素的一维数组”的指针变量**

    **```int(*p)[4];```**

* 注意事项(```int *p = &a[0];```)
  * a++是没有意义的，但p++会引起p变化；
  * p可以指向数组最后一个元素以后或者第一个元素以前的元素，所以指针做加减运算时一定注意有效的范围。

```C
#include <iostream>
using namespace std;

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int *p = &a[3],*p1=NULL;
    cout << *p << endl;
    *p = 100;
    cout << a[3] << endl;

    cout << a << endl;
    cout << *a << endl;
    cout << &a[0] << endl;
    cout << a[0] << endl;

    p1 = a;
    cout << p1 <<endl;
    cout << *p1 <<endl;
    cout << *p1++ << endl; //会先打印a[0]，同时p指向a[1]
    cout << *p1++ << endl; //会先打印a[1]，同时p指向a[2]
    return 0;
}
/*
4
100
5
3
0x61fdf0
1
0x61fdf0
1
0x61fdf0
1
1
2
*/
 ```

### 字符串与指针

* 指向字符串的指针（和指向数组的指针接近）

    指向字符串的指针变量：```char a[10]; char *p; p=a;```

* 指针操作字符串的便利

    可以把一个字符串赋给指针，也能把定义好的字符串数组付给指针，也能把数组中某个元素赋给指针。

```C++

#include <iostream>
using namespace std;

int main()
{
    char a[] = "How are you?", buffer[10]="ABC";
    char *pa = a, *pc;
    pc = "hello";
    // 指针可以直接赋值，但是不能修改（“hello”是常量）

    cout << a << endl; // cout对字符串进行了处理
    cout << pa << endl;
    cout << static_cast<void*>(a) << endl;
    cout << static_cast<void*>(pa) << endl;

    cout << pc << endl;
    pc++;
    cout << pc << endl;
    cout << *pc << endl;
    pc = buffer;
    // 字符串直接不能互相赋值，但是现在两个是相同基类型的指针变量
    cout << pc << endl;

    return 0;
}
/*
How are you?
How are you?
0x61fe03
0x61fe03
hello
ello
e
ABC
*/
```

### 指向二（多）维数组的指针

* 再谈一维数组的地址（**可推广至多维数组的三条重要规律**）

    * **数组名相当于指向数组第一个元素的指针**；
    * **&E 相当于管辖范围“上升”了一级；**
    * ***E 相当于管辖范围“下降”了一级。**

    ```C++
    #include <iostream>
    using namespace std;
    int main()
    {
        int a[4] = {1,3,5,7};

        cout << a << endl; // a 相当于指向数组首元素的那个指针
        cout << a+1 << endl; // 跨越一个基类型长度
        cout << &a << endl; // &a 相当于指向整个数组的一个指针
        cout << &a+1 << endl; // 跨越整个数组长度
        cout << *(&a) << endl;
        // 出现在*运算后面的表达式是指针的话，将返回指针指向的内容(此处指向该数组)，含义相当于a
        cout << *(&a)+1 << endl;
        return 0;
    }
    /*
    0x61fe10
    0x61fe14
    0x61fe10
    0x61fe20
    0x61fe10
    0x61fe14
    */
    ```

* 指向二维数组的指针

    * 二维数组a[3][4]包含三个元素，每个元素都是一个“包含四个整型元素”的数组；相当于，**该二维数组由三个数组名为a[0]、a[1]、a[2]的一位数组组成**。

    * 二维数组的第一个元素是a[0]（一个包含四个整型元素的一维数组），因为二维数组名相当于首元素的指针，所以**a相当于指向a[0]一维小数组的指针，a[0]相当于指向a[0][0]元素的指针**。

    * 推论
      *  a与&a[0]等价；
      *  a[0]与&a[0][0]等价；
      *  a[0]与*a等价；
      *  a[0][0]与**a等价；

    ```C++
    #include <iostream>
    using namespace std;

    int main()
    {
        int a[3][4] = { {1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
        };
        
        cout << "    a=" << a << endl;
        cout << "&a[0]=" << &a[0] << endl << endl;

        cout << "    a+1=" << a+1 << endl;
        cout << "&a[0]+1=" << &a[0] + 1 << endl
            << endl;

        cout << "      *a=" << *a << endl;
        cout << "    a[0]=" << a[0] << endl;
        cout << "&a[0][0]=" << &a[0][0] << endl
            << endl;


        cout << "      *a+1=" << *a+1 << endl;
        cout << "    a[0]+1=" << a[0]+1 << endl;
        cout << "&a[0][0]+1=" << &a[0][0]+1 << endl
            << endl;

        cout << "*a+1=" << *a + 1 << endl;
        cout << "*(a+1)=" << *(a + 1) << endl;
        return 0;
    }
    /*
        a=0x61fdf0
    &a[0]=0x61fdf0

        a+1=0x61fe00
    &a[0]+1=0x61fe00

          *a=0x61fdf0
        a[0]=0x61fdf0
    &a[0][0]=0x61fdf0

          *a+1=0x61fdf4
        a[0]+1=0x61fdf4
    &a[0][0]+1=0x61fdf4

      *a+1=0x61fdf4 
    *(a+1)=0x61fe00
    */
    
    ```

### 指针与函数

* 指针用做函数参数

    * 函数拿到地址可对其所指内容进行修改

    ```C++
    #include <iostream>
    using namespace std;

    void Rank(int *q1, int *q2)
    {
        int temp;
        if(*q1<*q2)
        {
            temp = *q1;
            *q1 = *q2;
            *q2 = temp;
        }
    }

    void sum(int *p, int n)
    {
        int total=0;
        for (int i=0;i<n;i++)
        {
            total+= *p++;
        }
        cout<<total<<endl;
    }

    int sum2(int array[], int n)
    // 编译器将形参数组名作为指针变量来处理！
    {
        int total = 0;
        for (int i = 0; i < n-1; i++)
        {
            *(array+1) = *array + *(array+1);
            array++;
        }
        return *array;
    }

    int main()
    {
        int a,b,*p1,*p2;
        cin>>a>>b;
        p1=&a;
        p2=&b;
        Rank(p1,p2);
        cout<<a<<" "<<b<<endl;

        int c[10]={1,2,3,4,5,6,7,8,9,10};
        sum(c, 10);
        for (int i=0;i<10;i++)
            cout<<c[i]<<" ";
        cout<<endl;
        cout << sum2(c, 10) << endl;
        for (int i = 0; i < 10; i++)
            cout << c[i] <<" ";
        cout << endl;
        return 0;
    }
    /*
    3 5
    5 3
    55
    1 2 3 4 5 6 7 8 9 10
    55
    1 3 6 10 15 21 28 36 45 55
    */
    ```

* “限制”指针实参的功能（可以使用const）

    * 指向符号常量的指针定义: ```const int *p;```
    * 不能通过p修改指针对应的变量

    ```C++
    #include <iostream>
    using namespace std;

    void sum(int *p, int n)
    {
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += *p++;
        }
        cout << total << endl;
    }

    int sum2( const int array[], int n)
    // 定义稍加修改，增加的const将array变成指向符号常量的指针
    {
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += *array++;
        }
        return total;
    }

    int main()
    {

        int c[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        sum(c, 10);
        for (int i = 0; i < 10; i++)
            cout << c[i] << " ";
        cout << endl;
        cout << sum2(c, 10) << endl;
        for (int i = 0; i < 10; i++)
            cout << c[i] << " ";
        cout << endl;
        return 0;
    }

    /*
    55
    1 2 3 4 5 6 7 8 9 10
    55
    1 2 3 4 5 6 7 8 9 10
    */
    ```

    ```C++
    #include <iostream>
    using namespace std;

    int main()
    {
        const int a=78; const int b=28; int c = 18;
        const int *pi = &a;
        cout << *pi << endl;
        // *pi = 58;(error，*p不能被赋值)
        pi = &b; // (可以对pi重新赋值)
        cout << *pi << endl;
        // *pi = 68;(error，*p不能被赋值)
        pi = &c;
        cout << *pi << endl;
        // *pi = 88;(error，*p不能被赋值)
        return 0;
    }

    /*
    78
    28
    18
    */
    ```

* 指针用做函数返回值

    * 函数的返回值可以是多种类型  
        * **返回整型数据的函数：** ```int max(int x, int y);```
        
        * **返回指针类型数据的函数：** ```int *function(int x, int y);```（函数名字前面表示函数的类型“*”）

    * 特别注意：返回一个处于生命周期中的变量的地址  
       * 返回**全局变量**的地址，而非**局部变量**的地址
            ```C++
            #include <iostream>
            using namespace std;

            int value1 = 20;
            int value2 = 30;
            int *getInt1()
            {
                return &value1;
            }
            int *getInt2()
            {
                return &value2;
            }
            int main()
            {
                int *p, *q;
                p = getInt1();
                q = getInt2();
                cout << *p << endl;
                return 0;
            }
            ```  
       * 返回**静态局部变量**的地址，而**非动态局部变量**的地址
            ```C++
            #include <iostream>
            using namespace std;

            int *getInt1()
            {
                static int value1 = 20;
                return &value1;
            }
            int *getInt2()
            {
                static int value2 = 20;
                return &value2;
            }
            int main()
            {
                int *p, *q;
                p = getInt1();
                q = getInt2();
                cout << *p << endl;
                return 0;
            }
            ```

* 静态局部变量
    * 定义：函数中的局部变量的值在函数调用结束后不消失而保留原值（即其占用的存储单元不释放，在下一次该函数调用时，仍可以继续使用该变量）
    * 使用：用关键词static进行声明，可将变量指定为“静态局部变量”：```static int value1 = 20;```
    ```C++
    #include <iostream>
    using namespace std;

    void function()
    {
        int a = 0;
        // (普通)动态局部变量a：有效范围在函数范围内（以前的版本前面可加可不加auto，新版本auto含义完全变化了）
        static int b = 0;
        // 静态局部变量b：有效范围从定义开始一直持续到程序结束
        a = a + 1;
        b = b + 1;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
    int main()
    {
        for (int i=0;i<5;i++)
        {
            function();
            cout << "Call Again!" << endl;
        }
        return 0;
    }
    ```