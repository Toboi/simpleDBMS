# Makefile im Top-Level-Verzeichnis

DIRS = database datastruct
DATEFORMAT = -R
all:
	for i in $(DIRS); do make -C $$i all; done
clean:
	for i in $(DIRS); do make -C $$i clean; done
git-push:
	git add Makefile; \
	for i in $(DIRS); do make -C $$i git-push; done; \
	git commit -m "automated update: $(shell date $(DATEFORMAT))"; \
	git push
