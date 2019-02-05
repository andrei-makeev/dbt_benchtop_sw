// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// IPmacDevice wrapper class

class IPmacDevice : public COleDispatchDriver
{
public:
	IPmacDevice() {}		// Calls COleDispatchDriver default constructor
	IPmacDevice(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IPmacDevice(const IPmacDevice& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void Open(long dwDevice, BOOL* pbSuccess);
	void Close(long dwDevice);
	void DataStart(long dwDevice, long resolution, long period);
	void DataStop(long dwDevice);
	void DataCollect(long dwDevice, VARIANT* pvArray, BOOL* pbSuccess);
	void GetPmacType(long dwDevice, long* pVal);
	void DPRVarBufRead(long dwDevice, long h, long entryNum, VARIANT* pVal, BOOL* pbSuccess);
	void DPRGetFloat(long dwDevice, long offset, float* pVal, BOOL* pbSuccess);
	void DPRGetLong(long dwDevice, long offset, long* pVal, BOOL* pbSuccess);
	void DPRVarBufInit(long dwDevice, const VARIANT& vAddressArray, const VARIANT& vTypeArray, long* pHandle, BOOL* pbSuccess);
	void DPRSetFloat(long dwDevice, long offset, float newVal, BOOL* pbSuccess);
	void DPRSetLong(long dwDevice, long offset, long newVal, BOOL* pbSuccess);
	void DPRVarBufWrite(long dwDevice, const VARIANT& vData, const VARIANT& vAddresses, const VARIANT& vTypes, long* pWritten);
	// method 'DPRFloat' not emitted because of invalid return type or parameter type
	void GetPmacLocation(long dwDevice, long* pVal);
	void SelectDevice(long hWindow, long* pDeviceNumber, BOOL* pbSuccess);
	long GetDPRSize(long dwDevice);
	BOOL GetDPRAvailable(long dwDevice);
	void SetChecksums(long dwDevice, BOOL bActive);
	BOOL GetDoChecksums(long dwDevice);
	void SetDoChecksums(long dwDevice, BOOL bNewValue);
	void GetAsciiComm(long dwDevice, long* pVal);
	void SetAsciiComm(long dwDevice, long newVal);
	BOOL GetInBootStrapMode(long dwDevice);
	BOOL GetMotionBufferOpen(long dwDevice);
	void SetCriticalIVars(long dwDevice, BOOL* pbSuccess);
	void AbortDownload(long dwDevice);
	void Download(long dwDevice, LPCTSTR filePath, BOOL bMacro, BOOL bMap, BOOL bLog, BOOL bDnld, BOOL* pbSuccess);
	BOOL GetDownloading(long dwDevice);
	void GetPlcStatus(long dwDevice, long* pNumPlc, long* pNumPlcc, long* pI5);
	BOOL GetIsAnyPlcRunning(long dwDevice);
	void GetGlobalStatus(long dwDevice, long* pStatusX, long* pStatusY, BOOL* pbSuccess);
	void GetCoordStatus(long dwDevice, long dwCoord, long* pStatusX, long* pStatusY, BOOL* pbSuccess);
	void GetMotorStatus(long dwDevice, long lMotor, long* pStatusX, long* pStatusY, BOOL* pbSuccess);
	void GetCommandedPos(long dwDevice, long mtr, double scale, double* pVal);
	void GetNetActualPosition(long dwDevice, long mtr, double scale, double* pVal);
	void GetProgExecPoint(long dwDevice, long dwCoord, long* pVal);
	BOOL GetProgramRunning(long dwDevice, long dwCoord);
	long GetGatherPeriod(long dwDevice);
	void SetGatherPeriod(long dwDevice, long nNewValue);
	BOOL GetGatherEnabled(long dwDevice, long num);
	void SetGatherEnabled(long dwDevice, long num, BOOL bNewValue);
	long GetGatherMode(long dwDevice);
	void SetGatherMode(long dwDevice, long nNewValue);
	double GetGatherSampleTime(long dwDevice);
	void SetGatherSampleTime(long dwDevice, double newValue);
	void GetNumGatherSources(long dwDevice, long* pVal);
	void GetNumGatherSamples(long dwDevice, long* pVal);
	void SetGather(long dwDevice, long num, LPCTSTR str, BOOL bEnable, BOOL* pbSuccess);
	void SetQuickGather(long dwDevice, long lComMask, long lEncMask, long lDacMask, long lCurMask, BOOL bEnable, BOOL* pbSuccess);
	void SetQuickGatherWithDirectCurrent(long dwDevice, long lComMask, long lEncMask, long lDacMask, long lCurMask, BOOL bEnable, BOOL* pbSuccess);
	void GetGather(long dwDevice, long num, BSTR* pStr, BOOL* pbSuccess);
	void ClearGather(long dwDevice);
	void InitGather(long dwDevice, long size, double msec, BOOL* pbSuccess);
	void ClearGatherData(long dwDevice);
	void CollectGatherData(long dwDevice, long* pSources, long* pSamples, BOOL* pbSuccess);
	void GetGatherSamples(long dwDevice, long sourceNum, VARIANT* pVariant, BOOL* pbSuccess);
	void GetGatherPoint(long dwDevice, long sourceNum, long sampleNum, double* pVal, BOOL* pbSuccess);
	void StartGather(long dwDevice, BOOL* pbSuccess);
	void StopGather(long dwDevice);
	void strtod48f(LPCTSTR str, double* pVal);
	void strtod48l(LPCTSTR str, double* pVal);
	void strtod24(LPCTSTR str, double* pVal);
	void strtod32dp(LPCTSTR str, double* pVal);
	void strto32f(LPCTSTR str, double* pVal);
	void UploadMacroConfig(long dwDevice, LPCTSTR bsFilePath, BOOL* pbSuccess);
	void SetCurrentGather(long dwDevice, long mask, BOOL bEnable, BOOL* pbSuccess);
	void GetMacroNodeInfo(long dwDevice, long modeNum, BOOL* pbEnabled, BOOL* pbIsIONode, long* pID);
	void GetBitValue(LPCTSTR hexStr, short bit, BOOL* pVal);
	void DPRGetShort(long dwDevice, long address, short* pVal, BOOL* pbSuccess);
	void DPRSetShort(long dwDevice, long address, short newVal, BOOL* pbSuccess);
	void DPRDWordBitSet(long dwDevice, long offset, long bit, BOOL* pVal, BOOL* pbSuccess);
	void DPRSetDWordBit(long dwDevice, long offset, long bit, BOOL* pbSuccess);
	void GetResponseEx(long dwDevice, LPCTSTR question, BOOL bAddLF, BSTR* pAnswer, long* pstatus);
	void DPRGetDWordMask(long dwDevice, long offset, long mask, long* pVal);
	void DPRSetDWordMask(long dwDevice, long offset, long mask, long Val);
	void DPRRotBufRemove(long dwDevice, long bufnum);
	void DPRRotBufInit(long dwDevice, BOOL* pbSuccess);
	void DPRRotBufClr(long dwDevice, long bufnum);
	void DPRSetRotBuf(long dwDevice, BOOL on);
	void DPRAsciiStrToRotEx(long dwDevice, LPCTSTR inpstr, long bufnum, BOOL bSendRemaining, long* pstatus);
	void DPRGetMem(long dwDevice, long offset, long bytes, VARIANT* pVal, BOOL* pbSuccess);
	void DPRSetMem(long dwDevice, long offset, long bytes, const VARIANT& Val, BOOL* pbSuccess);
	void GetResponseProgress(long dwDevice, LPCTSTR question, BOOL bAddLF, BSTR* pAnswer, long* pstatus);
	void Abort(long dwDevice);
	BOOL GetInterruptsEnabled(long dwDevice);
	void SetInterruptsEnabled(long dwDevice, BOOL bNewValue);
	long GetInterruptMask(long dwDevice);
	void SetInterruptMask(long dwDevice, long nNewValue);
	void PmacSave(long dwDevice, LPCTSTR question, long* pstatus);
	void PmacReset(long dwDevice, LPCTSTR question, BOOL bAsciiRingComm, long* pstatus);
	void PhaseMotor(long dwDevice, LPCTSTR question, long* pStatuss);
	void GetControlResponseEx(long dwDevice, short question, BSTR* pAnswer, long* pstatus);
	BOOL GetUSMonitoringEnabled(long dwDevice);
	void SetUSMonitoringEnabled(long dwDevice, BOOL bNewValue);
	long GetUSMonitoringPeriod(long dwDevice);
	void SetUSMonitoringPeriod(long dwDevice, long nNewValue);
	void DPRTest(long dwDevice, BOOL* pbSuccess);
	void AbortTest(long dwDevice);
	// method 'UltraLightAnalyzeStruct' not emitted because of invalid return type or parameter type
	// method 'GetPlcStatusStruct' not emitted because of invalid return type or parameter type
	BOOL get_DPRTesting(long dwDevice);
	void RawGetResponseEx(long dwDevice, LPCTSTR question, BOOL bAddLF, BSTR* pAnswer, long* pstatus);
	void RawGetControlResponseEx(long dwDevice, short question, BSTR* pAnswer, long* pstatus);
	void DPRSetupBuffers(unsigned long dwDevice, BOOL* pbSuccess);
	void DPRBackground(long dwDevice, long on, long period, long coord, BOOL* pbSuccess);
};

typedef enum DEVLOCATIONTYPE
{	DEV_LT_UNKNOWN	= 0,
	DEV_LT_ISA	= DEV_LT_UNKNOWN + 1,
	DEV_LT_SER	= DEV_LT_ISA + 1,
	DEV_LT_ETH	= DEV_LT_SER + 1,
	DEV_LT_PCI	= DEV_LT_ETH + 1,
	DEV_LT_USB	= DEV_LT_PCI + 1,
	DEV_LT_LAST	= DEV_LT_USB + 1
} 	DEVLOCATIONTYPE;

class PmacServer
{
public:
	PmacServer(void);
	~PmacServer(void);
};

