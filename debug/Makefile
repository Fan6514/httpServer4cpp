#规则命令行中的自动化变量“$^”代表所有通过目录搜索得到的依赖文件的完整路径名（目录 + 一般文件名）列表。#“$@”代表规则的目标
OBJS=*.o
ODIR=obj
$(ROOT_DIR)/$(BIN_DIR)/$(BIN):$(ODIR)/$(OBJS)
	$(CC) -o $@ $^ $(CFLAG)
