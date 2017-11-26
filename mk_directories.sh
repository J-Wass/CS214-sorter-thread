#!/bin/bash
for number in {1..6}
do mkdir spencer./"$number"
for numbera in {1..6}
cp movie_metadata.csv movie_metadata"$numbera".csv
mv movie_metadata"$number".csv spencer./"$numbera"
done 
done
gcc sorter-threads.c -pthread -o sorter-threads #threads
time ./sorter-threads -c gross
gcc sorter.c -o sorter #no_thread
time ./sorter -c gross
