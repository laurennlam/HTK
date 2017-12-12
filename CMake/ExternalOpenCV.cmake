include(ExternalProject)

set(PROJECT OpenCV)

#----------------------------------------------------------------
# Go into this if user sets a OpenCV_DIR, don't need to download it
#----------------------------------------------------------------

if (${PROJECT}_DIR)
  message("Using user-specified ${PROJECT}")
  ExternalProject_Add(${PROJECT}
    SOURCE_DIR ${${PROJECT}_DIR}
    DOWNLOAD_COMMAND ""
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
  )
  return()
endif()
