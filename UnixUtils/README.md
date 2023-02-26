This folder contains simple versions of common unix utilities:
- my-cat
- my-grep
- my-zip
- my-unzip

Usage:
    1. run `make` to build the executables
    2. run `./my-cat in.txt [out.txt]`
    3. run `./my-grep pattern in.txt`
        - Can also read from stdin
    4. run `./my-zip in.txt [> out.z]`
    5. run `./my-unzip in.z [> out.txt]`