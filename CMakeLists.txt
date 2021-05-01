cmake_minimum_required(VERSION 3.16)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

project(SAUND VERSION 0.0.1)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Ob3")

add_subdirectory("${CMAKE_SOURCE_DIR}/JUCE")

juce_add_plugin(SAUND
    # VERSION ...                               # Set this if the plugin version is different to the project version
    # ICON_BIG ...                              # ICON_* arguments specify a path to an image file to use as an icon for the Standalone
    # ICON_SMALL ...
    COMPANY_NAME fogelfonforne                        # Specify the name of the plugin's author
    IS_SYNTH FALSE                       # Is this a synth or an effect?
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE    # Does the editor need keyboard focus?
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    VST3_CATEGORIES Fx Distortion
    COPY_PLUGIN_AFTER_BUILD FALSE   
    PLUGIN_MANUFACTURER_CODE Ffff               # A four-character manufacturer id with at least one upper-case character
    PLUGIN_CODE Saun                            # A unique four-character plugin id with exactly one upper-case character
                                                # GarageBand 10.3 requires the first letter to be upper-case, and the remaining letters to be lower-case
    FORMATS VST3                  # The formats to build. Other valid formats are: AAX Unity VST AU AUv3
    PRODUCT_NAME "SAUND")        # The name of the final executable, which can differ from the target name

juce_generate_juce_header(SAUND)

target_sources(SAUND
    PRIVATE
        Source/Ebu128LoudnessMeter.cpp
        Source/SecondOrderIIRFilter.cpp
        Source/SimpleIIRFilter.cpp
        Source/DistortionProcessor.cpp
        Source/MainComponent.cpp
        Source/CurveComponent.cpp
        Source/WaveformComponent.cpp
        Source/PluginEditor.cpp
        Source/PluginProcessor.cpp)

target_compile_definitions(SAUND
    PUBLIC
        # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_plugin` call
        JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_plugin` call
        JUCE_VST3_CAN_REPLACE_VST2=0)


target_link_libraries(SAUND
    PRIVATE
        # AudioPluginData           # If we'd created a binary data target, we'd link to it here
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)
