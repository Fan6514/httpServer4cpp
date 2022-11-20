# 设置编译器
CC = g++
# debug文件的makefile文件最后执行，获取所有除debug目录名，$9代表第九列，代表文件名
SUBDIRS = $(shell ls -l | grep ^d | awk 'if($9 != "debug" && $9 != "test") print $9')
ROOT_DIR = $(shell pwd)
BIN = server
# 目标文件目录
OBJS_DIR = debug/obj
BIN_DIR = debug/bin
# 当前目录下的文件
CUR_SOURCE = ${wildcard *.cpp}
# 将当前目录下的.cpp文件转为.o文件放在CUR_SOURCE中
CUR_OBJS = ${patsubst %.cpp, %.o, $(CUR_SOURCE)}
CFLAG = -I$(ROOT_DIR) -Wall
#将以下变量导出到子shell中，本次相当于导出到子目录下的makefile中
export CC BIN OBJS_DIR BIN_DIR ROOT_DIR
#注意这里的顺序，需要先执行SUBDIRS最后才能是DEBUG
all:$(SUBDIRS) $(CUR_OBJS) DEBUG
#递归执行子目录下的makefile文件，这是递归执行的关键
$(SUBDIRS):ECHO
    make -C $@
DEBUG:ECHO
    #直接去debug目录下执行makefile文件
    make -C debug
ECHO:
    @echo $(SUBDIRS)
#将c文件编译为o文件，并放在指定放置目标文件的目录中即OBJS_DIR
$(CUR_OBJS):%.o:%.c
    $(CC) -c $^ -o $(ROOT_DIR)/$(OBJS_DIR)/$@
CLEAN:
    @rm $(OBJS_DIR)/*.o
    @rm -rf $(BIN_DIR)/*