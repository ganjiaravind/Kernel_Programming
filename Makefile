
obj-m := prog_1.o prog_2.o
obj-m += current_info.o
obj-m += workqueue_example.o

KOBJ := /lib/modules/$(shell uname -r)/build/

.PHONY: default
default: build

.PHONY: build
build:
	@$(MAKE) -C $(KOBJ) KBUILD_EXTMOD=$(shell pwd) modules
.PHONY: clean
clean:
	@$(MAKE) -C $(KOBJ) KBUILD_EXTMOD=$(shell pwd) modules clean
