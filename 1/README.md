## Lab 1 - Mutual Exclusion

This project builds two different executables; the first executable 'helloThreads' demonstrates how mutex locks are used
to prevent threads from running at the same time, the second executable "mutualEx" demonstrates this further by having each thread
write to a shared variable, without any threads writing to an older or newer version, meaning that the final state of the shared
variable will always be the same regardless of which thread touched it when.

## Github Repository 

[Github Repository](www.github.com/AlexDarigan/concurrencydev)

## License

GPL-3.0

See [LICENSE](LICENSE) for full license text.

## Author

David Darigan

C00263218@setu.ie

[Linkedin](https://www.linkedin.com/in/daviddarigan/)

## Installation

0.1 Install GCC
0.2 Install Make
0.3 Make sure you have the pthread library in your include path
1.  Open the terminal
2.  Navigate to this folder
3.A Run Make (or Make RELEASE) to build the resulting executable
3.B Run Make DEBUG to build the resulting executable with debug symbols
4.  Run the executable through the shell (./<exenamehere>)

# Files



# TODO

    - Add Tests


