#ifndef __EGIS0570_H
#define __EGIS0570_H 1

/*
 * Device data
 */
#define EGIS0570_VID 0x1c7a
#define EGIS0570_PID 0x0570

#define EGIS0570_CONF 1
#define EGIS0570_INTF 0

/*
 * Device endpoints
 */
#define EGIS0570_EPOUT 0x04
#define EGIS0570_EPIN  0x83

/* 
 * Initialization packets (7 bytes each)
 *
 * First 4 bytes are equivalent to string "EGIS", which must be just a company identificator
 * Other 3 bytes are not recognized yet and may be not important, as they are always the same

 * Answers for each packet contain 7 bytes again
 * First 4 bytes are reversed "EGIS", which is "SIGE", which is company ID again
 * Other 3 bytes are not recognized yet
 * Sending last packet makes sensor return image
 */
#define EGIS0570_TIMEOUT 3000
#define EGIS0570_PKTSIZE 7

#define EGIS0570_INIT_TOTAL (sizeof((init_pkts)) / sizeof((init_pkts[0])))
static unsigned char init_pkts[][EGIS0570_PKTSIZE] =
{
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x20, 0x3f },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x58, 0x3f },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x21, 0x09 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x57, 0x09 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x22, 0x03 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x56, 0x03 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x23, 0x01 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x55, 0x01 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x24, 0x01 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x54, 0x01 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x16, 0x3e },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x09, 0x0b },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x14, 0x03 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x15, 0x00 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x02, 0x0f },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x10, 0x00 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x11, 0x38 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x12, 0x00 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x13, 0x71 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x03, 0x80 },
	{ 0x45, 0x47, 0x49, 0x53, 0x00, 0x02, 0x80 },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x02, 0x2f },
	{ 0x45, 0x47, 0x49, 0x53, 0x06, 0x00, 0xfe }  /* image returned after this packet */
};

/*
 * After sending initial packets device returns image data (32512 bytes)
 * To ask device to send image data again, host needs to send four additional packets
 * Further work is to repeatedly send four repeat packets and read image data
 */

#define EGIS0570_IMGSIZE 32512 /* Not actually used anywhere */

#define EGIS0570_IMGWIDTH  254
#define EGIS0570_IMGHEIGHT 128

/*
 * Image repeat request
 * First 4 bytes are the same as in initialization packets
 * Have no idea what the other 3 bytes mean
 */
#define EGIS0570_REPEAT_TOTAL (sizeof((repeat_pkts)) / sizeof((repeat_pkts[0])))
static unsigned char repeat_pkts[][EGIS0570_PKTSIZE] =
{
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x02, 0x0f },
	{ 0x45, 0x47, 0x49, 0x53, 0x00, 0x02, 0x0f },
	{ 0x45, 0x47, 0x49, 0x53, 0x01, 0x02, 0x2f },
	{ 0x45, 0x47, 0x49, 0x53, 0x06, 0x00, 0xfe }   /* image returned after this packet */
};

#define EGIS0570_BZ3_THRESHOLD 50

#endif