# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/lucas/esp/v5.3.1/esp-idf/components/bootloader/subproject"
  "/home/lucas/Documents/Codes/esp32/fft/build/bootloader"
  "/home/lucas/Documents/Codes/esp32/fft/build/bootloader-prefix"
  "/home/lucas/Documents/Codes/esp32/fft/build/bootloader-prefix/tmp"
  "/home/lucas/Documents/Codes/esp32/fft/build/bootloader-prefix/src/bootloader-stamp"
  "/home/lucas/Documents/Codes/esp32/fft/build/bootloader-prefix/src"
  "/home/lucas/Documents/Codes/esp32/fft/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/lucas/Documents/Codes/esp32/fft/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/lucas/Documents/Codes/esp32/fft/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
