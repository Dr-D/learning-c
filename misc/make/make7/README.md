# make4

## makefile1
Several changes have been made to make things a bit more complicated but shows the versatility of using make for your project. NB We have include the -Wall CFLAGS option here which was previously commented out.

### updated mymath
Updated the add function to be mymath_add(...). This follows the general naming conventions used e.g. strcmp(), strlen(), strcpy()

Added a #ifndef to the mymath.h file to stop it being added more than once. If the file is ''#include'd in more than one file it will only be included the first time. If it were to be included twice the compiler complains that 

### added myprint
New files myprint.h and myprint.c this just moves the printf to this file so that we can easily print and integer.

### added myrand
New files myrand.h and myrand.c allows us to use a random integer in our calculations to make things a bit more interesting.

#check the makefile
Although this is a very contrived set of files we have added to the project it does add complexity, but if we look at the make file we can see the only changes required is to add the object files to the OBJS variable. 

## makefile2

In this second file we show and example of a make built in variable, although we have already been using built in variables.

The clean recipe has been updated with '-f' to stop error messages showing if a file is not present.
There is a commented out line that used $(RM) instead. This a built in variable that uses the correct remove file option for the system the makefile is running on.

Remove (rm) is found on pretty much all linux type systems so is not really needed but shows that we have not set the RM variable at the top of the script.

If you comment out the CC variable at the top of the file the makefile still works and uses the c compiler from your system which may be 'cc' or 'gcc'.

