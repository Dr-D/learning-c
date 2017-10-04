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



