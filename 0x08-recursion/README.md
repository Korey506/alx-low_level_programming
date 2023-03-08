Recursion is the process of repeating items in a self-similar way. In programming languages, if a program allows you to call a function inside the same function, then it is called a recursive call of the function.
The C programming language supports recursion, i.e., a function to call itself. But while using recursion, programmers need to be careful to define an exit condition from the function, otherwise it will go into an infinite loop.

What is Recursion? 
The process in which a function calls itself directly or indirectly is called recursion and the corresponding function is called a recursive function. Using a recursive algorithm, certain problems can be solved quite easily. Examples of such problems are Towers of Hanoi (TOH), Inorder/Preorder/Postorder Tree Traversals, DFS of Graph, etc. A recursive function solves a particular problem by calling a copy of itself and solving smaller subproblems of the original problems. Many more recursive calls can be generated as and when required. It is essential to know that we should provide a certain case in order to terminate this recursion process. So we can say that every time the function calls itself with a simpler version of the original problem.

Need of Recursion

Recursion is an amazing technique with the help of which we can reduce the length of our code and make it easier to read and write.

A classic example of recursion
The classic example of recursive programming involves computing factorials. The factorial of a number is computed as that number times all of the numbers below it up to and including 1. For example, factorial(5) is the same as 5*4*3*2*1, and factorial(3) is 3*2*1.

Basic steps of recursive programs
Every recursive program follows the same basic sequence of steps:

Initialize the algorithm. Recursive programs often need a seed value to start with. This is accomplished either by using a parameter passed to the function or by providing a gateway function that is nonrecursive but that sets up the seed values for the recursive calculation.
Check to see whether the current value(s) being processed match the base case. If so, process and return the value.
Redefine the answer in terms of a smaller or simpler sub-problem or sub-problems.
Run the algorithm on the sub-problem.
Combine the results in the formulation of the answer.
Return the results.

When should I use recursion? Recursion is made for solving problems that can be broken down into smaller, repetitive problems. It is especially good for working on things that have many possible branches and are too complex for an iterative approach . One good example of this would be searching through a file system.

A recursive function like the one above consists of two parts: the recursive call and the base case.

The base case (or bases cases sometimes) is the condition that checks to see if we have gotten the information that we need out of our function. Every recursive function should have at least one base case, though there may be multiple.

In the factorial example above, we have reached the end of our necessary recursive calls when we get to the number 0.

The recursive call, as you may have suspected, is when the function calls itself, adding to the recursive call stack.

Stacks are LIFO (Last In First Out) objects, meaning that the last item that was added to the top of the stack is the first one to be removed from the stack later on.

When should I use recursion?
Recursion is made for solving problems that can be broken down into smaller, repetitive problems. It is especially good for working on things that have many possible branches and are too complex for an iterative approach.

One good example of this would be searching through a file system. You could start at the root folder, and then you could search through all the files and folders within that one. After that, you would enter each folder and search through each folder inside of that.

 No. Use recursion when it is simplest solution.

Long Answer:

The C and C++ language were designed so that all each and every subroutine may be recursive. (main() should not be considered recursive. But it still builds a stack frame.) (One compiler optimization is to NOT build stack frames for “leaf” subroutines.).

Programs pay that cost in the instructions required to push and pop the stack frames. Programs take a performance penally to support recursion.

Recursion is used to simplify the architecture of programs. Implement the recursive form first. Only after performance testing and if there is a faster and simpler iteration scheme, use iteration instead.

But if you have to allocate a stack and manipulate the stack, use the built in recursion instead. The code is simpler and easier to maintain.

An interesting property of a factorial is that the factorial of a number is equal to the starting number multiplied by the factorial of the number immediately below it. For example, factorial(5) is the same as 5 * factorial(4). You could almost write the factorial function simply as this:i

Recursive functions are very useful to solve many mathematical problems, such as calculating the factorial of a number, generating Fibonacci series, etc.
0. She locked away a secret, deep inside herself, something she once knew to be true... but chose to forget
mandatory
Write a function that prints a string, followed by a new line.

1. Why is it so important to dream? Because, in my dreams we are together
mandatory
Write a function that prints a string in reverse.

2. Dreams feel real while we're in them. It's only when we wake up that we realize something was actually strange
mandatory
Write a function that returns the length of a string.

3. You mustn't be afraid to dream a little bigger, darling
mandatory
Write a function that returns the factorial of a given number.

4. Once an idea has taken hold of the brain it's almost impossible to eradicate
mandatory
Write a function that returns the value of x raised to the power of y.

Prototype: int _pow_recursion(int x, int y);
If y is lower than 0, the function should return -1
FYI: The standard library provides a different function: pow. Run man pow to learn more.

5. Your subconscious is looking for the dreamer
mandatory
Write a function that returns the natural square root of a number.

Prototype: int _sqrt_recursion(int n);
If n does not have a natural square root, the function should return -1
FYI: The standard library provides a different function: sqrt. Run man sqrt to learn more.

6. Inception. Is it possible?
mandatory
Write a function that returns 1 if the input integer is a prime number, otherwise return 0.

7. They say we only use a fraction of our brain's true potential. Now that's when we're awake. When we're asleep, we can do almost anything
#advanced
Write a function that returns 1 if a string is a palindrome and 0 if not.

Prototype: int is_palindrome(char *s);
An empty string is a palindrome

8. Inception. Now, before you bother telling me it's impossible...
#advanced
Write a function that compares two strings and returns 1 if the strings can be considered identical, otherwise return 0.

Prototype: int wildcmp(char *s1, char *s2);
s2 can contain the special character *.
The special char * can replace any string (including an empty string)
