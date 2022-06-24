#!/bin/bash
Num=$1
g=$Num
 
# store the sum of
# digits
s=0
 
# use while loop to
# calculate the sum
# of all digits
while [ $Num -gt 0 ]
do
    # get Remainder
    k=$(( $Num % 10 ))
 
    # get next digit
    Num=$(( $Num / 10 ))
 
    # calculate sum of
    # digit 
    s=$(( $s + $k ))
done
echo  "Sum of digits of $g is : $s"