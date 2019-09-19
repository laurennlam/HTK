#pragma once

#include <string>

#include "htkcommonlib_export.h"

namespace htk
{
	namespace io
	{
		/**
		 * Write a file with the 'filePath' parameter and fill it with the 'content' parameter
		 * If the file already exists, then append the content to the end of the file
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