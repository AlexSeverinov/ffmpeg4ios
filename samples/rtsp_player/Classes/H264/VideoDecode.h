/*************************************************
Copyright (C), 1998-2009
File name:      	CVideoDecode.h
Author:         	dongchaomissyou
Version:        	V1.0
Date:				2009-05-04
Description:   		��Ƶ������,֧�ֳ��õĽ����㷨
					��MPEG4��MPEG2��MJPEG��H264��
*************************************************/
#if !defined(_VIDEO_DEC_H)
#define _VIDEO_DEC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
#include "libswscale/swscale.h"
#ifdef __cplusplus
}
#endif	


typedef struct CVideoDecode
{
	
	AVCodec*			m_pAVCodec;							// ffmpeg����Ľṹ
	AVCodecContext*		m_pAVCodecContext;					// ffmpeg����Ľṹ
	struct SwsContext*			m_pSwsContext;
	AVFrame*			m_pPicture;							// ffmpeg����Ľṹ
	AVFrame*			m_pFrameYUV;						// ffmpeg����Ľṹ
	AVPacket			avpkt;                              //add by wayde
	uint8_t*			m_pVideoBuffer;						// �������ڲ���Ž�������ݵ��ڴ�����ַ
	int					m_nGetPicture;						// ����һ֡�ɹ����ֵΪ1��ʧ�ܴ�ֵΪ0
	int					m_nVideoFormat;						// �������Ƶ��ʽ
	int				m_bSupportIFrame;					// �Ƿ�֧��I֡���
	
	int				m_bInitSuccess;						// ��ʼ���ɹ���־
	
}CVIDEO_DECODE, *PCVIDEO_DECODE;

#ifdef __cplusplus
extern "C" {
#endif
	
// ��ʼ��������
int	InitDecode(PCVIDEO_DECODE pvideo, int nVideoWidth,int nVideoHeight,enum CodecID emDecCodeID,int nVideoFormat );

// ����ʼ��������
int		UnInitDecode(PCVIDEO_DECODE pvideo);

// ���뺯��
int AVDecode(PCVIDEO_DECODE pvideo, unsigned char *pInputBuffer,int nInputSize,unsigned char **ppOutputBuffer,int* bKeyFrame);
void SetSupportIFrame(PCVIDEO_DECODE pvideo, int bSupportIFrame);

void InitRgbYuv();
	void Yuv12ToRgb32(int iWidth, int iHeight, unsigned char * pYuv, unsigned char * pRgb);
	void Yuv12ToRgb24(int iWidth, int iHeight, unsigned char * pYuv, unsigned char * pRgb);	
	void ConvertYUVtoRGB(unsigned char *src0,unsigned char *src1,unsigned char *src2,unsigned char *dst_ori,int width, int height);
	void InitConvertTable();
	
	void YUV420_RGB32(unsigned char * pRGB, unsigned char* pYUV, int Width, int Height);
	void InitColorSpace();
	
#ifdef __cplusplus
}
#endif

#endif
