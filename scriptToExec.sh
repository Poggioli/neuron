#!/bin/bash

for i in 2 4 8 16; do
    ./mergesortMultiThread $i file1.txt output.txt
    ./mergesortMultiThread $i file1.txt file2.txt output.txt
    ./mergesortMultiThread $i file1.txt file2.txt file3.txt output.txt
    ./mergesortMultiThread $i file1.txt file2.txt file3.txt file4.txt output.txt
    ./mergesortMultiThread $i file1.txt file2.txt file3.txt file4.txt file5.txt output.txt
    ./mergesortMultiThread $i file1.txt file2.txt file3.txt file4.txt file5.txt file6.txt output.txt
    ./mergesortMultiThread $i file1.txt file2.txt file3.txt file4.txt file5.txt file6.txt file7.txt output.txt
    ./mergesortMultiThread $i file1.txt file2.txt file3.txt file4.txt file5.txt file6.txt file7.txt file8.txt output.txt
    ./mergesortMultiThread $i file1.txt file2.txt file3.txt file4.txt file5.txt file6.txt file7.txt file8.txt file9.txt output.txt
    ./mergesortMultiThread $i file1.txt file2.txt file3.txt file4.txt file5.txt file6.txt file7.txt file8.txt file9.txt file10.txt output.txt
    ./mergesortMultiThread $i file1.txt file2.txt file3.txt file4.txt file5.txt file6.txt file7.txt file8.txt file9.txt file10.txt file11.txt output.txt
    ./mergesortMultiThread $i file1.txt file2.txt file3.txt file4.txt file5.txt file6.txt file7.txt file8.txt file9.txt file10.txt file11.txt file12.txt output.txt
    ./mergesortMultiThread $i file1.txt file2.txt file3.txt file4.txt file5.txt file6.txt file7.txt file8.txt file9.txt file10.txt file11.txt file12.txt file13.txt output.txt
    ./mergesortMultiThread $i file1.txt file2.txt file3.txt file4.txt file5.txt file6.txt file7.txt file8.txt file9.txt file10.txt file11.txt file12.txt file13.txt file14.txt output.txt
    ./mergesortMultiThread $i file1.txt file2.txt file3.txt file4.txt file5.txt file6.txt file7.txt file8.txt file9.txt file10.txt file11.txt file12.txt file13.txt file14.txt file15.txt output.txt
    ./mergesortMultiThread $i file1.txt file2.txt file3.txt file4.txt file5.txt file6.txt file7.txt file8.txt file9.txt file10.txt file11.txt file12.txt file13.txt file14.txt file15.txt file16.txt output.txt
done