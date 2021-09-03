# Linked List Demo

**Just a little linked list demo: some toy code, comments, and bugs.**

*Author: Noah Kuhn*

> Java is like a bicycle with training wheels. <br> C is like a unicycle, and you're going downhill.
> *\- Dr. Chatterjee (paraphrased)*

---

## Contents of this repo
* `list.h`: The header file containing definitions of our `value_t` `union`, our `value_type_t` `enum`, and our `node_t` and `list_t` `struct`s.
* `linkedlist.c`: The actual C file that needs to be edited to complete the definitions of our various `list_t` functions. Running the `main` function will go through whatever tests are written in it; there are a few tests already written in.
* `linkedlist-ref.c`: The reference 'solution' for the above file, though it isn't particularly focused on efficiency or on preventing memory leaks, so ***don't treat it as the best possible solution***. In fact, I would advise that (upon making a solution that works) you try to fix any memory leaks and improve efficiency. This 'solution' is only to provide examples and usage of basic C concepts.
* `Makefile`: The Makefile for this repo, that allows you to simply type `make` into the command line instead of the normal compiling line (it is very minimal and does not support `make clean` or anything fancy like that).
* `README.md`: Oh, hey! That's this file!

---

## Hello!
My name is Noah Kuhn, and I wrote a little bit of toy code here for a demonstration of basic C concepts, like pointers, unions, structs, and enums. ***I assume the programmer is familiar with Java and has worked with linked lists before***. I've commented this code fairly thoroughly and left the functions gutted so that you can take a crack at filling them out to make them work. The comments outline the ideas behind the implementations of the functions, and there's a reference 'solution' file to look at if you need the help.

Here's my suggested order of doing things:
* Look through the `list.h` file to get a full understanding of what the `union`, `enum`, and `struct`s are made up of and how they are related to each other. Drawing boxes and arrows is encouraged.
* In the `linkedlist.c` file, search "TODO" and you can find the ten sections of code that are left to be implemented.
* Once you've taken a crack at it, feel free to run `make` and run the executable to see whether it works!
* Look through the reference "solution" in `linkedlist-ref.c` to see a functional implementation with explanations in comments.

## Well, that's the whole README.
Happy coding!

