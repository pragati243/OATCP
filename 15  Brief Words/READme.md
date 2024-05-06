## Algorithm

### Definitions
- **Short Form**: A shorter representation of a word obtained by combining its consecutive characters.
- **Codeword**: A unique identifier assigned to each word based on its short forms.

### Functions
1. **generateShortForms(word)** (Comment this function if all short forms are not required to be generated) :
   - **Input**: A word `word` for which short forms are to be generated.
   - **Output**: A vector containing all possible short forms of the given word.
   - **Algorithm**:
     - Initialize an empty set `shortForms` to store unique short forms.
     - Iterate over each character of the word.
     - For each character, create all possible substrings starting from that character and add them to `shortForms`.
     - Return the vector of short forms.

2. **generateCodewords(words)**:
   - **Input**: A vector of words `words` for which codewords are to be generated.
   - **Output**: An unordered map containing word-to-codeword mappings.
   - **Algorithm**:
     - Initialize an empty map `codewordMap` to store word-to-codeword mappings.
     - Initialize an empty map `usedCodewords` to keep track of used codewords.
     - Iterate over each word in the input vector.
     - For each word, iterate over its characters and generate all possible short forms.
     - Create a unique codeword for the word using its short forms, ensuring that no codeword is used twice.
     - Return the word-to-codeword mappings.

### Main Program
1. **Input**:
   - Accept the number of words `n`.
   - Accept `n` words into a vector `dictionary`.
   
2. **Generate Short Forms**:
   - For each word in the `dictionary`, generate its short forms and store them in a map `allShortForms`.

3. **Generate Codewords**:
   - Generate unique codewords for each word in the `dictionary` using its short forms.

4. **Output**:
   - Print the word-to-codeword mappings.
   - Print the short forms for each word.

### Execution
1. Read the number of words `n`.
2. Read `n` words into the `dictionary`.
3. Generate short forms for each word and store them.
4. Generate unique codewords for each word.
5. Print the word-to-codeword mappings.
6. Print the short forms for each word.

### Complexity
- **Time Complexity**: O(n * m^4), where n is the number of words and m is the maximum length of a word.
- **Space Complexity**: O(n * m^4), where n is the number of words and m is the maximum length of a word.