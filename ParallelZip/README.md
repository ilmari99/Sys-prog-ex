This folder contains a simple version of run-length encoding in parallel, with pthreads.
The representation of the run-length encoding is 4 bytes for the run-length, and 1 byte for the character.
The zipping algorithm is the same as in the UnixUtils folder.

Usage:
- run `make` to build the executables
- run `./pzip [-t N -s M] in.txt [> out.z]`. 
    - `-t N` specifies the number of threads to use (defaults to `get_nprocs()-1`)
    - `-s M` specifies the number of segments to use (defaults to the number of threads)
    - `in.txt` is the input file
    - `out.z` is the output file (defaults to stdout)

- run `./my-unzip in.z [> out.txt]`
    - `in.z` is the input file
    - `out.txt` is the output file (defaults to stdout)


The logic for parallellization is as follows:
For each input file:
- Open the input file
- Check size of file
- Divide the file into `M` segments represented as a ThreadArgs struct. (M defaults to the number of threads)
- Create `N` threads (defaults to `get_nprocs()-1`)
- Threads pop the segment arguments off the queue and "zip" it to a temporary file
- An extra thread waits for each segments results (in order), and writes the result to the output file as soon as the segment is done, and then deletes the temporary file
