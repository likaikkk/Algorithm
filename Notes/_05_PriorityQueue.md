# 优先队列

C++中的优先队列（Priority Queue）是一种特殊类型的队列，它在元素出队时不是按照先进先出（FIFO）的顺序出队，而是按照元素的优先级出队，优先级高的元素先出队。这意味着在优先队列中，你可以确保在任何时候都可以访问到具有最高优先级的元素。

C++中的优先队列通常使用堆（Heap）数据结构来实现，特别是使用最大堆（Max Heap）或最小堆（Min Heap）。最大堆保证队列中具有最高优先级的元素位于队列的顶部，而最小堆则保证队列中具有最低优先级的元素位于顶部。

在 C++中，你可以使用 STL（标准模板库）中的 std::priority_queue 类来创建和操作优先队列。以下是一个简单的示例，演示了如何使用 std::priority_queue：

```cpp
#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> maxHeap; // 默认是最大堆
    maxHeap.push(30);
    maxHeap.push(10);
    maxHeap.push(25);

    std::cout << "Top element of maxHeap: " << maxHeap.top() << std::endl; // 输出 30

    maxHeap.pop(); // 弹出顶部元素
    std::cout << "Top element after pop: " << maxHeap.top() << std::endl; // 输出 25

    return 0;
}
```

```cpp
#include <iostream>
#include <queue> // 包含优先队列的头文件

int main() {
    // 创建一个最小堆优先队列，存储整数类型的元素
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // 向最小堆中插入元素
    minHeap.push(30);
    minHeap.push(10);
    minHeap.push(25);

    // 访问最小堆中的顶部元素（最小元素）
    std::cout << "Top element of minHeap: " << minHeap.top() << std::endl; // 输出 10

    // 弹出最小堆的顶部元素
    minHeap.pop();

    // 再次访问最小堆中的顶部元素
    std::cout << "Top element after pop: " << minHeap.top() << std::endl; // 输出 25

    return 0;
}
```
