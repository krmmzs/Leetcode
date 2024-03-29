# clang

因为熟悉了C++, 需要和C进行对照来准备科软机试

## 字符串

- c++中的string s `s >= "1" && s <= "26`使用c的时候建议是不要用string的思路, 而是转而去转化为int, `(s[0] - '0') * 10 + s[1] - '0'就可以实现string to int`

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
