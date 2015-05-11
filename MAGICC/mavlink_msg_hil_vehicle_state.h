// MESSAGE HIL_VEHICLE_STATE PACKING

#define MAVLINK_MSG_ID_HIL_VEHICLE_STATE 150

typedef struct __mavlink_hil_vehicle_state_t
{
 uint64_t time_usec; ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 float position[3]; ///< Position north, east, height (m)
 float Va; ///< Airspeed (m/s)
 float alpha; ///< Angle of attack (rad)
 float beta; ///< Side slip angle (rad)
 float phi; ///< Roll angle (rad)
 float theta; ///< Pitch angle (rad)
 float psi; ///< Yaw angle (rad)
 float chi; ///< Course angle (rad)
 float p; ///< Body-frame roll rate (rad/s)
 float q; ///< Body-frame pitch rate (rad/s)
 float r; ///< Body-frame yaw rate (rad/s)
 float Vg; ///< Ground speed (m/s)
 float wn; ///< Wind speed north component
 float we; ///< Wind speed east component
 float quat[4]; ///< Attitude quaternion {w,x,y,z} (NED)
 uint8_t quat_valid; ///< Quaternion valid (boolean value)
} mavlink_hil_vehicle_state_t;

#define MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN 89
#define MAVLINK_MSG_ID_150_LEN 89

#define MAVLINK_MSG_ID_HIL_VEHICLE_STATE_CRC 194
#define MAVLINK_MSG_ID_150_CRC 194

#define MAVLINK_MSG_HIL_VEHICLE_STATE_FIELD_POSITION_LEN 3
#define MAVLINK_MSG_HIL_VEHICLE_STATE_FIELD_QUAT_LEN 4

#define MAVLINK_MESSAGE_INFO_HIL_VEHICLE_STATE { \
	"HIL_VEHICLE_STATE", \
	17, \
	{  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_hil_vehicle_state_t, time_usec) }, \
         { "position", NULL, MAVLINK_TYPE_FLOAT, 3, 8, offsetof(mavlink_hil_vehicle_state_t, position) }, \
         { "Va", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_hil_vehicle_state_t, Va) }, \
         { "alpha", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_hil_vehicle_state_t, alpha) }, \
         { "beta", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_hil_vehicle_state_t, beta) }, \
         { "phi", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_hil_vehicle_state_t, phi) }, \
         { "theta", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_hil_vehicle_state_t, theta) }, \
         { "psi", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_hil_vehicle_state_t, psi) }, \
         { "chi", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_hil_vehicle_state_t, chi) }, \
         { "p", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_hil_vehicle_state_t, p) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_hil_vehicle_state_t, q) }, \
         { "r", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_hil_vehicle_state_t, r) }, \
         { "Vg", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_hil_vehicle_state_t, Vg) }, \
         { "wn", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_hil_vehicle_state_t, wn) }, \
         { "we", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_hil_vehicle_state_t, we) }, \
         { "quat", NULL, MAVLINK_TYPE_FLOAT, 4, 72, offsetof(mavlink_hil_vehicle_state_t, quat) }, \
         { "quat_valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 88, offsetof(mavlink_hil_vehicle_state_t, quat_valid) }, \
         } \
}


/**
 * @brief Pack a hil_vehicle_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param position Position north, east, height (m)
 * @param Va Airspeed (m/s)
 * @param alpha Angle of attack (rad)
 * @param beta Side slip angle (rad)
 * @param phi Roll angle (rad)
 * @param theta Pitch angle (rad)
 * @param psi Yaw angle (rad)
 * @param chi Course angle (rad)
 * @param p Body-frame roll rate (rad/s)
 * @param q Body-frame pitch rate (rad/s)
 * @param r Body-frame yaw rate (rad/s)
 * @param Vg Ground speed (m/s)
 * @param wn Wind speed north component
 * @param we Wind speed east component
 * @param quat Attitude quaternion {w,x,y,z} (NED)
 * @param quat_valid Quaternion valid (boolean value)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hil_vehicle_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint64_t time_usec, const float *position, float Va, float alpha, float beta, float phi, float theta, float psi, float chi, float p, float q, float r, float Vg, float wn, float we, const float *quat, uint8_t quat_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 20, Va);
	_mav_put_float(buf, 24, alpha);
	_mav_put_float(buf, 28, beta);
	_mav_put_float(buf, 32, phi);
	_mav_put_float(buf, 36, theta);
	_mav_put_float(buf, 40, psi);
	_mav_put_float(buf, 44, chi);
	_mav_put_float(buf, 48, p);
	_mav_put_float(buf, 52, q);
	_mav_put_float(buf, 56, r);
	_mav_put_float(buf, 60, Vg);
	_mav_put_float(buf, 64, wn);
	_mav_put_float(buf, 68, we);
	_mav_put_uint8_t(buf, 88, quat_valid);
	_mav_put_float_array(buf, 8, position, 3);
	_mav_put_float_array(buf, 72, quat, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN);
#else
	mavlink_hil_vehicle_state_t packet;
	packet.time_usec = time_usec;
	packet.Va = Va;
	packet.alpha = alpha;
	packet.beta = beta;
	packet.phi = phi;
	packet.theta = theta;
	packet.psi = psi;
	packet.chi = chi;
	packet.p = p;
	packet.q = q;
	packet.r = r;
	packet.Vg = Vg;
	packet.wn = wn;
	packet.we = we;
	packet.quat_valid = quat_valid;
	mav_array_memcpy(packet.position, position, sizeof(float)*3);
	mav_array_memcpy(packet.quat, quat, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_HIL_VEHICLE_STATE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN);
#endif
}

/**
 * @brief Pack a hil_vehicle_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param position Position north, east, height (m)
 * @param Va Airspeed (m/s)
 * @param alpha Angle of attack (rad)
 * @param beta Side slip angle (rad)
 * @param phi Roll angle (rad)
 * @param theta Pitch angle (rad)
 * @param psi Yaw angle (rad)
 * @param chi Course angle (rad)
 * @param p Body-frame roll rate (rad/s)
 * @param q Body-frame pitch rate (rad/s)
 * @param r Body-frame yaw rate (rad/s)
 * @param Vg Ground speed (m/s)
 * @param wn Wind speed north component
 * @param we Wind speed east component
 * @param quat Attitude quaternion {w,x,y,z} (NED)
 * @param quat_valid Quaternion valid (boolean value)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hil_vehicle_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint64_t time_usec,const float *position,float Va,float alpha,float beta,float phi,float theta,float psi,float chi,float p,float q,float r,float Vg,float wn,float we,const float *quat,uint8_t quat_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 20, Va);
	_mav_put_float(buf, 24, alpha);
	_mav_put_float(buf, 28, beta);
	_mav_put_float(buf, 32, phi);
	_mav_put_float(buf, 36, theta);
	_mav_put_float(buf, 40, psi);
	_mav_put_float(buf, 44, chi);
	_mav_put_float(buf, 48, p);
	_mav_put_float(buf, 52, q);
	_mav_put_float(buf, 56, r);
	_mav_put_float(buf, 60, Vg);
	_mav_put_float(buf, 64, wn);
	_mav_put_float(buf, 68, we);
	_mav_put_uint8_t(buf, 88, quat_valid);
	_mav_put_float_array(buf, 8, position, 3);
	_mav_put_float_array(buf, 72, quat, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN);
#else
	mavlink_hil_vehicle_state_t packet;
	packet.time_usec = time_usec;
	packet.Va = Va;
	packet.alpha = alpha;
	packet.beta = beta;
	packet.phi = phi;
	packet.theta = theta;
	packet.psi = psi;
	packet.chi = chi;
	packet.p = p;
	packet.q = q;
	packet.r = r;
	packet.Vg = Vg;
	packet.wn = wn;
	packet.we = we;
	packet.quat_valid = quat_valid;
	mav_array_memcpy(packet.position, position, sizeof(float)*3);
	mav_array_memcpy(packet.quat, quat, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_HIL_VEHICLE_STATE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN);
#endif
}

/**
 * @brief Encode a hil_vehicle_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param hil_vehicle_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hil_vehicle_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_hil_vehicle_state_t* hil_vehicle_state)
{
	return mavlink_msg_hil_vehicle_state_pack(system_id, component_id, msg, hil_vehicle_state->time_usec, hil_vehicle_state->position, hil_vehicle_state->Va, hil_vehicle_state->alpha, hil_vehicle_state->beta, hil_vehicle_state->phi, hil_vehicle_state->theta, hil_vehicle_state->psi, hil_vehicle_state->chi, hil_vehicle_state->p, hil_vehicle_state->q, hil_vehicle_state->r, hil_vehicle_state->Vg, hil_vehicle_state->wn, hil_vehicle_state->we, hil_vehicle_state->quat, hil_vehicle_state->quat_valid);
}

/**
 * @brief Encode a hil_vehicle_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param hil_vehicle_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hil_vehicle_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_hil_vehicle_state_t* hil_vehicle_state)
{
	return mavlink_msg_hil_vehicle_state_pack_chan(system_id, component_id, chan, msg, hil_vehicle_state->time_usec, hil_vehicle_state->position, hil_vehicle_state->Va, hil_vehicle_state->alpha, hil_vehicle_state->beta, hil_vehicle_state->phi, hil_vehicle_state->theta, hil_vehicle_state->psi, hil_vehicle_state->chi, hil_vehicle_state->p, hil_vehicle_state->q, hil_vehicle_state->r, hil_vehicle_state->Vg, hil_vehicle_state->wn, hil_vehicle_state->we, hil_vehicle_state->quat, hil_vehicle_state->quat_valid);
}

/**
 * @brief Send a hil_vehicle_state message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param position Position north, east, height (m)
 * @param Va Airspeed (m/s)
 * @param alpha Angle of attack (rad)
 * @param beta Side slip angle (rad)
 * @param phi Roll angle (rad)
 * @param theta Pitch angle (rad)
 * @param psi Yaw angle (rad)
 * @param chi Course angle (rad)
 * @param p Body-frame roll rate (rad/s)
 * @param q Body-frame pitch rate (rad/s)
 * @param r Body-frame yaw rate (rad/s)
 * @param Vg Ground speed (m/s)
 * @param wn Wind speed north component
 * @param we Wind speed east component
 * @param quat Attitude quaternion {w,x,y,z} (NED)
 * @param quat_valid Quaternion valid (boolean value)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_hil_vehicle_state_send(mavlink_channel_t chan, uint64_t time_usec, const float *position, float Va, float alpha, float beta, float phi, float theta, float psi, float chi, float p, float q, float r, float Vg, float wn, float we, const float *quat, uint8_t quat_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 20, Va);
	_mav_put_float(buf, 24, alpha);
	_mav_put_float(buf, 28, beta);
	_mav_put_float(buf, 32, phi);
	_mav_put_float(buf, 36, theta);
	_mav_put_float(buf, 40, psi);
	_mav_put_float(buf, 44, chi);
	_mav_put_float(buf, 48, p);
	_mav_put_float(buf, 52, q);
	_mav_put_float(buf, 56, r);
	_mav_put_float(buf, 60, Vg);
	_mav_put_float(buf, 64, wn);
	_mav_put_float(buf, 68, we);
	_mav_put_uint8_t(buf, 88, quat_valid);
	_mav_put_float_array(buf, 8, position, 3);
	_mav_put_float_array(buf, 72, quat, 4);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HIL_VEHICLE_STATE, buf, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HIL_VEHICLE_STATE, buf, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN);
#endif
#else
	mavlink_hil_vehicle_state_t packet;
	packet.time_usec = time_usec;
	packet.Va = Va;
	packet.alpha = alpha;
	packet.beta = beta;
	packet.phi = phi;
	packet.theta = theta;
	packet.psi = psi;
	packet.chi = chi;
	packet.p = p;
	packet.q = q;
	packet.r = r;
	packet.Vg = Vg;
	packet.wn = wn;
	packet.we = we;
	packet.quat_valid = quat_valid;
	mav_array_memcpy(packet.position, position, sizeof(float)*3);
	mav_array_memcpy(packet.quat, quat, sizeof(float)*4);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HIL_VEHICLE_STATE, (const char *)&packet, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HIL_VEHICLE_STATE, (const char *)&packet, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_hil_vehicle_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, const float *position, float Va, float alpha, float beta, float phi, float theta, float psi, float chi, float p, float q, float r, float Vg, float wn, float we, const float *quat, uint8_t quat_valid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 20, Va);
	_mav_put_float(buf, 24, alpha);
	_mav_put_float(buf, 28, beta);
	_mav_put_float(buf, 32, phi);
	_mav_put_float(buf, 36, theta);
	_mav_put_float(buf, 40, psi);
	_mav_put_float(buf, 44, chi);
	_mav_put_float(buf, 48, p);
	_mav_put_float(buf, 52, q);
	_mav_put_float(buf, 56, r);
	_mav_put_float(buf, 60, Vg);
	_mav_put_float(buf, 64, wn);
	_mav_put_float(buf, 68, we);
	_mav_put_uint8_t(buf, 88, quat_valid);
	_mav_put_float_array(buf, 8, position, 3);
	_mav_put_float_array(buf, 72, quat, 4);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HIL_VEHICLE_STATE, buf, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HIL_VEHICLE_STATE, buf, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN);
#endif
#else
	mavlink_hil_vehicle_state_t *packet = (mavlink_hil_vehicle_state_t *)msgbuf;
	packet->time_usec = time_usec;
	packet->Va = Va;
	packet->alpha = alpha;
	packet->beta = beta;
	packet->phi = phi;
	packet->theta = theta;
	packet->psi = psi;
	packet->chi = chi;
	packet->p = p;
	packet->q = q;
	packet->r = r;
	packet->Vg = Vg;
	packet->wn = wn;
	packet->we = we;
	packet->quat_valid = quat_valid;
	mav_array_memcpy(packet->position, position, sizeof(float)*3);
	mav_array_memcpy(packet->quat, quat, sizeof(float)*4);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HIL_VEHICLE_STATE, (const char *)packet, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HIL_VEHICLE_STATE, (const char *)packet, MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE HIL_VEHICLE_STATE UNPACKING


/**
 * @brief Get field time_usec from hil_vehicle_state message
 *
 * @return Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 */
static inline uint64_t mavlink_msg_hil_vehicle_state_get_time_usec(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field position from hil_vehicle_state message
 *
 * @return Position north, east, height (m)
 */
static inline uint16_t mavlink_msg_hil_vehicle_state_get_position(const mavlink_message_t* msg, float *position)
{
	return _MAV_RETURN_float_array(msg, position, 3,  8);
}

/**
 * @brief Get field Va from hil_vehicle_state message
 *
 * @return Airspeed (m/s)
 */
static inline float mavlink_msg_hil_vehicle_state_get_Va(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field alpha from hil_vehicle_state message
 *
 * @return Angle of attack (rad)
 */
static inline float mavlink_msg_hil_vehicle_state_get_alpha(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field beta from hil_vehicle_state message
 *
 * @return Side slip angle (rad)
 */
static inline float mavlink_msg_hil_vehicle_state_get_beta(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field phi from hil_vehicle_state message
 *
 * @return Roll angle (rad)
 */
static inline float mavlink_msg_hil_vehicle_state_get_phi(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field theta from hil_vehicle_state message
 *
 * @return Pitch angle (rad)
 */
static inline float mavlink_msg_hil_vehicle_state_get_theta(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field psi from hil_vehicle_state message
 *
 * @return Yaw angle (rad)
 */
static inline float mavlink_msg_hil_vehicle_state_get_psi(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field chi from hil_vehicle_state message
 *
 * @return Course angle (rad)
 */
static inline float mavlink_msg_hil_vehicle_state_get_chi(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field p from hil_vehicle_state message
 *
 * @return Body-frame roll rate (rad/s)
 */
static inline float mavlink_msg_hil_vehicle_state_get_p(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field q from hil_vehicle_state message
 *
 * @return Body-frame pitch rate (rad/s)
 */
static inline float mavlink_msg_hil_vehicle_state_get_q(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field r from hil_vehicle_state message
 *
 * @return Body-frame yaw rate (rad/s)
 */
static inline float mavlink_msg_hil_vehicle_state_get_r(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field Vg from hil_vehicle_state message
 *
 * @return Ground speed (m/s)
 */
static inline float mavlink_msg_hil_vehicle_state_get_Vg(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field wn from hil_vehicle_state message
 *
 * @return Wind speed north component
 */
static inline float mavlink_msg_hil_vehicle_state_get_wn(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field we from hil_vehicle_state message
 *
 * @return Wind speed east component
 */
static inline float mavlink_msg_hil_vehicle_state_get_we(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  68);
}

/**
 * @brief Get field quat from hil_vehicle_state message
 *
 * @return Attitude quaternion {w,x,y,z} (NED)
 */
static inline uint16_t mavlink_msg_hil_vehicle_state_get_quat(const mavlink_message_t* msg, float *quat)
{
	return _MAV_RETURN_float_array(msg, quat, 4,  72);
}

/**
 * @brief Get field quat_valid from hil_vehicle_state message
 *
 * @return Quaternion valid (boolean value)
 */
static inline uint8_t mavlink_msg_hil_vehicle_state_get_quat_valid(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  88);
}

/**
 * @brief Decode a hil_vehicle_state message into a struct
 *
 * @param msg The message to decode
 * @param hil_vehicle_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_hil_vehicle_state_decode(const mavlink_message_t* msg, mavlink_hil_vehicle_state_t* hil_vehicle_state)
{
#if MAVLINK_NEED_BYTE_SWAP
	hil_vehicle_state->time_usec = mavlink_msg_hil_vehicle_state_get_time_usec(msg);
	mavlink_msg_hil_vehicle_state_get_position(msg, hil_vehicle_state->position);
	hil_vehicle_state->Va = mavlink_msg_hil_vehicle_state_get_Va(msg);
	hil_vehicle_state->alpha = mavlink_msg_hil_vehicle_state_get_alpha(msg);
	hil_vehicle_state->beta = mavlink_msg_hil_vehicle_state_get_beta(msg);
	hil_vehicle_state->phi = mavlink_msg_hil_vehicle_state_get_phi(msg);
	hil_vehicle_state->theta = mavlink_msg_hil_vehicle_state_get_theta(msg);
	hil_vehicle_state->psi = mavlink_msg_hil_vehicle_state_get_psi(msg);
	hil_vehicle_state->chi = mavlink_msg_hil_vehicle_state_get_chi(msg);
	hil_vehicle_state->p = mavlink_msg_hil_vehicle_state_get_p(msg);
	hil_vehicle_state->q = mavlink_msg_hil_vehicle_state_get_q(msg);
	hil_vehicle_state->r = mavlink_msg_hil_vehicle_state_get_r(msg);
	hil_vehicle_state->Vg = mavlink_msg_hil_vehicle_state_get_Vg(msg);
	hil_vehicle_state->wn = mavlink_msg_hil_vehicle_state_get_wn(msg);
	hil_vehicle_state->we = mavlink_msg_hil_vehicle_state_get_we(msg);
	mavlink_msg_hil_vehicle_state_get_quat(msg, hil_vehicle_state->quat);
	hil_vehicle_state->quat_valid = mavlink_msg_hil_vehicle_state_get_quat_valid(msg);
#else
	memcpy(hil_vehicle_state, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_HIL_VEHICLE_STATE_LEN);
#endif
}
