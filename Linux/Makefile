.PHONY: all
all: Mytest Mytest2


Mytest:System_v_1.cc
	g++ -o $@ $^ 


Mytest2:System_v_2.cc
	g++ -o $@ $^ 


#$@ 表示生成文件 $^ 表示 依赖文件



.PHONY:clean
clean:
	rm -f Mytest Mytest2 
