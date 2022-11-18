#!/bin/bash

# Bash script that finds all files from /usr/share/man subdirectories man1 - man8

term=*$1*
mandir='/usr/share/man'
echo 'Searching for man pages in' $mandir 'with the term:' $term
for folder in man1 man2 man3 man4 man5 man6 man7 man8; do
    find $mandir/$folder -iname $term
done

: '
./T5.sh apple
Searching for man pages in /usr/share/man with the term: *apple*
/usr/share/man/man1/nm-applet.1.gz
/usr/share/man/man1/system-config-printer-applet.1.gz
/usr/share/man/man5/sane-apple.5.gz
'