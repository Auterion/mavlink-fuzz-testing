#define MAVLINK_CHECK_MESSAGE_LENGTH 1
#include <common/mavlink.h>

#include <algorithm>
#include <cstring>


extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {

    const size_t num_messages = size / sizeof(mavlink_message_t) + ((size % sizeof(mavlink_message_t)) > 0 ? 1 : 0);

    uint8_t buffer[MAVLINK_MAX_PACKET_LEN * num_messages];
    size_t buffer_len = 0;


    for (int i = 0; i < num_messages; ++i) {
        mavlink_message_t message {};
        const size_t copy_len = std::min(sizeof(message), size - (i * sizeof(message)));
        std::memcpy(reinterpret_cast<void *>(&message.checksum), data, copy_len);

        buffer_len += mavlink_msg_to_send_buffer(buffer + buffer_len, &message);
    }

    for (size_t i = 0; i < buffer_len; ++i) {
        mavlink_message_t received_message;
        mavlink_status_t status;
        mavlink_parse_char(MAVLINK_COMM_0, buffer[i], &received_message, &status);
    }
    return 0;
}

