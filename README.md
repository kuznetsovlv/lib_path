# lib-path
C library to work with UNIX-type file path

## Content
- [Content](#user-content-content "Conten")
- [GitHub.](#user-content-github "Link to GitHub repository")
- [Install.](#user-content-install "Install")
- [Usage.](#user-content-usege "Usage")
- [License](#user-content-license "License")

## GitHub.
[Progect on GitHub.](https://github.com/kuznetsovlv/lib_path "Link to GitHub repository")

## Install.
Coppy project from repository then in the project's root directory use ```make install``` this will compile and install library into __/usr/local/lib/libPath.so__. The header file will not be installed into your system.

## Usage.
After installetion add into your source header file __src/path.h__. It allow you next functions:

- ```char *getAbsolutePath(const char *path)``` - returns absolute UNIX-type file path constructed from any UNIX-type file path ```path``` using information of user's current and home directories.
- ```char *getCurrentPath(void);``` - returns UNIX-type absolute path to current user's directory.
- ```char *getHome(void);``` - returns UNIX-type absolute path to user's home directory.
- ```int isValidPath(const char *path);``` - returns ```1``` if the string ```path``` is valid UNIX-type path and ```0``` in othe case.
- ```char *getLibPathVersion(void);``` - returns version of the library.

## License
[MIT](./LICENSE "MIT") Copyright (c) 2019 Kuznetsov Leonid.