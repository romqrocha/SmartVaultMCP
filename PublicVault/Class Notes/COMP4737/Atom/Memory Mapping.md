# Memory Mapping
- Two types; [[#File Mapping]] and [[#Anonymous Mapping]]
## File Mapping
- Reading or writing to these addresses causes the underlying [[Files]] to be read to written.
## Anonymous Mapping
- Like `malloc` in C; contents are initialized to $0$