Algorithm:
Define bubble_sort(arr) function:
Iterate through the array n-1 times.
In each pass, compare adjacent elements and swap if needed.
Use a swapped flag to break early if the array is already sorted.

Define measure_time(arr) function:
Record the start time.
Call bubble_sort(arr).
Record and return the elapsed time.

Generate input sizes (sizes):
Create an array of increasing input sizes using np.linspace(100, 2000, 10).

Measure sorting time for best and worst cases:
Best case: Already sorted array [0, 1, 2, ..., size-1].
Worst case: Reverse sorted array [size-1, ..., 2, 1, 0].
Store the execution times in separate lists.

Plot the results:
Use matplotlib to create a graph.
Plot Best Case (O(n)) in green and Worst Case (O(n²)) in red.
Label axes and add a title and legend.

import time
import matplotlib.pyplot as plt
import numpy as np
import random

def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        swapped = False
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break

def measure_time(arr):
    start_time = time.time()
    bubble_sort(arr)
    return time.time() - start_time

sizes = np.linspace(100, 2000, 10, dtype=int)
best_case_times = []
worst_case_times = []

for size in sizes:
    best_case = list(range(size))  # Already sorted (Best Case)
    worst_case = list(range(size, 0, -1))  # Reverse sorted (Worst Case)
    
    best_case_times.append(measure_time(best_case))
    worst_case_times.append(measure_time(worst_case))

plt.figure(figsize=(10, 6))
plt.plot(sizes, best_case_times, label='Best Case (O(n))', marker='o', color='green')
plt.plot(sizes, worst_case_times, label='Worst Case (O(n^2))', marker='s', color='red')
plt.xlabel('Input Size')
plt.ylabel('Time (seconds)')
plt.title('Bubble Sort Complexity Analysis')
plt.legend()
plt.grid(True)
plt.show()
