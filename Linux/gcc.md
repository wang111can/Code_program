# GCC / G++ 

### 编译选项
1. -o \[file_name\] <br>
   > 将 gcc/g++ 生成的文件写入 file name <br>
2. -E <br>
   >  进行 预处理 <br>
3. -S <br>
   > 进行编译 编译为 汇编语言<br>
4. -c <br>
   > 翻译为 二进制文件 (可重定位 二进制 目标文件)<br> 

5. -I + 指定路径 <br>
   > 指定 头文件的 搜索路径 <br>

6. -L + 指定路径 <br>
   > 指定链接lib路径 <br>

7. -l + 库名称 <br>
   > 指定的lib 路径下的 指定库名称 <br>

8. -fPIC <br>
   > 生成动态库 -o 文件 必加 选项



### 动静态库
*** 

<br>

> #### 动态链接
> 将库中方法的 地址 填入 可执行程序中 <br>
> #### 静态链接
> -static <br>
> 将库中的 方法拷贝到 可执行程序中 <br>
**gcc/g++形成的可执行程序默认是动态链接的** 

<br>

*** 
# MakeFile
``` 
[target_name]: dependent file // 依赖关系
   dependent method // 依赖方法

```
> \[make\] 执行文件 <br>


