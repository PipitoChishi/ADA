Algorithm
Define insertion_sort(arr) function:
Iterate through the array from index 1 to n-1.
Store arr[i] as the key and compare it with previous elements.
Shift larger elements one position to the right.
Place the key in its correct position.

Define measure_time(arr) function:
Record the start time.
Call insertion_sort(arr).
Record and return the elapsed time.

Generate input sizes (sizes):
Create an array of increasing input sizes using np.linspace(100, 2000, 10).

Measure sorting time for best and worst cases:
Best case: Already sorted array [0, 1, 2, ..., size-1] (O(n)).
Worst case: Reverse sorted array [size-1, ..., 2, 1, 0] (O(n²)).
Store the execution times in separate lists.

Plot the results:
Use matplotlib to create a graph.
Plot Best Case (O(n)) in green and Worst Case (O(n²)) in red.
Label axes and add a title and legend.


import time
import matplotlib.pyplot as plt
import numpy as np

def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def measure_time(arr):
    start_time = time.time()
    insertion_sort(arr)
    return time.time() - start_time

sizes = np.linspace(100, 2000, 10, dtype=int)
best_case_times = []
worst_case_times = []

for size in sizes:
    best_case = list(range(size))  # Already sorted (Best Case O(n))
    worst_case = list(range(size, 0, -1))  # Reverse sorted (Worst Case O(n^2))
    
    best_case_times.append(measure_time(best_case))
    worst_case_times.append(measure_time(worst_case))

plt.figure(figsize=(10, 6))
plt.plot(sizes, best_case_times, label='Best Case (O(n))', marker='o', color='green')
plt.plot(sizes, worst_case_times, label='Worst Case (O(n^2))', marker='s', color='red')
plt.xlabel('Input Size')
plt.ylabel('Time (seconds)')
plt.title('Insertion Sort Complexity Analysis')
plt.legend()
plt.grid(True)
plt.show()
