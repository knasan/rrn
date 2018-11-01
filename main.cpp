/**
 * @title              : rrn, recursive rename
 * @author             : Sandy Marko Knauer
 * @email              : github@knasan.de
 * @version            : 0.0.1
 * @last modified      : Wed, 08 Aug 2018 00:00:34 +0200
 */

#include <iostream>
#include <string>

// Boost
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

// rrn
#include "rrn.hpp"

namespace {
  const size_t ERROR_IN_COMMAND_LINE = 1;
  const size_t SUCCESS = 0;
  const size_t ERROR_UNHANDLED_EXCEPTION = 2;
} // namespace

namespace po = boost::program_options;

int main(int argc, char** argv)
{
  std::string destination, find, replace;
  Rrn *rrn = new Rrn();
  std::string appName = boost::filesystem::basename(argv[0]);
  try
  {
    /** Define and parse program options
     *
     */
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "help screen")
        ("destination,d", po::value<std::string>(),
         "destination file or directory")
        ("search-character,s", po::value<std::string>()->required(),
         "search character")
        ("replace-character,r", po::value<std::string>()->required(),
         "to be replaced sign")
        ("verbose,v", "verbose mode")
        ("try,t", "try-run");

    po::variables_map vm;

    try
    {
      // store can throw
      po::store(po::parse_command_line(argc, argv, desc), vm);
      po::notify(vm);

      /** --help option
       */
      if ((vm.count("help")) || (argc < 4) )
      {
        std::cout << appName << std::endl;
        std::cout << desc    << std::endl;
        return ERROR_IN_COMMAND_LINE;
      }

      /** --destination, if not specified, the current directory is searched
       */
      if (vm.count("destination"))
        destination = vm["destination"].as<std::string>();
      else
        destination = "./";

      /** --search-character
       */
      if (vm.count("search-character"))
        find    = vm["search-character"].as<std::string>();

      /** --replace-character
       */
      if (vm.count("replace-character"))
        replace = vm["replace-character"].as<std::string>();

      /** --verbose
       */
      if (vm.count("verbose"))
        rrn->verbose = true;

      /** --try
       */
      if (vm.count("try"))
        rrn->tryrun = true;

    } // store try
    catch(po::error &e)
    {
      std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
      std::cerr << desc << std::endl;
      return ERROR_IN_COMMAND_LINE;
    }

    // application
    bool ok = rrn->rrname(find, replace, destination);
    delete(rrn);
    if (!ok) {
      std::cerr << "ERROR: " << appName << " failed - Sorry for inconsistency."
                << std::endl;
      return ERROR_UNHANDLED_EXCEPTION;
    }
  }
  catch(std::exception& e)
  {
    std::cerr << e.what() << ", " << appName << " will now exit" << std::endl;
  }
  return SUCCESS;
}
