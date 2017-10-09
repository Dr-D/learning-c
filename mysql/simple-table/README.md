# mysql create table and select

Simple example of how to *execute multiple queries*
1. Create database
2. Create table
3. Insert into table 
4. Execute a select

## Get result
Gets the a MYSQL_RES.
Iterate through reach row returned from the select.
Get each field for the row and print out the values.

## TODO
Update show result to be getResult. This can then return a struct **Person* which can then be printed out in the main method.

If a query fails then the program exits at the moment this means the executeQuery and showResult methods have to close the connection. Better to return a fail value and then close the connection in the main method where it was created.
