#ifndef PROGRAM_OPTIONS_H
#define PROGRAM_OPTIONS_H

#include <cstddef>
#include <string>
#include <vector>

class ProgramOptions
{
public:
  ProgramOptions(const std::vector<const char*>& args);
  ~ProgramOptions(void) =default;

  bool hasHelp(void) const;
  std::string helpLines(void) const;
  std::size_t length(void) const;
  std::string user(void) const;
  std::string domain(void) const;

private:
  bool        hasHelp_;
  std::string helpLines_;
  std::size_t length_;
  std::string user_;
  std::string domain_;
};

#endif  // PROGRAM_OPTIONS_H
