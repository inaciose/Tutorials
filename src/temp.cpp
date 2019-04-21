#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
template<typename Clock, typename Duration>
std::ostream &operator<<(std::ostream &stream,
  const std::chrono::time_point<Clock, Duration> &time_point) {
  const time_t time = Clock::to_time_t(time_point);
#if __GNUC__ > 4 || \
    ((__GNUC__ == 4) && __GNUC_MINOR__ > 8 && __GNUC_REVISION__ > 1)
  // Maybe the put_time will be implemented later?
  struct tm tm;
  localtime_r(&time, &tm);
  return stream << std::put_time(&tm, "%c"); // Print standard date&time
#else
  char buffer[26];
  ctime_r(&time, buffer);
  buffer[24] = '\0';  // Removes the newline that is added
  return stream << buffer;
#endif
}
auto start = std::chrono::high_resolution_clock::now();
int main() {
  std::cout << std::chrono::system_clock::now() << std::endl;
  // Wed May 22 14:17:03 2013




  auto elapsed = std::chrono::high_resolution_clock::now() - start;

  long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();


  std::cout<<microseconds <<std::endl;
}
