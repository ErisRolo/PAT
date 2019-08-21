# PAT Tips

```c++
/*
设置Dev c++支持c++11标准的方法：Tools->
                            Compiler Options->
                            勾选Add the following commands when calling the compiler->
                            在该选项的框下写 -std=c++11
*/

//标准代码开头
#include <bits/stdc++.h>
using namespace std;
```
<div STYLE="page-break-after: always;"></div>
## 一.数学问题

#### 1.进制转换

将P进制数x转换为Q进制数z需要分为两步：① 将P进制数x转换为十进制数y

 　　　　　　　　　　　　　　　　　　　② 将十进制数y转换为Q进制数z

```c++
//将P进制数x转换为十进制数y
int PToTen(int x) {
    int y = 0, product = 1; //product在循环中会不断乘P，得到1、P、P²、P³...
    while(x != 0) {
        y = y + (x % 10) * product; //x % 10是为了每次获取x的个位数
        x = x / 10; //去掉x的个位
        product = product * P;
    }
    return y;
}
//若从左到右可以获得数字的每一位则可以如下转换
int PToTen(int x[]) {
    int y = 0;
    for(int i = 0; i < n; i++)
        y = y * P + x[i];
    return y;
}

//将十进制数y转换为Q进制数z
void TenToQ(int y) {
    int z[40], num = 0; //数组z存放Q进制数y的每一位
    do {
        z[num++] = y % Q; //除基取余
        y = y / Q;
    } while(y != 0);
    //最终z数组从高位z[num-1]到低位z[0]即为Q进制数z
}
```

注意若数字为字符串，则进制转换是不同的，因为字符串可以从左到右直接获得每一位的字符，参照字符串hash和PAT A1010，PAT A1010的模板如下

```c++
//将radix进制的数（字符串）转换为十进制数，其中a-z表示10-35，很容易理解，理解即可
LL strToTen(string s, LL radix) {
    LL res = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            res = res * radix + s[i] - '0'; // '0'-'9' ~ 0-9
        }
        if(s[i] >= 'a' && s[i] <= 'z') {
            res = res * radix + s[i] - 'a' + 10; // 'a'-'z' ~ 10-35
        }
        if(res < 0)
            return -1; //判断是否溢出
    }
    return res;
}
```

#### 2.最大公约数与最小公倍数

方法就是辗转相除法，模板如下

```c++
//最大公约数
int gcd(int a, int b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}
//最小公倍数
int lcm(int a, int b) {
    int d = gcd(a, b);
    return a / d * b; //原本为ab/d，为防止ab溢出，改成a/db
}
```

#### 3.分数的四则运算

用结构体表示分数，四则运算直接按平常计算推导，主要掌握根据三项规则化简和输出，模板如下

```c++
//分数的表示
struct Fraction {
    int up, down; //分子、分母
};
//分数的化简
Fraction reduction(Fraction f) {
    if(f.down < 0) { //如果分母为负数，令分子和分母都变为相反数
        f.up = -f.up;
        f.down = -f.down;
    }
    if(f.up == 0) { //如果分子为0，令分母为1
        f.down = 1;
    } else { //如果分子不为0，进行约分（求最大公约数然后分子分母分别整除）
        int d = gcd(abs(f.up), abs(f.down));
        f.up /= d;
        f.down /= d;
    }
    return f;
}
//分数的输出
void showFraction(Fraction f) {
    f = reduction(f);
    if(f.down == 1) { //如果分母为1说明为整数，只输出分子
        printf("%lld", f.up);
    } else if(abs(f.up) > f.down) { //假分数，应该以带分数的形式输出
        printf("%d %d/%d", f.up / f.down, abs(f.up) % f.down, f.down);
    } else { //真分数，直接输出
        printf("%d/%d", f.up, f.down);
    }
}
```

#### 4.素数

要掌握素数的判断和埃氏筛法获得素数表，模板如下

```c++
//素数的判断
bool isPrime(int n) {
    if(n <= 1)
        return false; //特判
    int sqr = (int)sqrt(1.0 * n); //根号n
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0)
            return false; //如果n能整除i，则n不是素数
    }
    return true;
}
//素数表的获取，以获得1-100以内的所有素数为例，存储在prime数组内，数量为num，不需要使用isPrime()函数
const int maxn = 101;
int prime[maxn], num = 0;
bool p[maxn] = {false}; //如果i为素数则p[i]为false
void findPrime() {
    for(int i = 2; i < maxn; i++) {
        if(p[i] == false) {
            p[num++] = i;
            for(int j = i + i; j < maxn; j += i)
                p[j] = true;
        }
    }
}
```

#### 5.质因子分解

用结构体存储质因子，数组只需要开到10，先获得素数表，然后枚举1-sqrt(n)的所有质因子进行判断，结束后单独判断n，是否有一个大于sqrt(n)的质因子（若有的话只有一个），模板如下

```c++
//质因子分解
struct factor {
    int x, cnt; //质因子及其个数
} fac[10];
int sqr = (int)sqrt(1.0 * n);
for(int i = 0; i < pNum && prime[i] <= sqr; i++) {
    if(n % prime[i] == 0) { //如果能整除该因子
        fac[num].x = prime[i]; //记录该因子
        fac[num].cnt = 0;
        while(n % prime[i] == 0) { //计算该因子个数
            fac[num].cnt++;
            n /= prime[i];
        }
        num++; //计算不同的质因子个数
    }
}
if(n != 1) {
    fac[num].x = n;
    fac[num].cnt = 1;
    num++;
}
```

需要注意的是1不是质因子，但有的题目需要对1进行特判

如果要求一个正整数的因子个数，算出每个质因子的个数c1,c2,...,cn后，因子个数则为(c1+1)*(c2+1)...(cn+1)

总之最重要的结论，整数n不能被自己以外的大于sqrt(n)的数整除

#### 6.大整数运算

用结构体存储，**整数的高位存储在数组的高位**，**整数的低位存储在数组的低位**，需要用构造函数初始化，输入使用字符串，存进结构体时要倒着赋值，模板如下

```c++
//大整数
struct bign {
    int d[maxn]; //maxn为位数
    int len; //实际长度
    bign() {
        fill(d, d + maxn, 0);
        len = 0;
    }
};
bign change(string s) {
    bign a;
    a.len = s.size();
    for(int i = 0; i < a.len; i++) {
        a.d[i] = s[s.size() - 1 - i] - '0';
    }
    return a;
}
```

**大整数的大小比较**，先比较长度，再从高位开始比较

**高精度加法**，同小学加法，借助一个进位变量carry即可

**高精度减法**，同小学减法，够减直接减，不够向高位借位，即高位减1本位加10再减；注意减法之前需要比较大小

**高精度与低精度乘法**，不同于小学乘法，需要把低精度整数视为一个整体，借助一个进位变量carry，用高精度的

每一位去乘，只留一位，剩下的作为进位（可能不止有一位），下一位乘完加上进位，仍然留一位作为结果，其余

作为进位，如此循环，最后全部乘完，判断进位是否为0，补在最高位上

**高精度与低精度除法**，同小学除法，但需要一个全局变量r作为余数，用r和每一位组合去除，不够除就商0，下一

位加上r*10继续除，最后将高位的0删去但同时至少保证有一位，返回的大整数即为商，全局变量r即为余数

此部分理解即可，不附模板，代码见晴神宝典p170-p176


<div STYLE="page-break-after: always;"></div>
## 二.字符串处理

#### 1.字符串的输入输出

PAT禁用gets()，因此用以下几种替代：① 读取整行不含空格的string，使用 `cin>>s; cout<<s;`

 　　　　　　　　　　　　　　　　 　② 读取整行含空格的string，使用`getline(cin,s); cout<<s;`

 　　　　　　　　　　　　　　　　　 ③ 读取整行不含空格的char[]，使用`scanf("%s",s); printf("%s",s);`

注意：scanf一个整数后，如果要使用getline，需要先用getchar()接收整数后的换行符

​           scanf一个整数后，如果要用scanf的%c格式输入几行连续的字符（PAT 1102），每行输入前都需要把上一行的换行符吸收掉

#### 2.常用字符串函数

参数为string的常用字符串函数：① 插入 `insert(pos,s)` 或 `insert(it,it2,it3)`

　　　　　　　　　　　　　　 ② 删除 `str.erase(it)` 或 `str.erase(first,last)`

 　　　　　　　　　　　　　　　或 ` str.erase(pos,length)`

 　　　　　　　　　　　　　　③ 获得子串 `str.substr(pos,len)`

 　　　　　　　　　　　　　　④ 查找子串 `str.find(s)` 或 `str.find(s,pos)`

 　　　　　　　　　　　　　　⑤ 替换 `str.replace(pos,len,s)` 或 `str.replace(it1,it2,s)`

 　　　　　　　　　　　　　　⑥ 与整数转换 `stoi(s)` 和 `to_string(n)`

 　　　　　　　　　　　　　　⑦ 转换成字符数组 `str.c_str()`

参数为char s[]的常用字符串函数：① 获得长度 `strlen(s)`

　　　　　　　　　　　　　　　 ② 比较大小 `strcmp(s1,s2)`

　　　　　　　　　　　　　　　  ③ 复制 `strcpy(s1,s2)`

　　　　　　　　　　　　　　　  ④ 拼接 `strcat(s1,s2)`

　　　　　　　　　　　　　　　  ⑤ 与整数转换 `atoi(s)` 和 `itoa(n,s)`

一些其他的注意事项如下：

① algorithm下的`reverse(it1,it2)`也可以对string操作

② 如果考场的codeblocks为16.01版本，即使支持c++11可能也不支持stoi，可用`atoi(s.c_str())`或

​    `sscanf(s,"%d",&n)` ; 如果itoa被禁用，则使用`sprintf(s,"%d",n)`，后两者参数为char s[]

​    至于字符数组转换成字符串，可直接用`char c[10]; string s = c;`

③ 还有str.find()返回的是位置下标，是int型数值，不是迭代器，若对这个位置上的字符操作不能直接使用返回值，应该写成str.begin()+返回值，如`int pos = s.find("0"); s.erase(s.begin()+pos);`


<div STYLE="page-break-after: always;"></div>
## 三.排序

模板固定，如下：

**① 定义相关结构体**

有时排名会放在结构体中；有时需要在结构体中对某个成员变量初始化；复杂题有时会定义不只一个结构体

 **② 编写cmp函数**

主要注意下字符串比较直接比，字符数组比较用strcmp

 **③ 实现排名**

可以在结构体中把排名记录下来，也可以直接在最后遍历时输出，代码如下

```c++
	stu[0].r = 1;
	for (int i = 1; i < n; i++) {
		if(stu[i].score == stu[i-1].score) {
			stu[i].r = stu[i-1].r;
		} else {
			stu[i].r = i + 1; //如果当前个体分数不等于上一个，则当前个体排名为数组下标加1
		}
	}
```

一些技巧和注意点：① 处理时间进行排序比较，可以把时分秒全部转换为秒，即

​                                       `int time = h*3600 + m*60 + s;`

​                                       `h = time / 3600;` `m = time % 3600 / 60;` `s = time % 60;` 或者用一个while循环

​                                   ② 复杂题数据量大要求多时，可能需要建立多个结构体数组，并进行多次排序进行筛选，

​                                        获得有效数据后再进行输出处理

​                                   ③ 对A1016和A1095那种数据带状态的题，要学会筛选有效数据

​                                   ④ cmp函数的写法要准确，只有一个比较条件就直接return，多个比较条件再加if、else if

​                                        然后最后一个return前也不要加if判断；加不加if(a!=b)是为了处理相等的情况，即直接return相当于严格的＞和＜，加了if(a!=b)则是≥和≤；其实记住写法即可，写法固定的


<div STYLE="page-break-after: always;"></div>
## 四.哈希

#### 1.整数hash

**散列函数（直接考察）：**

直接定址法：H(key)  = key

　　　　　　H(key)  = a * key + b

平方取中法：取key的平方的中间若干为作为hash值，应该不考

除留余数法：H(key)= key % mod （表长Tsize不小于mod，一般mod取Tsize，常素）

**解决冲突（考察模拟）：**

线性探查法（**Linear Probing**）：检查H(key)+1，超过表长则回表首位

**平方探查法（Quadratic Probing）**：检查H(key)+1²、H(key)-1²、H(key)+2²、H(key)-2².....，如果H(key)+k²超过表长就把H(key)+k²对表长Tsize取模，如果检查过程中出现H(key)-k²<0的情况（表首位为0），则取 ((H(key)-k²)%Tsize+Tsize)%Tsize 作为结果。PAT中只考过正向探测，步长k<Tsize；若双向探测，则步长k<Tsize/2。实际操作时，无论是不是超过表长，直接取模，即`int pos = (hkey + k*k) % Tsize;`

链地址法（**chaining**）：把所有H(key)相同的key连接成一条单链表，设Link[mod]

注意：哈希数组hash[maxn]一定要写在main()外面！

补：二维坐标映射整数：若P(x,y)，0≤x,y≤range，则H(P) = x * range + y

　　记得还要学习平均查找长度相关，19年机试考了，后续有可能考，总之数据结构基础要扎实

#### 2.字符串hash

将字符串映射整数的方法，类比进制转换，如将A~Z视为0-25为二十六进制，再将其转换为十进制数字

其实和一般数字进制转换算法不太一样，因为字符串可以直接取出第一位字符，模板（**直接背**）如下

```c++
//字符串hash，将只含有大写字母A-Z的字符串转换为整数
int hashFunc(char S[], int len) {
    int id = 0;
    for(int i = 0; i < len; i++) {
        id = id * 26 + (S[i] - 'A');
    }
    return id;
}

//字符串hash，将只含有字母A-Z、a-z的字符串转换为整数
int hashFunc(char S[], int len) {
    int id = 0;
    for(int i = 0; i < len; i++) {
        if(S[i] >= 'A' && S[i] <= 'Z') {
            id = id * 52 + (S[i] - 'A');
        } else if(S[i] >= 'a' && S[i] <= 'z') {
            id = id * 52 + (S[i] - 'a') + 26;
        }
    }
    return id;
}

//若还有数字，则增大进制数至62
```


<div STYLE="page-break-after: always;"></div>
## 五.STL

#### 1.vector（可变数组）

元素访问：直接访问下标；或用迭代器`auto it = v.begin();`

常用函数：`push_back(x); pop_back();`

　　　　　`size(); clear();`

　　　　　`insert(it,x); erase(it)、erase(first,last);`

命题思路：考查vector的二维数组的使用，一般有两种，一般考第二种，如下

```c++
vector<vector<int> > name; //两个维都可变长的二维数组（没考过）
vector<int> name[size]; //一维为定长，表示name[0]~name[size-1]中每一个都是一个int型的vector容器
```

#### 2.set（内部自动有序且不含重复元素）

元素访问：只能通过迭代器`auto it = s.begin();`

常用函数：`insert(x); find(x);`

　　　　　`size(); clear();`

　　　　　`erase(it); erase(x); erase(first,last);`

命题思路：一般遇到需要去重但是不方便开数组的情况下使用set，可以实现自动去重并按升序排序

　　　　　注意set只能通过迭代器访问，且其元素访问方式不支持`*(it+i)`，只能用`*it`

　　　　　除此之外记住set.insert()用来插入元素，set.find()用来查找元素即可

　　　　　如果需要只去重不排序，可以用**unordered_set**替代

#### 3.string（字符串）

元素访问：下标；迭代器，需要注意的是string和vector一样支持对迭代器直接加减数字如`str.begin()+3`

常用函数：`operator+= //即可以直接加减拼接`

　　　　　`compare operator //即可以直接用==、!=、<、>=等比较`

　　　　　`length()/size(); clear();`

　　　　　`insert(pos,string); insert(it,it2,it3);`

　　　　　`erase(it); erase(first,last); erase(pos,len)`

　　　　　`substr(pos,len);`

　　　　　`find(str); find(str,pos); string::npos`

　　　　　`replace(pos,len,str); replace(it1,it2,str);`

命题思路：详见“字符串处理”

#### 4.map（映射，键值自动有序）

元素访问：下标；迭代器`it->first,it->second`

常用函数：`find(key);`

　　　　　`size(); clear();`

　　　　　`erase(it); erase(key); erase(first,last);`

命题思路：① **建立字符串到整型的映射**，即map<string,int>

　　　　　　　在知道数量的前提下整型到字符串之间的映射用一个字符串数组即可，如string str[n]

　　　　　　　还有一种整型到字符数组的映射，即char ch[m] [n]

　　　　　　　map映射到整型，默认值为0

　　　　　② **判断大整数或其他数据类型是否存在**，相当于hash

　　　　　③ **字符串到字符串的映射**，相关题目可能会用isalnum()判断是否为字母或数字

　　　　　　　　　　　　　　　　　　　　　　　　用isdigit()判断是否为数字

　　　　　　　　　　　　　　　　　　　　　　　　用tolower()和toupper()转换字母大小写

　　　　　如果只映射不按key排序可以用**unordered_map**替代，而且速度更快

#### 5.queue（队列）

元素访问：只能通过front()和back()访问

常用函数：`push(x); pop();`

　　　　　`front(); back();`

　　　　　`empty(); size();`

命题思路：一般不单独考查，BFS时使用，注意**使用front()和pop()前必须用empty()判空**即可

#### 6.priority_queue（优先队列）

元素访问：只能通过top()访问

常用函数：`push(x); pop();`

　　　　　`top(); empty(); size();`

命题思路：哈夫曼树解决部分贪心问题会用到，但是一般不考

#### 7.stack（栈）

元素访问：只能通过top()访问

常用函数：`push(x); pop();`

　　　　　`top(); empty(); size();`

命题思路：不怎么考，注意**使用top()和pop()前必须用empty()判空**即可

#### 8.algorithm（常用算法函数）

① `max(x,y); min(x,y); abs(x);`

② `swap(x,y);`

③ `reverse(it1,it2);`

④ `next_permutation(a,a+maxn);`

⑤ `fill(a,a+maxn,0);`

⑥ `sort(a,a+maxn,cmp);`

⑦ `lower_bound(first,last); upper_bound(first,last);`


<div STYLE="page-break-after: always;"></div>
## 六.线性数据结构（以链表为主）

#### 1.栈（后进先出）

见STL stack，注意STL没有提供清空操作，清空的话用while+pop，或者定义一个新栈

#### 2.队列（先进先出）

见STL queue，注意STL没有提供清空操作，清空的话用while+pop，或者定义一个新队列

#### 3.链表（静态实现）

PAT的题目对于链表的考查只考静态链表，而且模板固定，如下

**① 定义静态链表**

```c++
struct Node {
    int address; //结点地址（有的可能不需要，直接数组下标作为地址，一般涉及排序的会需要）
    typename data; //数据域（目前考过的题都是int型，只有一道是char型）
    int next; //指针域
    XXX; //结点的某个性质，不同的题目会有不同的设置（目前只出过在链表上的序号或者是否为链表上的一个结点）
} node[maxn];
```

**② 在程序的开始，对静态链表进行初始化**

一般来说，需要对定义中的XXX进行初始化，将其定义为正常情况下达不到的数字（一般需要小于所有能达到的数字，有时候需要大于所有能达到的数字），例如对结点是否在链表上这个性质来说，可以初始化为0，如下

```c++
for(int i = 0; i < maxn; i++) {
    node[i].XXX = 0;
}
```

**③ 遍历链表，标记特殊性质，统计有效结点个数**

题目一般都会给出一条链表的首结点的地址，可以依据这个地址来遍历得到整条链表，这一步同时对结点的性质XXX进行标记，并且对有效结点的个数进行计数，如下

```c++
int p = begin, count = 0;
while(p != -1) { //-1代表链表结束
    XXX = 1;
    count++;
    p = node[p]->next;
}
```

**④ 对数组排序以把有效结点移到数组左端（有时可能不用，看具体题目，一般按某种要求输出时需要）**

写sort的排序函数cmp时，可以在cmp的两个参数结点中有无效结点时按XXX从大到小排序（所以步骤②要定义成小于所有能达到的数字，从小到大排序的话就定义成大于所有能达到的数字如maxn），这样就可以把有效结点全部移到数组左端。一般题目中一定会有额外的要求，因此cmp函数中一般需要有第二级排序，如下

```c++
bool cmp(Node a, Node b) {
    if(a.XXX == -1 || b.XXX == -1) { //至少一个结点是无效结点，就把它放到数组后面
        return a.XXX > b.XXX;
    } else { //第二级排序
        
    }
}
```

**⑤ 看题目在排序之后的具体要求（比较常见的是按各种不同的要求输出链表）**

这种题要灵活，不能一昧套模板，尤其③和⑤要自己想清思路。总之基本模板写下来，主体思路自己想

注意输出要根据地址位数输出，如%05d，同时若要输出末尾空结点地址-1需要提前判断，单独输出

还有输入链表结点时，如果结点数据域是字符，地址数据后继结点地址这些必须严格按照格式写，加空格，不能直接%d%c%d

有的需要特判输出0 -1（极少 就1分）


<div STYLE="page-break-after: always;"></div>
## 七.搜索

#### 1.深度优先搜索（DFS）

首先要能判断出什么题用DFS：枚举所有完整路径以遍历所有情况从而得出最优解

其次是DFS的解题步骤：① 声明好所需变量，预处理/获取数据

　　　　　　　　　　 ② 设计DFS函数，先**选定递归参数**

　　　　　　　　　　　然后编写**“死胡同”**和**“岔路口”**，按要求处理数据

　　　　　　　　　　③ 在main函数调用DFS，用**合理的参数**赋值，输出数据

DFS一般不会单独考，常常应用于树、图的遍历，因此在后面的模块结合起来学习，然后再多加练习即可，不必深究单独的考点，注意此处模板与图的遍历不一样

关于DFS的参数什么时候需要引用，如果是通过DFS改变的变量则直接作为DFS的参数无需引用，如果是需要得到最后结果的变量（比如求和，比如通过比较获取一个最大最小值）就需要加引用，或者直接作为全局变量，保险起见就别用引用就可以了

#### 2.广度优先搜索（BFS）

首先是基本模板，如下

```c++
void BFS(int s) {
    queue<int> q;
    q.push(s);
    标记s已入队;
    while(!q.empty()) {
        取出队首元素top;
        访问队首元素top;
        将队首元素出队;
        将top的下一层结点中未曾入队的结点全部入队，并设置成已入队;
    }
}
```

其次PAT对于单独的BFS只考过**多维矩阵统计有效1的个数（PAT 1091）**的题，步骤如下：

**①** 编写结构体，成员变量为坐标；声明相关变量，包括行列数层数、矩阵、记录是否入队的标记数组和增量数组

**②** 编写judge函数，判断结点是否需要访问，往往是越界、数据不合要求以及已入过队时返回false，其余时候返回true表示可以访问

**③** 编写BFS函数，按照基本模板写，同时增加需要统计数量的变量，用于出入队时的临时变量，队首出队后统计变量+1，然后用judge对下一层结点进行判断，符合条件的入队并标记已入队，最后返回统计数量即可

**④** main函数输入数据，调用BFS处理数据，按格式要求输出即可

和DFS一样，BFS一般不会单独考，常常应用于树、图的遍历，因此在后面的模块结合起来学习，然后再多加练习即可，不必深究单独的考点


<div STYLE="page-break-after: always;"></div>
## 八.树

#### 1.二叉树的遍历

PAT常考题型为给出中序遍历和另外一种遍历，要求输出其他的遍历顺序

解题思路为根据两种遍历顺序建树，即通过前序或后序确定根结点，通过中序划分区间，递归建树

但是注意建树的操作要灵活，每道题建树的方法可能不一样，深刻掌握二叉树静态结构代表的含义即可

因此要熟悉二叉树的结构和各种操作，采用静态实现，一般操作的模板如下

```c++
//二叉树的静态实现
struct Node {
    int data;
    int lchild;
    int rchild;
} node[maxn];
//二叉树的插入（用于一般建树，题目给出的序列用数组存储）
int index = 0; //辅助变量 还可以统计结点个数
int root = -1; //注意下面的root必须使用引用
void insert(int &root, int x) {
    if(root == -1) {
        node[index].data = x;
        node[index].lchild = node[index].rchild = -1;
        root = index++;
        return;
    }
    if(由二叉树的性质x应该插在左子树)
        insert(node[root].lchild, x);
    else
        insert(node[root].rchild, x);
}
//二叉树的层序遍历（和普通BFS区分，没有标记入队出队）
void LayerOrder(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        if(node[temp].lchild != -1)
            q.push(node[temp].lchild);
        if(node[temp].rchild != -1)
            q.push(node[temp].rchild);
    }
}
```

#### 2.树的遍历

① 采用静态实现，如果有数据域就用结构体数组，孩子结点用`vector<int> child`表示，没有数据域可直接用`vector<int> child[maxn]`表示一棵树，理解**树的先根遍历即DFS**，**层序遍历即BFS**，对于DFS的写法要灵活掌握，一般都需要**index**作为当前访问结点，然后根据题目要求的添加其他判定条件如**统计量**，每递归一层就修改一下递归的参数值，有些结果值不添加引用的话可以直接定义一个全局变量，用树的遍历解DFS其实很简单，除了题目有判定要求的，大部分都是以叶子结点作为递归边界，**最关键的是识别出有些DFS的题能建树操作**，一般题目里会有提示，比如直接说了tree，结点编号0~n-1；BFS的写法则为固定模板，没思路的时候可以直接套模板试一下

② 有些题目要求输出路径，保存路径的方法主要有两种，一是使用path[]数组表示路径，path[i]即路径上第i个结点的编号；二是用vector表示路径，用push_back()和pop_back()分别在DFS前后操作结点即可，推荐第二种

③ 部分DFS题目需要剪枝

#### 3.完全二叉树（CBT）

① 定义：一种特殊的二叉树，结点编号有序，从1-n，根结点为1号，可以用一个大小为2^k的**数组存放结点信息**，

k为最大高度（实际操作时数组大小设为结点数加1即可）

② 性质：若结点编号为 i ，则其左孩子为2 * i，右孩子为2 * i + 1

　　　　判断是否为叶结点即判断左孩子结点编号2 * i 是否大于n

　　　　判断是否为空结点即判断下标 i 是否大于n

　　　　**数组中元素存放的顺序即为层序遍历序列**

③ 目前PAT没有单独的考题，和其他的树结合考查，但只要结合，就可以把一般建树改成用数组实现，以CBT为主

#### 4.二叉查找树（BST）

① 定义：一种特殊的二叉树，其结点值域左子树<根结点<右子树，基本操作和二叉树一样，注意下删除操作

② 性质：**中序遍历序列是有序递增的**（因此给一组数据，排序之后可以中序建树）

③ 完全二叉查找树：既拥有完全二叉树的性质也有二叉搜索树的性质，考到的话往往两种树的性质结合起来解题

④ 关于删除操作：目前没考过，考到的话分四种情况递归，具体看相关资料，不赘述

#### 5.平衡二叉树（AVL）

① 定义：一种特殊的**二叉查找树**

② 性质：有BST的全部性质，同时是平衡的，即平衡因子（左右子树高度差）的绝对值不超过1

③ 对于AVL的考查全部套模板即可解决，而且模板完全固定，模板代码要在理解的基础上背熟并能快速写出来，注意左旋右旋和插入都要加引用，如下

```c++
//平衡二叉树AVL的固定模板
//结构体
struct Node {
    int v;
    int height; //记得增加height变量
    int lchild, rchild;
} node[maxn];
//获得高度
int getHeight(int root) {
    if(root == -1)
        return 0;
    return node[root].height;
}
//获得平衡因子
int getBalanceFactor(int root) {
    return getHeight(node[root].lchild) - getHeight(node[root].rchild); //左子树减右子树高度
}
//更新高度
void updateHeight(int root) {
    node[root].height = max(getHeight(node[root].lchild), getHeight(node[root].rchild)) + 1; //左右子树高度的最大值加1
}
//左旋
int L(int &root) { //右子树高了需要左旋，所以左旋取出的是右孩子
    int temp = node[root].rchild;
    node[root].rchild = node[temp].lchild;
    node[temp].lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
//右旋
int R(int &root) { //左子树高了需要右旋，所以右旋取出的是左孩子
    int temp = node[root].lchild;
    node[root].lchild = node[temp].rchild;
    node[temp].rchild = root;
    updateHeight(root);
    updateHegint(temp);
    root = temp;
}
//插入（重点）
int index = 0;
void insert(int &root, int v) {
    if(root == -1) {
        node[index].v = v;
        node[index].height = 1; //高度别忘了初始化为1
        node[index].lchild = node[index].rchild = -1;
        root = index++;
        return;
    }
    if(v < node[root].v) { //根据BST的插入，小于时插入左子树
        insert(node[root].lchild, v);
        updateHeight(root); //一定要在插入到子树之后及时更新高度
        if(getBalanceFactor(root) == 2) { //因为插入到左子树，左子树变高，根结点平衡因子只能为2
            if(getBalanceFactor(node[root].lchild) == 1) { // 2 1 为LL型，右旋一次root即可
                R(root);
            } else if(getBalanceFactor(node[root].lchild) == -1) { // 2 -1 为LR型，先左旋一次左子树，再右旋一次根结点
                L(node[root].lchild);
                R(root);
            }
        }
    } else { //否则插入右子树，这里一定要写else，保证等于的情况也在右子树
        insert(node[root].rchild, v);
        updateHeight(root);
        if(getBalanceFactor(root) == -2) {
            if(getBalanceFactor(node[root].rchild) == -1) { // -2 -1 为RR型，左旋一次root即可
                L(root);
            } else if(getBalanceFactor(node[root].rchild) == 1) { // -2 1为RL型，先右旋一次右子树，再左旋一次根结点
                R(node[root].rchild);
                L(root);
            }
        }
    }
}
```

#### 6.并查集

① 定义：集合，支持合并和查找操作，用一个数组`int father[n]`表示

② 性质：对同一个集合来说只存在一个根结点，且将其作为所属集合的标识

③ 并查集也有模板代码，但不是完全固定，要结合题意适当修改灵活处理，往往需要一个`bool isRoot[n]`用来标记每个结点是否为某个集合的根结点，用于统计集合数目，如果需要**记录每个集合的结点数目**则改为int型，`isRoot[findFather[i]]++`即可；如果涉及到考查每个结点的父亲结点（一般不会），不可以用路径压缩；一定要想清楚合并的条件是什么，然后直接当作集合去合并，模板写好就不用考虑实现的细节，模板如下

```c++
//并查集模板
int father[maxn];
bool isRoot[maxn]; //如若使用也需要初始化
//初始化（这步千万别忘了在main函数调用）
void init(int n) {
    for(int i = i; i <= n; i++) {
        father[i] = 1;
        isRoot[i] = false; //如果需要
    }
}
//查找（路径压缩版本，如不需要路径压缩只写第一个while循环return x即可）
int findRoot(int x) {
    int y = x;
    while(x != father[x]) { //找根结点
        x = father[x];
    }
    while(y != father[y]) { //路径压缩
        int z = y;
        y = father[y];
        father[z] = x;
    }
    return x;
}
//合并
void Union(int a, int b) {
    int ra = findRoot(a);
    int rb = findRoot(b);
    if(ra != rb) {
        father[ra] = rb;
    }
}
//一顿操作读取数据合并处理之后，记得处理isRoot[]，以统计集合结点数目为例
for(int i = 1; i <= n; i++) {
    isRoot[findRoot(i)]++;
}
```

#### 7.堆（heap）

① 定义：一种特殊的**完全二叉树**

② 性质：有CBT的全部性质，树中每个结点的值都不小于（或不大于）其左右孩子结点的值为大顶堆（小顶堆）

③ 模板固定，理解的基础上背熟，以大顶堆，从小到大做堆排序为例（要能仿照写出相应的小顶堆），如下

```c++
//堆
int heap[maxn], n;
//对heap数组在[low,high]范围内向下调整（用于建堆、删除、堆排序）
//其中low为欲调整结点的数组下标，high一般为堆的最后一个元素的数组下标
void downAdjust(int low, int high) {
    int i = low, j = i * 2; //i为欲调整结点，j为其左孩子
    while(j <= high) { //存在孩子结点
        if(j + 1 <= high && heap[j + 1] > heap[j]) { //如果右孩子存在且右孩子的值大于左孩子
            j = j + 1; //让j存储右孩子下标
        }
        if(heap[j] > heap[i]) { //如果孩子中最大的权值比欲调整结点i大
            swap(heap[i], heap[j]); //交换权值
            i = j; //保持i为欲调整结点
            j = i * 2; //j为i的左孩子
        } else {
            break; //孩子的权值均比欲调整结点i小，结束循环
        }
    }
}
//对heap数组在[low,high]范围内向上调整（用于插入）
//其中low一般设置为1，high为欲调整结点的数组下标，与向下调整相反
void upAdjust(int low, int high) {
    int i = high, j = i / 2;
    while(j >= low) { //只能有一个父亲，所以没有向下调整那个判断
        if(heap[j] < heap[i]) { //如果父亲权值小于欲调整结点i的权值
            swap(heap[i], heap[j]);
            i = j; //保持i为欲调整结点
            j = i / 2;
        } else {
            break; //别忘了跳出循环
        }
    }
}
//建堆
void createHeap() {
    for(int i = n / 2; i >= 1; i--) { // n/2为最后一个非叶子结点，根据算法导论，倒着枚举
        downAdjust(i, n); //对i到n进行向下调整
    }
}
//删除堆顶元素
void deleteTop() {
    heap[1] = heap[n--]; //用最后一个元素覆盖堆顶元素并让元素个数减1
    downAdjust(1, n); //然后进行一次从1到n的向下调整
}
//插入
void insert(int x) {
    heap[++n] = x; //元素个数加1并将堆的最后一个位置赋值为x
    upAdjust(1, n); //然后记性一次从1到n的向上调整
}
//堆排序
void heapSort() {
    createHeap(); //先建堆
    for(int i = n; i > 1; i--) { //倒着枚举直到堆中只有一个元素
        swap(heap[1], heap[i]); //交换堆顶与heap[i]
        downAdjust(1, i - 1); //调整堆顶
    }
}
```

#### 8.哈夫曼树（最优二叉树）

没考过，应该不考，只学习了合并果子问题，大概代码如下

```c++
//策略就是反复选择最小的两个元素合并，直到只剩下一个元素，简单看一下一般优先队列的使用即可
priority_queue<int, vector<int>, greater<int> > q; //greater:数字越小优先级越高，从小到大排

scanf("%d", &n);
for(int i = 0; i < n; i++) {
    scanf("%d", &temp);
    q.push(temp);
}
while(q.size() > 1) {
    x = q.top();
    q.pop();
    y = q.top();
    q.pop();
    q.push(x + y);
    ans += x + y; //ans即为所求
}
```


<div STYLE="page-break-after: always;"></div>
## 九.图

#### 1.图论

① 图的存储方式：邻接矩阵`int g[maxn][maxn]; int weight[maxn];`，其中weight为点权

　　　　　　　　 和邻接表`vector<Node> Adj[maxn]`，其中Node包括边的终点编号v和边权w

　　　　　　　　 顶点数目较大（一般个数在1000个以上）时用邻接表（务必，两分也是分，得要）

　　　　　　　　稀疏图用邻接表，稠密图用邻接矩阵

② 常考概念题，没有固定模板，理解题意不行暴力，去ANOJ上做那个专题多练习

#### 2.图的遍历

① DFS：基本模板固定，需要结合题意适当修改，如下

```c++
void DFS(int u) { //如果需要统计其他数据可以修改参数（引用），或者使用全局变量
    vis[u] = true;
    //如果需要对u进行一些操作，可以在这里进行
    for(u能到达的所有顶点v) {
        if(vis[v] == flase)
            DFS(v);
    }
}
void DFSTrave() { //若给定图为连通图则只需DFS一次，否则就需要遍历每个连通块（所有顶点）
    for(图的所有顶点u) {
        if(vis[u] == false)
            DFS(u); //这里可以顺便统计连通块个数和其他需要的信息
    }
}
```

② BFS：和普通BFS模板完全一致，若需要输出顶点层号，简单修改即可，基本模板如下

```c++
void BFS(int u) {
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while(!q.empty()) {
        int u = q.front();
        //操作
        q.pop();
        for(u能到达的所有顶点v) {
            if(inq[v] == false) {
                q.push(v);
                inq[v] = true; //别忘了标记已入队
            }
        }
    }
}
void BFSTrave() { //若给定图为连通图则只需BFS一次，否则就需要遍历每个连通块（所有顶点）
    for(图的所有顶点u) {
        if(inq[u] == false)
            BFS(u); //这里可以顺便统计连通块个数和其他需要的信息
    }
}
```

**关于DFS和BFS的简单小结：**至此一共三种情况，如下

① 常规DFS：`void DFS(int index,统计量)`，选定好递归参数(当前序号和统计量)，写**死胡同**和**岔路口**

​     常规BFS：模板固定，注意需要标记入队出队`bool inq[maxn];`

② 树的先根遍历DFS：和常规DFS类似，但模板更为固定，递归边界即孩子结点个数为0，递归式即对

　　　　　　　　　　所有子结点进行递归，其间可进行操作获得其他统计量

​     树的层序遍历BFS：和常规BFS相同，区别是不用标记入队出队（二叉树的层序遍历也是如此，唯一区
　　　　　　　　　　别是只有两个孩子结点入队）

③ 图的遍历DFS：和常规DFS不同，模板固定，标记结点是否访问，访问所有可达的未访问结点，其间可进行操作

​     图的遍历BFS：和常规BFS相同，需要标记入队出队

总的来说，DFS就是由一个当前序号出发去尽量遍历每一个结点，在遍历的过程中根据题意进行操作获得题目所要求的统计量，而BFS更加突出层次，模板较为固定，总之理解算法思想，灵活处理即可

#### 3.最短路径（Dijkstra+DFS）

① 一般考法：距离为第一标尺，然后会附加点权或边权为第二标尺，求第二标尺最优的最短路径

先用Dijkstra算法求出最短距离解决第一标尺，然后用DFS解决第二标尺，模板如下

```c++
//最短路径（以邻接矩阵为例）
const int inf = 100000000;
int g[maxn][maxn];
int d[maxn]; //距起点的距离
bool vis[maxn] = {false};
vector<int> pre[maxn]; //最短路径上每个结点的前驱结点
//别忘了调用算法前将图初始化
main() { fill(g[0], g[0] + maxn * maxn, inf); }
//使用Dijkstra算法记录所有最短路径（完全固定）
void Dijkstra(int s) { //起点
    fill(d, d + maxn, inf);
    d[s] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, min = inf;
        for(int j = 0; j < n; j++) {
            if(vis[j] == false && d[j] < min) {
                u = j;
                min = d[j];
            }
        }
        if(u == -1)
            return;
        vis[u] = true;
        for(int v = 0; v < n; v++) {
            if(vis[v] == false && g[u][v] != inf) {
                if(d[u] + g[u][v] < d[v]) {
                    d[v] = d[u] + g[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(d[u] + g[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
//遍历所有最短路径，找出一条使第二标尺最优的路径（第一标尺为距离，上一步已确定）
int optValue;
vector<int> path, tempPath; //最优路径、临时路径
void DFS(int v) { //当前访问结点（从终点开始）
    if(v == st) { //递归边界
        tempPath.push_back(v);
        int value = 0;
        计算路径tempPath上的value值;
        if(value优于optValue) {
            optValue = value;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    //递归式
    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++)
        DFS(pre[v][i]);
    tempPath.pop_back();
}
//填充DFS的value计算部分
//边权
for(int i = tempPath.size() - 1; i > 0; i--) {
    int id = tempPath[i], nextid = tempPath[i - 1];
    value += v[id][idnext];
}
//点权
for(int i = tempPath.size() - 1; i >= 0; i--) {
    int id = tempPath[i];
    value += v[id];
}
//路径条数
开一个全局变量num，DFS到达叶子结点时令全局变量加1即可
//打印路径
for(int i = path.size() - 1; i >= 0; i--) { //注意逆序输出
    printf("%d", path[i]);
}
```

② 没有第二标尺的问题：距离为第一标尺,没有第二标尺,然后根据平均距离等条件判断选择最优路径

此类题只需用Dijkstra(模板不变)求出最短距离，不用写DFS，直接在main函数计算要求量进行比较即可

③ 未考过的简单问题：距离为第一标尺,没有第二标尺,只考最短路径,但有一条或多条路径并需要打印

Dijkstra不变，简单修改DFS即可（减少计算部分，直接打印路径），如下

```c++
//对于有多条最短路径但没有第二标尺且需要打印路径的情况，修改DFS
void DFS(int v) { //当前访问结点（从终点开始）
    if(v == st) { //递归边界
        path.push_back(v);
        打印路径;
        path.pop_back();
        return;
    }
    //递归式
    path.push_back(v);
    for(int i = 0; i < pre[v].size(); i++)
        DFS(pre[v][i]);
    path.pop_back();
}
```

注意：考试时看清题目给的下标，修改循环条件里的变量

#### 4.最小生成树（MST）

没考过，简单了解下，求MST的权值，使用prim算法，模板与Dijkstra基本相同，如下

```c++
//用prim算法解决最小生成树（与Dijkstra不同的地方已添加注释，只看这几处就可以）
int prim(int s) {
    fill(d, d + maxn, inf);
    d[s] = 0;
    int ans = 0; //存放最小生成树的边权之和
    for(int i = 0; i < n; i++) {
        int u = -1, min = inf;
        for(int j = 0; j < n; j++) {
            if(vis[j] == false && d[j] < min) {
                u = j;
                min = d[j];
            }
        }
        if(u == -1)
            return;
        vis[u] = true;
        ans += d[u]; //将与集合距离最小的边加入最小生成树
        for(int v = 0; v < n; v++) {
            //判断条件加上 以u为中介点可以使v离集合更近
            if(vis[v] == false && g[u][v] != inf && g[u][v] < d[v]) {
                d[v] = g[u][v]; //将g[u][v]赋值给d[v]
            }
        }
    }
    return ans;
}
```

#### 5.拓扑排序

判断一个给定的图是否为有向无环图（DAG），主要思想是用一个队列，把所有入度为0的结点入队，然后取队首结点，输出，删边，并令这些边到达的顶点的入度减1，若减为0，将顶点入队，不断重复这一步骤，直至队列为空，如果队列为空时入过队的结点数目恰好为n，则拓扑排序成功，图为有向无环图，理解即可，模板如下

```c++
//拓扑排序
vector<int> adj[maxn]; //用邻接表存储
int indegree[maxn];
bool topSort() {
    int num = 0; //记录加入拓扑序列的顶点数
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty()) {
        int u = q.front();
        //printf("%d", u); //这里可以输出
        q.pop();
        num++; //加入拓扑序列的顶点数加
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i]; //u的后继结点v
            indegree[v]--; //v的入度减1
            if(indegree[v] == 0)
                q.push(v); //v的入度为0则入队
        }
        adj[u].clear(); //清空顶点u的所有出边（如无必要可不写）
    }
    if(num == n)
        return true;
    else
        return false;
}
```

#### 6.关键路径

使用动态规划解决问题，求DAG最长路，即权值之和最大的路径，也就是关键路径

**① 求整个DAG中的最长路径（不固定起点和终点）**

令状态dp[i]表示从i号顶点出发能到达的最大长度

状态转移方程为**dp[i] = max{dp[j] + g[i] [j]}**，j为i的所有可到达的点

边界为出度为0的顶点的dp值为0，具体实现时可以将整个dp数组初始化为0

按照逆拓扑序列的顺序求解dp数组，用一个choice数组记录最长路径上顶点的后继顶点，模板如下

```c++
//求整个DAG中的最长路径（不固定起点和终点）
int dp[maxn], choice[maxn];
//求解dp数组
int DP(int i) {
    if(dp[i] > 0)
        return dp[i]; //如果dp[i]已经计算得到，直接返回
    for(int j = 0; j < n; j++) { //遍历i的所有出边
        if(g[i][j] != inf) {
            int temp = dp[j] + g[i][j];
            if(temp > dp[i]) {
                dp[i] = temp;
                choice[i] = j;
            }
        }
    }
    return dp[i];
}
//调用printPath前需要先得到最大的dp[i]，然后i作为路径起点传入
void printPath(int i) {
    printf("%d", i);
    while(choice[i] != -1) { //choice数组初始化为-1
        i = choice[i];
        printf("->%d", i);
    }
}

```

**② 固定终点，求DAG的最长路径长度**

只需将边界修改为终点的dp值为0，具体实现时可以将整个dp数组初始化为-inf，然后单独修改终点的dp值，然后设置一个vis数组表示顶点是否已被计算，模板如下

```c++
//求固定终点的DAG最长路径
bool vis[maxn];
fill(dp, dp + maxn, -inf);
dp[ed] = 0;
int DP(int i) {
    if(vis[i])
        return dp[i];
    vis[i] = true;
    for(int j = 0; j < n; j++) {
        if(g[i][j] != inf) {
            dp[i] = max(dp[i], DP(j) + g[i][j]);
        }
    }
    return dp[i];
}
```


<div STYLE="page-break-after: always;"></div>
## 十.其他算法

#### 1.贪心

我也不知道贪心的题怎么做，虽然说是找局部最优解，但感觉就是模拟，想得到就能做，想不到就做不对，刷完PAT上出过的贪心题，唯一的一点点收获就是有道题用pos[num]表示位置，用预处理变量控制循环，别的没什么，贪心也不是重要考点，大致就这样吧。



#### 2.二分

① 主要用于解决“**寻找有序序列中第一个满足某条件的元素的位置**”问题，所谓的“某条件”在序列中一定是从左到右先不满足，然后满足的（否则把该条件取反即可），固定模板如下

```c++
//二分区间为左闭右闭的[left,right]，初值必须能覆盖解的所有可能取值（传入的初值应该为[0,n]）
int solve(int left, int right) {
    int mid; //mid为left和right的中点
    while(left < right) { //对[left,right]来说，left==right意味着找到唯一位置
        mid = (left + right) / 2; //取中点
        if(条件成立) { //条件成立，第一个满足条件的元素的位置<=mid
            right = mid; //往左子区间[left,mid]查找
        } else { //条件不成立，则第一个满足条件的元素的位置>mid
            left = mid + 1; //往右子区间[mid+1,right]查找
        }
    }
    return left; //返回夹出来的位置
}
//如果是while(left<=right)，那么则right=mid-1,left=mid+1

//如果找最后一个满足”条件C“的元素的位置，则先求第一个满足“条件!C”的元素的位置，然后将该位置减1即为所求

//主要理解二分的思想，这个模板要理解，灵活处理，尤其是循环部分，上述模板是一定存在要找的值
//可能找不到的时候循环条件要写成if{} else if{} else{}，找到直接return，循环结束则说明没找到，参考PAT A1010
```

② 如果是寻找数值，则可以用STL中的lower_bound()和upper_bound()代替，如下

```c++
lower_bound(first, last, val); //在数组或容器的[fist,last)范围内寻找第一个大于等于val的元素的位置
upper_bound(first, last, val); //在数组或容器的[fist,last)范围内寻找第一个大于val的元素的位置

int a[10] = {1, 2, 2, 3, 3, 3, 4, 4, 5, 5};
int pos = lower_bound(a, a + 10, 1) - a; //找到的元素的数组下标
```

③ 二分法其他应用，诸如求单调函数f(x)=0的近似值、装水问题和木棒切割问题等，同理，不过区间变换改为`right=mid`和`left=mid`，其他相同，不赘述。



#### 3.快速幂（没考过，且只有一种题型，考前随缘）

求解a^b%m，模板如下

```c++
//快速幂 求a^b%m 递归写法
typedef long long LL;
LL binaryPow(LL a, LL b, LL m) {
    if(b == 0)
        return 1; //如果b为0，那么a^0=1
    if(b % 2 == 1) //b为奇数，转换为b-1
        return a * binaryPow(a, b - 1, m) % m;
    else { //b为偶数，转换为b/2
        LL mul = binaryPow(a, b / 2, m);
        return mul * mul % m;
    }
}
```



#### 4.two pointers

同样用于处理有序序列，利用问题本身与序列的特性，使用两个下标i、j对序列进行扫描（可以同向也可以反向）解决问题。



#### 5.经典排序算法

以下算法均以数组下标[0,n-1]为例

```c++
//插入排序
void insertSort(int a[]) {
    //n-1趟排序
    for(int i = 1; i <= n - 1; i++) {
        int temp = a[i], j = i;
        while(j > 0 && temp < a[j - 1]) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
    }
}
//另外插入排序也可以用sort替代
void insertSort(int a[]) {
    for(int i = 1; i <= n - 1; i++) {
        sort(a, a + i + 1); //左闭右开区间
    }
}
```

```c++
//归并排序
void mergeSort(int a[]) {
    for(int step = 2; step / 2 <= n; step *= 2) {
        for(int i = 0; i < n; i += step) {
            sort(a + i, a + min(i + step, n));
        }
    }
}
```



#### 6.动态规划（DP）

“子序列”可以不连续，“子串”必须连续

**① 最大连续子列和**

状态dp[i]：以A[i]作为末尾的连续序列的最大和

状态转移方程：**dp[i] = max{A[i], dp[i-1] + A[i]}**

边界：**dp[0] = A[0]**

**② 最长不下降子列（LIS）**

状态dp[i]：以A[i]结尾的最长不下降（非递减）子序列长度

状态转移方程：**dp[i] = max{1, dp[j] + 1} ( j=1,2,...,i-1 && A[j]<=A[i] )**

边界：**dp[i] = 1**

**③ 最长公共子序列（LCS）**

状态dp[i] [j]：字符串A的i号位和字符串B的j号位之前的LCS长度（下标从1开始）

状态转移方程：**dp[i] [j] = dp[i-1] [j-1] + 1 (A[i]==B[j])**

　　　　　　　或 **= max{dp[i-1] [j], d[i] [j-1]} (A[i]!=B[j])**

边界：**dp[i] [0] = dp [0] [j] = 0 (0≤i≤n, 0≤j≤n)**

**④ 最长回文子串**

状态dp[i] [j]：S[i]至S[j]所表示的子串是否为回文子串，是则为1，不是为0

状态转移方程：**dp[i] [j] = dp[i+1] [j-1] (S[i]==S[j])**

　　　　　　　或 **= 0 (S[i]!=S[j])**

边界：**dp[i] [i] = 1, dp[i] [i+1] = (S[i]==S[i] [i+1])? 1:0**

**⑤ DAG最长路（关键路径）**

见“图 关键路径”

**⑥ 背包问题**

01背包问题：状态dp[i] [v]：前 i (1≤i≤n, 0≤v≤V)件物品恰好装入容量为v的背包中所能获得的最大价值

　　　　　　状态转移方程：**dp[i] [v] = max{dp[i-1] [v], dp[i-1] [v-w[i]] + c[i]} (1≤i≤n, w[i]≤v≤V)**

　　　　　　边界：**dp[0] [v] = 0 (0≤v≤V)**

　　　　　　优化：**dp[v] = max{dp[v], dp[v-w[i]] + c[i]} (1≤i≤n, w[i]≤v≤V)**

　　　　　　　　　 **dp[v] = 0 (0≤v≤V)**    务必**逆向**枚举（外循环：i从1到n，内循环：v从V到w[i]）

完全背包问题：和01背包问题的唯一区别是物品数量每种有无穷件

　　　　　　　一维形式的状态转移方程和01背包相同

　　　　　　　 唯一区别是枚举方向不同，因此直接给出优化版本的状态转移方程，如下

　　　　　　　 **dp[v] = max{dp[v], dp[v-w[i]] + c[i]} (1≤i≤n, w[i]≤v≤V)**

　　　　　　　**dp[v] = 0 (0≤v≤V)**    务必**正向**枚举（外循环：i从1到n，内循环：v从w[i]到V）



#### 7.分块思想

开两个hash数组，`int block[maxb]; int h[maxn];`

若元素为0-10^5，则maxb=sqrt(100001)，maxn=100010

从而block[i]表示第i块中的元素个数，x/maxb表示数字x在的块号，h[x]表示数字x的存在个数

求第k大的数，设sum变量，sum+=block[numb++]找到块号，num=maxb*numb，sum+=h[num++]找到数字



#### 8.一些小技巧

① 打表（空间换时间）：1> 一次性计算出所有需要用到的结果，之后的查询直接取这些结果

　　　　　　　　　　　 2> 在程序B中计算所有用到的结果，手工把结果写在程序A的数组中，在A中

　　　　　　　　　　　　　直接使用

② 对一些感觉不会做的题目，可以先用暴力程序计算小范围数据的结果然后找规律，适用于数据范围非

常大的题

③ 递推：比如涉及序列的题，假如序列的每一位所需要计算的值都可以通过该位左右两侧的结果计算得

到，那么就可以考虑所谓的“左右两侧的结果”能否通过递推进行预处理来得到，从而降低时间复杂度
