# Tips

## STL

- create Min stl priority_queue
    - [How can I create Min stl priority_queue?](https://stackoverflow.com/questions/2439283/how-can-i-create-min-stl-priority-queue)

## Index

- index伴随的循环**一定要有个边界**
    - 边界加上一定不会出错(就算当确定不会越界也不会有代码上的错误)

## 括号

- 一个合法的括号序列(只有一类括号, 比如只有小括号)需要满足两个条件：
    - 任意前缀中左括号数量 >= 右括号数量 （也就是说每一个右括号总能找到相匹配的左括号）
    - 左右括号数量相等
