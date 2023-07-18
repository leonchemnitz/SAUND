# SAUND

Acronym for: _**S**ymmetric / **A**symmetric **U**nit for **N**olinear **D**istortion_.

SAUND is a VST Audio-Plugin designed for use in an academic context. The Plugin enables users to distort audio signals
using symmetric and asymmetric polynomial distortion.

## General Info

At the moment this project is being maintained by precisely one person, me [Leon Chemnitz](https://github.com/leonchemnitz). If you have any questions about the project
or you want to use it for your own research and need assistance, feel free to write me at <leonchemnitz@gmail.com> 🚀

## Installation

SAUND is compatible with all Digital Audio Workstations (DAW) that support the VST3 standard (i.e. most of them e.g. [Ableton Live](https://www.ableton.com/de/live/), [Reaper](https://www.reaper.fm/), [Cubase](https://www.steinberg.net/de/cubase/), [Pro Tools](https://www.avid.com/de/pro-tools)).
You can choose to compile SAUND yourself but this requires more in-depth knowledge about C++ and the JUCE framework.
Alternatively, you can download a pre-compiled version here.

Once you have your SAUND.vst3 file please consult the documentation of your specific DAW on how to install a VST3 plugin
(the process differs a bit for every DAW but is usually pretty straightforward).

### Example installation on Windows

If you want to try out SAUND and don't have much experience with common audio processing tools (i.e. you don't have a DAW yet),
we recommend installing [Reaper](https://www.reaper.fm/). Reaper has a 60-day free trial which is hopefully sufficient for
trying out SAUND.
- Follow the instructions on their website on how to install Reaper.
- Place the SAUND.vst3 file under `C:\Program Files\Common Files\VST3`.
- Open Reaper.
- Click Insert > Track.
- Click Insert > Virtual Instrument on New Track, then select VST3:SAUND in the VST3 category.

Congratulations, you now have SAUND installed and running on your system!🎉


## Contributing

Contributions are always welcome!

See [contributing guidelines](CONTRIBUTING.md) for ways to get started.

Please adhere to this project's [Code of Conduct](CODE_OF_CONDUCT.md).
