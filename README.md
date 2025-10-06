# Custom Simple Shell

## Overview
This project is a custom-built simple shell designed to provide a lightweight and efficient command-line interface for interacting with the system. It offers seamless command execution, input/output redirection, environment variable management, and more. The shell is developed in C programming language, ensuring low-level control and efficiency.

## Table of Contents
- [Features](#features)
- [Technologies Used](#technologies-used)
- [Installation Guide](#installation-guide)
- [Usage Instructions](#usage-instructions)
- [Testing](#testing)
- [Contributing Guidelines](#contributing-guidelines)
- [License](#license)

## Features
- Command Execution: Users can execute system commands and interact with the underlying operating system.
- Environment Variables: Allows management of environment variables, including setting, exporting, and displaying values.
- History and Editing: Provides command history and editing capabilities for efficient navigation and modification of previous commands.
- Signal Handling: Implements proper signal handling for common signals like SIGINT and SIGTSTP.
- Job Control: Enables job control features, allowing users to manage and manipulate running jobs.
- Built-in Commands: Includes built-in commands such as cd, pwd, echo, and more.
- Exit Status: Displays exit status of executed commands, indicating success or failure.

## Technologies Used
- C Programming Language: The shell is developed in C, ensuring low-level control and efficiency.
- System Calls: Utilizes standard C library functions and system calls to interact with the operating system.
- Standard I/O Library: Leverages standard input/output functions for handling user input and output.
- Memory Management: Employs dynamic memory allocation and proper memory management techniques.

## Installation Guide
To install and build the Custom Simple Shell:

1. Clone the repository: `git clone https://github.com/joekariuki3/joel-shell.git`
2. Navigate to the project directory: `cd joel-shell.git`
3. Compile the source code: `gcc *.c -o shell`
4. Set execution permission: `chmod +x shell`

## Usage Instructions
1. Run the shell by executing the binary file: `./shell`
2. Start interacting with the shell by entering commands. Here are some basic commands you can use:
    - `ls`: List the contents of the current directory.
    - `pwd`: Print the current working directory.
    - `cd`: Change the current working directory. Usage: `cd <directory_path>`
    - `env`: Display all environment variables and their values.
    - `echo`: Display a line of text. Usage: `echo <text_to_display>`
    - `mkdir`: Create a new directory. Usage: `mkdir <directory_name>`
    - `touch`: Create a new file. Usage: `touch <file_name>`
    - `cat`: Display the contents of a file. Usage: `cat <file_name>`
    - `rm`: Remove a file or directory. Usage: `rm <file_name>` or `rm -r <directory_name>` for recursive removal.
3. Exit the shell using the `exit` command.

## Testing
To ensure the reliability and correctness of the shell, comprehensive testing has been conducted, including:
- Unit Testing: Individual functions and modules have been tested in isolation.
- Integration Testing: The shell has been tested as a whole, ensuring proper interaction between components.
- Stress Testing: The shell has been subjected to high load to evaluate its performance and stability.
- Memory Testing: Valgrind has been used to identify and address any memory-related issues. `valgrind ./shell`

## Contributing Guidelines
Contributions are welcome! Please follow these steps:
1. Fork the repository on GitHub.
2. Create a branch for your changes: `git checkout -b feature/your-feature`.
3. Commit your changes: `git commit -m 'Describe your changes'`.
4. Push your changes to your branch: `git push origin feature/your-feature`.
5. Submit a pull request for review.

## License
This project is licensed under the MIT License. For more information, refer to the `LICENSE` file in the repository.

Feel free to contact @joekariuki3 the project owner for any queries or suggestions. Enjoy using and contributing to the Custom Simple Shell!
