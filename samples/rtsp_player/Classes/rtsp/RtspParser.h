// DhStreamParser.h: interface for the DhStreamParser class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DHSTREAMPARSER_H__4CB30E13_2FFF_4236_AEE3_E7BD20C8C173__INCLUDED_)
#define AFX_DHSTREAMPARSER_H__4CB30E13_2FFF_4236_AEE3_E7BD20C8C173__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FrameList.h"
#include "rtsp.h"

class RtspParser  
{
public:
	RtspParser();
	virtual ~RtspParser();
	int play();
	void stop();
	int create(const char * url);//,const char *address,int port);
	int create(const char * url ,int type);
	int getstatu();
	// ��������.
	//int InputData(unsigned char *pData, unsigned long nDataLength);
	//int InputDataEx(unsigned char *pData, unsigned long nDataLength);
	// ͬ�����֡����.
	MediaData_FRAME * GetNextFrame();
	// ���������ͬ������I֡,���ߵ�һ�ε��õ�ʱ��,��I֡.
	MediaData_FRAME * GetNextKeyFrame();
	void PutPacketToQueueVodEx(char* pcContent, int iLen);
	int Reset();
	
	MediaData_FRAME * GetNextAudioFrame();
	MediaData_FRAME* m_tmp_Frameinfo;//��ʱ֡��Ϣ

	CFrameList m_FrameInfoList ;//֡��Ϣ����
	CFrameList m_auFrameInfoList ;//��Ƶ֡��Ϣ����
	MediaData_FRAME *m_FrameInfo;

	int statu;
	/*char * m_szDVRData;	//������DVR_Data
	int  m_nCurLenDVRData; //��ǰDVR_Data�Ĵ�С
	char * m_szPacket;	//������DVR_Data
	int  m_nStartPos;	//��ǰλ��*/
	
	source_struct * source;
    
    int GetMediaInfo(TAVPMediaInfo * pInfo);
	
private:
	//ͨ��URL��ȡ��������ַ���˿ڵ���Ϣ
	//According to url get address, port
	//iTypeĬ��Ϊ0, �ο� SST_..
	int parseUrl(const char * url, int iType); 

	char m_address[256];
	int	 m_port;
	
};

#endif // !defined(AFX_DHSTREAMPARSER_H__4CB30E13_2FFF_4236_AEE3_E7BD20C8C173__INCLUDED_)
