# Brightray Example

This is an example app that uses
[Brightray](https://github.com/brightray/brightray).

## Development

### Prerequisites

* Python 2.7
* gyp
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

## License

See the [`LICENSE`](LICENSE) file.
