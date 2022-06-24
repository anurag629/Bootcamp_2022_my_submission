#!/bin/bash
    
for (( i=1; i < 6; i++ ))
do
	mkdir -p root/dir${i}
	for (( j=1; j < 5; j++ ))
	do
		touch root/dir${i}/file${j}
		for (( k=1; k <= j; k++ ))
		do
			echo ${j} >> root/dir${i}/file${j}
		done
	done
done

    
