# Homework 4: Person Vector

The assignment for this week is to implement a very specialized std::vector. Don't
panic! There's a lot of functionality in that class that we won't really cover or care
about here. The main focus is to make sure you're comfortable working with
dynamically-allocated memory, to ensure that you understand how one might go about
developing an actual useful class in C++ if you're only given the interface, and more
broadly to ensure you get more comfortable working with implementing something given
some requirements.

In this homework, unlike some past ones, we expect all tests to pass when you're
finished. There's no stretch goals, only the main exercise.

## Summary

Your task here, as mentioned before, is to implement a class that provides a
vector-like interface. Specifically, it dynamically stores an "array" of people, using
a very similar class to the one we used in
[`03_organise/classes2.cpp`](../../03_organise/classes2.cpp). You will need to
implement a handful of methods in the [`vector.hpp`](./vector.hpp) file:

- *A constructor* that takes in a size and an initial value.
- *A destructor*, as you see appropriate to use
- *get()*, which lets you fetch items in the array at a given index
- *size()*, which tells you how many elements the array contains
- *push_back()*, which lets you add elements at the end of the array
- *remove_back()*, which lets you remove elements at the end of the array
- *replace()*, which lets you replace a person at a given index
- *contains()*, which tells you if the array contains a given person object

If you want more details on what to implement, we've left comments in every method
which should clarify what they do. If its still unclear, please come ask in #cpp-101!

Please note that we *expect* you to use dynamically-allocated memory, as defined in the
class. That means you *might* want to create arrays at different times using the `new`
keywoard we learned in class. We also expect you to `delete` the array when appropriate
to make sure you don't leak memory! Unfortunately we don't explicitly test for it.

There's also few requirements in the file that that require concepts we haven't covered
in class. As always, feel free to ask questions in slack or office hours, but either
way, what follows are a few explanations of those topics.

## Header files

You might have noticed that the file you're modifying has a file extension of `.hpp`
instead of the usual `.cpp` that we've been using throughout the class. This means that
it's a header file, not a "source" file. So far, we've been working with single files
and not looked at how you'd distribute your code across different files. We will go
more in depth in a future class on this topic, but the important things to note are:

- Any time we've done an `#include "..."` statement at the top of a .cpp file, we've
  been including one of these header files. How this works is not exceedingly important
  now, but do know that in C++ you include files directly, and you only include header
  files and NEVER source files.
- Header files are, by themselves, not compiled. They need to be included in a source
  file (or included in a series of header files that eventually are included in some
  source file).
- Header files should *always* start with a `#pragma once` statement. These are called
  header guards and, sufice it to say, they will save you a lot of headache in the
  future

## Exceptions

One of the functions requires you to throw an `OutOfBoundsException` when a certain
condition is met. You probably noticed, near the top of the `vector.hpp` file there's
a class with that name. That's the "exception" we're gonna throw. Exceptions are a way
of signalling failure of something in your code. They are the standard way of
propagating errors in C++ (though not all C++ programmers like using them). The way you
throw this particular exception is by writing:

```cpp
if(some_failure_condition) {
    throw OutOfBoundsException();
}
```

Running this line, much like with throw statements, will cause the function to exit
immediately and will in fact make every function that lead to this statement being run
to exit, _unless_ they handle the exception. We will see how you do that in a future
lecture.

## GTest and Testing

The reason we're using header files in this homework is because we'll be using a test
framework called gtest. This test framework is written for use in C++ by google and
provided as open source software. Feel free to look around [test.cpp](./test.cpp) to
see how we test your class for correctness.
