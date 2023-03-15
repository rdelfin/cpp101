# Homework 2

As always, this homework will be automatically "graded" using CI tests. Try and get as
many tests as possible to pass!

# Word Count

In this exercise, we'll be writing a slightly unique CLI tool which I'll call `wh`, or
"word histogram" for short. The purpose of this tool is that you'll be able to feed it
in text through standard input and get back a count of how often all the different
words in that text show up. We'll build up by extending the problem as we go. The
expectation is that you'll get over the first part of this problem. All subsequent
parts are "extra credit" that will make the program behave more like what you'd expect
it to.

All parts of the problem should be filled out in `wh.cpp`.

## Base case: Getting Words

AS the first pass at this problem, we'll use a simple definition for word: any segment
of text separated from other text by whitespace, specifically spaces, new lines, and
tabs. We consider two words as identical if they contain the exact same array of
characters (this will be important later).
Your first task is to write a program that will take in standard input line by line and
prints out a tally of words you encountered, per the defition above, in order of most
common and least common. As an example output, let's see what we'd get from the humpty
dumpty nursery rhyme:

> humpty dumpty sat on a wall
> humpty dumpty had a great fall
> all the king's horses and all the king's men
> couldn't put humpty dumpty back together again

Would output:

```
dumpty 3
humpty 3
a 2
all 2
king's 2
the 2
again 1
and 1
back 1
couldn't 1
fall 1
great 1
had 1
horses 1
men 1
on 1
put 1
sat 1
together 1
wall 1
```

### A Note On Ordering

The example output above is sorted from the most to least common words. However, all
words of the same frequency show up in alphabetical order. Our expectation is that it
doesn't matter what order words of the same frequency show up as. However, there is one
test that does expect them in alphabetical order. See if you can figure out how to get
it to work!

### Helpful Notes

For this case, you'll need to levarage a lot of things from C++ we haven't necessarily
learned about. Some things to think about:

- How do you split up a line into words?
- Does C++ give you a way of going through and splitting strings?
- How do you store word to count mapping in a way that you can efficiently update the
  number?
- How do you sort the output after you've finished?

Just one small hint that I'll give for free. There's a way for storing pairs of data.
C++ provides a type called `std::pair`. You can imagine having a variable of type
`std::pair<std::string, int>`, which could be useful somewhere. You can even use that
in some collection type, like `std::vector<std::pair<std::string, int>>`.

Read through the C++ collections library and the C++ string documentation, go over the
documentation and make sure you find the types that would be useful for this problem.
If you're completely stuck, expand the spoiler below.

<details>
    <summary>Solution spoiler</summary>
You can first store your counts in an `std::unordered_map<std::string, int>`. This will
let you efficiently add to a list of words and increment the count.

To actually sort the list, you might want to then copy the values out of the map into
an `std::vector<std::pair<std::string, int>>` and use the `std::sort()` utility we
talked about in class to actually sort that list. You might need to look into how you
specify what you're sorting _by_.
</details>

## Complexity 1, Capital Letters

The next part of this problem is handling capital letters correctly. We shouldn't count
`The` and `the` as two separate words. How do you modify your program to handle both
correctly? Read through the std::string documentation and see if you find any useful
utilities in there.

Note that in the expected output, all words should be in all lower-case.

## Complexity 2, Punctuation

A lot of English text will have punctuation. Symbols like `.,-_'"`. We should ignore
these appropriately. Otherwise you might end up with a bunch of words that just have
punctuation! How do you eliminate these?

Note, we expect you to ignore punctuation specifically the following punctuation, and
only if they're at the edge of words: `*()[]{}/,:;'.\#"£$%^&*=`

## Complication 3: CLI-defined Behaviour

In class we learned how to use a library called CLI11 for building CLI tools. THis is
one of many tools that can be used for this purpose. Your goal in this section is to
add two flags: `-r` and `-n $NUM`. `-r` should reverse the output, ordering it from
least to most common words. `-n $NUM` lets you specify how many items to print. If the
flag is not provided, you should print all word counts. To give an example, if you run:
```
wc -n 20
```
It will print the 20 most common words in the text you feed in. If you run:
```
wc -r -n 5
```
Will show the 5 least common words, sorted from least to most common. Note that the
arguments are not guaranteed to show up in that order! CLI11 should handle this for
you.


## Note On Last Test

The last test of this homework will feed in some text from the Gutenberg project, a
project that keeps transcribed copies of a myriad of texts that have since gone into
the public domain. These are quite large. Part of the test is making sure you're
solving this problem efficiently. If your test times out, can you figure out why and
where you can improve your program?
