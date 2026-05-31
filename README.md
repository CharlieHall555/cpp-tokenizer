## Overview
A simple tokenizer written in C++ that converts source code for my own small language, KOOLSCRIPT (`.ks`), into a sequence of tokens in a text file. (`.cs` was taken sadly... so no COOLSCRIPT. 😞)

Eventually, I plan to build this repository into a full compiler. For now, it focuses on tokenization.

## Why I Built This
I had been wanting to get back into C++ for a while, and I recently became interested in how compilers work after thinking about a Roblox game idea that would need a remote code compiler.

This project started as a small way to practise C++ again while learning the basics of lexical analysis and compiler design. I built it myself using knowledge from my university C++ course, so there may still be some bad C++ practice. 

## Usage
```./ tokenizer <input_path> <output_path>```

```./ tokenizer test.ks output.txt```