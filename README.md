# drv8835_arduino
drv8835 motor driver arduino library

## How to Use
```
$ git clone ssh://git@github.com/shirokunet/drv8835_arduino.git
$ cd drv8835_arduino
$ cd src; ln -fs ../example/one_driver/main.cpp main.cpp; cd ../
$ pio run -e main
$ pio run -e main --target nobuild --target upload --upload-port /dev/ttyUSB0
```
