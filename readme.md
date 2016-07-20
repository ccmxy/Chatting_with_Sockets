Description: A client-server model chat program with sockets. The client half is in C and the server half is optionally in C or Python. 

How to use this program, with the python server (on the OSU flip:

1. Open two different linux command line windows in this directory

2. Enter `makefile` into command line

*If there are permissions issues than first enter `makefile chmod 777` and try again

### Using python server: 

3. In one of the windows, enter `python chatserve.py [portnumber]`

4. In the other window, enter `chatclient [portnumber] [name of host where chatserve is]

5. You will be promted for your name in the chat client window. Enter it.

6. Go to the server window and say something back.

7. Enter `\quit` from either side to end the connection. The server will stay on and wait for new client connections. If you try to connect multiple clients to it at once, it will wait until the connection with one of them has ended to start the next one.  