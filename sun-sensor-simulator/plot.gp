set title "angle vs current"

# Set labels for the x and y axes
set xlabel "angle [deg]"
set ylabel "current [units]"

# Set the range for the x and y axes (if needed)
# set xrange [xmin:xmax]
# set yrange [ymin:ymax]

# Specify the output file format and name
set terminal png
set output "plot2.png"

# Plot the data from a file
plot "build/res2.txt" using 1:2 with points pointtype 7 pointsize 1 title "Data Points"

