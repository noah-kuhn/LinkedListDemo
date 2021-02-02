# Linked List Demo

*Author: Noah Kuhn*

**Just a little linked list demo: some toy code, comments, and bugs.**

> Java is like a bicycle with training wheels. <br> C is like a unicycle, and you're going downhill.
> *\- Dr. Chatterjee (paraphrased)*

---

## Contents of this repo
* `list.h`: The header file containing definitions of our `value_t` `union`, our `value_type_t` `enum`, and our `node_t` and `list_t` `struct`s.
* `linkedlist.c`: The actual C file that needs to be edited to complete the definitions of our various `list_t` functions. Running the `main` function will go through whatever tests are written in it; there are a few tests already written in.
* `linkedlist-ref.c`: The reference 'solution' for the above file, though it isn't particularly focused on efficiency or on preventing memory leaks, so ***don't treat it as the best possible solution***. In fact, I would advise that (upon making a solution that works) you try to fix any memory leaks and improve efficiency. This 'solution' is only to provide examples and usage of basic C concepts.
* `Makefile`: The Makefile for this repo, that allows you to simply type `make` into the command line instead of the normal compiling line (it is very minimal and does not support `make clean` or anything like that).
* `README.md`: Oh, hey! That's this file!

---

## Hello!
My name is Noah Kuhn, and I wrote a little bit of toy code here for a demonstration of basic C concepts, like pointers, unions, structs, and enums. ***I assume the programmer is familiar with Java and has worked with linked lists before***. I've commented this code fairly thoroughly and left the functions gutted so that you can take a crack at filling them out to make them work. The comments outline the ideas behind the implementations of the functions, and there's a reference 'solution' file to look at if you need the help.

Here's my suggested order of doing things:
* Look through the `list.h` file to get a full understanding of what the `union`, `enum`, and `struct`s are made up of and how they are related to each other. Drawing boxes and arrows is encouraged.
* In the `linkedlist.c` file, search "TODO" and you can find the ten sections of code that are left to be implemented.

### For those of you in my discussion section...
I'm sure you can recall that I ran into a few bugs and issues while going through this demonstration with you. That's okay (I wanted to demonstrate `gdb` and `printf` debugging) but I do want to assure you I've run through the code and fixed the major issues we were having.

Some key differences from how the code looked in discussion section:
* In the `list_pop` and `list_remove_last` functions, the original code returned the actual address of the string if the node contained a string. Since we decided to implement a free for the strings of these nodes during discussion section (something my original code hadn't expected to do) I had to change that section to *copy* the string and return the copy's address. This is because we ended up freeing the actual string before returning it. I've also explained this in comments in the files. The takeaway here is that this is what caused our `list_pop` to fail during discussion section.
  * *A quick note: I found this via, you guessed it, `gdb`. I told you it's useful!*
* In the `list_free` function, I originally had the loop set up on the condition `while(curr_node != NULL)`. The double-`free` error we were getting came from this loop; by instead making the condition `while(curr_node != l->header)` and then calling `free` on `l->header` afterward, we ensure that each node is only freed once, including the header.
* I've added comments in a few other places that I've changed since discussion section; looking through them is heavily advised, as some segments of code I had had were written in the wee hours of the night and were pretty gross at best. Many of these places can be found by searching for "discussion section".

## Well, that's the whole README.
Happy coding!

