# socket using openssl

This is bascially the same simple server socket with openssl.

## Install libssl-dev.
This should give you libssl and libcrypto that are required for developing with openssh.

## make and run main
This will open a server socket awaiting an https connection.

## use curl to connect
curl -k https://localhost:55555/test

The client is asked for a password which is 'password'.
The socket read and write should complete.

Try curl -v -k https://localhost:55555/test
This gives a verbose output which was helpful debugging issues.


## TODO
The curl -k means https can be used insecurely.
May need a root certificate authority certificate (cacert) to get this to work properly.

From my understanding a server.cert is required which has a public key. This is sent to the client which uses the public key to encrypt a key that can be used for the session.
The server has the private key to allow it to decrypt the message sent from the client.

