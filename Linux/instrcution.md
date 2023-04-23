# Instructions in Linux


### pwd 

> 查看 当前 目录 相对于 根 路径 的 绝对 路径<br/>
### ls 

> 显示 当前 路径 下 的 文件名 <br/>
> ls -l 显示额外的属性 <br/>
> ls -a 显示隐藏文件 <br/>
> ls -i 查看文件 i(每个文件唯一编号) <br/> 
> ls -s 显示文件大小 <br/>
### touch 

> 创建一个 普通文件 <br/>
### mkdir
> 创建一个 目录/文件夹 <br/>

### cd - 
> 跳转至 上次 所在 目录 <br>

### touch 
> 创建 一个 空文件 或者 修改文档或目录的日期 时间 (存取 读取) <br>

### mkdir
> mkdir [选项] dirname <br>
> 在当前路径下 创建 一个名为 dirname 的 目录 <br>


### stat filename
> * access 最后访问时间 <br>
> * modify 最后修改时间(不包括修改文件属性) <br>
> * change 最后修改时间(包括修改文件属性) <br>


### cp 
> cp [filename] [target path] <br>

### more
> 显示文件内容 充满整个屏幕 <br>

### less
> less [file name] 显示文件内容<br>

### head
> head \[-要求显示的行数\] \[filename\] 从头开始显示 <br>

### tail 
>tail \[-要求显示的行数\] \[filename\] 从尾开始显示 <br>

### date +%s 
> 时间戳 <br>

## find 
> find \[路径\] -name \[文件名\] 搜索相关文件所在目录 <br>

### which 
> 在系统路径中 查找特定的指令所在的 路径

### grep
> grep "string" filename 查找并输出 指定 file 里包含 string 的 文本信息 <br>
> -n 显示行号 <br>
> -v 不显示 包含 "string" 的行 <br>
> -i 忽略大小写 <br>


### xargs
> 将字符串 转换为 命令行 参数 <br>
> xargs instruction <br>

### ctrl + c
> 终止前端进程 <br>

### uname 
> 查看 linux 系统信息 <br>
>  -a 查看所有 <br> 
> -r 查看内核 <br>


# 打包 和 压缩
> zip / unzip <br>
> zip -r \[final_name\] \[targetname\] <br>
> uzip \[filename\] <br>
> -d \[指定路径\] <br>
> <br>
> tar (看文档吧 懒得写了) 





