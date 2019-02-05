// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "pmacserver.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// IPmacDevice properties

/////////////////////////////////////////////////////////////////////////////
// IPmacDevice operations

void IPmacDevice::Open(long dwDevice, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_PBOOL;
	InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, pbSuccess);
}

void IPmacDevice::Close(long dwDevice)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice);
}

void IPmacDevice::DataStart(long dwDevice, long resolution, long period)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4;
	InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, resolution, period);
}

void IPmacDevice::DataStop(long dwDevice)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice);
}

void IPmacDevice::DataCollect(long dwDevice, VARIANT* pvArray, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_PVARIANT VTS_PBOOL;
	InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, pvArray, pbSuccess);
}

void IPmacDevice::GetPmacType(long dwDevice, long* pVal)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4;
	InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, pVal);
}

void IPmacDevice::DPRVarBufRead(long dwDevice, long h, long entryNum, VARIANT* pVal, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4 VTS_PVARIANT VTS_PBOOL;
	InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, h, entryNum, pVal, pbSuccess);
}

void IPmacDevice::DPRGetFloat(long dwDevice, long offset, float* pVal, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_PR4 VTS_PBOOL;
	InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, offset, pVal, pbSuccess);
}

void IPmacDevice::DPRGetLong(long dwDevice, long offset, long* pVal, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_PI4 VTS_PBOOL;
	InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, offset, pVal, pbSuccess);
}

void IPmacDevice::DPRVarBufInit(long dwDevice, const VARIANT& vAddressArray, const VARIANT& vTypeArray, long* pHandle, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_VARIANT VTS_VARIANT VTS_PI4 VTS_PBOOL;
	InvokeHelper(0xf, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, &vAddressArray, &vTypeArray, pHandle, pbSuccess);
}

void IPmacDevice::DPRSetFloat(long dwDevice, long offset, float newVal, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_R4 VTS_PBOOL;
	InvokeHelper(0x10, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, offset, newVal, pbSuccess);
}

void IPmacDevice::DPRSetLong(long dwDevice, long offset, long newVal, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4 VTS_PBOOL;
	InvokeHelper(0x11, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, offset, newVal, pbSuccess);
}

void IPmacDevice::DPRVarBufWrite(long dwDevice, const VARIANT& vData, const VARIANT& vAddresses, const VARIANT& vTypes, long* pWritten)
{
	static BYTE parms[] =
		VTS_I4 VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_PI4;
	InvokeHelper(0x12, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, &vData, &vAddresses, &vTypes, pWritten);
}

void IPmacDevice::GetPmacLocation(long dwDevice, long* pVal)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4;
	InvokeHelper(0x16, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, pVal);
}

void IPmacDevice::SelectDevice(long hWindow, long* pDeviceNumber, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4 VTS_PBOOL;
	InvokeHelper(0x1a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 hWindow, pDeviceNumber, pbSuccess);
}

long IPmacDevice::GetDPRSize(long dwDevice)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms,
		dwDevice);
	return result;
}

BOOL IPmacDevice::GetDPRAvailable(long dwDevice)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x1c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms,
		dwDevice);
	return result;
}

void IPmacDevice::SetChecksums(long dwDevice, BOOL bActive)
{
	static BYTE parms[] =
		VTS_I4 VTS_BOOL;
	InvokeHelper(0x1d, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, bActive);
}

BOOL IPmacDevice::GetDoChecksums(long dwDevice)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x25, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms,
		dwDevice);
	return result;
}

void IPmacDevice::SetDoChecksums(long dwDevice, BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_I4 VTS_BOOL;
	InvokeHelper(0x25, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 dwDevice, bNewValue);
}

void IPmacDevice::GetAsciiComm(long dwDevice, long* pVal)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4;
	InvokeHelper(0x2a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, pVal);
}

void IPmacDevice::SetAsciiComm(long dwDevice, long newVal)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x2b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, newVal);
}

BOOL IPmacDevice::GetInBootStrapMode(long dwDevice)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x30, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms,
		dwDevice);
	return result;
}

BOOL IPmacDevice::GetMotionBufferOpen(long dwDevice)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x31, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms,
		dwDevice);
	return result;
}

void IPmacDevice::SetCriticalIVars(long dwDevice, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_PBOOL;
	InvokeHelper(0x36, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, pbSuccess);
}

void IPmacDevice::AbortDownload(long dwDevice)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x3c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice);
}

void IPmacDevice::Download(long dwDevice, LPCTSTR filePath, BOOL bMacro, BOOL bMap, BOOL bLog, BOOL bDnld, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR VTS_BOOL VTS_BOOL VTS_BOOL VTS_BOOL VTS_PBOOL;
	InvokeHelper(0x3e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, filePath, bMacro, bMap, bLog, bDnld, pbSuccess);
}

BOOL IPmacDevice::GetDownloading(long dwDevice)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x3f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms,
		dwDevice);
	return result;
}

void IPmacDevice::GetPlcStatus(long dwDevice, long* pNumPlc, long* pNumPlcc, long* pI5)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4;
	InvokeHelper(0x44, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, pNumPlc, pNumPlcc, pI5);
}

BOOL IPmacDevice::GetIsAnyPlcRunning(long dwDevice)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x49, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms,
		dwDevice);
	return result;
}

void IPmacDevice::GetGlobalStatus(long dwDevice, long* pStatusX, long* pStatusY, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4 VTS_PI4 VTS_PBOOL;
	InvokeHelper(0x4a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, pStatusX, pStatusY, pbSuccess);
}

void IPmacDevice::GetCoordStatus(long dwDevice, long dwCoord, long* pStatusX, long* pStatusY, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 VTS_PBOOL;
	InvokeHelper(0x4b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, dwCoord, pStatusX, pStatusY, pbSuccess);
}

void IPmacDevice::GetMotorStatus(long dwDevice, long lMotor, long* pStatusX, long* pStatusY, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 VTS_PBOOL;
	InvokeHelper(0x4c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, lMotor, pStatusX, pStatusY, pbSuccess);
}

void IPmacDevice::GetCommandedPos(long dwDevice, long mtr, double scale, double* pVal)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_R8 VTS_PR8;
	InvokeHelper(0x57, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, mtr, scale, pVal);
}

void IPmacDevice::GetNetActualPosition(long dwDevice, long mtr, double scale, double* pVal)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_R8 VTS_PR8;
	InvokeHelper(0x59, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, mtr, scale, pVal);
}

void IPmacDevice::GetProgExecPoint(long dwDevice, long dwCoord, long* pVal)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_PI4;
	InvokeHelper(0x60, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, dwCoord, pVal);
}

BOOL IPmacDevice::GetProgramRunning(long dwDevice, long dwCoord)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x62, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms,
		dwDevice, dwCoord);
	return result;
}

long IPmacDevice::GetGatherPeriod(long dwDevice)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x80, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms,
		dwDevice);
	return result;
}

void IPmacDevice::SetGatherPeriod(long dwDevice, long nNewValue)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x80, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 dwDevice, nNewValue);
}

BOOL IPmacDevice::GetGatherEnabled(long dwDevice, long num)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x81, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms,
		dwDevice, num);
	return result;
}

void IPmacDevice::SetGatherEnabled(long dwDevice, long num, BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_BOOL;
	InvokeHelper(0x81, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 dwDevice, num, bNewValue);
}

long IPmacDevice::GetGatherMode(long dwDevice)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x82, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms,
		dwDevice);
	return result;
}

void IPmacDevice::SetGatherMode(long dwDevice, long nNewValue)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x82, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 dwDevice, nNewValue);
}

double IPmacDevice::GetGatherSampleTime(long dwDevice)
{
	double result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x83, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, parms,
		dwDevice);
	return result;
}

void IPmacDevice::SetGatherSampleTime(long dwDevice, double newValue)
{
	static BYTE parms[] =
		VTS_I4 VTS_R8;
	InvokeHelper(0x83, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 dwDevice, newValue);
}

void IPmacDevice::GetNumGatherSources(long dwDevice, long* pVal)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4;
	InvokeHelper(0x84, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, pVal);
}

void IPmacDevice::GetNumGatherSamples(long dwDevice, long* pVal)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4;
	InvokeHelper(0x85, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, pVal);
}

void IPmacDevice::SetGather(long dwDevice, long num, LPCTSTR str, BOOL bEnable, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_BSTR VTS_BOOL VTS_PBOOL;
	InvokeHelper(0x86, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, num, str, bEnable, pbSuccess);
}

void IPmacDevice::SetQuickGather(long dwDevice, long lComMask, long lEncMask, long lDacMask, long lCurMask, BOOL bEnable, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BOOL VTS_PBOOL;
	InvokeHelper(0x87, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, lComMask, lEncMask, lDacMask, lCurMask, bEnable, pbSuccess);
}

void IPmacDevice::SetQuickGatherWithDirectCurrent(long dwDevice, long lComMask, long lEncMask, long lDacMask, long lCurMask, BOOL bEnable, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BOOL VTS_PBOOL;
	InvokeHelper(0x88, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, lComMask, lEncMask, lDacMask, lCurMask, bEnable, pbSuccess);
}

void IPmacDevice::GetGather(long dwDevice, long num, BSTR* pStr, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_PBSTR VTS_PBOOL;
	InvokeHelper(0x89, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, num, pStr, pbSuccess);
}

void IPmacDevice::ClearGather(long dwDevice)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice);
}

void IPmacDevice::InitGather(long dwDevice, long size, double msec, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_R8 VTS_PBOOL;
	InvokeHelper(0x8b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, size, msec, pbSuccess);
}

void IPmacDevice::ClearGatherData(long dwDevice)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x8c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice);
}

void IPmacDevice::CollectGatherData(long dwDevice, long* pSources, long* pSamples, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4 VTS_PI4 VTS_PBOOL;
	InvokeHelper(0x8d, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, pSources, pSamples, pbSuccess);
}

void IPmacDevice::GetGatherSamples(long dwDevice, long sourceNum, VARIANT* pVariant, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_PVARIANT VTS_PBOOL;
	InvokeHelper(0x8e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, sourceNum, pVariant, pbSuccess);
}

void IPmacDevice::GetGatherPoint(long dwDevice, long sourceNum, long sampleNum, double* pVal, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4 VTS_PR8 VTS_PBOOL;
	InvokeHelper(0x8f, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, sourceNum, sampleNum, pVal, pbSuccess);
}

void IPmacDevice::StartGather(long dwDevice, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_PBOOL;
	InvokeHelper(0x90, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, pbSuccess);
}

void IPmacDevice::StopGather(long dwDevice)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x91, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice);
}

void IPmacDevice::strtod48f(LPCTSTR str, double* pVal)
{
	static BYTE parms[] =
		VTS_BSTR VTS_PR8;
	InvokeHelper(0x95, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 str, pVal);
}

void IPmacDevice::strtod48l(LPCTSTR str, double* pVal)
{
	static BYTE parms[] =
		VTS_BSTR VTS_PR8;
	InvokeHelper(0x96, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 str, pVal);
}

void IPmacDevice::strtod24(LPCTSTR str, double* pVal)
{
	static BYTE parms[] =
		VTS_BSTR VTS_PR8;
	InvokeHelper(0x97, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 str, pVal);
}

void IPmacDevice::strtod32dp(LPCTSTR str, double* pVal)
{
	static BYTE parms[] =
		VTS_BSTR VTS_PR8;
	InvokeHelper(0x98, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 str, pVal);
}

void IPmacDevice::strto32f(LPCTSTR str, double* pVal)
{
	static BYTE parms[] =
		VTS_BSTR VTS_PR8;
	InvokeHelper(0x99, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 str, pVal);
}

void IPmacDevice::UploadMacroConfig(long dwDevice, LPCTSTR bsFilePath, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR VTS_PBOOL;
	InvokeHelper(0x9a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, bsFilePath, pbSuccess);
}

void IPmacDevice::SetCurrentGather(long dwDevice, long mask, BOOL bEnable, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_BOOL VTS_PBOOL;
	InvokeHelper(0xbc, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, mask, bEnable, pbSuccess);
}

void IPmacDevice::GetMacroNodeInfo(long dwDevice, long modeNum, BOOL* pbEnabled, BOOL* pbIsIONode, long* pID)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_PBOOL VTS_PBOOL VTS_PI4;
	InvokeHelper(0xbf, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, modeNum, pbEnabled, pbIsIONode, pID);
}

void IPmacDevice::GetBitValue(LPCTSTR hexStr, short bit, BOOL* pVal)
{
	static BYTE parms[] =
		VTS_BSTR VTS_I2 VTS_PBOOL;
	InvokeHelper(0xce, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 hexStr, bit, pVal);
}

void IPmacDevice::DPRGetShort(long dwDevice, long address, short* pVal, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_PI2 VTS_PBOOL;
	InvokeHelper(0xd2, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, address, pVal, pbSuccess);
}

void IPmacDevice::DPRSetShort(long dwDevice, long address, short newVal, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I2 VTS_PBOOL;
	InvokeHelper(0xd3, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, address, newVal, pbSuccess);
}

void IPmacDevice::DPRDWordBitSet(long dwDevice, long offset, long bit, BOOL* pVal, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4 VTS_PBOOL VTS_PBOOL;
	InvokeHelper(0xd4, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, offset, bit, pVal, pbSuccess);
}

void IPmacDevice::DPRSetDWordBit(long dwDevice, long offset, long bit, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4 VTS_PBOOL;
	InvokeHelper(0xd6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, offset, bit, pbSuccess);
}

void IPmacDevice::GetResponseEx(long dwDevice, LPCTSTR question, BOOL bAddLF, BSTR* pAnswer, long* pstatus)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR VTS_BOOL VTS_PBSTR VTS_PI4;
	InvokeHelper(0xd8, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, question, bAddLF, pAnswer, pstatus);
}

void IPmacDevice::DPRGetDWordMask(long dwDevice, long offset, long mask, long* pVal)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4 VTS_PI4;
	InvokeHelper(0xda, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, offset, mask, pVal);
}

void IPmacDevice::DPRSetDWordMask(long dwDevice, long offset, long mask, long Val)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4 VTS_I4;
	InvokeHelper(0xdb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, offset, mask, Val);
}

void IPmacDevice::DPRRotBufRemove(long dwDevice, long bufnum)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0xdd, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, bufnum);
}

void IPmacDevice::DPRRotBufInit(long dwDevice, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_PBOOL;
	InvokeHelper(0xde, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, pbSuccess);
}

void IPmacDevice::DPRRotBufClr(long dwDevice, long bufnum)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0xdf, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, bufnum);
}

void IPmacDevice::DPRSetRotBuf(long dwDevice, BOOL on)
{
	static BYTE parms[] =
		VTS_I4 VTS_BOOL;
	InvokeHelper(0xe0, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, on);
}

void IPmacDevice::DPRAsciiStrToRotEx(long dwDevice, LPCTSTR inpstr, long bufnum, BOOL bSendRemaining, long* pstatus)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR VTS_I4 VTS_BOOL VTS_PI4;
	InvokeHelper(0xe1, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, inpstr, bufnum, bSendRemaining, pstatus);
}

void IPmacDevice::DPRGetMem(long dwDevice, long offset, long bytes, VARIANT* pVal, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4 VTS_PVARIANT VTS_PBOOL;
	InvokeHelper(0xeb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, offset, bytes, pVal, pbSuccess);
}

void IPmacDevice::DPRSetMem(long dwDevice, long offset, long bytes, const VARIANT& Val, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4 VTS_VARIANT VTS_PBOOL;
	InvokeHelper(0xec, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, offset, bytes, &Val, pbSuccess);
}

void IPmacDevice::GetResponseProgress(long dwDevice, LPCTSTR question, BOOL bAddLF, BSTR* pAnswer, long* pstatus)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR VTS_BOOL VTS_PBSTR VTS_PI4;
	InvokeHelper(0xed, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, question, bAddLF, pAnswer, pstatus);
}

void IPmacDevice::Abort(long dwDevice)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xee, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice);
}

BOOL IPmacDevice::GetInterruptsEnabled(long dwDevice)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xef, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms,
		dwDevice);
	return result;
}

void IPmacDevice::SetInterruptsEnabled(long dwDevice, BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_I4 VTS_BOOL;
	InvokeHelper(0xef, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 dwDevice, bNewValue);
}

long IPmacDevice::GetInterruptMask(long dwDevice)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xf0, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms,
		dwDevice);
	return result;
}

void IPmacDevice::SetInterruptMask(long dwDevice, long nNewValue)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0xf0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 dwDevice, nNewValue);
}

void IPmacDevice::PmacSave(long dwDevice, LPCTSTR question, long* pstatus)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR VTS_PI4;
	InvokeHelper(0xf1, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, question, pstatus);
}

void IPmacDevice::PmacReset(long dwDevice, LPCTSTR question, BOOL bAsciiRingComm, long* pstatus)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR VTS_BOOL VTS_PI4;
	InvokeHelper(0xf2, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, question, bAsciiRingComm, pstatus);
}

void IPmacDevice::PhaseMotor(long dwDevice, LPCTSTR question, long* pStatuss)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR VTS_PI4;
	InvokeHelper(0xf4, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, question, pStatuss);
}

void IPmacDevice::GetControlResponseEx(long dwDevice, short question, BSTR* pAnswer, long* pstatus)
{
	static BYTE parms[] =
		VTS_I4 VTS_I2 VTS_PBSTR VTS_PI4;
	InvokeHelper(0xf5, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, question, pAnswer, pstatus);
}

BOOL IPmacDevice::GetUSMonitoringEnabled(long dwDevice)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xf6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, parms,
		dwDevice);
	return result;
}

void IPmacDevice::SetUSMonitoringEnabled(long dwDevice, BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_I4 VTS_BOOL;
	InvokeHelper(0xf6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 dwDevice, bNewValue);
}

long IPmacDevice::GetUSMonitoringPeriod(long dwDevice)
{
	long result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xf7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms,
		dwDevice);
	return result;
}

void IPmacDevice::SetUSMonitoringPeriod(long dwDevice, long nNewValue)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0xf7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 dwDevice, nNewValue);
}

void IPmacDevice::DPRTest(long dwDevice, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_PBOOL;
	InvokeHelper(0xf8, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, pbSuccess);
}

void IPmacDevice::AbortTest(long dwDevice)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xf9, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice);
}

BOOL IPmacDevice::get_DPRTesting(long dwDevice)
{
	BOOL result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x106, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		dwDevice);
	return result;
}

void IPmacDevice::RawGetResponseEx(long dwDevice, LPCTSTR question, BOOL bAddLF, BSTR* pAnswer, long* pstatus)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR VTS_BOOL VTS_PBSTR VTS_PI4;
	InvokeHelper(0x107, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, question, bAddLF, pAnswer, pstatus);
}

void IPmacDevice::RawGetControlResponseEx(long dwDevice, short question, BSTR* pAnswer, long* pstatus)
{
	static BYTE parms[] =
		VTS_I4 VTS_I2 VTS_PBSTR VTS_PI4;
	InvokeHelper(0x108, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, question, pAnswer, pstatus);
}

void IPmacDevice::DPRSetupBuffers(unsigned long dwDevice, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_PBOOL;
	InvokeHelper(0x10b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, pbSuccess);
}

void IPmacDevice::DPRBackground(long dwDevice, long on, long period, long coord, BOOL* pbSuccess)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PBOOL;
	InvokeHelper(0x10c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 dwDevice, on, period, coord, pbSuccess);
}


PmacServer::PmacServer(void)
{
}


PmacServer::~PmacServer(void)
{
}
