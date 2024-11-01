#!/bin/bash

echo "date | value
2005-02-02 || 0.1
2011-09-14 abc| 390.57
2010-11-03 || 517.239
2020-06-26 | 998.808 |
2014-03-16 | 632.64 a
2014-03-17 | 632.64 | a
2014-03-18 | 632.64 | aa
2014-03-19 | 632.64;
2014-03-20 | 632.64 ;
2014-03-21 | 632.64 | ;
2014-03-22 | 632.64 a |
2014-03-23 | 632.64 a | a
2014-03-24 ; | 632.64
2014-03-25 | ; 632.64
2014-03-26 | a
2014-03-27 | 
2a14-03-28 | 632.64
0014-03-29 | 632.64
2014/03/30 | 632.64
2014-33-16 | 632.64
2014-03-01 | 632.64.18
2014-04-2 | 0..
2014-03-3 | -0.1
2014-03-4 | -32 | 1
2014-03-5 | 632.64]{}{}
2014a-03-6 | 632.64
2014-03-7a | 632.64
2014-03-8; | 632.64
2014;-03-16 | 632.64" > invalidInput.txt

echo "date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648" > subjectInput.txt

echo "date | value
2005-02-02 | 0.1
2011-09-14 | 390.57
2010-11-03 | 517.239
2020-06-26 | 998.808
2012-07-09 | 1242.2
2019-07-11 | 700.492
2019-06-25 | 416.636
2017-05-22 | 507.753
2012-12-23 | 1146.69
2013-12-02 | 1293.19
2016-12-12 | 1602.81
2017-04-22 | 737.216
2014-11-26 | 782.601
2015-07-13 | 583.763
2013-04-12 | 353.688
2009-11-06 | 1018.34
2010-11-19 | 396.835
2020-03-29 | 1558.83
2014-01-26 | 1800.22
2016-07-30 | 515.044
2014-03-16 | 632.64" > correctionInput.csv

touch emptyInput.txt

./btc invalidInput.txt >> my_output
./btc subjectInput.txt >> my_output
./btc correctionInput.csv >> my_output
./btc >> my_output
./btc emptyInput.txt >> my_output

echo "Error: bad input => 2005-02-02 || 0.1
Error: bad input => 2011-09-14 abc| 390.57
Error: bad input => 2010-11-03 || 517.239
Error: bad input => 2020-06-26 | 998.808 |
Error: bad input => 2014-03-16 | 632.64 a
Error: bad input => 2014-03-17 | 632.64 | a
Error: bad input => 2014-03-18 | 632.64 | aa
Error: value is invalid.
Error: bad input => 2014-03-20 | 632.64 ;
Error: bad input => 2014-03-21 | 632.64 | ;
Error: bad input => 2014-03-22 | 632.64 a |
Error: bad input => 2014-03-23 | 632.64 a | a
Error: bad input => 2014-03-24 ; | 632.64
Error: bad input => 2014-03-25 | ; 632.64
Error: bad input => 2014-03-26 | a
Error: bad input => 2014-03-27 | 
Error: bad input => 2a14-03-28 | 632.64
Error: bitcoin was not available at this date => 0014-03-29
Error: bad input => 2014/03/30 | 632.64
Error: bad input => 2014-33-16 | 632.64
Error: value is invalid.
Error: bad input => 2014-04-2 | 0..
Error: bad input => 2014-03-3 | -0.1
Error: bad input => 2014-03-4 | -32 | 1
Error: bad input => 2014-03-5 | 632.64]{}{}
Error: bad input => 2014a-03-6 | 632.64
Error: bad input => 2014-03-7a | 632.64
Error: bad input => 2014-03-8; | 632.64
Error: bad input => 2014;-03-16 | 632.64
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
Error: bitcoin was not available at this date => 2005-02-02
2011-09-14 => 390.57 = 2417.63
2010-11-03 => 517.239 = 108.62
2020-06-26 => 998.808 = 9.26552e+06
Error: too large a number.
2019-07-11 => 700.492 = 8.81694e+06
2019-06-25 => 416.636 = 4.59029e+06
2017-05-22 => 507.753 = 1.01999e+06
Error: too large a number.
Error: too large a number.
Error: too large a number.
2017-04-22 => 737.216 = 911663
2014-11-26 => 782.601 = 287105
2015-07-13 => 583.763 = 181288
2013-04-12 => 353.688 = 44175.6
Error: too large a number.
2010-11-19 => 396.835 = 111.114
Error: too large a number.
Error: too large a number.
2016-07-30 => 515.044 = 337544
2014-03-16 => 632.64 = 401720
Error: could not open file.
Error: file is empty." >> correct_output

echo "Error: can't open file or is not accessible.
Error: could not open database file.
Error: wrong number of arguments.
Usage: ./btc <database>" >> error_check

my_output=$(diff my_output correct_output | wc -l)

if [ $my_output -eq 0 ]; then
    echo -e "\033[32mTEST NORMAL USE PASSED!\033[0m"
else
	echo -e "\033[31mTEST NORMAL USE FAILED!\033[0m"
fi

chmod 000 correctionInput.csv
./btc correctionInput.txt > my_output
chmod 000 data.csv
chmod 666 correctionInput.csv
./btc correctionInput.txt >> my_output
./btc correctionInput.txt extra_argument >> my_output
chmod 666 data.csv

my_output=$(diff my_output error_check | wc -l)

