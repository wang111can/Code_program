# 1 、 常见指令

> <img src="attachment:063c96e951c72cc06e7982ed4e3becef" alt="20220711_Linux基本指令1.png" style="zoom:50%;" />
> 
> ![20220713_基本指令2.png](attachment:5459e93eacabb74b1e98be7e00058e4c)
> 
> ** == ls == ** ** ： 对于目录， 该命令列出目录下所有子目录与文件。 **
> 
> 			** 对于文件， 将列出文件名以及其他信息 **

<br/>

![截图](attachment:45e6a380d8e6694aec0b9139669a36a9)

- -i 是inode 编号

- ls  ./*  显示联想 文件 

   *是一种通配结构

== ** pwd** == ** : 显示当前我所处的路径**

<br/>

<br/>

<br/>

	==**touch**== **:在当前路径下创建一个 普通文件 **

- $ 文件 == 内容数据 + 属性数据    $ 、

- 隐藏 文件/目录  可以 使该文件 以 ** . ** 开头

> ** touch 同名文件 ---> 更新文件的最近修改 / (创建时间)时间 **
> 
> <br/>
> 
> 访问时间 Access: 2022-07-13 20:37:56.141251654 +0800
> 
> Modify: 2022-07-13 20:37:56.141251654 +0800
> 
> Change: 2022-07-13 20:37:56.141251654 +0800
> 
> <br/>

<br/>

<br/>

<br/>

	==**mkidr**== **:在当前路径下创建一个目录（文件夹）** 

> mkdir -p 创建 一串路径 
> 
> ** tree ** 树形显示路径

	** yum install -y tree ** 安装tree

	== ** rmdir    /  rm**==  ** 删除文件 ** 

> rm -r 递归删除目录 

> rm -r -f 强制递归删除
> 
> rm -i  提示我 确认删除
> 
> <br/>

<br/>

	==**cd**== **：进入一个路径**

- cd .   	当前路径 ---> 限定我们要执行的文件的路径 
- cd ..  	直接上级路径 ---> 进行路径切换
- cd - 		切换到上一次在的路径
- cd ~   	到家目录
- cd / 		到根目录

<br/>

<br/>

	## man 指令

- **根据指令显示使用手册 ** 

<br/>

## cp 指令

- 语法 
  
  	cp [选项] 源文件或目录 目标文件或目录
  
  ** 功能** 复制文件或目录
  
   ![截图](attachment:1800647bb65edd2a6c9169baf83b88f4)
  
  ![截图](attachment:3a664cc0f06b680bb3c7f68c06c16187)

		cp -rf .... 拷贝 一个目录

<br/>

## mv

- <u>移动 （剪切）</u>
- 改名 
  
  ***
- mv 当前文件   改名文件

<br/>

## cat

打印文件内容

<br/>

## head  tail    -number

> 提取文本文件的 前  ...... 行

> 提取文本文件的 后 ....... 行

> 提取文本文件指定区间的 ...... 行 

** ‘ | ’ **  管道

<img src="attachment:354ae35008900e6fa86705862612c81f" alt="截图" style="zoom:50%;" />

 (入口)  |  (出口)   

<br/>

## date  cal

获取时间    显示日历

<br/>

# == find == 

** find  (目录) -name (名字) ** 

<br/>

<br/>

*** 

![截图](attachment:82ff7676d1c7e5df671384ee84231f36)

== ** Which ** == :  找到可执行程序的路径

 == ** whereis ** == : 查找所有带有关键字的路径

== ** alias ** == : 给命令起别名

<br/>

== ** grep** == :  文本内关键字 搜索 (行文本过滤)

grep -n 显示行号

grep -v 反向匹配 (排除关键字搜索)

grep -i 忽略大小写搜索 search

<br/>

***

# <u> 打包压缩</u>

<br/>

> zip -r name.zip 目录

unzip name.zip 当前目录

unzip name.zip -d 指定目录

<br/>

> tar

<img src="attachment:c90a76488fa737aa474ee7f18b9ff495" alt="截图" style="zoom:50%;" />

<br/>

打包并压缩

![截图](attachment:6feda7e2fb28bdcf877cd061cf5c6030)

解压

![截图](attachment:02fcb3f4ec31a41330941776f63cfa57)

指定路径

![截图](attachment:9187d886ae48b5ac339a736820b660c1)

<br/>

<br/>

<br/>

uname -a 显示linux 结构

uname -r 显示linux 版本