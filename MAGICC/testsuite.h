/** @file
 *	@brief MAVLink comm protocol testsuite generated from MAGICC.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef MAGICC_TESTSUITE_H
#define MAGICC_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_MAGICC(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_common(system_id, component_id, last_msg);
	mavlink_test_MAGICC(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_hil_vehicle_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_hil_vehicle_state_t packet_in = {
		93372036854775807ULL,{ 73.0, 74.0, 75.0 },157.0,185.0,213.0,241.0,269.0,297.0,325.0,353.0,381.0,409.0,437.0,465.0,493.0,{ 521.0, 522.0, 523.0, 524.0 },13
    };
	mavlink_hil_vehicle_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.time_usec = packet_in.time_usec;
        	packet1.Va = packet_in.Va;
        	packet1.alpha = packet_in.alpha;
        	packet1.beta = packet_in.beta;
        	packet1.phi = packet_in.phi;
        	packet1.theta = packet_in.theta;
        	packet1.psi = packet_in.psi;
        	packet1.chi = packet_in.chi;
        	packet1.p = packet_in.p;
        	packet1.q = packet_in.q;
        	packet1.r = packet_in.r;
        	packet1.Vg = packet_in.Vg;
        	packet1.wn = packet_in.wn;
        	packet1.we = packet_in.we;
        	packet1.quat_valid = packet_in.quat_valid;
        
        	mav_array_memcpy(packet1.position, packet_in.position, sizeof(float)*3);
        	mav_array_memcpy(packet1.quat, packet_in.quat, sizeof(float)*4);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_hil_vehicle_state_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_hil_vehicle_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_hil_vehicle_state_pack(system_id, component_id, &msg , packet1.time_usec , packet1.position , packet1.Va , packet1.alpha , packet1.beta , packet1.phi , packet1.theta , packet1.psi , packet1.chi , packet1.p , packet1.q , packet1.r , packet1.Vg , packet1.wn , packet1.we , packet1.quat , packet1.quat_valid );
	mavlink_msg_hil_vehicle_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_hil_vehicle_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.position , packet1.Va , packet1.alpha , packet1.beta , packet1.phi , packet1.theta , packet1.psi , packet1.chi , packet1.p , packet1.q , packet1.r , packet1.Vg , packet1.wn , packet1.we , packet1.quat , packet1.quat_valid );
	mavlink_msg_hil_vehicle_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_hil_vehicle_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_hil_vehicle_state_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.position , packet1.Va , packet1.alpha , packet1.beta , packet1.phi , packet1.theta , packet1.psi , packet1.chi , packet1.p , packet1.q , packet1.r , packet1.Vg , packet1.wn , packet1.we , packet1.quat , packet1.quat_valid );
	mavlink_msg_hil_vehicle_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_MAGICC(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_hil_vehicle_state(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAGICC_TESTSUITE_H
