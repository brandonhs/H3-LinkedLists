#include <iostream>
#include <vector>
#include <list>
#include <chrono>

// Function to display the progress bar
void printProgressBar(double progress)
{
    int barWidth = 70;
    std::cout << "[";
    int pos = barWidth * progress;
    for (int i = 0; i < barWidth; ++i)
    {
        if (i < pos)
            std::cout << "=";
        else if (i == pos)
            std::cout << ">";
        else
            std::cout << " ";
    }
    std::cout << "] " << int(progress * 100.0) << " %\r";
    std::cout.flush();
}

void testInsertBeginning(int numElements)
{
    std::cout << "\nStarting Insert Beginning test:\n";

    // Vector test
    std::vector<int> vec;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        vec.insert(vec.begin(), i);
        if (i % (numElements / 100) == 0)
        { // Update every 1%
            printProgressBar(static_cast<double>(i) / numElements);
        }
    }
    printProgressBar(1.0); // Complete the progress bar
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "\nVector Insert Beginning: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";

    // List test
    std::list<int> lst;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        lst.push_front(i);
        if (i % (numElements / 100) == 0)
        {
            printProgressBar(static_cast<double>(i) / numElements);
        }
    }
    printProgressBar(1.0);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "\nList Insert Beginning: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";
}

void testInsertEnd(int numElements)
{
    std::cout << "\nStarting Insert End test:\n";

    // Vector test
    std::vector<int> vec;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        vec.push_back(i);
        if (i % (numElements / 100) == 0)
        {
            printProgressBar(static_cast<double>(i) / numElements);
        }
    }
    printProgressBar(1.0);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "\nVector Insert End: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";

    // List test
    std::list<int> lst;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        lst.push_back(i);
        if (i % (numElements / 100) == 0)
        {
            printProgressBar(static_cast<double>(i) / numElements);
        }
    }
    printProgressBar(1.0);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "\nList Insert End: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";
}

void testRemoveBeginning(int numElements)
{
    std::cout << "\nStarting Remove Beginning test:\n";

    // Vector test
    std::vector<int> vec(numElements);
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        vec.erase(vec.begin());
        if (i % (numElements / 100) == 0)
        {
            printProgressBar(static_cast<double>(i) / numElements);
        }
    }
    printProgressBar(1.0);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "\nVector Remove Beginning: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";

    // List test
    std::list<int> lst(numElements);
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        lst.pop_front();
        if (i % (numElements / 100) == 0)
        {
            printProgressBar(static_cast<double>(i) / numElements);
        }
    }
    printProgressBar(1.0);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "\nList Remove Beginning: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";
}

void testRemoveEnd(int numElements)
{
    std::cout << "\nStarting Remove End test:\n";

    // Vector test
    std::vector<int> vec(numElements);
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        vec.pop_back();
        if (i % (numElements / 100) == 0)
        {
            printProgressBar(static_cast<double>(i) / numElements);
        }
    }
    printProgressBar(1.0);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "\nVector Remove End: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";

    // List test
    std::list<int> lst(numElements);
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        lst.pop_back();
        if (i % (numElements / 100) == 0)
        {
            printProgressBar(static_cast<double>(i) / numElements);
        }
    }
    printProgressBar(1.0);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "\nList Remove End: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";
}

int main()
{
    int testSizes[] = {1000000, 2000000, 3000000}; // Adjust as needed

    for (int size : testSizes)
    {
        std::cout << "\nTesting with " << size << " elements:\n";

        testInsertBeginning(size);
        testInsertEnd(size);
        testRemoveBeginning(size);
        testRemoveEnd(size);
    }

    return 0;
}
