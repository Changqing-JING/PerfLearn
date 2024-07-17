#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
std::condition_variable cv;
bool ready = false; // Flag to indicate the data is ready
int data = 0;       // Shared data between producer and consumer

void producer() {
  std::this_thread::sleep_for(std::chrono::milliseconds(3000)); // Simulate work
  std::lock_guard<std::mutex> lock(mtx);
  data = 42; // Produce data
  ready = true;
  std::cout << "Producer: Data produced\n";
  cv.notify_one(); // Notify the consumer
}

void consumer() {
  std::unique_lock<std::mutex> lock(mtx);
  cv.wait(lock, [] { return ready; }); // Wait for data to be ready
  std::cout << "Consumer: Data consumed: " << data << std::endl;
}

int main() {
  std::thread producerThread(producer);
  std::thread consumerThread(consumer);

  producerThread.join();
  consumerThread.join();

  return 0;
}