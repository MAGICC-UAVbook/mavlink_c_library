// MESSAGE NEW_WAYPOINT PACKING

#define MAVLINK_MSG_ID_NEW_WAYPOINT 152

typedef struct __mavlink_new_waypoint_t
{
 uint64_t time_usec; ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 float w[3]; ///< waypoint in local NED (m)
 float chi_d; ///< Desired course at this waypoint (rad)
 float Va_d; ///< Desired airspeed at this waypoint (m/s)
 uint8_t chi_valid; ///< Desired course valid (boolean value)
 uint8_t set_current; ///< Sets this waypoint to be exicuted now! (boolean value)
} mavlink_new_waypoint_t;

#define MAVLINK_MSG_ID_NEW_WAYPOINT_LEN 30
#define MAVLINK_MSG_ID_152_LEN 30

#define MAVLINK_MSG_ID_NEW_WAYPOINT_CRC 173
#define MAVLINK_MSG_ID_152_CRC 173

#define MAVLINK_MSG_NEW_WAYPOINT_FIELD_W_LEN 3

#define MAVLINK_MESSAGE_INFO_NEW_WAYPOINT { \
	"NEW_WAYPOINT", \
	6, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_new_waypoint_t, time_usec) }, \
         { "w", NULL, MAVLINK_TYPE_FLOAT, 3, 8, offsetof(mavlink_new_waypoint_t, w) }, \
         { "chi_d", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_new_waypoint_t, chi_d) }, \
         { "Va_d", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_new_waypoint_t, Va_d) }, \
         { "chi_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_new_waypoint_t, chi_valid) }, \
         { "set_current", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_new_waypoint_t, set_current) }, \
         } \
}


/**
 * @brief Pack a new_waypoint message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param w waypoint in local NED (m)
 * @param chi_d Desired course at this waypoint (rad)
 * @param chi_valid Desired course valid (boolean value)
 * @param Va_d Desired airspeed at this waypoint (m/s)
 * @param set_current Sets this waypoint to be exicuted now! (boolean value)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_new_waypoint_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, const float *w, float chi_d, uint8_t chi_valid, float Va_d, uint8_t set_current)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_NEW_WAYPOINT_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 20, chi_d);
	_mav_put_float(buf, 24, Va_d);
	_mav_put_uint8_t(buf, 28, chi_valid);
	_mav_put_uint8_t(buf, 29, set_current);
	_mav_put_float_array(buf, 8, w, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_NEW_WAYPOINT_LEN);
#else
	mavlink_new_waypoint_t packet;
	packet.time_usec = time_usec;
	packet.chi_d = chi_d;
	packet.Va_d = Va_d;
	packet.chi_valid = chi_valid;
	packet.set_current = set_current;
	mav_array_memcpy(packet.w, w, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_NEW_WAYPOINT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_NEW_WAYPOINT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_NEW_WAYPOINT_LEN, MAVLINK_MSG_ID_NEW_WAYPOINT_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_NEW_WAYPOINT_LEN);
#endif
}

/**
 * @brief Pack a new_waypoint message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param w waypoint in local NED (m)
 * @param chi_d Desired course at this waypoint (rad)
 * @param chi_valid Desired course valid (boolean value)
 * @param Va_d Desired airspeed at this waypoint (m/s)
 * @param set_current Sets this waypoint to be exicuted now! (boolean value)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_new_waypoint_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t time_usec,const float *w,float chi_d,uint8_t chi_valid,float Va_d,uint8_t set_current)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_NEW_WAYPOINT_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 20, chi_d);
	_mav_put_float(buf, 24, Va_d);
	_mav_put_uint8_t(buf, 28, chi_valid);
	_mav_put_uint8_t(buf, 29, set_current);
	_mav_put_float_array(buf, 8, w, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_NEW_WAYPOINT_LEN);
#else
	mavlink_new_waypoint_t packet;
	packet.time_usec = time_usec;
	packet.chi_d = chi_d;
	packet.Va_d = Va_d;
	packet.chi_valid = chi_valid;
	packet.set_current = set_current;
	mav_array_memcpy(packet.w, w, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_NEW_WAYPOINT_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_NEW_WAYPOINT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_NEW_WAYPOINT_LEN, MAVLINK_MSG_ID_NEW_WAYPOINT_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_NEW_WAYPOINT_LEN);
#endif
}

/**
 * @brief Encode a new_waypoint struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param new_waypoint C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_new_waypoint_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_new_waypoint_t* new_waypoint)
{
	return mavlink_msg_new_waypoint_pack(system_id, component_id, msg, new_waypoint->time_usec, new_waypoint->w, new_waypoint->chi_d, new_waypoint->chi_valid, new_waypoint->Va_d, new_waypoint->set_current);
}

/**
 * @brief Encode a new_waypoint struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param new_waypoint C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_new_waypoint_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_new_waypoint_t* new_waypoint)
{
	return mavlink_msg_new_waypoint_pack_chan(system_id, component_id, chan, msg, new_waypoint->time_usec, new_waypoint->w, new_waypoint->chi_d, new_waypoint->chi_valid, new_waypoint->Va_d, new_waypoint->set_current);
}

/**
 * @brief Send a new_waypoint message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param w waypoint in local NED (m)
 * @param chi_d Desired course at this waypoint (rad)
 * @param chi_valid Desired course valid (boolean value)
 * @param Va_d Desired airspeed at this waypoint (m/s)
 * @param set_current Sets this waypoint to be exicuted now! (boolean value)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_new_waypoint_send(mavlink_channel_t chan, uint64_t time_usec, const float *w, float chi_d, uint8_t chi_valid, float Va_d, uint8_t set_current)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_NEW_WAYPOINT_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 20, chi_d);
	_mav_put_float(buf, 24, Va_d);
	_mav_put_uint8_t(buf, 28, chi_valid);
	_mav_put_uint8_t(buf, 29, set_current);
	_mav_put_float_array(buf, 8, w, 3);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NEW_WAYPOINT, buf, MAVLINK_MSG_ID_NEW_WAYPOINT_LEN, MAVLINK_MSG_ID_NEW_WAYPOINT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NEW_WAYPOINT, buf, MAVLINK_MSG_ID_NEW_WAYPOINT_LEN);
#endif
#else
	mavlink_new_waypoint_t packet;
	packet.time_usec = time_usec;
	packet.chi_d = chi_d;
	packet.Va_d = Va_d;
	packet.chi_valid = chi_valid;
	packet.set_current = set_current;
	mav_array_memcpy(packet.w, w, sizeof(float)*3);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NEW_WAYPOINT, (const char *)&packet, MAVLINK_MSG_ID_NEW_WAYPOINT_LEN, MAVLINK_MSG_ID_NEW_WAYPOINT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NEW_WAYPOINT, (const char *)&packet, MAVLINK_MSG_ID_NEW_WAYPOINT_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_NEW_WAYPOINT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_new_waypoint_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, const float *w, float chi_d, uint8_t chi_valid, float Va_d, uint8_t set_current)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 20, chi_d);
	_mav_put_float(buf, 24, Va_d);
	_mav_put_uint8_t(buf, 28, chi_valid);
	_mav_put_uint8_t(buf, 29, set_current);
	_mav_put_float_array(buf, 8, w, 3);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NEW_WAYPOINT, buf, MAVLINK_MSG_ID_NEW_WAYPOINT_LEN, MAVLINK_MSG_ID_NEW_WAYPOINT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NEW_WAYPOINT, buf, MAVLINK_MSG_ID_NEW_WAYPOINT_LEN);
#endif
#else
	mavlink_new_waypoint_t *packet = (mavlink_new_waypoint_t *)msgbuf;
	packet->time_usec = time_usec;
	packet->chi_d = chi_d;
	packet->Va_d = Va_d;
	packet->chi_valid = chi_valid;
	packet->set_current = set_current;
	mav_array_memcpy(packet->w, w, sizeof(float)*3);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NEW_WAYPOINT, (const char *)packet, MAVLINK_MSG_ID_NEW_WAYPOINT_LEN, MAVLINK_MSG_ID_NEW_WAYPOINT_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NEW_WAYPOINT, (const char *)packet, MAVLINK_MSG_ID_NEW_WAYPOINT_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE NEW_WAYPOINT UNPACKING


/**
 * @brief Get field time_usec from new_waypoint message
 *
 * @return Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 */
static inline uint64_t mavlink_msg_new_waypoint_get_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field w from new_waypoint message
 *
 * @return waypoint in local NED (m)
 */
static inline uint16_t mavlink_msg_new_waypoint_get_w(const mavlink_message_t* msg, float *w)
{
	return _MAV_RETURN_float_array(msg, w, 3,  8);
}

/**
 * @brief Get field chi_d from new_waypoint message
 *
 * @return Desired course at this waypoint (rad)
 */
static inline float mavlink_msg_new_waypoint_get_chi_d(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field chi_valid from new_waypoint message
 *
 * @return Desired course valid (boolean value)
 */
static inline uint8_t mavlink_msg_new_waypoint_get_chi_valid(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  28);
}

/**
 * @brief Get field Va_d from new_waypoint message
 *
 * @return Desired airspeed at this waypoint (m/s)
 */
static inline float mavlink_msg_new_waypoint_get_Va_d(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field set_current from new_waypoint message
 *
 * @return Sets this waypoint to be exicuted now! (boolean value)
 */
static inline uint8_t mavlink_msg_new_waypoint_get_set_current(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  29);
}

/**
 * @brief Decode a new_waypoint message into a struct
 *
 * @param msg The message to decode
 * @param new_waypoint C-struct to decode the message contents into
 */
static inline void mavlink_msg_new_waypoint_decode(const mavlink_message_t* msg, mavlink_new_waypoint_t* new_waypoint)
{
#if MAVLINK_NEED_BYTE_SWAP
	new_waypoint->time_usec = mavlink_msg_new_waypoint_get_time_usec(msg);
	mavlink_msg_new_waypoint_get_w(msg, new_waypoint->w);
	new_waypoint->chi_d = mavlink_msg_new_waypoint_get_chi_d(msg);
	new_waypoint->Va_d = mavlink_msg_new_waypoint_get_Va_d(msg);
	new_waypoint->chi_valid = mavlink_msg_new_waypoint_get_chi_valid(msg);
	new_waypoint->set_current = mavlink_msg_new_waypoint_get_set_current(msg);
#else
	memcpy(new_waypoint, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_NEW_WAYPOINT_LEN);
#endif
}
