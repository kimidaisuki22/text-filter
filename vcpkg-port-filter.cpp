#include <cy/io/read_to_buffer.h>
#include <cy/text/process.h>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>
int main(int argc, char **argv) {
  std::vector<std::string> results;
  auto buffers = cy::io::read_to_buffer(std::cin);

  auto lines = cy::text::to_lines(std::string(buffers.data(), buffers.size()));
  for (auto line : lines) {
    if (line.empty()) {
      continue;
    }
    if (!isspace(line.front())) {
      continue;
    }
    line = cy::text::trim(line);

    auto ok = cy::text::contains(line, "find_package") ||
              cy::text::contains(line, "target_link_libraries");
    if (ok) {
      results.push_back(line);
    }
  }

  std::ranges::sort(results);
  std::ranges::unique(results);
  for (auto l : results) {
    if (argc > 1) {
      std::string_view pattern = "(main ";
      auto pos = l.find(pattern);
      if (pos != std::string::npos) {
        l.replace(pos + 1, pattern.size() - 2 , argv[1]);
      }
    }

    std::cout << l << "\n";
  }
}
