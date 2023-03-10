# Homework 3: Wordle

The assignment for this week is to implement a basic version of the wordle game. For
those of you not familiar, wordle is a word-based puzzle where the goal is to guess
a 5 letter word in 6 tries. It will give you very specific hints with each attempt,
telling you which letters you got right but in the wrong position, which letters are
in the right position, and which ones don't show up at all. You can find the current
official version [here](https://www.nytimes.com/games/wordle/index.html).

We only require students to complete the first section, but encourage them to give
other sections a try.

## Test 1: No Feedback Wordle

Your program should work the following way:

1. It should have a flag "--answer" that, if provided, should be followed by a word
   to be used as the "correct" answer. We recommend making it so that if this flag is
   not set, it gives you a random answer, though we won't be testing that.
2. The program should take in input from standard input (aka `std::cin`). After you
   press enter, it should check if the guess is correct. If so, it should print
   "CORRECT" and exit with exit code zero. Otherwise, it should print "WRONG" and
   either let the user input another line or, if they've already tried 6 attempts, it
   should exit with exit code 1.
3. If the user gives more or less than 5 characters, you should exit immediately,
   without printing anything, with exit code 2.

### How to organise

Think about the following:

- How can you organise this code into functions? What are the different things you do?
- Are there any obvious concepts that work well in classes with methods? What about a
  "verifier" class that's responsible for storing the dictionary and checking words
  against it?

## Test 2: Only Valid Words Wordle

Modify the program above to now only accept valid wordle words. If the user provides an
invalid word, then you should exit immediately with error code 3.

## Test 3: Feedback Wordle

Modify your program above so that, when you pass a special flag "--feedback", instead
of printing "WRONG" when the answer is correct, it will print one character for each
character input with the following key:

- If the character does not show up on the word, you should print an upper case X
- If the character appears in the word, but in a different position, you should print
  an ~
- If the character appears in the word in that exact position, you should print an
  upper-case V (kind of like a tick mark)

### How to organise

Think about the following:

- Where should the logic for checking against the answer be? Should it be in a
  function, should you put the answer into a class, should you do something else?
