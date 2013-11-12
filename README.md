# Brightray Example

This is an example app that uses
[Brightray](https://github.com/brightray/brightray).

## Development

### Prerequisites

* Python 2.7
* Mac:
    * Xcode
* Windows:
    * Visual Studio 2010 SP1

### One-time setup

You must previously have built and uploaded libchromiumcontent using its
`script/upload` script.

    $ script/bootstrap http://base.url.com/used/by/script/upload

### Building

    $ script/build

This will build the app into the `build` directory.

### Running

Run `out/Debug/brightray_example`

On Linux, you need to copy the Chrome SUID sandbox or explicitly run
without it.  Any of these three choices should work:

* Run `tools/linux/copy-chrome-sandbox.sh` to install the sandbox.  The
  script must be run as root.
* Use the sandbox from an existing installed Chrome: `CHROME_DEVEL_SANDBOX=/usr/lib/chromium-browser/chrome-sandbox out/Debug/brightray_example`
* Use no sandbox: `out/Debug/brightray_example --disable-setuid-sandbox`

## License

See the [`LICENSE`](LICENSE) file.
