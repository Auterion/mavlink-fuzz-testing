# MAVLink Fuzz Testing

## Instructions

1. Make sure clang is installed.

2. Git submodules:
```
git submodule update --init --recursive
```

3. Generate the C headers:
```
python3 -m mavlink.pymavlink.tools.mavgen --lang=C --wire-protocol=2.0 --output=generated/include/mavlink/v2.0 mavlink/message_definitions/v1.0/common.xml
```

4. Run fuzzer:

```
cmake -Bbuild src && cmake --build build && build/parser_fuzzing
```

5. The fuzzer will run until it detects crash. To stop it just press Ctrl+C.