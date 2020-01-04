#ifndef RRN_HPP
#define RRN_HPP

#include <boost/filesystem.hpp>
#include <string>
#include <vector>

class Rrn
{
public:
  bool rrname(std::string s_search,
              std::string s_replace,
              std::string s_destination,
              std::vector<std::string> excludefiles,
              std::vector<std::string> excludedirectories);
  bool verbose, tryrun;

private:
  std::vector<std::string> v_directory;

  std::string renameString(std::string s_search,
                           std::string s_replace,
                           std::string s_toReplace);

  void fillDirectoryVector(std::string s_directory, std::vector<std::string> excludefiles, std::vector<std::string> excludedirectories);

  std::string splitStrOnLast(std::string s_search,
                             std::string s_replace,
                             std::string s_destination);

  void isDirAndAtWithSlash(std::string &s_dir);
};

#endif // RRN_HPP
