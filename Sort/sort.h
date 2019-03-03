#include <iostream>
#include <cmath>

template <class T>
void bub(T p[], int n)  // 冒泡排序
{
    for(int i = 0;i < n; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            if (p[j] > p[j + 1])
            {
                T temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}


// 快速排序
template <class T>
int partition(T p[], int left, int right);

template <class T>
void swap(T p[], int i, int j);

template <class T>
void quickSort(T p[], int left, int right)
{
    int partitionIndex;
    if(left < right)
    {
        partitionIndex = partition(p, left, right);
        quickSort(p, partitionIndex + 1, right);
        quickSort(p, left, partitionIndex - 1);
    }
}

template <class T>
int partition(T p[], int left, int right)
{
    int pivot = left, index = pivot + 1;
    for(int i = index; i <= right; i++)
    {
        if (p[i] < p[pivot])
        {
            swap(p, i, index);
            index++;
        }
    }
    swap(p, pivot, index - 1);
    return index - 1;
}

template <class T>
void swap(T p[], int i, int j)
{
    T temp = p[i];
    p[i] = p[j];
    p[j] = temp;
}


// 插入排序
template <class T>
void insertSort(T p[], int n)
{
    int preIndex; T current;
    for(int i = 1; i < n; i++)
    {
        preIndex = i - 1;
        current = p[i];
        while(preIndex >= 0 && p[preIndex] >= current)
        {
            p[preIndex + 1] = p[preIndex];
            preIndex--;
        }
        p[preIndex + 1] = current;
    }
}

// 希尔排序
template <class T>
void shellSort(T p[], int n)
{
    T temp;
    int gap = n / 2;
    for(gap; gap > 0; gap /= 2)
    {
        for(int i = gap; i < n; i++)
        {
            temp = p[i];
            int j;
            for(j = i - gap; j >= 0 && p[j] > temp; j-=gap)
            {
                p[j + gap] = p[j];
            }
            p[j + gap] = temp;
        }
    }
}

// 选择排序
template <class T>
void selectionSort(T p[], int n)
{
    int minIndex;
    T temp;
    for(int i = 0; i < n; i++)
    {
        minIndex = i;
        for(int j = i + 1; j < n; j++)
        {
            if(p[j] < p[minIndex])
                minIndex = j;
        }
        temp = p[i];
        p[i] = p[minIndex];
        p[minIndex] = temp;
    }
}

// 堆排序

template <class T>
void heapify(T p[], int i, int n);

template <class T>
void buildHeapt(T p[], int n)   // 建立堆
{
    for(int i = floor(n / 2); i >= 0; i--)
        heapify(p, i, n);          // 堆调整
};

template <class T>
void heapify(T p[], int i, int n)
{
    int left = i * 2 + 1,   // 左节点下标
        right = i * 2 + 2,  // 右节点下标
        largest = i;        // 暂存最大节点下标（根节点）
    if (left < n && p[left] > p[largest]) largest = left;
    if (right < n && p[right] > p [largest]) largest = right;   // 比较根节点、左右节点

    if(largest != i)    // 最大节点不是根节点
    {
        swap(p, i, largest);    // 交换节点位置
        heapify(p, largest, n); // 递归调整节点 若最大为左节点，则调整左子树 若最大为右节点，则调整右子树
    }
}

template <class T>
void heapSort(T p[], int n)
{
    buildHeapt(p, n);   // 建立堆

    for(int i = n - 1; i > 0; i--)
    {
        swap(p, 0, i);
        n--;
        heapify(p, 0, n);
    }
}



// 归并排序

template <class T>
void merge(T p[], T tm[], int left, int center, int right);

template <class T>
void msort(T p[], T tm[], int left, int right);

template <class T>
void mergeSort(T p[], int n)
{
    if (n < 2) return;
    T* tm = new T[n];
    msort(p, tm, 0, n - 1);

}

template <class T>
void msort(T p[], T tm[], int left, int right)
{
    int center;
    if (left < right)
    {
        center = (left + right) / 2;
        msort(p, tm, left, center);
        msort(p, tm, center + 1, right);
        merge(p, tm, left, center + 1, right);
    }
}

template <class T>
void merge(T p[], T tm[], int left, int center, int right)
{
    int leftend = center - 1;  // 前半段最后位置
    int total = right - left + 1;
    int tmpos = left;

    while(left <= leftend && center <= right)
        if (p[left] <= p[center])
            tm[tmpos++] = p[left++];
        else
            tm[tmpos++] = p[center++];

    while(left <= leftend) tm[tmpos++] = p[left++];
    while(center <= right) tm[tmpos++] = p[center++];

    for(int i = 0; i < total; i++, right--) p[right] = tm[right];
}





