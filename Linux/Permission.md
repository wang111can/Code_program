# Permission in Linux

### su - 
> 切换为 root 用户 <br>

### su + username
> 切换用户 需输入 该用户的密码 <br>


## 权限
### 权限标识
> hear r w x <br>
> hear 为 该 文件 的类型 <br>
>> * 一般为 d -directory <br>
>> * \- 普通文件 <br>
>> * p 管道文件 <br>
>> * b 块设备 (磁盘) <br>
>> * c 字符设备 (键盘 / 显示器) <br>

> r read <br>
> w write <br>
> x <br>

### chmod
> 操作 +/-r +/-w +/-x (也可以使用 二进制数 来 表示 是否开放该权限 7 为 开放全部权限 (111)) <br>
> -u 对拥有者进行操作 <br>
> -g 对所属组进行操作 <br>
> -o 对访客进行操作 <br>
> -a 对所有成员进行操作 <br>


### chown
> 改变拥有者 <br>
> chown [user_name] [file_name] <br>

### chgrp
> 改变所属组 <br>
> chgrp [group_name] [file_name] <br>






