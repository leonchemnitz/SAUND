# Install script for directory: S:/development/SAUND/JUCE

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/SAUND")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Qt/Tools/mingw810_64/bin/objdump.exe")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/JUCE-6.0.7" TYPE FILE FILES
    "S:/development/SAUND/JUCE/tools/JUCEConfigVersion.cmake"
    "S:/development/SAUND/JUCE/tools/JUCEConfig.cmake"
    "S:/development/SAUND/JUCE/extras/Build/CMake/JUCEHelperTargets.cmake"
    "S:/development/SAUND/JUCE/extras/Build/CMake/JUCECheckAtomic.cmake"
    "S:/development/SAUND/JUCE/extras/Build/CMake/JUCEUtils.cmake"
    "S:/development/SAUND/JUCE/extras/Build/CMake/LaunchScreen.storyboard"
    "S:/development/SAUND/JUCE/extras/Build/CMake/PIPAudioProcessor.cpp.in"
    "S:/development/SAUND/JUCE/extras/Build/CMake/PIPComponent.cpp.in"
    "S:/development/SAUND/JUCE/extras/Build/CMake/PIPConsole.cpp.in"
    "S:/development/SAUND/JUCE/extras/Build/CMake/RecentFilesMenuTemplate.nib"
    "S:/development/SAUND/JUCE/extras/Build/CMake/UnityPluginGUIScript.cs.in"
    "S:/development/SAUND/JUCE/extras/Build/CMake/copyDir.cmake"
    "S:/development/SAUND/JUCE/extras/Build/CMake/juce_runtime_arch_detection.cpp"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("S:/development/SAUND/JUCE/tools/modules/cmake_install.cmake")
  include("S:/development/SAUND/JUCE/tools/extras/Build/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "S:/development/SAUND/JUCE/tools/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
