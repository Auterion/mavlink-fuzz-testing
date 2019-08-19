#define MAVLINK_CHECK_MESSAGE_LENGTH 1
#include <common/mavlink.h>

#include <algorithm>
#include <cstring>

mavlink_message_t create_message(const uint8_t *data, size_t size) {

    mavlink_obstacle_distance_t obstacle_distance;

    size_t copy_len = std::min(sizeof(obstacle_distance), size);
    std::memcpy(reinterpret_cast<void *>(&obstacle_distance.time_usec), data, copy_len);

    const uint8_t system_id = 0;
    const uint8_t component_id = 0;

    mavlink_message_t message;
    mavlink_msg_obstacle_distance_encode(system_id, component_id, &message, &obstacle_distance);

    return message;
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {

    const mavlink_message_t message = create_message(data, size);

    uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
    uint16_t buffer_len = mavlink_msg_to_send_buffer(buffer, &message);

    for (size_t i = 0; i < buffer_len; ++i) {
        mavlink_message_t received_message;
        mavlink_status_t status;
        mavlink_parse_char(MAVLINK_COMM_0, buffer[i], &received_message, &status);
    }
    return 0;
}

