Algorithm
Define partition(arr, low, high) function:
Choose the last element as the pivot.
Rearrange elements so that smaller elements are on the left and larger ones are on the right.
Return the pivot's final index.

Define quick_sort(arr, low, high) function:
If low < high, find the partition index.
Recursively apply Quick Sort to the left and right subarrays.

Define measure_time(arr) function:
Record the start time.
Call quick_sort(arr, 0, len(arr) - 1).
Record and return the elapsed time.

Generate input sizes (sizes):
Create an array of increasing input sizes using np.linspace(100, 2000, 10).

Measure sorting time for best and worst cases:
Best case: Already sorted array [0, 1, 2, ..., size-1] (O(n log n)).
Worst case: Reverse sorted array [size-1, ..., 2, 1, 0] (O(n²)).
Store the execution times in separate lists.

Plot the results:
Use matplotlib to create a graph.
Plot Best Case (O(n log n)) in green and Worst Case (O(n²)) in red.
Label axes and add a title and legend.

import time
import matplotlib.pyplot as plt
import numpy as np

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

def measure_time(arr):
    start_time = time.time()
    quick_sort(arr, 0, len(arr) - 1)
    return time.time() - start_time

sizes = np.linspace(100, 2000, 10, dtype=int)
best_case_times = []
worst_case_times = []

for size in sizes:
    best_case = list(range(size))  
    worst_case = list(range(size, 0, -1)) 
    
    best_case_times.append(measure_time(best_case))
    worst_case_times.append(measure_time(worst_case))

plt.figure(figsize=(10, 6))
plt.plot(sizes, best_case_times, label='Best Case (O(n log n))', marker='o', color='green')
plt.plot(sizes, worst_case_times, label='Worst Case (O(n^2))', marker='s', color='red')
plt.xlabel('Input Size')
plt.ylabel('Time (seconds)')
plt.title('Quick Sort Complexity Analysis')
plt.legend()
plt.grid(True)
plt.show()
