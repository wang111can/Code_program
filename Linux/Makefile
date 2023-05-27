.PHONY: all
all: Mytest 


Mytest:signal.cc
	g++ -o $@ $^ -O3


#$@ 表示生成文件 $^ 表示 依赖文件



.PHONY:clean
clean:
	rm -f Mytest  
