#include <common/mavlink.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    for (size_t i = 0; i < Size; ++i) {
        mavlink_message_t message;
        mavlink_status_t status;
        mavlink_parse_char(MAVLINK_COMM_0, Data[i], &message, &status);
    }
    return 0;
}
