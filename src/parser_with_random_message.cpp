#include <common/mavlink.h>
#include <algorithm>
#include <cstring>


extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {

    mavlink_message_t message {};

    size_t copy_len = std::min(sizeof(message), size);
    std::memcpy(reinterpret_cast<void *>(&message.checksum), data, copy_len);

    uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
    uint16_t buffer_len = mavlink_msg_to_send_buffer(buffer, &message);

    for (size_t i = 0; i < buffer_len; ++i) {
        mavlink_message_t received_message;
        mavlink_status_t status;
        mavlink_parse_char(MAVLINK_COMM_0, buffer[i], &received_message, &status);
    }
    return 0;
}

