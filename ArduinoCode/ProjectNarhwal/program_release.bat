SET "AVRDUDE_PATH=C:\Program Files (x86)\Arduino\hardware\tools\avr"
SET "AVRDUDE_CMD=%AVRDUDE_PATH%/bin/avrdude"
SET "AVRDUDE_CONFIG=%AVRDUDE_PATH%/etc/avrdude.conf"

SET "PROG_HEX_FILENAME=./Release/ProjectNarwhal.hex"
SET "COMPORT=COM4"
"%AVRDUDE_CMD%" -C"%AVRDUDE_CONFIG%" -v -patmega2560 -cwiring -P%COMPORT% -b115200 -D -Uflash:w:%PROG_HEX_FILENAME%:i > program.log