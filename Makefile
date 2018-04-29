SRC:=$(wildcard *.c)
TAR:=$(basename $(SRC))
all: $(TAR)


copy: $(TAR)
	sudo su
	mount -o loop -t ext4 /home/hmsjwzb/intel/code.img /home/hmsjwzb/intel/mycode
	$(info $^)
	$(info $@)
	$(CP) -f $^ /home/hmsjwzb/intel/mycode
	umount /home/hmsjwzb/intel/mycode
mount:
	sudo su
	mount -o loop -t ext4 /home/hmsjwzb/intel/code.img /home/hmsjwzb/intel/mycode
    
% : %.c ftrace/ftrace.a
	$(CC) -static $^ -o $@
#	$(info $(SRC))
#	$(info $(TAR))
