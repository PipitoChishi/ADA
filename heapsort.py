Algorithm
Define heapify(arr, n, i) function:
Assume i as the largest element (root).
Compute the left (2*i + 1) and right (2*i + 2) child indices.
Compare root with its children and update largest if needed.
Swap root with the largest child and recursively heapify.

Define heap_sort(arr) function:
Build a max heap by calling heapify() for all non-leaf nodes (from n//2 - 1 to 0).
Extract elements one by one by swapping the root with the last element.
Call heapify() on the reduced heap.

Define measure_time(arr) function:
Record the start time.
Call heap_sort(arr).
Record and return the elapsed time.

Generate input sizes (sizes):
Create an array of increasing input sizes using np.linspace(100, 2000, 10)

Measure sorting time for best and worst cases:
Best case: Already sorted array [0, 1, 2, ..., size-1].
Worst case: Reverse sorted array [size-1, ..., 2, 1, 0].
Store the execution times in separate lists.

Plot the results:
Use matplotlib to create a graph.
Plot Best Case (O(n log n)) in green and Worst Case (O(n log n)) in red.
Label axes and add a title and legend.


import time
import matplotlib.pyplot as plt
import numpy as np
import random

def heapify(arr, n, i):
    largest = i   
    left = 2 * i + 1  
    right = 2 * i + 2   

    if left < n and arr[left] > arr[largest]:
        largest = left
    if right < n and arr[right] > arr[largest]:
        largest = right
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

def measure_time(arr):
    start_time = time.time()
    heap_sort(arr)
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
plt.plot(sizes, best_case_times, label='Best Case (O(n log n))', marker='o', color='green')
plt.plot(sizes, worst_case_times, label='Worst Case (O(n log n))', marker='s', color='red')
plt.xlabel('Input Size')
plt.ylabel('Time (seconds)')
plt.title('Heap Sort Complexity Analysis')
plt.legend()
plt.grid(True)
plt.show()
