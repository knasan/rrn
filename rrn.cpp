#include "rrn.hpp"

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <iterator>

#include <boost/filesystem.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/filesystem/exception.hpp>
#include <boost/algorithm/string.hpp>

namespace fs = boost::filesystem;

/**
 * @brief Rrn::rrnameString
 * @param s_search character of search
 * @param s_replace character to replace
 * @param s_toReplace character
 * @return call boost::replace_all_copy function
 */
std::string Rrn::renameString(std::string s_search, std::string s_replace,
                              std::string s_toReplace)
{
  return boost::replace_all_copy(s_toReplace, s_search, s_replace);
}

/**
 * @brief Rrn::rrname
 * @param s_search character of search
 * @param s_replace character to replace
 * @param s_destination work directory
 * @return boolean
 */
bool Rrn::rrname(std::string s_search,
                 std::string s_replace,
                 std::string s_destination)
{
  bool ok = true;
  if (fs::is_directory(s_destination))
    {
      fillDirectoryVector(s_destination);

      // directory reverse iterator
      typedef std::vector<std::string>::iterator iter;
      iter from (v_directory.begin());
      iter until (v_directory.end());
      std::reverse_iterator<iter> rev_until (from);
      std::reverse_iterator<iter> rev_from (until);
      while (rev_from != rev_until)
        {
          std::ostringstream oss_tmpName;
          oss_tmpName << *rev_from;
          std::string s_tmp_str_destination = oss_tmpName.str();

          std::string s_new_destination = splitStrOnLast(s_search,
                                                         s_replace,
                                                         s_tmp_str_destination);

          if (s_tmp_str_destination == s_new_destination)
            {
              rev_from++;
              continue;
            }

          if (verbose)
            {
              std::cout << s_tmp_str_destination << " => " << s_new_destination
                        << std::endl;
            }

          fs::path oldPath{s_tmp_str_destination};
          fs::path newPath{s_new_destination};

          try {
            if (!tryrun)
              {
                fs::rename(oldPath.c_str(),newPath.c_str());
              }
          }
          catch (fs::filesystem_error& ex)
          {
            std::cerr << "Error: " << ex.what() << std::endl;
            ok = false;
          }
          rev_from++;
        }
    }

  // it no longer needs to be scanned for file or directory.
  // because the directory is not listed in v_directory vector.
  // therefore, everything that comes can be renamed.
  std::string s_new_destination = renameString(s_search, s_replace,
                                               s_destination);
  fs::path oldPath{s_destination};
  fs::path newPath{s_new_destination};

  if (s_destination != s_new_destination)
    {
      if (verbose)
        {
          std::cout << s_destination << " => " << s_new_destination
                    << std::endl;
        }

      try {
        if (!tryrun)
          {
            fs::rename(oldPath.c_str(),newPath.c_str());
          }
      }
      catch (fs::filesystem_error& ex)
      {
        std::cerr << "Error: " << ex.what() << std::endl;
        ok = false;
      }
    }
  return ok;
}

/**
 * @brief Rrn::fillDirectoryVector
 * @param s_directory fill vecotor
 */
void Rrn::fillDirectoryVector(std::string s_directory)
{
  v_directory.clear();
  fs::path dir{s_directory};
  fs::recursive_directory_iterator rit{dir};
  while (rit != fs::recursive_directory_iterator{})
    {
      v_directory.push_back(rit->path().string());
      rit++;
    }
}

/**
 * @brief Rrn::splitStrOnLast
 * @param s_search character of search
 * @param s_replace character to replace
 * @param s_destination work directory
 * @return list of last_renamed
 * Example:
            /home/users/user/this is a directory/with a directory
  result => /home/users/user/this is a directory/with_a_directory
 */
std::string Rrn::splitStrOnLast(std::string s_search,
                                std::string s_replace,
                                std::string s_destination)
{
  // i_cnumber, is a directory -2, is a file -1
  // directory have a empty in vector
  unsigned int i_cnumber = 0;
  if (fs::is_directory(s_destination))
    i_cnumber = 2;
  else
    i_cnumber = 1;

  std::vector<std::string> v_tmp;
  isDirAndAtWithSlash(s_destination);

  // Save the first two characters.
  // ./ or only /
  // Absolute path and relative path
  int counter = 0;
  std::string s_firstCharacters;
  for (std::string::iterator it = s_destination.begin();
       it != s_destination.end(); ++it)
    {
      std::ostringstream oss_tmp;
      oss_tmp << *it;
      if (oss_tmp.str() != "/")
        break;

      if (counter == 0 || counter == 1)
        {
          if (oss_tmp.str() == "/")
            {
              s_firstCharacters.append(oss_tmp.str());
              counter++;
              if (counter == 1)
                break;
            } //  str_firstCharacters end
        } // counter end
      else
        {
          break;
        }
    }

  boost::split(v_tmp, s_destination, boost::is_any_of("/"));

  std::string str_last = v_tmp[v_tmp.size()-i_cnumber];

  std::string s_last_renamed =
      renameString(s_search, s_replace, str_last);

  // Put the v_tmp together again.
  std::string result;
  result.append(s_firstCharacters);
  for (unsigned int i = 0; i < v_tmp.size()-i_cnumber; i++)
    {
      if (v_tmp[i] != "")
        {
          result.append(v_tmp[i]);
          isDirAndAtWithSlash(result);
        }
    }
  result.append(s_last_renamed);
  isDirAndAtWithSlash(result);
  return result;
}

/**
 * @brief Rrn::isDirAndAtWithSlash
 * @param s_dir  Adress for directory
 * @todo Check if the last character is on /.
 */
void Rrn::isDirAndAtWithSlash(std::string &s_dir)
{
  if (fs::is_directory(s_dir))
    {
      std::ostringstream oss;
      oss << s_dir.at(s_dir.size()-1);
      if (oss.str() != "/")
        s_dir.append("/");
    }
}
