This project exchange message passed to client program as argument to a server using UNIX signals 
`SIGUSR1` and ` SIGUSR2`.

`make` generate **client** and **server** programs. 

**server** print its PID and loop infinitely.

**client** must get the PID of the server program and the message to transmit as arguments.

Message characters are converted to bits and sended to server, `SIGUSER1`=1 and `SIGUSER2`=0. 
Server will convert received bits to characters and print the message on the run.

If wrong number or format of arguments are passed to **client** error message will be displayed.
