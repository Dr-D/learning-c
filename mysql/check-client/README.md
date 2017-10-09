# connect mysql database

Install mysql server
```
sudo apt-get update
sudo apt-get install mysql-server
```

Check that you can connect to the server
```
mysql -u root -p
```
Should ask you to enter the password you used for root user during installation of mysql-server.
Opens a prompt mysql>

```
mysql>SHOW DATABASES;
```
Should show a small table of databases.

Install the client development components
```
sudo apt-get install libmysqlclient-dev
```
Check /usr/include/mysql exists and contains mysql.h

Check the library is present with ldconfig -p
```
ldconfig -p | grep mysql
```
On my machine shows two libraries
        libmysqlclient.so.20 (libc6,x86-64) => /usr/lib/x86_64-linux-gnu/libmysqlclient.so.20
	libmysqlclient.so (libc6,x86-64) => /usr/lib/x86_64-linux-gnu/libmysqlclient.so
The first which has the number on the end is the actual library the second is a symbolic link for the library. The number is used to indicate the major version of the library, allows different versions to be used.


mysql has a configuration tool that will show the libraries required for compilation.
```
mysql_config --libs
```
View the makefile to see how this is used with the compiler.

Check you final main executable file with ldd
```
ldd main
```
This shows all the shared object (.so) files used by the executable. You will see many of these correspond directly with the libraries seen with mysql_config --libs.

