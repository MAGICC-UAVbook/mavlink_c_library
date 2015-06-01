// MESSAGE HIL_CONTROLLER_COMMANDS PACKING

#define MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS 151

typedef struct __mavlink_hil_controller_commands_t
{
 uint64_t time_usec; ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 float Va_c; ///< Commanded airspeed (m/s)
 float h_c; ///< Commanded altitude (m)
 float chi_c; ///< Commanded course (rad)
 float aux[4]; ///< Optional auxiliary commands
 uint8_t aux_valid; ///< Auxiliary commands valid (boolean value)
} mavlink_hil_controller_commands_t;

#define MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN 37
#define MAVLINK_MSG_ID_151_LEN 37

#define MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_CRC 170
#define MAVLINK_MSG_ID_151_CRC 170

#define MAVLINK_MSG_HIL_CONTROLLER_COMMANDS_FIELD_AUX_LEN 4

#define MAVLINK_MESSAGE_INFO_HIL_CONTROLLER_COMMANDS { \
	"HIL_CONTROLLER_COMMANDS", \
	6, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_hil_controller_commands_t, time_usec) }, \
         { "Va_c", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_hil_controller_commands_t, Va_c) }, \
         { "h_c", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_hil_controller_commands_t, h_c) }, \
         { "chi_c", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_hil_controller_commands_t, chi_c) }, \
         { "aux", NULL, MAVLINK_TYPE_FLOAT, 4, 20, offsetof(mavlink_hil_controller_commands_t, aux) }, \
         { "aux_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_hil_controller_commands_t, aux_valid) }, \
         } \
}


/**
 * @brief Pack a hil_controller_commands message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param Va_c Commanded airspeed (m/s)
 * @param h_c Commanded altitude (m)
 * @param chi_c Commanded course (rad)
 * @param aux Optional auxiliary commands
 * @param aux_valid Auxiliary commands valid (boolean value)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hil_controller_commands_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, float Va_c, float h_c, float chi_c, const float *aux, uint8_t aux_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, Va_c);
	_mav_put_float(buf, 12, h_c);
	_mav_put_float(buf, 16, chi_c);
	_mav_put_uint8_t(buf, 36, aux_valid);
	_mav_put_float_array(buf, 20, aux, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN);
#else
	mavlink_hil_controller_commands_t packet;
	packet.time_usec = time_usec;
	packet.Va_c = Va_c;
	packet.h_c = h_c;
	packet.chi_c = chi_c;
	packet.aux_valid = aux_valid;
	mav_array_memcpy(packet.aux, aux, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN);
#endif
}

/**
 * @brief Pack a hil_controller_commands message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param Va_c Commanded airspeed (m/s)
 * @param h_c Commanded altitude (m)
 * @param chi_c Commanded course (rad)
 * @param aux Optional auxiliary commands
 * @param aux_valid Auxiliary commands valid (boolean value)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hil_controller_commands_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t time_usec,float Va_c,float h_c,float chi_c,const float *aux,uint8_t aux_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, Va_c);
	_mav_put_float(buf, 12, h_c);
	_mav_put_float(buf, 16, chi_c);
	_mav_put_uint8_t(buf, 36, aux_valid);
	_mav_put_float_array(buf, 20, aux, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN);
#else
	mavlink_hil_controller_commands_t packet;
	packet.time_usec = time_usec;
	packet.Va_c = Va_c;
	packet.h_c = h_c;
	packet.chi_c = chi_c;
	packet.aux_valid = aux_valid;
	mav_array_memcpy(packet.aux, aux, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN);
#endif
}

/**
 * @brief Encode a hil_controller_commands struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param hil_controller_commands C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hil_controller_commands_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_hil_controller_commands_t* hil_controller_commands)
{
	return mavlink_msg_hil_controller_commands_pack(system_id, component_id, msg, hil_controller_commands->time_usec, hil_controller_commands->Va_c, hil_controller_commands->h_c, hil_controller_commands->chi_c, hil_controller_commands->aux, hil_controller_commands->aux_valid);
}

/**
 * @brief Encode a hil_controller_commands struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param hil_controller_commands C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hil_controller_commands_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_hil_controller_commands_t* hil_controller_commands)
{
	return mavlink_msg_hil_controller_commands_pack_chan(system_id, component_id, chan, msg, hil_controller_commands->time_usec, hil_controller_commands->Va_c, hil_controller_commands->h_c, hil_controller_commands->chi_c, hil_controller_commands->aux, hil_controller_commands->aux_valid);
}

/**
 * @brief Send a hil_controller_commands message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param Va_c Commanded airspeed (m/s)
 * @param h_c Commanded altitude (m)
 * @param chi_c Commanded course (rad)
 * @param aux Optional auxiliary commands
 * @param aux_valid Auxiliary commands valid (boolean value)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_hil_controller_commands_send(mavlink_channel_t chan, uint64_t time_usec, float Va_c, float h_c, float chi_c, const float *aux, uint8_t aux_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, Va_c);
	_mav_put_float(buf, 12, h_c);
	_mav_put_float(buf, 16, chi_c);
	_mav_put_uint8_t(buf, 36, aux_valid);
	_mav_put_float_array(buf, 20, aux, 4);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS, buf, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS, buf, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN);
#endif
#else
	mavlink_hil_controller_commands_t packet;
	packet.time_usec = time_usec;
	packet.Va_c = Va_c;
	packet.h_c = h_c;
	packet.chi_c = chi_c;
	packet.aux_valid = aux_valid;
	mav_array_memcpy(packet.aux, aux, sizeof(float)*4);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS, (const char *)&packet, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS, (const char *)&packet, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_hil_controller_commands_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, float Va_c, float h_c, float chi_c, const float *aux, uint8_t aux_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, Va_c);
	_mav_put_float(buf, 12, h_c);
	_mav_put_float(buf, 16, chi_c);
	_mav_put_uint8_t(buf, 36, aux_valid);
	_mav_put_float_array(buf, 20, aux, 4);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS, buf, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS, buf, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN);
#endif
#else
	mavlink_hil_controller_commands_t *packet = (mavlink_hil_controller_commands_t *)msgbuf;
	packet->time_usec = time_usec;
	packet->Va_c = Va_c;
	packet->h_c = h_c;
	packet->chi_c = chi_c;
	packet->aux_valid = aux_valid;
	mav_array_memcpy(packet->aux, aux, sizeof(float)*4);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS, (const char *)packet, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS, (const char *)packet, MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE HIL_CONTROLLER_COMMANDS UNPACKING


/**
 * @brief Get field time_usec from hil_controller_commands message
 *
 * @return Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 */
static inline uint64_t mavlink_msg_hil_controller_commands_get_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field Va_c from hil_controller_commands message
 *
 * @return Commanded airspeed (m/s)
 */
static inline float mavlink_msg_hil_controller_commands_get_Va_c(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field h_c from hil_controller_commands message
 *
 * @return Commanded altitude (m)
 */
static inline float mavlink_msg_hil_controller_commands_get_h_c(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field chi_c from hil_controller_commands message
 *
 * @return Commanded course (rad)
 */
static inline float mavlink_msg_hil_controller_commands_get_chi_c(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field aux from hil_controller_commands message
 *
 * @return Optional auxiliary commands
 */
static inline uint16_t mavlink_msg_hil_controller_commands_get_aux(const mavlink_message_t* msg, float *aux)
{
	return _MAV_RETURN_float_array(msg, aux, 4,  20);
}

/**
 * @brief Get field aux_valid from hil_controller_commands message
 *
 * @return Auxiliary commands valid (boolean value)
 */
static inline uint8_t mavlink_msg_hil_controller_commands_get_aux_valid(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Decode a hil_controller_commands message into a struct
 *
 * @param msg The message to decode
 * @param hil_controller_commands C-struct to decode the message contents into
 */
static inline void mavlink_msg_hil_controller_commands_decode(const mavlink_message_t* msg, mavlink_hil_controller_commands_t* hil_controller_commands)
{
#if MAVLINK_NEED_BYTE_SWAP
	hil_controller_commands->time_usec = mavlink_msg_hil_controller_commands_get_time_usec(msg);
	hil_controller_commands->Va_c = mavlink_msg_hil_controller_commands_get_Va_c(msg);
	hil_controller_commands->h_c = mavlink_msg_hil_controller_commands_get_h_c(msg);
	hil_controller_commands->chi_c = mavlink_msg_hil_controller_commands_get_chi_c(msg);
	mavlink_msg_hil_controller_commands_get_aux(msg, hil_controller_commands->aux);
	hil_controller_commands->aux_valid = mavlink_msg_hil_controller_commands_get_aux_valid(msg);
#else
	memcpy(hil_controller_commands, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_HIL_CONTROLLER_COMMANDS_LEN);
#endif
}
