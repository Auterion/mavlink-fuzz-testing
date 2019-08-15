# MAVLink Fuzz Testing

## Instructions

Get submodules:
```
git submodule update --init --recursive
```

Generate the C headers:
```
python3 -m mavlink.pymavlink.tools.mavgen --lang=C --wire-protocol=2.0 --output=generated/include/mavlink/v2.0 mavlink/message_definitions/v1.0/common.xml
```
