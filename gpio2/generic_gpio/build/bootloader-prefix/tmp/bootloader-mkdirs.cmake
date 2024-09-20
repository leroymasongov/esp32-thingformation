# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/ESP-IDF-Container/v5.2.1/esp-idf/components/bootloader/subproject"
  "D:/repos3/esp-idf-work/esp32-thingformation/gpio2/generic_gpio/build/bootloader"
  "D:/repos3/esp-idf-work/esp32-thingformation/gpio2/generic_gpio/build/bootloader-prefix"
  "D:/repos3/esp-idf-work/esp32-thingformation/gpio2/generic_gpio/build/bootloader-prefix/tmp"
  "D:/repos3/esp-idf-work/esp32-thingformation/gpio2/generic_gpio/build/bootloader-prefix/src/bootloader-stamp"
  "D:/repos3/esp-idf-work/esp32-thingformation/gpio2/generic_gpio/build/bootloader-prefix/src"
  "D:/repos3/esp-idf-work/esp32-thingformation/gpio2/generic_gpio/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/repos3/esp-idf-work/esp32-thingformation/gpio2/generic_gpio/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/repos3/esp-idf-work/esp32-thingformation/gpio2/generic_gpio/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
