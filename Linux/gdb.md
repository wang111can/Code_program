# gdb

*** 


<br>
<br>
<br>

1. 进入 gdb 条件: 由于gcc/g++ 默认 生成可执行文件为 release 版本， 进入 gdb 需要debug 版本， 需要 在 gcc/g++ 加-g 选项 <br>
2. 进入 gdb: gdb \[file_name\] <br>
3. 指令:  <br>
    > l + number 查看代码从第 number 行 <br>
    > quit 退出 <br>
    > r 开始调试 <br>
    > b + line_number 在指定行加断点 <br>
    > info b 查看断点信息 <br>
    > d + break_point_number 删除断点 <br>
    > disable + break_point_number 暂时关闭断点 <br>
    > enable + break_point_number 打开段点 <br>
    > n 逐过程 (不进入函数调用 等) <br>
    > s 逐语句 (进入函数调用 等) <br>
    > until + line_number 执行到 指定行
    > finish 完成 当前 函数 的执行 <br>
    > display + 变量 常显示 变量 <br>
    > undisplay + display_number 取消常显示 <br>
    > c  跳转到下一个断点处
    > p + value 查看变量内容 <br>
    > bt 查看当前调用堆栈
