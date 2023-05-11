.PHONY: all
all: Mytest process


Mytest:test.c
	gcc -o $@ $^ 

process:process.c
	gcc -o $@ $^ 
#$@ 表示生成文件 $^ 表示 依赖文件



.PHONY:clean
clean:
	rm -f Mytest process
