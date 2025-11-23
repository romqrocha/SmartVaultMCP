![[Interrupts]]

# Standard Streams

|        | symbol | [[File Descriptor]] | Inputs           | Example                     |
| ------ | ------ | ------------------- | ---------------- | --------------------------- |
| stdin  | <      | 0                   | Keyboard or file | `> cat `                    |
| stdout | 1>     | 1                   | Terminal or file | `> cat 1> foo.txt`          |
| stderr | 2>     | 2                   | Terminal or file | `>cat foo.txt 2> log_error` |
