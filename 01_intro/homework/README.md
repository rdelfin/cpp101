# Week 1 Homework

# Collatz Conjecture

The Collatz Conjecture, alternatively known as the 3n+1 problem is a famous problem in
mathematics about a certain iterative process. Let's describe said iterative process
first. Imagine picking a positive, non-zero integer $n$. To run a step of the
process, you first check if $n$ is even. If it is, the next number will be
$\frac{n}{2}$. If it's not, the next number will be $3n + 1$. You can then repeat
the process again on the output over and over again, at infinitum. This function is
often expressed as:

$$
f(n) = \begin{cases}
    \frac{n}{2} & \text{if } x = 0 (\mod{2})\\
    3n+1 & \text{if } x = 1 (\mod{2})
\end{cases}
$$

The conjecture states that, for any positive non-zero integer $n$ you repeat this
process with, you will always eventually hit 1. While it hasn't been proven
unequivocally true, it has held true for every number humanity has tested. For this
excercise we will assume it's true. We will refer to the set of numbers that you get
after applying the Collatz process over an over again until you get to one $n$'s
Collatz Sequence. As an example, $5$'s Collatz sequence is 5, 16, 8, 4, 2, 1.


For this assignment, your task is to write a program that does the following:

1. Takes in an integer $n$ as input to the program (same way we've been getting numbers
    in the lecture).
2. Proceeds to print out every number in $n$'s Collatz Sequence, in order
3. Exits

It should also return a *non-zero exit code* for invalid inputs. It's worth noting that
some of the errors thrown by our program will already do that for you. Test it and make
sure you cover all your bases!

## Logistics

Please put the program that does this in the `collatz.cpp` file in this directory. You
can run your program by running `bazel run //01_intro/homework:collatz` or, if you're
in this directory, you can run `bazel run :collatz`. Feel free to test your program and
verify what you did by hand.

Your program has to work for all integers we might feed in that fit in 31 bits (though
we might not test every single one). You can verify and get your "grade" for this
exercise by openning a PR against this repo with your solution. This will automatically
run the grading test in CI and give you a number for how well you did.

You can also run the grading program yourself by running `bazel run
//01_intro/homework:grade_collatz`.

### Things to watch out for

This particular test works by parsing everything you send to the terminal via
`std::cout`. We ignore any lines that don't just contain numbers, so you can print out
a prompt to let a user enter a number. However, if you just add an `std::flush` at the
end of the prompt, and no new line (e.g. by adding an `std::endl`), whatever the first
number of the sequence is will be part of that same line, even if it doesn't look like
it on your terminal. I would recommend sending a new line before printing anything
yourself, by adding a line like follows:

```cpp
std::cout << std::endl;
```

## Exta Credit

### Multiple inputs

There's a separate exercise called `collatz_multiple.cpp`. In this program, we will
give you multiple initial values and expect you to give us the length of the Collatz
sequence for each one, instead of the full sequence (aka the number of steps required
to get to `1`). As an example again, for $n=5$, where the sequence is 5, 16, 8, 4, 2,
1, you would print 5 (one less than the length of the sequence).

In this scenario, you will get multiple lines of input. The first line will contain the
number of elements $l$ that will follow, and then you'll get $l$ numbers, one in each
line. For example, an input could look like:

```
5
100
20
6
3
25
```

Here, the 5 is the number of elements, and the next 5 numbers are the $n$'s we expect
your calculations for.

You *should not* complete this excercise by making use of lists, arrays, or any other
similar constructs (if you know how they work in C++ that is!). If you're not sure how
to do this without lists, and you want some help, expand the spoiler below:

<details>
    <summary>Solution spoiler</summary>
You don't need to read all the input at the start. You can read them one by one.

Additionally, you can have nested loops. For example:
```cpp
for(unsigned int i = 0; i < 100; i++) {
    // This while loop will run 100 times
    for(unsigned int j = 0; j < 10; j++) {
        // The code in here will 100*10 = 1,000 times
    }
}
```

Note they don't need to be the same kind of loop. You can mix while loops and for
loops, for example.
</details>

### Performance

While this extra credit does not have associated tests, we're challenging you to figure
out how to make the multiple inputs code as performant as possible. There's a few
places where you can get some significant performance benefits. Can you reduce the
number of calculations being done for single paths? Is there some gain you can get by
taking advantage of the fact that you have multiple inputs? Explore your options!

Getting a fully optimal answer to this will require concepts we will see in the next
lesson, but if you want to get ahead with your previous programming knowledge, see if
you can find something useful in [cppreference.com](https://en.cppreference.com/w/).
