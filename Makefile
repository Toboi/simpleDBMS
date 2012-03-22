# Makefile im Top-Level-Verzeichnis

DIRS = database datastruct

%:
	for i in $(DIRS); do make -C $$i $@; done
