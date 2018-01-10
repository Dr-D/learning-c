# CGI in apache server

When initially practicing Common Gateway Interface(CGI) I used a virtual machine running a linux server and installed apache server on it and c development tools.
I then had to modify the apache configuration to allow CGI scripts to be run.

##Apache Server in Docker
This example apache server running inside a fedora docker container. This server is already set up to allow CGI scripts to be run so needs no modification.

Pull the image `docker pull fedora/apache`

Run a container from the image.
```docker run -it -p 8080:80 -v ~/applications/cgi:/var/www/cgi-bin fedora/apache```

Note the port mapping from 80 in the container to 8080 on the host machine. Maps the cgi-bin directory from the container to a local folder in this case ~/applications/cgi.

##Create the executable
You will be creating the executables in your local ~/applications/cgi directory.

Run 'make hw' due to the mapping of the container to the host directory it will need to be run as sudo.
Make sure the binary is executable, you can run it in your terminal to make sure it is working.

##Accessing the executable from browser
Should now be able to access the script in a browser
http://localhost:8080/cgi-bin/hw

The hw.c file itself just returns a simple html page to the browser.
Try adding some query parameter to the request http://localhost:8080/cgi-bin/hw?name=drd&password=mypassword.

##Things to try
Use curl to get the repsonse rather than a browser.

Create a bash script that when executes will return a HTML page i.e. you do not need to use a compiled executable
