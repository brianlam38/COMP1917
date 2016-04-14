/*
	Lecture 21 - HTTP
*/

IP ADDRESSES
- Each number is a byte
- A 4 byte address = IP ADDRESS (E.g. Facebook = 74.125.237.18)

Function Related:
- You told your web browser (Firefox) a http address (a function)
- Firefox sent a request to Google
- Google did a bit of thinking
--> Took the request (the input to the function)
--> Looked at the contents of the address
--> Returned a web page (output)
- Language using to do this is called: HTTP
- Request going up = HTTP Request
- Response coming back = HTTP Response

What I sent out as the request to Google:
- GET / (no particular page) HTTP/1.0\n

SERVERS:
--> Servers on the internet have an address, which is a 4 or 6 byte number.
--> But for many machines, you can also use a NAME (www.google.com) which is a lot easier to remember

--> Servers have a lot of ways to get in, called PORTS
--> Servers are like a big hotel: To get a message to someone staying there, you need to know:
(1) The address of the hotel (OR ITS NAME) +
(2) What room (PORT) they are staying in

--> Web Servers usually expect to receive HTTP messages at their PORT 80

CONNECTING:
- telnet 74.125.237.18 80 //Connecting to a server, PORT 80

HTTP DATA:
- Content-Type: Text/html //Indicating that they're sending a page in HTML
- Charset //Indicating what alphabet they're using.
- Server: gws //Indicating the name of their server (Google Web Server)

/*
	Lecture 22 - Calling a Function
*/

Write a program in 8004 to print out all Wondrous Numbers
- If ODD = x 3
- If EVEN = x 1/2
--> Test even/odd by dividing by two
- How would we do it by machine code?

Writing a function for even/odd









