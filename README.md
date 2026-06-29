#Conway's Game of Life (C++)


This project is a console-based implementation of Conway's Game of Life written in C++. The user can define the size of the grid, place initial live cells, and observe how the population evolves according to Conway's cellular automaton rules.

##Conway's Rules

For each generation:

###Living Cell:
Fewer than 2 neighbors → Dies (underpopulation)
2 or 3 neighbors → Survives
More than 3 neighbors → Dies (overpopulation)

###Dead Cell:
Exactly 3 neighbors → Becomes alive (reproduction)

##Usage
Enter the desired number of rows.
Enter the desired number of columns.
Input coordinates for initial live cells.
Continue adding cells until finished.
Start the simulation and observe each generation.
