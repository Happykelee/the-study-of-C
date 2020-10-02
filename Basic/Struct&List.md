# [the study of C/C++](../README.md)

**C/C++语言学习笔记**

## 结构体

### 结构体定义

* 一种新的数据类型——结构体

    ```C++
    struct student
    {
    int id;
    char name[20];
    char sex;
    int age;
    float score;
    char addr[30];
    };
    ```

* 定义结构体变量的方式
    
    ```C++
    // (1) 直接用已声明的结构体类型定义变量名
    student student1,student2;
    // (结构体类型名) (结构体变量名)

    // (2) 在声明类型的同时定义变量
        struct student
    {
    int id;
    char name[20];
    char sex;
    int age;
    float score;
    char addr[30];
    }lige_1, lige_2;
    ```

### 结构体使用

* 简单使用的例子

    ```C++
    #include <iostream>
    using namespace std;

    struct student
    {
        int id_num;
        char name[10];
    };

    int main()
    {
        student mike = {123, {'m','i','k','e','\0'}};
        mike.id_num = 20130000 + mike.id_num;
        //结构体变量存储方式和数组的很像

        for(int i=0;mike.name[i]!='\0';i++)
        {
            mike.name[i] = toupper(mike.name[i]);
        }
        cout << mike.id_num << " " << mike.name << endl;
        return 0;
    }
    ```

* 结构体变量赋值

    ```C++
    #include <iostream>
    using namespace std;

    struct student
    {
        int id_num;
        char name[10];
    };

    int main()
    {
        student mike1 = {123, {'m','i','k','e','\0'}};
        student mike2;
        mike2 = mike1; // 结构体赋值相当于拷贝一份给新变量
        mike2.id_num = 20130000 + mike2.id_num;

        for(int i=0;mike2.name[i]!='\0';i++)
        {
            mike2.name[i] = toupper(mike2.name[i]);
        }
        cout << mike1.id_num << " " << mike1.name << endl;
        cout << mike2.id_num << " " << mike2.name << endl;
        return 0;
    }
    ```
  
* 结构体做函数参数

    ```C++
    #include <iostream>
    using namespace std;

    struct student
    {
        int id_num;
        char name[10];
    };

    void renew(student one)
    {
        one.id_num = 20130000 + one.id_num;
        for (int i = 0; one.name[i] != '\0'; i++)
        {
            one.name[i] = toupper(one.name[i]);
        }
        cout << one.id_num << " " << one.name << endl;
    }

    int main()
    {
        student mike = {123, {'m','i','k','e','\0'}};
        renew(mike);
        // 结构体做函数参数相当于拷贝一份给函数
        cout << mike.id_num << " " << mike.name << endl;
        return 0;
    }
    ```

* 结构体做函数返回值

    ```C++
    #include <iostream>
    using namespace std;

    struct student
    {
        int id_num;
        char name[10];
    };

    student newone()
    {
        student one = { 20130123,
                        {'M', 'I', 'K', 'E', '\0'} };
        return one;
    }

    int main()
    {
        student mike = newone();
        // 结构体做返回值相当于拷贝一份给调用者
        cout << mike.id_num << " " << mike.name << endl;
        return 0;
    }
    ```

* 指向结构体变量的指针
  
    ```C++
    #include <iostream>
    using namespace std;

    struct student
    {
        int id_num;
        char name[10];
    };

    int main()
    {
        student mike = {20130123,{'m', 'i', 'k', 'e', '\0'}};
        student *one = &mike;
        cout << (*one).id_num << " " << (*one).name << endl;
        cout << one->id_num << " " << one->name << endl; //同理，更简便 ->叫指向运算符
        return 0;
    }
    ```

    ```C++
    #include <iostream>
    using namespace std;

    struct student
    {
        int id_num;
        char name[10];
    };

    void renew(student *one)
    {
        one->id_num = 20130000 + one->id_num;
        for(int i=0;one->name[i]!='\0';i++)
        {
            one->name[i] = toupper(one->name[i]);
        }
    }

    int main()
    {
        student mike = {20130123,{'m', 'i', 'k', 'e', '\0'}};
        renew(&mike);
        cout << mike.id_num << " " << mike.name;
        return 0;
    }
    ```

* 结构体数组

    * 数组名相当于指向数组的第一个元素的指针；
    * 指向元素的指针++，则跨过一整个结构体。

    ```C++
    #include <iostream>
    using namespace std;

    struct student
    {
        int id_num;
        char name[10];
    };

    int main()
    {
        student myclass[3] =
        {
            123,
            {'m', 'i', 'k', 'e', '\0'},
            133,
            {'t', 'o', 'm', '\0'},
            143,
            {'j', 'a', 'c', 'k', '\0'}
        };
        student *one = myclass;
        cout << one->id_num << " " << one->name << endl;
        one++;
        cout << one->id_num << " " << one->name << endl;
        return 0;
    }
    ```

* 小结

    * 结构体数据类型的特性与普通数据类型的特性是一致的。

* 应用示例
 
    * 生日相同问题（数组统计，结构体数组）


## 链表

要想在结构体内插入变量，会十分麻烦，但是用链表可以方便解决。 

### 链表定义

* 一种**非常常见**的数据结构
  * 链表头：指向第一个链表结点的指针；
  * 链表结点：链表中的每一个元素，包括：
    * 当前节点的数据
    * 下一个节点的地址
  * 链表尾：不再指向其他结点的结点，其地址部分放一个NULL，表示链表到此结束。

### 链表创建

* 动态申请内存空间
  * **new**: ```int *pint = new int(1024); int *pia = new int[4];```
  * **delete**: ```delete pint; delete [] pia;```

* 动态建立链表节点
  ```C++
  struct student
  {
      int id;
      student *next;
  };
  student *head;
  head = new student;
  ```

* 逐步创建链表
  * Step1:
    * head = new student;
    * student *temp = head;
  * Step2:
    * Continue?
    * Y: 
      * temp->next = new student;
      * temp = temp->next
      * goto Step2
    * N:
    * temp->next = NULL;
  
  ```C++
  student *create()
  {
      student *head, *temp;
      int num, n=0;
      head = new student;
      temp = head;
      cin >> num;
      while(num!=-1)
      {
          n++;
          temp->id = num;
          temp->next = new student;
          temp = temp->next;
          cin >> num;
      }
      if(n==0)
        head = NULL;
    else
        temp->next = NULL;
    return head;
  }
  ```

### 链表操作

* 链表遍历

  ```C++
  #include <iostream>
    using namespace std;

    struct student
    {
        int id_num;
        student *next;
    };

    student *create()
    {
        student *head, *temp;
        int num, n = 0;
        head = new student;
        temp = head;
        cin >> num;
        while (num != -1)
        {
            n++;
            temp->id_num = num;
            temp->next = new student;
            temp = temp->next;
            cin >> num;
        }
        if (n == 0)
            head = NULL;
        else
            temp->next = NULL;
        return head;
    }

    int main()
    {
        student *pointer = create();
        while(pointer->next!=NULL)
        {
            cout << pointer->id_num << endl;
            pointer = pointer->next;
        }
        return 0;
    }
  ```

* 删除链表结点
  
  * 第一个结点
    
    ```C++
    temp = head;
    head = head->next;
    delete temp;
    ```

  * 中间结点
    ```C++
    follow->next = temp->next
    delete temp;
    // temp是要删除的结点，follow是temp前的结点
    ```

  ```C++
  // 在链表中将值为n的元素删掉
  sudent *dele(student *head, int n)
  {
      student *temp, *follow;
      temp = head;
      if(head=NULL)
      // head为空，空表的情况
      {
        return(head);
      }

      if(head->num==n)
      // 第一个结点是要删除的目标
      {
          head = head->next;
          delete temp;
          return(head);
      }

      while(temp!=NULL&&temp->num!=n)
      {
          follow = temp;
          temp = temp->next;
      }
      if（temp==NULL)
        cout << "not found";
      else
      {
          follow->next = temp->next;
          delete temp;
      }
      return(head);
  }
  ```

* 插入结点
  
  * 插入到开头
    
    ```C++
    unit->next = head;
    head = unit;
    ```

  * 插入中间
    
    ```C++
    unit->next = temp;
    follow->next = unit;
    ``` 


  ```C++
  // 在链表中插入结点值为n的结点
  sudent *insert(student *head, int n)
  {
      student *temp, *follow, *uint;
      temp = head;
      unit = new student;
      unit->num = n;
      unit->next = NULL;

      if(head=NULL)
      // head为空，直接插入
      {
          head = unit; 
          return(head);
      }

      while((temp->next!=NULL)&&(temp->num<n))
      // 寻找第一个不小于n或结尾的结点temp
      {
          follow = temp;
          temp = temp->next;
      }
      if（temp==head)
      // 如果temp为第一个结点
      {
          unit->next = head;
          head = unit;
      }
      else
      {
          if(temp->next==NULL)
          //如果temp为最后一个结点
          {
              temp->next = unit;
          }
          else
          //如果temp为一个中间结点
          {
            follow->next = unit;
            unit->next = temp;
          }

      }
      return(head);
  }
  ```

### 双向链表

* 双向链表包含两个指针，一个指向下一个结点，一个指向上一个结点。

* 双向链表的删除
  ```C++
  temp->ahead->next = temp->next;
  //修改temp前驱结点的next指针成next结点

  temp->next->ahead = temp->ahead;
  //修改temp后驱结点的ahead指针成ahead结点

  delete temp;
  ```

* 双向链表的插入
  ```C++
  // 先解决unit的前后两个结点
  unit->next = temp->next;
  unit->ahead = temp;

  // 然后把后面节点的ahead指针修改成unit
  temp->next->ahead = unit;
  // 把前面节点的next指针修也要改成unit
  temp->next = unit;
  ```

* 双向链表的应用示例

    * 约瑟夫问题
    ```C++
    // 利用双向循环链表
    #include <iostream>
    using namespace std;

    struct Node
    {
        int num;
        Node *next;
        Node *ahead;
    };

    Node *Create(int N);
    Node *Search(Node *head, int P);
    Node *Release(Node *head, int M);

    int main()
    {
        int N,P,M; // N-起使结点数，P-开始结点数
        cin >> N >> P >> M;
        Node *head = Create(N); // 创建
        head = Search(head,P); // 找到第P个结点
        while(head->next!=head)
        // 不断始放第M个元素，直至只剩一个元素
        {
            head = Release(head, M);
        }
        cout << "*" << head->num <<endl;
        return 0;
    }

    Node *Create(int N)
    {
        Node *head, *temp, *unit;
        head = new Node;
        head->num = 1;
        temp = head;

        for(int i=2;i<=N;i++)
        {
            unit = new Node;
            unit->num = i;
            unit->ahead = temp;
            temp->next = unit;
            temp = temp->next;
        }
        // 尾结点处理
        unit->next = head;
        head->ahead = unit;
        return (head);
        }

    Node *Search(Node *head, int P)
    {
        P = P - 1;
        for(int i=0;i<P;i++)
            head = head->next;
        return(head);
    }

    Node *Release(Node *head, int M)
    {
        Node *temp = head;
        for(int i=1;i<M;i++)
            temp = temp->next; // 找到第M个位置指针
        temp->ahead->next = temp->next;
        temp->next->ahead = temp->ahead;
        cout << temp->num << endl;
        head = temp->next;
        delete temp;
        return(head);
    }
    ```
