.PHONY: all
all: Mytest 


Mytest:thread.cc
	g++ -o $@ $^ -l pthread


#$@ 表示生成文件 $^ 表示 依赖文件



.PHONY:clean
clean:
	rm -f Mytest  
