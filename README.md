USB permission error:

`sudo chmod 666 /dev/ttyUSB0`

To use a watchface from the Watchfaces folder, create a symlink from it to the src folder:

`cd watchy-pio`
`rm -rf src`
`ln -s Watchfaces/Pokemon src`