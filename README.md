# LZW-Compression

### Introduction

LZW compression algorithm uses fixed-length codewords to represent variable-length strings of symbols/characters that commonly occur together.

* Encoder and decoder build up the same dictionary dynamically while receiving the data.
* Places longer and longer repeated entries into a dictionary.

### Pseudo Code

~~~
BEGIN
	s = next input character;
	while not EOF
	{
		c = next input character;

		if s + c exists in the dictionary
			s = s + c;
		else
		{
            output the code for s;
    		add string s + c to the dictionary with a new code;
    		s = c;
		}
	}
	output the code for s;
END
~~~

### Example

| s    | c    | output | code | string |
| ---- | ---- | ------ | ---- | ------ |
|      |      |        | 0    | a      |
|      |      |        | 1    | b      |
|      |      |        | 2    | c      |
| a    | c    | 0      | 3    | ac     |
| c    | b    | 2      | 4    | cb     |
| b    | b    | 1      | 5    | bb     |
| b    | a    | 1      | 6    | ba     |
| a    | c    |        |      |        |
| ac   | a    | 3      | 7    | aca    |
| a    | EOF  | 0      |      |        |

