#!/bin/bash

output_file="Results/time_report.csv"

echo "Test_No, Status, Time_Taken(ms)" > $output_file

test_no=1

for unit in Unit_test/unit_*; do
    unit_id=$(basename $unit | cut -d'_' -f2)
    
    start=$(date +%s%3N)
    
    status=$(./driver $unit_id)

    end=$(date +%s%3N)
    time_taken=$((end - start))

    echo "$test_no, $status, $time_taken" >> $output_file
    test_no=$((test_no + 1))
done

echo "Time report generated in $output_file"
