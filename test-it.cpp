#include <iostream>
#include <vector>
#include <chrono>

// Function to display a progress bar
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

void testForLoop(const std::vector<std::string> &authorsList)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < authorsList.size(); i++)
    {
        auto authorName = authorsList[i];
        // Update the progress bar every 1% of completion
        if (i % (authorsList.size() / 100) == 0)
        {
            printProgressBar(static_cast<double>(i) / authorsList.size());
        }
    }
    printProgressBar(1.0); // Complete the progress bar

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "\nFor loop time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";
}

void testIterator(const std::vector<std::string> &authorsList)
{
    auto start = std::chrono::high_resolution_clock::now();

    auto it = authorsList.begin();
    size_t count = 0;
    while (it != authorsList.end())
    {
        auto authorName = *it;
        ++it;

        // Update the progress bar every 1% of completion
        if (count % (authorsList.size() / 100) == 0)
        {
            printProgressBar(static_cast<double>(count) / authorsList.size());
        }
        ++count;
    }
    printProgressBar(1.0); // Complete the progress bar

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "\nIterator loop time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";
}

int main()
{
    // Initialize a large vector of strings
    std::vector<std::string> authorsList(100000000, "Author Name");

    // Measure time for each loop
    std::cout << "\nMeasuring for 100,000,000 elements:\n";
    testForLoop(authorsList);
    testIterator(authorsList);

    return 0;
}
