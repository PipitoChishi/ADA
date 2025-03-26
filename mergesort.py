Algorithm
Define merge_sort(arr) function:
If len(arr) > 1:
Divide the array into two halves (left_half and right_half).
Recursively sort both halves.
Merge sorted halves back together.
Use two pointers to merge elements in sorted order.

Define measure_time(arr) function:
Record the start time.
Call merge_sort(arr).
Record and return the elapsed time.

Generate input sizes (sizes):
Create an array of increasing input sizes using np.linspace(100, 2000, 10).

Measure sorting time for best and worst cases:
Best case: Already sorted array [0, 1, 2, ..., size-1] (O(n log n)).
Worst case: Reverse sorted array [size-1, ..., 2, 1, 0] (O(n log n)).
Store the execution times in separate lists.

Plot the results:
Use matplotlib to create a graph.
Plot Best Case (O(n log n)) in green and Worst Case (O(n log n)) in red.
Label axes and add a title and legend.


import time
import matplotlib.pyplot as plt
import numpy as np

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]
        
        merge_sort(left_half)
        merge_sort(right_half)
        
        i = j = k = 0
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1
        
        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1
        
        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

def measure_time(arr):
    start_time = time.time()
    merge_sort(arr)
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
plt.plot(sizes, worst_case_times, label='Worst Case (O(n log n))', marker='s', color='red')
plt.xlabel('Input Size')
plt.ylabel('Time (seconds)')
plt.title('Merge Sort Complexity Analysis')
plt.legend()
plt.grid(True)
plt.show()
