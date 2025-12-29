# Effective-TCP-IP-Programming
Working through some examples of *Effective TCP/IP Programming* by Jon C. Snader

## Chapter 1
In this chapter I set up a simple build environment
- I chose the clang compiler
- I'm using gnu99 for the C standard of choice for now
- I set up a basic makefile
- I'm using some debugging macros that I picked up from the book *Learn C the Hard Way* and simplified a bit to not use goto statements

```
cd ch1
make
./simple_server
# in a separate window
./simple_client
```

the utility of the `CHECK` macros used throughout is shown if you start the client first and take a look at the helpful error message

```
~/tcpip/ch1$ ./simple_client 
[ERROR] (simple_client.c:29: errno: Connection refused) connect call failed
```

you get not only the errno translation, but also the line number and file of the error automatically
