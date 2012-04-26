# Makefile im Top-Level-Verzeichnis

DIRS = database datastruct net
GIT_DIRS = database datastruct net test
DATEFORMAT = +"%a, %d %b %Y %T"

all:
	for i in $(DIRS); do make -C $$i all; done
clean:
	for i in $(DIRS); do make -C $$i clean; done
clean-all:
	for i in $(DIRS); do make -C $$i clean-all; done
git-push:
	git add Makefile; \
	git add README; \
	for i in $(GIT_DIRS); do make -C $$i git-push; done; \
	git commit -m "automated update: $(shell date $(DATEFORMAT))"; \
	git push
git-pull:
	git pull;
