# make3

## makefile1
The makefile has been adjusted slightly to create a main.o object file as well as a mymath.o object file. Then creates the main executable by just having to do the final linking of the object files.

There is also now a clean: target, this has no preqrequsites so does not depend on anything to run. There will also never be a file named clean in this build, so the target will always process the recipe. For the recipe we rm all object files and the executable main file. As with any other target you just use make and the target name.
```bash
make clean
```

Try adding a file called clean to the makefile1 directory, then run make clean again:
```bash
touch clean
make clean
```
You will see `'make: 'clean' is up to date.` shows. It is unlikely you will ever create a file called clean in your project but the next section shows how to avoid this issue.

## makefile2

This makefile has a .PHONY target with clean as a prerequisite. There is already a file named clean in the directory. Try to run `make clean` again, this time you will see that the clean: target runs. The .PHONY: target allows the clean: target to always run.

