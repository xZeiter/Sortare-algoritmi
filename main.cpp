// C++ program for implementation of 
// selection sort 
#include <bits/stdc++.h>
using namespace std;
void insertionSort(vector<int long long>& arr)
{
    int i, key, j,n = arr.size();;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function for Selection sort 
void selectionSort(vector<int long long>& arr)
{
    int long long i, j, min_idx;
    int long long n = arr.size();
    // One by one move boundary of 
    // unsorted subarray 
    for (i = 0; i < n - 1; i++) {

        // Find the minimum element in 
        // unsorted array 
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element 
        // with the first element 
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

// Function to print an array 
void printArray(vector<int long long>& arr, int long long size)
{
    int long long i;
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
        cout << endl;
    }
}
void bubbleSort(vector<int long long>& arr)
{
    int long long n = arr.size();
    int long long i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}
void merge(vector<int long long>& array, int const left, int const mid,
           int const right)
{
    int long long const subArrayOne = mid - left + 1;
    int long long const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new int long long[subArrayOne],
            *rightArray = new int long long[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                    = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                    = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<int long long>& array, int long long const begin, int long long const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
int partition(vector<int long long>& arr,int long long low,int long long high)
{
    //choose the pivot

    int long long pivot=arr[high];
    //Index of smaller element and Indicate
    //the right position of pivot found so far
    int long long i=(low-1);

    for(int long long j=low;j<=high;j++)
    {
        //If current element is smaller than the pivot
        if(arr[j]<pivot)
        {
            //Increment index of smaller element
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}

// The Quicksort function Implement

/*void quickSort(vector<int long long>& arr,int long long low,int long long high)
{
    // when low is less than high
    if(low<high)
    {
        // pi is the partition return index of pivot

        int long long pi=partition(arr,low,high);

        //Recursion Call
        //smaller element than pivot goes left and
        //higher element goes right
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}*/
void quickSort(vector<int long long>& arr, int long long low, int long long high) {
    while (low < high) {
        int long long pi = partition(arr, low, high);

        // Recur for the smaller partition, and
        // eliminate tail recursion
        if (pi - low < high - pi) {
            quickSort(arr, low, pi - 1);
            low = pi + 1;
        } else {
            quickSort(arr, pi + 1, high);
            high = pi - 1;
        }
    }
}

// A utility function to get maximum
// value in arr[]
int getMax(vector<int long long>& arr, int long long n)
{
    int long long mx = arr[0];
    for (int long long i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[]
// according to the digit
// represented by exp.
void countSort(vector<int long long>& arr, int long long n, int long long exp) {
    vector<int long long> output(n);
    vector<int long long> count(10, 0);

    for (int long long i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int long long i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int long long i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int long long i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[]
// of size n using Radix Sort
void radixsort(vector<int long long>& arr)
{
    int long long n = arr.size();
    // Find the maximum number to
    // know number of digits
    int long long m = getMax(arr, n);

    // Do counting sort for every digit.
    // Note that instead of passing digit
    // number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int long long exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
// Driver program 
int main()
{
    int long long n=1000000;
    vector<int long long> arr(n);
    vector<int long long> vec(n);
    for(int long long i=0;i<n/2;i++)
     arr[i]=rand() % 9999999999;
    for(int long long i=0;i<n;i++)
        vec[i]=rand() % 9999999999;
  std::sort(arr.begin(),arr.end());
    std::sort(vec.begin(),vec.end());
    for(int long long i=0;i<n/2;i++)
        arr[i]=vec[i];
    //std::sort(arr.begin(),arr.end(),greater<int>());
 // arr[n-1]=rand() % 9999999999;
    // Function Call
    auto begin = std::chrono::high_resolution_clock::now();
    radixsort(arr);
    //quickSort(arr, 0, n - 1);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "Sorted array: \n";
   //printArray(arr, n);
    printf("Time measured: %.50f seconds.\n", elapsed.count() * 1e-9);
    return 0;
}
