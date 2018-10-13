#ifndef PROGRAM_OPTIONS_H
#define PROGRAM_OPTIONS_H

#include <cstddef>
#include <string>

class ProgramOptions
{
public:
  ProgramOptions(int argc, char** argv);
  ~ProgramOptions(void);

  bool hasHelp(void) const;
  std::string helpLines(void) const;
  std::size_t length(void) const;
  std::string user(void) const;
  std::string domain(void) const;

private:
  bool hasHelp_;
  std::string helpLines_;
  std::size_t length_;
  std::string user_;
  std::string domain_;
};

#endif  // PROGRAM_OPTIONS_H
