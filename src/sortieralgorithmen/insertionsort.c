/*********************** GNU General Public License 3.0 ***********************\
|                                                                              |
|  Copyright (C) 2023 Lukas Fischer                                            |
|                                                                              |
|  This program is free software: you can redistribute it and/or modify        |
|  it under the terms of the GNU General Public License as published by        |
|  the Free Software Foundation, either version 3 of the License, or           |
|  (at your option) any later version.                                         |
|                                                                              |
|  This program is distributed in the hope that it will be useful,             |
|  but WITHOUT ANY WARRANTY; without even the implied warranty of              |
|  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               |
|  GNU General Public License for more details.                                |
|                                                                              |
|  You should have received a copy of the GNU General Public License           |
|  along with this program.  If not, see <https://www.gnu.org/licenses/>.      |
|                                                                              |
\******************************************************************************/

// https://www.chrislaux.com/de/miscsort
//  https://de.wikipedia.org/wiki/Insertionsort
//  https://www.hackerearth.com/practice/algorithms/sorting/insertion-sort/visualize/

/*
Der Insertion-Sort-Algorithmus sortiert eine Liste, indem er jedes Element durchläuft und es an die
richtige Position innerhalb des bereits sortierten Teils der Liste einfügt.
Hierzu vergleicht er das aktuelle Element mit den bereits sortierten Elementen
und platziert es an der entsprechenden Stelle im sortierten Bereich.
*/

#include <stdio.h>

// Iterative Insertion Sort
void insertionSortIterative(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Rekursive Insertion Sort
void insertionSortRecursive(int arr[], int n)
{
    if (n <= 1)
        return;

    insertionSortRecursive(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsortiertes Array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Iterative Insertion Sort
    insertionSortIterative(arr, n);

    printf("\nSortiertes Array iterativ: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    int arr2[] = {12, 11, 13, 5, 6}; // Resetting the array

    // Recursive Insertion Sort
    insertionSortRecursive(arr2, n);

    printf("\nSortiertes Array rekrusiv: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr2[i]);
    printf("\n");

    return 0;
}
