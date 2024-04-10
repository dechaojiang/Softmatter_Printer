/********************************** ZMCϵ�п�����  ************************************************
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**�ļ���: zmotion.h
**������: ֣Т��
**ʱ��: 20121008
**����: ZMCDLL �ⲿ�ӿں���

**------------�޶���ʷ��¼----------------------------------------------------------------------------
** �޸���: 
** ��  ��: 
** �ա���: 
** �衡��: 
**
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/




#ifndef _ZMOTION_DLL_H
#define _ZMOTION_DLL_H

#ifdef __cplusplus  
extern "C" {
#endif 

/*********************************************************
�������Ͷ���
**********************************************************/

typedef unsigned __int64   uint64;  
typedef __int64   int64;  


//#define BYTE           INT8U
//#define WORD           INT16U
//#define DWORD          INT32U
typedef unsigned char  BYTE;
typedef unsigned short  WORD;
//typedef unsigned int  DWORD;
//#define __stdcall 
typedef unsigned char  uint8;                   /* defined for unsigned 8-bits integer variable     �޷���8λ���ͱ���  */
typedef signed   char  ZMC_int8;                    /* defined for signed 8-bits integer variable        �з���8λ���ͱ���  */
typedef unsigned short uint16;                  /* defined for unsigned 16-bits integer variable     �޷���16λ���ͱ��� */
typedef signed   short int16;                   /* defined for signed 16-bits integer variable         �з���16λ���ͱ��� */
typedef unsigned int   uint32;                  /* defined for unsigned 32-bits integer variable     �޷���32λ���ͱ��� */
typedef signed   int   ZMC_int32;                   /* defined for signed 32-bits integer variable         �з���32λ���ͱ��� */
typedef float          fp32;                    /* single precision floating point variable (32bits) �����ȸ�������32λ���ȣ� */
typedef double         fp64;                    /* double precision floating point variable (64bits) ˫���ȸ�������64λ���ȣ� */
typedef unsigned int   uint;                  /* defined for unsigned 32-bits integer variable     �޷���32λ���ͱ��� */

// ��������, 
enum ZMC_CONNECTION_TYPE
{
    ZMC_CONNECTION_COM = 1,
    ZMC_CONNECTION_ETH = 2,
    ZMC_CONNECTION_USB = 3,
    ZMC_CONNECTION_PCI = 4,
};

//ȱʡ�ĵȴ�ʱ��
#define ZMC_DEFAULT_TIMEOUT   5000

//������ʱ��Ҫ���ӳ�һЩ
#define ZMC_DEFAULT_TIMEOUT_COM   5000


//ͨ���������
typedef  void* ZMC_HANDLE;



/************************************************/
//������ ��ϸ�Ĵ����볣��˵����� zerror.h
/************************************************/
#define ERR_OK  0
#define ERROR_OK 0
#define ERR_SUCCESS  0



/*********************************************************
ϵͳ״̬����
**********************************************************/
enum ZBASIC_TASKSTATE
{
    TASK_STATE_RUNING = 1,
    TASK_STATE_PAUSE = 3, 
    TASK_STATE_STOP = 0,

    /************  ������trio����״̬, ��ʱ��֧��  ************/
    //����
    TASK_STATE_STEP = 2,
    TASK_STATE_PAUSING = 4,
    TASK_STATE_STOPING = 5,
    
    TASK_STATE_ERROR = 100,//��ѯ��ʱ�����ID���������ֵ, �ű���ʼ�������﷨����Ҳ�����������
};

//������
#define  SYS_STATE_CANNOT_CONNECT   50 //���Ӳ���



/*********************************************************
��������
**********************************************************/

/*************************************************************
Description:    //���������������
Input:          //��
Output:         //������handle
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_Open(ZMC_CONNECTION_TYPE type, char *pconnectstring ,ZMC_HANDLE * phandle);

/*************************************************************
Description:    //���������������, ����ָ�����ӵĵȴ�ʱ��
Input:          //��
Output:         //������handle
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_FastOpen(ZMC_CONNECTION_TYPE type, char *pconnectstring, uint32 uims ,ZMC_HANDLE * phandle);

/*************************************************************
Description:    //��������������ӣ� ���ڷ�ʽ.
Input:          //��
Output:         //������handle
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_OpenCom(uint32 comid, ZMC_HANDLE * phandle);


/*************************************************************
Description:    //�����޸�ȱʡ�Ĳ����ʵ�����

uint32 dwByteSize = 8, uint32 dwParity = NOPARITY, uint32 dwStopBits = ONESTOPBIT

Input:          //
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_SetComDefaultBaud(uint32 dwBaudRate, uint32 dwByteSize, uint32 dwParity, uint32 dwStopBits);
/*************************************************************
Description:    //���ٿ�������������
Input:          //��
Output:         //������handle
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_PeakCom(uint32 comid, uint32 uims,ZMC_HANDLE * phandle);

/*************************************************************
Description:    //���������������
Input:          //IP��ַ���ַ����ķ�ʽ����
Output:         //������handle
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_OpenEth(char *ipaddr, ZMC_HANDLE * phandle);

/*************************************************************
Description:    //���������������
Input:          //IP��ַ��32λ����IP��ַ����, ע���ֽ�˳��
Output:         //������handle
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_OpenEth2(struct in_addr straddr, ZMC_HANDLE * phandle);

/*************************************************************
Description:    //���������������
Input:          //PCI�����
Output:         //������handle
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_OpenPci(uint32 cardnum, ZMC_HANDLE * phandle);

/*************************************************************
Description:    //��ȡPCI�Ŀ��ƿ�����
Input:          //
Output:         //
Return:         //����
*************************************************************/
uint32 __stdcall ZMC_GetMaxPciCards();

/*************************************************************
Description:    //���������������, �Զ�����COM��
Input:          //COM�ŷ�Χ
Output:         //������handle
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_SearchAndOpenCom(uint32 uimincomidfind, uint32 uimaxcomidfind,uint* pcomid, uint32 uims, ZMC_HANDLE * phandle);
/*************************************************************
Description:    //���������������, �Զ���������. ��ʱ��֧��
Input:          //��ȴ�ʱ��
Output:         //������handle ���ӵ�IP��ַ
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_SearchAndOpenEth(char *ipaddr, uint32 uims, ZMC_HANDLE * phandle);

/*************************************************************
Description:    //���������������, �Զ���������.
Input:          //��ȴ�ʱ��
Output:         //������IP��ַ, ��ַ���ÿո����֡�
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_SearchEth(char *ipaddrlist,  uint32 addrbufflength, uint32 uims);


/*************************************************************
Description:    //�رտ���������
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_Close(ZMC_HANDLE  handle);

/*************************************************************
Description:    //�������ʱ�ȴ�ʱ��
Input:          //������handle ����ʱ��
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_SetTimeOut(ZMC_HANDLE  handle, uint32 timems);

/*************************************************************
Description:    //�������ʱ�ȴ�ʱ��
Input:          //������handle 
Output:         //����ʱ��
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_GetTimeOut(ZMC_HANDLE  handle, uint32* ptimems);

/*************************************************************
Description:    //��ȡ��ʱ������Ľ���
Input:          //������handle 
Output:         //
Return:         //���ȣ� ���㣬 
*************************************************************/
float  __stdcall ZMC_GetProgress(ZMC_HANDLE  handle);

/*************************************************************
Description:    //��ȡ���ӵ�����
Input:          //������handle 
Output:         //
Return:         //ZMC_CONNECTION_TYPE
*************************************************************/
uint8  __stdcall ZMC_GetConnectType(ZMC_HANDLE  handle);

/*************************************************************
Description:    //��ȡ���ӵ�����
Input:          //������handle 
Output:         //
Return:         //string
*************************************************************/
const char*  __stdcall ZMC_GetConnectString(ZMC_HANDLE  handle);

#if 0
#endif
/***************************************************
	ZBASIC����ļ���غ����б�
***************************************************/


/*************************************************************
Description:    ////��ȡϵͳ״̬
Input:          //������handle
Output:         //״̬ ZBASIC_TASKSTATE
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_GetState(ZMC_HANDLE handle,uint8 *pstate);

/*************************************************************
Description:    //��ȡ��ͣ���µ������
Input:          //������handle
Output:         //�����
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_GetStopPauseTaskid(ZMC_HANDLE handle,uint8 *ptaskid);


/*************************************************************
Description:    ////��ȡ���ӿ�����������������
Input:          //������handle
Output:         //
Return:         //����������0
*************************************************************/
uint8 __stdcall ZMC_GetAxises(ZMC_HANDLE handle);

/*************************************************************
Description:    //ͨ�õ�����ִ�нӿ�,�������ȡ��������Ӧ��.  ��������û�л���ʱ�Զ�����
Input:          //������handle     pszCommand���,  uimswait ��ȴ�msʱ�� 
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_ExecuteNoAck(ZMC_HANDLE handle, const char* pszCommand, uint32 uimswait);

/*************************************************************
Description:    //ͨ�õ�����ִ�нӿ�  ��������û�л���ʱ�Զ�����
Input:          //������handle  pszCommand���,    uimswait ��ȴ�msʱ�� 
Output:         //psResponse ���տ�������ִ�н�����
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_Execute(ZMC_HANDLE handle, const char* pszCommand, uint32 uimswait, char* psResponse, uint32 uiResponseLength);

/*************************************************************
Description:    //�ȴ�ǰ�������ִ�н�����������ִ�е�Ӧ�𱻶���. ��û�л���ʱ�Զ�����
Input:          //������handle  uimswait ��ȴ�msʱ�� 
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_ExecuteWaitDown(ZMC_HANDLE handle, uint32 uimaxms);

/*************************************************************
Description:    //��ȡ���������Ӧ�� ��û�н���Ӧ�����������.
				�˺���������
Input:          //������handle  uimax ���峤��
Output:         //pbuff ���ض�ȡ�����  puiread ��ȡ�ĳ��ȣ�  pbifExcuteDown �Ƿ��Ѿ�ִ�н���
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_ExecuteGetReceive(ZMC_HANDLE handle, char * pbuff, uint32 uimax, uint32 *puiread, uint8 *pbifExcuteDown);


/*************************************************************
Description:    //��ȡ��������ĵ�ǰʣ�໺��
Input:          //������handle
Output:         //
Return:         //ʣ��ռ� ���� - 0
*************************************************************/
uint32 __stdcall ZMC_ExecuteGetRemainBuffSpace(ZMC_HANDLE handle);




/*************************************************************
Description:    //ֱ������ӿڣ����ڵ���, ֻ֧���������� ��ʱ��֧��
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_DirectCommand(ZMC_HANDLE handle, const char* pszCommand, char* psResponse, uint32 uiResponseLength);


/*************************************************************
Description:    // ����zdevelop��zpj�ı��ļ�������������zpj�ļ�.
Input:          // pZpjfilename  �ı��ļ�����·��
Output:         // pzpj     ��Ŀ�ļ�����
                                pBasDir  BAS�ļ�·��, ����ZAR��ʱ����Ҫ.
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_MakeMultiFileZpj(void *pZpjBuff, char *pBasDir,  const char* pZpjfilename);


/*************************************************************
Description:    //����ZAR�����, 
Input:          pZpjfilename ��Ŀ�ļ��� ��·��
                pZarfilename ZAR�ļ��� 
                pPass ��������, ��APP_PASS  û������ʱpPass = NULL
                uid �󶨿�����ΨһID�� 0-����
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_MakeZar(const char* pZpjfilename, const char* pZarfilename, const char *pPass, uint32 uid);

/*************************************************************
Description:    //����ZAR�����, ��������Ƶ�zpj�ļ�
Input:          //������handle  
                pzpj �ļ�����
                pBasDir bas�����ļ�·�� 
                pZarfilename ZAR�ļ��� 
                pPass ��������, ��APP_PASS  û������ʱpPass = NULL
                uid �󶨿�����ΨһID�� 0-����
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_MakeZar2(void *pzpj,const char *pBasDir, const char* pZarfilename, const char *pPass, uint32 uid);

/*************************************************************
Description:    //����ZAR���ļ�
Input:          //������handle 
                pfilename  zar�ļ���
                pfilenameinControl  BASICϵͳֻ��һ�����ļ������Բ�ָ��.
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_DownZar(ZMC_HANDLE handle, const char* pfilename, const char* pfilenameinControl);

/*************************************************************
Description:    //���ذ��ļ�
Input:          //������handle
                pbuffer     zar�ļ����ڴ��еĵ�ַ
                buffsize    zar�ļ�����
                pfilenameinControl ���������ļ������� , BASICϵͳֻ��һ�����ļ������Բ�ָ��.
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_DownMemZar(ZMC_HANDLE handle, const char* pbuffer, uint32 buffsize, const char* pfilenameinControl);

/*************************************************************
Description:    //���а�
Input:          //������handle 
                pfilenameinControl �ļ����� ��ΪNULL��ʱ������ȱʡ�ļ� , BASICϵͳֻ��һ�����ļ������Բ�ָ��.
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_RunZarFile(ZMC_HANDLE handle, const char* pfilenameinControl);

/*************************************************************
Description:    //��ͣ��������
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_Resume(ZMC_HANDLE handle);

/*************************************************************
Description:    //���ص�ram������
Input:          //������handle 
                pfilename zar�ļ���, ��·��
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_DownZarToRamAndRun(ZMC_HANDLE handle, const char* pfilename);

/*************************************************************
Description:    //���ذ���ram������
Input:          //������handle
                pbuffer     zar�ļ����ڴ��еĵ�ַ
                buffsize    zar�ļ�����
Output:         // 
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_DownMemZarToRamAndRun(ZMC_HANDLE handle, const char* pbuffer, uint32 buffsize);

/*************************************************************
Description:    //�����ذ�ZAR�� �����ص�RAM����
Input:          pZpjfilename ��Ŀ�ļ��� ��·��
                pPass ��������, ��APP_PASS  û������ʱpPass = NULL
                uid �󶨿�����ΨһID�� 0-����
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_MakeZarAndRamRun(const char* pZpjfilename,const  char *pPass, uint32 uid);

/*************************************************************
Description:    //�����ذ�ZAR�� �����ص�RAM����
Input:          //������handle �ļ���
                pzpj �ļ�����
                pBasDir bas�����ļ�·�� 
                pPass ��������, ��APP_PASS  û������ʱpPass = NULL
                uid �󶨿�����ΨһID�� 0-����
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_MakeZarAndRamRun2(ZMC_HANDLE handle, void *pzpj,const char *pBasDir,const  char *pPass, uint32 uid);

/*************************************************************
Description:    //�����ذ�ZAR, �����ص�������ROM
Input:          //������handle �ļ���
                pZpjfilename ��Ŀ�ļ��� ��·��
                pPass ��������, ��APP_PASS  û������ʱpPass = NULL
                uid �󶨿�����ΨһID�� 0-����
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_MakeZarAndDown(const char* pZpjfilename,const  char *pPass, uint32 uid);

/*************************************************************
Description:    //�����ذ�ZAR, �����ص�������ROM
Input:          //������handle �ļ���
                pzpj �ļ�����
                pBasDir bas�����ļ�·�� 
                pPass ��������, ��APP_PASS  û������ʱpPass = NULL
                uid �󶨿�����ΨһID�� 0-����
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_MakeZarAndDown2(ZMC_HANDLE handle, void *pzpj,const char *pBasDir,const  char *pPass, uint32 uid);

/*************************************************************
Description:    //�������ļ��Ķ�����ZPJ�ļ�
Input:          //pBasfilename basic�ļ�������·�� 
Output:         //pzpj     ��Ŀ�ļ�����
                  pBasDir  BAS�ļ�·�����
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_MakeOneFileZpj(void *pZpjBuff,  char *pBasDir, const char* pBasfilename);

/*************************************************************
Description:    //ZPJ�ļ���������, ���ں��ϴ���ZPJ�Ƚ��Ƿ��޸�.
Input:          //pZpjfilename ������zpj�ļ�������·��
Output:         //
                pbuffer ���壬���峤�Ȳ���С���ļ�����
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_MakeRealZpj(const char* pZpjfilename, char* pbuffer, uint32 buffsize);


/*************************************************************
Description:    //ZPJ�ļ���������, ���ں��ϴ���ZPJ�Ƚ��Ƿ��޸�.
                  ȫ����buff����
Input:          //pBasDir basic�ļ���·��
                pzpj ���壬������zpj�ļ��� ͬʱ��Ϊ���
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_MakeRealZpjMem(const char* pBasDir, void *pzpj);

/*************************************************************
Description:    //����ZLIB�ļ�
Input:          //pfilenameBas  basic �ļ�
                pfilenameZlb    zlb �ļ�
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_MakeZlib(const char* pfilenameBas, const char* pfilenameZlb);

/*************************************************************
Description:    //��ȡZLIB�ļ���ȫ������������������SUB��
Input:          //pfilenameZlb  lib�ļ�������·��
Output:         //pbuffer ����ȫ������
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_GetZlibGlobalDefine(const char* pfilenameZlb, char* pbuffer, uint32 buffsize);


/*************************************************************
Description:    //�ϴ�zpj������PC�Ϳ������ļ��Ƚ�
Input:          //������handle
                pbuffer ����zpj�ļ��Ļ��� buffsize ������󳤶�                
Output:         //puifilesize ��ȡ��zpj�ļ�����
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_UpCurZpjToMem(ZMC_HANDLE handle, char* pbuffer, uint32 buffsize, uint32* puifilesize);


/*************************************************************
Description:    //��ͣ
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_Pause(ZMC_HANDLE handle);

/*************************************************************
Description:    //ֹͣ
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_Stop(ZMC_HANDLE handle);




/*********************************************************
    3���ļ�������ʱ��֧��.
**********************************************************/

/*************************************************************
Description:    //����ļ��Ƿ����  
Input:          //������handle ���������ļ�����������չ
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_Check3File(ZMC_HANDLE handle, const char* pfilenameinControl, uint8 *pbIfExist, uint32 *pFileSize);

/*************************************************************
Description:    //���ҿ������ϵ��ļ��� �ļ���Ϊ�ձ�ʾ�ļ���������
Input:          //������handle ���������ļ�����������չ
Output:         // �Ƿ���� �ļ���С
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_FindFirst3File(ZMC_HANDLE handle, char* pfilenameinControl, uint32 *pFileSize);

/*************************************************************
Description:    //���ҿ������ϵ��ļ��� �ļ���Ϊ�ձ�ʾ�ļ���������
Input:          //������handle ���������ļ�����������չ
Output:         // �Ƿ���� �ļ���С
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_FindNext3File(ZMC_HANDLE handle, char* pfilenameinControl, uint32 *pFileSize);

/*************************************************************
Description:    //���ҿ������ϵĵ�ǰ�ļ�
Input:          //������handle ���������ļ�����������չ
Output:         // �Ƿ���� �ļ���С(��ʱ��֧��)
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_GetCur3File(ZMC_HANDLE handle, char* pfilenameinControl, uint32 *pFileSize);

/*************************************************************
Description:    //ɾ���������ϵ��ļ�
Input:          //������handle ���������ļ�����������չ
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_Delete3File(ZMC_HANDLE handle, const char* pfilenameinControl);


/*************************************************************
Description:    //ɾ���������ϵ��ļ�
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_RemoveAll3Files(ZMC_HANDLE handle);

/*************************************************************
Description:    //д�û�flash��, float����
Input:          //������handle
					uiflashid 	flash���
					uinumes		��������
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_FlashWritef(ZMC_HANDLE handle, uint16 uiflashid, uint32 uinumes, float *pfvlue);

/*************************************************************
Description:    //��ȡ�û�flash��, float����
Input:          //������handle
					uiflashid 	flash���
					uibuffnum	�����������
Output:         //
					puinumesread ��ȡ���ı�������
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_FlashReadf(ZMC_HANDLE handle, uint16 uiflashid, uint32 uibuffnum, float *pfvlue, uint32* puinumesread);



/*************************************************************
Description:    //��ȡ��ǰ��������IP��ַ, 
Input:          //������handle
Output:         //sIpAddr  ����IP��ַ��  ע��:������dhcp�Ժ����õ�IP��ʵ�ʵĲ�һ�¡�
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_GetCurIpAddr(ZMC_HANDLE handle, char* sIpAddr);


/*************************************************************
Description:    //��ȡ�ַ����ڵ�ǰ�������ϵ�����
Input:          //������handle
Output:         //type  ���ͣ�string_types
                  TYPE2 ������Ϊ����ʱ����������ĳ��� 
                  pvalue ����ֱ�ӷ���ֵ
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_GetStringType(ZMC_HANDLE handle, const char *sname, uint16 filenum, uint16* type, uint32* type2, double *pvalue);

enum string_types 
{
    STRING_USERSUB = 1, 
    STRING_VARIABLE = 2, 
    STRING_ARRAY = 3, 
    STRING_PARA = 4, 

    STRING_CMD = 5,
    STRING_KEYWORD = 6, // AS �ȹؼ���

    STRING_LOCAL = 7, //�ֲ�����

    STRING_MODULE = 8, //�ֲ�����

    STRING_UNKOWN = 10, 
};


/*************************************************************
Description:    //IO�ӿ� ��ʹ��, ���ֿ�����������ʹ�ܵ����
Input:          //������handle
Output:         //״̬
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_SetAxisEnable(ZMC_HANDLE handle, uint8 iaxis, uint8 bifenable);

/*************************************************************
Description:    //IO�ӿ� �������
Input:          //������handle 1- IO��
Output:         //״̬
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_SetOutput(ZMC_HANDLE handle, uint16 inum, uint8 iostate);


/*************************************************************
Description:    //IO�ӿ� ��ȡ����
Input:          //������handle
Output:         //״̬
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_GetIn(ZMC_HANDLE handle, uint16 inum, uint8* pistate);



/*************************************************************
Description:    //IO�ӿ� ��ȡ���
Input:          //������handle
Output:         //״̬
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_GetOutput(ZMC_HANDLE handle, uint16 inum, uint8* pistate);


typedef struct
{
    uint8 m_HomeState; //
    uint8 m_AlarmState;
    uint8 m_SDState;
    uint8 m_INPState;
    uint8 m_ElDecState;
    uint8 m_ElPlusState;
    uint8 m_HandWheelAState;
    uint8 m_HandWheelBState;
    uint8 m_EncodeAState; //
    uint8 m_EncodeBState; //
    uint8 m_EMGState; //ÿ���ᶼһ��
    uint8 m_ClearState; //
    uint8 m_EnableOut;

    //��������λ�ź�
    uint8 m_SoftElDecState; //0- ��Ч
    uint8 m_SoftElPlusState;
    uint8 m_LatchAState; //�����ź�
    uint8 m_LatchBState; //�����ź�
}struct_AxisStates;

/*************************************************************
Description:    //IO�ӿ� ��ȡ��״̬
Input:          //������handle
Output:         //״̬ struct_AxisStates
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_GetAxisStates(ZMC_HANDLE handle, uint8 iaxis, struct_AxisStates* pstrstates);


/*************************************************************
Description:    //IO�ӿ� ��ȡAD
Input:          //������handle
Output:         //״̬
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_GetAIn(ZMC_HANDLE handle, uint16 inum, float* pfstate);


/*************************************************************
Description:    //IO�ӿ� ��ȡDA
Input:          //������handle
Output:         //״̬
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_GetDaOut(ZMC_HANDLE handle, uint16 inum, float* pfstate);

/*************************************************************
Description:    //IO�ӿ� ����DA
Input:          //������handle
Output:         //״̬
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_SetDaOut(ZMC_HANDLE handle, uint16 inum, float fstate);

/*************************************************************
Description:    //IO�ӿ� �������
Input:          //������handle
Output:         //״̬
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_SetOutAll(ZMC_HANDLE handle, uint16 inumfirst,uint16 inumend, uint32 istate);

/*************************************************************
Description:    //IO�ӿ� ��ȡ�����
Input:          //������handle
Output:         //״̬
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_GetInAll(ZMC_HANDLE handle, uint16 inumfirst,uint16 inumend, uint32* pistate);


/*************************************************************
Description:    //IO�ӿ� ��ȡ�����
Input:          //������handle
Output:         //״̬
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_GetOutAll(ZMC_HANDLE handle, uint16 inumfirst,uint16 inumend, uint32* pistate);






/*************************************************************
Description:    //modbus�Ĵ�������
Input:          //������handle �Ĵ�����ַ
Output:         //
Return:         //������
*************************************************************/
uint32 __stdcall ZMC_Modbus_Set0x(ZMC_HANDLE handle, uint16 start, uint16 inum, uint8* pdata);
uint32 __stdcall ZMC_Modbus_Get0x(ZMC_HANDLE handle, uint16 start, uint16 inum, uint8* pdata);
uint32 __stdcall ZMC_Modbus_Get4x(ZMC_HANDLE handle, uint16 start, uint16 inum, uint16* pdata);
uint32 __stdcall ZMC_Modbus_Set4x(ZMC_HANDLE handle, uint16 start, uint16 inum, uint16* pdata);


/*************************************************************
Description:    //�Ѵ�����ת�������ַ���
Input:          //Ӧ�����Ϣ
Output:         //
Return:         //������
*************************************************************/
const char* ZMC_GetErrcodeDescription(ZMC_int32 ierrcode);

/*************************************************************
Description:    //�������﷨

��ʱ���ṩ

Input:          //�����ַ������棬����1024�ֽ�
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_CheckProgramSyntax(const char *pzpjfilename, char *sError);


//������λ
enum AXIS_FEATURE_BIT
{
    AXIS_FEATURE_STEPPER = 0, //  ����  ���巽��
    AXIS_FEATURE_STEPPER_DOUBLE = 1, //  ���� ˫����
    AXIS_FEATURE_STEPPER_AB = 2, //  ���� A, B��
    
    AXIS_FEATURE_ENCODER = 4, // ֧������Ϊ������, ����, 
    AXIS_FEATURE_ENCODER_PULDIR = 5, // ���巽��ʽ�ı�����
    AXIS_FEATURE_ENCODER_DOUBLE = 6, // ˫���������
    
    AXIS_FEATURE_ENCODER_SSI = 7, // 
    AXIS_FEATURE_ENCODER_TAMA = 8, // 
    AXIS_FEATURE_ENCODER_ENDAT = 9, // 
    
    
    AXIS_FEATURE_WITH_EZ = 10, // ��EZ���룬���ԺͲ���һ��ʹ��
    AXIS_FEATURE_SERVODAC = 11, // dac �ŷ�
    AXIS_FEATURE_STEPCODER = 12, // ��������� �����ͱ�����һ��ʹ��
    
    AXIS_FEATURE_CANOPEN = 13, //  �������ʱ��֧��
    //AXIS_FEATURE_ZCAN = 14, // ֧������ΪZCAN, ������Ժ�����������һ��ϲ�

    
};

/*************************************************************
Description:    //��ȡ����������
Input:          //������handle
                  iaxis     ���
Output:         //pfeatures ���
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_GetAxisFeatures(ZMC_HANDLE handle, uint8 iaxis, uint32 *pfeatures);


typedef  struct
{
    //��Ҫ���
    uint8   m_bIfSupportBasic; // 
    uint8   m_bIfSupportPLC; // �Ƿ�֧��PLC����
    uint8   m_bIfSupportRamRun; // ���ص�RAM����
    uint8   m_bIfLocked; // �Ƿ�LOCK

    //�������
    uint16  m_MaxVirtuAxises;
    uint8   m_MaxAxises;
    uint8   m_MaxBreakes;  // ���ϵ���
    //IO���
    uint8   m_MaxInController;
    uint8   m_MaxOutController;
    uint8   m_MaxAdController;
    uint8   m_MaxDaController;

    //�洢���
    uint32  m_MaxProgramSpaceinKB;  // �ܳ���ռ�
    uint32  m_MaxNandSpaceinKB;
    uint32  m_MaxNandSpaceRemaininKB; //ʣ��Ŀռ�

    //modbus�Ĵ������
    uint16  m_MaxModbusBits;
    uint16  m_MaxModbusRegs;

    //����ΪBASIC���
    uint16  m_MaxFiles;     //ϵͳ֧�ֳ����ļ���
    uint8   m_Max3Files;
    //uint8   m_bIfSupport3File; // 3���ļ�.
    uint8   m_bReserve;

	//trio����
    uint32  m_MaxTable;
    uint32  m_MaxVr;
    
    uint16  m_MaxTaskes;    //ϵͳ������
    uint16  m_MaxTimeres;   //���TIMES��
    
    uint16  m_MaxVarNum; //    ������
    uint16  m_MaxArrayNum; //        

    uint32  m_MaxArraySpace; //      
    
    uint16  m_MaxSubes; //            
    uint16  m_MaxStackes; //            
    
    uint16  m_MaxExpressionLayeres; //  ����ʽ���ӳ̶�
    uint16  m_MaxLabelChares;  //�����ַ���
    



    
}struct_SysMaxSpecification;

/*************************************************************
Description:    //��ȡ���������
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_GetSysSpecification(ZMC_HANDLE handle, struct_SysMaxSpecification *pspeci);

/*************************************************************
Description:    //��ȡ�ű��������Ϣ
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_ReadMessage(ZMC_HANDLE handle, char * pbuff, uint32 uimax, uint32 *puiread);


/*************************************************************
Description:    //����ִ��
Input:          //
// ��������
enum ZBASIC_STEPMODE
{
    STEP_MODE_NONE = 0,
    STEP_MODE_IN = 1,  // ��������
    STEP_MODE_NEXT = 2,  // ���� ��һ��
    STEP_MODE_OUT = 3,  // ���� �ϲ�
    STEP_MODE_SPECIALLINE = 4,  // ���� ָ����
};
				ifilenum:ָ���е�ʱ��ʹ��
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_StepRun(ZMC_HANDLE handle, uint16 taskid, uint8 Stepmode, uint8 bifBreakAll, uint8 ifilenum, uint32 iLineNum);


enum ZBASIC_STEPMODE
{
    STEP_MODE_NONE = 0,
    STEP_MODE_IN = 1,  // ��������
    STEP_MODE_NEXT = 2,  // ���� ��һ��
    STEP_MODE_OUT = 3,  // ���� �ϲ�
    STEP_MODE_SPECIALLINE = 4,  // ���� ָ����
};


typedef struct
{

    //Ӳ��ID
    uint32 m_hardid;

    uint16 m_cardid; // �Ա��һ��
    
    //
    uint8 m_imaxin;
    uint8 m_imaxout;
    uint8 m_imaxad;
    uint8 m_imaxda;

    //��������0��ʾ����
    uint8 m_iAxises;    

}struct_ChildCardInfo;


/*************************************************************
Description:    //ȡ����ǰ����ִ�е�����
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_CancelOnline(ZMC_HANDLE handle);


/*************************************************************
Description:    //�ϵ�, LIB�ļ����治�����Ӷϵ�.
Input:          //������handle �к� ��0 ��ʼ���
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_BreakAdd(ZMC_HANDLE handle, const char* filenamenoext, uint32 ilinenum, uint8 bifPauseAll);

/*************************************************************
Description:    //�ϵ�, LIB�ļ����治�����Ӷϵ�.
Input:          //������handle �к� ��0 ��ʼ���
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_BreakDel(ZMC_HANDLE handle, const char* filenamenoext, uint32 ilinenum);

/*************************************************************
Description:    //�ϵ����
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_BreakClear(ZMC_HANDLE handle);



/*************************************************************
Description:    ////�����ϱ��Ļص�������ʽ
Input:          //������handle
				itypecode: �ϴ�������
				idatalength: ���ݳ���
				pdata: ����ָ��
Output:         //
Return:         //������
*************************************************************/
typedef void (*PZMCAutoUpCallBack)(ZMC_HANDLE handle, ZMC_int32 itypecode, ZMC_int32 idatalength, uint8 *pdata); 


/*************************************************************
Description:    //�����ϱ��ص�����, ��Ҫ������֧��.
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_SetAutoUpCallBack(ZMC_HANDLE handle, PZMCAutoUpCallBack pcallback);


/*************************************************************
Description:    //�ӿ���Ϣ��ȡ
Input:          //������handle
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_EnumChildCard(ZMC_HANDLE handle, uint16 lastid, struct_ChildCardInfo *pCard);

/*************************************************************
Description:    // �Ĵ�������  һ�γ��Ȳ�Ҫ����200�ֽ�
Input:          //������handle �Ĵ�����ַ
				pRegName "D" "M" "VR" "VR_INT" "V" "Z" "X" "Y" "T" "C" "DT"
				iRegbites  0-ȱʡ�� "T" "C" ���� DT����ѡ��32��64��64��ʾdouble����.
				
Output:         //
Return:         //������
*************************************************************/
uint32 __stdcall ZMC_RegisterRead(ZMC_HANDLE handle, const char *pRegName, uint8 iRegbites, uint32 start, uint16 inum, uint8* pdata);
/*************************************************************
Description:    // �Ĵ�������  һ�γ��Ȳ�Ҫ����200�ֽ�
Input:          //������handle �Ĵ�����ַ
				pRegName "D" "M" "VR" "VR_INT" "V" "Z"   "Y" "T" "C" "DT"
				iRegbites  0-ȱʡ�� "T" "C" ����,  DT����ѡ��32��64��64��ʾdouble����.

Output:         //
Return:         //������
*************************************************************/
uint32 __stdcall ZMC_RegisterWrite(ZMC_HANDLE handle, const char *pRegName, uint8 iRegbites, uint32 start, uint16 inum, uint8* pdata);


// ���������ϱ��ĺ�������
/*************************************************************
Description:    // ʹ�������ϱ�
Input:          // cycleindex:  �ϱ�ͨ����, 0-���ֵ-1
                    fintervalms:  �ϱ����ʱ��, ms��λ, ���ܵ��ڿ�����SERVO_PERIOD
                    psetesname �ϱ�����ѡ��, �﷨: ����1, ����2(index), ����3(index, numes)
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_CycleUpEnable(ZMC_HANDLE handle, uint32 cycleindex, float fintervalms, const char* psetesname);


/*************************************************************
Description:    // ȥʹ�������ϱ�
Input:          // cycleindex:  �ϱ�ͨ����, 0-���ֵ-1
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_CycleUpDisable(ZMC_HANDLE handle, uint32 cycleindex);



/*************************************************************
Description:	// �����ϱ��յ��İ�����, �������. ����ʹ��.
Input:			// 
Output: 		//
Return: 		// ����
*************************************************************/
uint32 __stdcall ZMC_CycleUpGetRecvTimes(ZMC_HANDLE handle, uint32 cycleindex);


/*************************************************************
Description:    // ǿ���ϱ�һ��, ���˶�ָ���idle���ܲ�׼ȷ������µ���.
Input:          // 
Output:         //
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_CycleUpForceOnce(ZMC_HANDLE handle, uint32 cycleindex);




/*************************************************************
Description:	// �������ϱ������ȡ����
Input:			// cycleindex -1, �Զ�ѡ��cycle���
					psetname	��������
					isetindex 	�������
					
Output: 		//	pvalue ����ֵ
Return: 		// ������
*************************************************************/
uint32 __stdcall  ZMC_CycleUpReadBuff(ZMC_HANDLE handle, uint32 cycleindex, const char *psetname, uint32 isetindex, double *pvalue);



/*************************************************************
Description:	// �������ϱ������ȡ����
Input:			// cycleindex -1, �Զ�ѡ��cycle���
					psetname	��������
					isetindex 	�������
					
Output: 		//	pvalue ����ֵ
Return: 		// ������
*************************************************************/
uint32 __stdcall  ZMC_CycleUpReadBuffInt(ZMC_HANDLE handle, uint32 cycleindex, const char *psetname, uint32 isetindex, ZMC_int32*pvalue);


/*************************************************************
Description:    // ֱ�ӷ�������С�߶β岹.
Input:          //������handle
				imain �������
				imode	bit0- bifabs	
						bit1- bifsp		�Ƿ�				
						bit2- bifresume	
						bit3- bifmovescan ����							
				iseges	ֱ�߸���
				ilineaxises	һ���岹������
				piaxislist  ���б�
				pfValue	��������, һ�� iseges * ilineaxises

Output:         // pRemainBuff ����ʣ��ֱ�߻�����
Return:         //������
*************************************************************/
ZMC_int32 __stdcall ZMC_MultiLineN(ZMC_HANDLE handle, ZMC_int32 imain, ZMC_int32 imode, ZMC_int32 iseges, ZMC_int32 ilineaxises, ZMC_int32 *piaxislist,  float *pfposlist, ZMC_int32 *pRemainBuff);

/*************************************************************
Description:    //�����汾�ţ������ڱ�ʶ
Input:          //������handle
Output:         //״̬
Return:         //������
*************************************************************/
uint32 __stdcall ZMC_GetSoftVersion(ZMC_HANDLE handle,float *pVersion, char *pVerString, uint32 *pVerDate);


#ifdef __cplusplus  
}  
#endif 


#endif


