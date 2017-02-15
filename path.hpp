#include <cstdlib>
#include <iostream>
#include <limits.h>
#include <stdio.h> /* defines FILENAME_MAX */
#include <unistd.h>

std::string getDirPath() // from:
                         // http://stackoverflow.com/questions/143174/how-do-i-get-the-directory-that-a-program-is-running-from
{
  char buff[FILENAME_MAX];
  getcwd(buff, FILENAME_MAX);
  std::string current_working_dir(buff);
  return current_working_dir;
}

std::string
getExePath() // from: http://www.codebind.com/cpp-tutorial/c-get-current-directory-linuxwindows/
{
  char result[PATH_MAX];
  ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
  return std::string(result, (count > 0) ? count : 0);
}
