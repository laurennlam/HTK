#pragma once

#include <string>

#include "htkcommonlib_export.h"

namespace htk
{
  namespace common
  {
    namespace io
    {
      /**
       * Write text in a file. If the file doesn't exist it is created,
       * otherwise the file can be erased or not before writing.
       *
       * @param filePath Path to the output file that will contain the 'content'
       * @param content Content of the output file
       * @param appendContent If the file already exists, define if the content
       * is appended or erase the current content
       */
      HTKCOMMONLIB_EXPORT void WriteOutputFile(const std::string& filePath,
        const std::string& content,
        const bool appendContent = false);
    }
  }
}