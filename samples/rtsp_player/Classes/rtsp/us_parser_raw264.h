// RtspParser.h: interface for the DhStreamParser class.
// Parser�Ƕ��̹߳�����һ����ȡ���ݣ�һ��������ṩ����
// ��Ҫ����ͬ������
//
//////////////////////////////////////////////////////////////////////

#if !defined(US_PARSER_RAW264__INCLUDED_)
#define US_PARSER_RAW264__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "stdafx.h"
//#include "us_kode.h"
//#include "us_core_parser.h"
//#include "us_parser.h"
#include "FrameList.h"

class Raw264Parser //: public IUSParser 
{
public:
	Raw264Parser();
	virtual ~Raw264Parser();
	// ��������.
	//int InputData(unsigned char *pData, unsigned long nDataLength);
	//int InputDataEx(unsigned char *pData, unsigned long nDataLength);
	void PutPacketToQueueVodEx(char* pcContent, int iLen);

public:
	//IUSParser

	//Start Play
	int		Play();

	//Stop
	void	Stop();

	//Create source
	int Prepare(const char * Tempip, int Tempport,const char * Tempusername,const char * Temppassword,int Tmepchannelid,int TempStreamType)
	{
		return 0;
	}
	
	int Prepare(const char * Tempuri, int Temptype);

	//Get status
	int	 GetStatus();
	void SetStatus(int Playstatu)
	{
		return;
	}

	//Gettype
	int		gettype();

	//finish
	int	Reset();

	//PTZ���� PTZ���� PTZ���� ͨ��
	int DoPtzControl(int PtzCmd,int PtzData,int ChannelID) 
	{
		return 0;
	}
	
	void SetCompanyIdentity(char * TempcompanyIdentity)
	{
		return;
	}

	//����0����ʧ�� ����1���óɹ�
	//int SetDeviceChanelInfo(ChannelInfoSeting ChannelInfo)
	//{
	//	return 0;
	//}

	//	
	// ͬ�����֡����.
	MediaData_FRAME * GetNextFrame();
	MediaData_FRAME * GetNextAudioFrame();
	
	// ���������ͬ������I֡,���ߵ�һ�ε��õ�ʱ��,��I֡.
	MediaData_FRAME * GetNextKeyFrame();

	//************�㲥���***************
	//virtual int Play(unsigned char * VideoFilename) = 0;//videofilename��Ҫ���ŵ�¼���ļ�
	//��Ҫ���ŵ�¼��ṹ��
//	int Play(Video_File VideoFile)
//	{
//		return 0;
//	}
	
	//SeekTime��Ҫseek��ʱ��
//	virtual int Seek(Date_Time SeekTime)
//	{
//		return 0;
//	}

	//��ͣ
	virtual int Pause()
	{
		return 0;
	}

	virtual int Resume()
	{
		return 0;
	}
	
	//����¼���ļ�channel ��0��ʼ FileType��ѯ��¼������
	//1������¼��(��ʱ¼��) 2������¼��(�ƶ�����¼��)��3 ������¼�� 4���ֶ�¼�� 5��̽ͷ����¼��
	//��������Ҫ�������������ݣ�ͬʱ��������������б� ֮����ܷ��� �����յ������ݳ��� ���ʧ�ܷ���-1
	//virtual int SearchVideoFile(Date_Time StartTime,Date_Time EndTime,int channel,int FileType)
	//{
	//	return 0;
	//};
	//************�㲥���***************

	//��ȡ��һ��¼���ļ�
	//Video_File * GetNextVideoFile()
	//{
	//	return NULL;
	//}
	
	//��ȡ��һ��������¼
	//Alarm_Struct * GetNextAlarm()
	//{
	//	return NULL;
	//}

public:
	int statu;
	CFrameList m_FrameInfoList ;//֡��Ϣ����
	MediaData_FRAME *m_FrameInfo;
	CFrameList m_auFrameInfoList ;//��Ƶ֡��Ϣ����

	char m_url[512];
	int	 m_Type; 
	


protected:
	//////////////////////////////////////////////////////////////////////////
	//

	MediaData_FRAME* m_tmp_Frameinfo;//��ʱ֡��Ϣ


	/*char * m_szDVRData;	//������DVR_Data
	int  m_nCurLenDVRData; //��ǰDVR_Data�Ĵ�С
	char * m_szPacket;	//������DVR_Data
	int  m_nStartPos;	//��ǰλ��*/
private:
	//ͨ��URL��ȡ��������ַ���˿ڵ���Ϣ
	//According to url get address, port
	//iTypeĬ��Ϊ0, �ο� SST_..
	int parseUrl(const char * url, int iType); 

	char m_address[256];
	int	 m_port;	

	//US_THREAD_T		m_Thread;
};

#endif // !defined(AFX_DHSTREAMPARSER_H__4CB30E13_2FFF_4236_AEE3_E7BD20C8C173__INCLUDED_)
