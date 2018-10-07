# Ggggggg gggg Ggggg-ggggg!

This coding challenges comes from [/r/dailyprogrammer](https://www.reddit.com/r/dailyprogrammer/comments/3x3hqa/20151216_challenge_245_intermediate_ggggggg_gggg/).

We have discovered a new species of aliens! They look like this and are trying to communicate with us using the /r/ggggg subreddit! As you might have been able to tell, though, it is awfully hard to understand what they're saying since their super-advanced alphabet only makes use of two letters: "g" and "G". Fortunately, their numbers, spacing and punctuation are the same.

We are going to write a program to translate to and from our alphabet to theirs, so we can be enlightened by their intelligence.

Feel free to code either the encoding program, the decoding program, or both.

## Part 1: Decoding

First, we need to be able to understand what the Ggggg aliens are saying. Fortunately, they are cooperative in this matter, and they helpfully include a "key" to translate between their g-based letters and our Latin letters. Your decoder program needs to read this key from the first line of the input, then use it to translate the rest of the input.

### Sample decoder input 1
```
H GgG d gGg e ggG l GGg o gGG r Ggg w ggg
GgGggGGGgGGggGG, ggggGGGggGGggGg!
```

### Sample decoder output 1
```
Hello, world!
```

Explanation: Reading the input, the key is:
H = GgG
d = gGg
e = ggG
l = GGg
o = gGG
r = Ggg
w = ggg

When we read the message from left to right, we can divide it into letters like so (alternating letters bolded):

> **GgG**ggG**GGg**GGg**gGG**, ggg**gGG**Ggg**GGg**gGg!

Take those letter groups and turn them into letters using the key, and you get "Hello, world!"

### Sample decoder input 2
```
a GgG d GggGg e GggGG g GGGgg h GGGgG i GGGGg l GGGGG m ggg o GGg p Gggg r gG y ggG
GGGgGGGgGGggGGgGggG /gG/GggGgGgGGGGGgGGGGGggGGggggGGGgGGGgggGGgGggggggGggGGgG!
```

Note that the letters are not guaranteed to be of equal length.

### Sample decoder output 2
```
hooray /r/dailyprogrammer!
```

## Part 2: Encoding
Next, we will go in the other direction. Come up with a key based on the letters "g" and "G" that maps all the letters in a given message to Ggggg equivalents, use it to translate the message, then output both the key and the translated message. You can double-check your work using the decoding script from part 1.

### Sample input
```
Hello, world!
```

### Sample output
```
H GgG d gGg e ggG l GGg o gGG r Ggg w ggg
GgGggGGGgGGggGG, ggggGGGggGGggGg!
```

Your key (and thus message) may end up being completely different than the one provided here. That's fine, as long as it can be translated back.

## Part 2.1 (Bonus points): Compression

Just as it annoys us to see someone typing "llliiiiikkkeeee ttttthhhiiiisssss", the Ggggg aliens don't actually enjoy unnecessary verbosity. Modify your encoding script to create a key that results in the shortest possible Ggggg message. You should be able to decode the output using the same decoder used in part 1 (the second sample input/output in part 1 is actually compressed).

Here's a [hint](https://en.wikipedia.org/wiki/Variable-length_code).
