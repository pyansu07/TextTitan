
# TextTitan

This is a powerful spell checker based on a Trie data structure. It features simple spell checking through dictionary lookup and provides auto-correction suggestions. The application is designed for command-line interface interaction.





## Features

- Uses a `Trie data structure` to store and lookup words efficiently.
- Checks words against a dictionary of over `466,549 entries`.
- Provides suggestions for misspelled words using` Levenshtein distance`.
- Easy to use CLI for interacting with the spell checker.


# Installation

## Step-1: Clone the repository:

```bash
git clone "<--->"
```
## Step-2: Navigate to the project directory:

```bash
cd TextTitan-main
```

## Step-3: Compile the project (if necessary):

```bash
make build
```
## Step-5: To start the spell checker:

```bash
.\spell_checker
```


### Example

```bash
> .\spell_checker
Enter a word (or 'quit' to exit): hfbsukyfk

'hfbsukyfk' might be misspelled.

Suggestions:
  fluky
  habakkuk
  habuka
  hasky
  haysuck
  
Enter a word (or 'quit' to exit): 

```
