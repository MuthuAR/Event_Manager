all: init.c event_manager.c module.c
	gcc init.c event_manager.c module.c -o output
	mv output ../bin
