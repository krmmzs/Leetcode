# clang

因为熟悉了C++, 需要和C进行对照来准备科软机试

## C动态分配

写leetcode用c最大的难点是如何精准处理最小的空间

---

### 一些条件反射

- `int* returnSize, int** returnColumnSizes`, 前者是返回的二维数组的行数, 后者是每行多少列的数组
    - 其中需要注意`(*returnColumnSizes)[res_sz ++] = ?`必须要加上括号

- malloc一个空间以后要条件反射给值初始化
    - malloc一个链表以后要手动初始化val和next
    - malloc一个?*, 最好初始化为NULL, 比如: 
        ```c
        // 分配一个struct TreeNode*的空间, 如何初始化为NULL
        dfs(...) {
            if (l > r) {
                int res_sz = 0;
                struct TreeNode** res = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
                res[res_sz ++] = NULL;
                *returnSize = res_sz;
                return res;
            }
            ...
        }
        ```

### malloc(0)

malloc(0)在处理树这样有空指针的时候非常安全, 根据[malloc man](https://pubs.opengroup.org/onlinepubs/009695399/functions/malloc.html)可分配一个null pointer但是又给可以直接被free接受并不会报错

### remalloc(res, sizeof(...))

在树的应用非常多, 能够极大地控制空间不会浪费

## 字符串

- c++中的string s `s >= "1" && s <= "26`使用c的时候建议是不要用string的思路, 而是转而去转化为int, `(s[0] - '0') * 10 + s[1] - '0'就可以实现string to int`

### strncpy

- [cplusplus strncpy](https://cplusplus.com/reference/cstring/strncpy/)

- 将源字符串的前 num 个字符复制到目标字符串。如果在复制完 num 个字符之前发现源 C 字符串已结束（空字符表示结束），**则将用零填充目标字符串**，直到总共写入 num 个字符。
    - **意思是当strncpy(des, src, num), num <= strlen(src)则会在结尾填上\0**
- 如果源字符串长度超过 num，则不会在目标字符串末尾隐式添加空字符。因此，在这种情况下，不应将目标字符串视为以空字符结束的 C 字符串（这样读取会溢出）。
    - **意思是num > strlen(src)的时候需要手动加上\0才能表示字符串**
- 目标字符串和源字符串不得重叠（重叠时更安全的替代方法参见 memmove）。
- **应试的时候拿不准就全部手动: t[strlen(?)] = '\0';即可**

## C的一些函数

- `?.size()` to `strlen(char* s)`(只能是char*类型的字符串(字符数组结尾是\n的))
- fmax和max

## 链表

将`ListNode*`前面都添上`struct`

将
```c++
new ListNode(?)
```
需要都手动初始化
```c
struct ListNode* cur =  malloc(sizeof(struct ListNode));
cur->val = ?
cur->next = NULL;
```

## 手写哈希表

## 字符哈希<char, int>

`unordered_map<char, int> hash;` to `int hash[128] = {0};`(0-127可以包括所有字符了)
`max` to `fmax`(这个不知道为什么会报错, 得使用fmax...)

## c的DFS

### 将path添加到res结尾

```c

char** res;
int res_sz;
char path[20];

dfs(...) {
    if (...) {
        char t[40];
        strncpy(t, path, strlen(path));
        // t[strlen(path) - 1] = '\0'; (这是本题的代码)
        res[res_sz] = (char*)malloc(strlen(path) + 1); // +1 是为了给'\0'空间
        strcpy(res[res_sz], t);
        res_sz ++;
        return;    
    }
}
```

## c的树

### 空节点

比较特殊, 会有一个`TreeNode*`的空间, 但是赋值`NULL`(实际上通常是0, 这个看编译器)

```c
struct TreeNode** dfs(int l, int r, int* returnSize) {
    if (l > r) {
        int res_sz = 0;
        struct TreeNode** res = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        res[res_sz ++] = NULL;
        *returnSize = res_sz;
        return res;
    }

...
```
