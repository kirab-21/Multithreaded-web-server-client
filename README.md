<h1>Multithreaded Proxy-server with cache</h1>
C and parsing of HTTP referred from the <a href = "https://github.com/vaibhavnaagar/proxy-server"> Proxy Server </a> are used to implement this project.

#### Introduction
- The GET method is supported by the proxy server, which connects to the specified host and provides host info in response to client requests.
- It can handle both HTTP/1.1 and HTTP/1.0 protocol request.
- When a client submits an erroneous request or an error, the server responds with the proper Status-code and Response-Phrase values.
- Server is designed such that it can run continuously until error occurs.

#### Need of this Project
- To Undersand :-
  - Working of request from local computer to the server.
  - Managing several client demands from different clients.
  - Concurrency locking technique.
  - The idea of cache and the various ways that browsers may utilise it.
- Proxy Server uses :-
  - It decreases server-side traffic and expedites the operation.
  - It can be applied to prevent users from visiting particular websites.
  - An effective proxy will alter the IP so that the server is unaware of the client sending the request.
  - To prevent unauthorised access to your client's requests, you can modify the proxy to encrypt the requests.

#### Operating System Concept Used :-
 - Semaphore
 - Locks
 - Threading
 - Cache (LRU algorithm is implemented).


#### Drawbacks
- Our cache will save each client's response as a distinct element in the linked list if a URL opens multiple clients. Therefore, only a portion of the response will be sent during cache retrieval, and the website won't launch.
- Large websites might not be cached because of the cache element's fixed size.

#### How to run it
- Run makefile using 'make' command.
- It will create an executable file.
- Runs server using command:

``` bash
$ ./proxy <port-no>
```

`Open http://localhost:port/https://www.cs.princeton.edu/`   using incognito mode in browser
