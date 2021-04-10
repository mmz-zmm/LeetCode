# Read from the file words.txt and output the word frequency list to stdout.
# cat words.txt | tr -s ' ' '\n' | LC_ALL=C sort | uniq -c | sort -k1,1r | awk '{print $2,$1}'
cat words.txt | xargs -n1 | LC_ALL=C sort | uniq -c | sort -k1,1r | awk '{print $2,$1}'