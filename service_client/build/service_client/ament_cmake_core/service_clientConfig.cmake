# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_service_client_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED service_client_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(service_client_FOUND FALSE)
  elseif(NOT service_client_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(service_client_FOUND FALSE)
  endif()
  return()
endif()
set(_service_client_CONFIG_INCLUDED TRUE)

# output package information
if(NOT service_client_FIND_QUIETLY)
  message(STATUS "Found service_client: 0.0.0 (${service_client_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'service_client' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${service_client_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(service_client_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${service_client_DIR}/${_extra}")
endforeach()
