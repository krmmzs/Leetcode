# clang

因为熟悉了C++, 需要和C进行对照来准备科软机试

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
