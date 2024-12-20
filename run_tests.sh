#!/bin/bash

# Output file for results
output_file="Results/time_report.csv"

# Header for the CSV file
echo "Test_No, Unit_Id, Variation, Status, Time_Taken(ms), Remarks" > $output_file

# Variations of matrix multiplication
variations=("ijk" "ikj" "jik" "jki" "kij" "kji")

# Initialize test counter
test_no=1

# Iterate over each test case
for unit in Unit_test/unit_*; do
    # Extract the unit number
    unit_id=$(basename $unit | cut -d'_' -f2)

    # Run each variation
    for variation in "${variations[@]}"; do

        # Compile the driver with the corresponding variation
        gcc driver.c -o driver

        # Run the driver
        status_time_remarks=$(./driver $unit_id $variation)

        # Append the result to the CSV file
        echo "$test_no, $unit_id, $variation, $status_time_remarks" >> $output_file
        echo "$test_no, $unit_id, $variation, $status_time_remarks"

        test_no=$((test_no + 1))
    done
    echo "" >> $output_file
done

echo "Time report generated in $output_file"
