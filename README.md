# cmkr-driver-example
An example project for a Windows kernel driver built with cmkr

### Building
Make sure that in `cmake.toml`, under [variables], you place your own values for the cert name, the company name, etc.

Create a build/ folder, then:
```bash
cmake -B build -G "Visual Studio 17 2022"
cmake --build build --config Debug
```
(Of course, the config is for your choosing)

### Thanks
- **@mrexodia** for teaching me cmkr and essentially showing me how to do this entire thing
- **@DymOK93** for your fork of the CMake repo, allowing easy driver test signing.
