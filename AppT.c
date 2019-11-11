#include "AppT.h"

CHAR16 * Logbuffer = NULL;
UINTN	Logbufsize = 0x3000000;
UINTN	count = 0;

EFI_BLOCK_IO  *BlkIo = NULL; 
UINT16 gModuleConfig = 0; //软件功能模块化配置标志
UINT8 GetMultiLanguageFlag = 0;

//当前程序运行的根目录Handle
EFI_FILE_PROTOCOL *RootDirectoryFileHandle = NULL; //
EFI_FILE_PROTOCOL *RtdirFileHdl;
EFI_FILE_PROTOCOL *RtDirFileHDL_USB = NULL; //
//////////////////////////////////////////////////////////////////////////

//load system boot loader image file
EFI_STATUS NovaBoot(IN EFI_HANDLE ImageHandle)
{
	EFI_STATUS	Status;
	EFI_LOADED_IMAGE * LoadedImage = NULL;
	EFI_HANDLE ChildImageHandle;
	EFI_DEVICE_PATH_PROTOCOL * DevicePath = NULL;
  
	DisplayMode	ScreenMode;
	EFI_GRAPHICS_OUTPUT_PROTOCOL	* Graphic;
  EFI_GUID gEfiLoadedImageProtocol  = EFI_LOADED_IMAGE_PROTOCOL_GUID;
  
	Status = gBS->HandleProtocol(ImageHandle, &gEfiLoadedImageProtocol, (VOID **) &LoadedImage);
	if(EFI_ERROR(Status))
	{
    eLog(L"HandleProtoclo error,Error-code:%r.",Status);
    return Status;
	}
  
	DevicePath = DevicePathFromHandle(LoadedImage->DeviceHandle);
	if(DevicePath == NULL)
	{
		eLog(L"DevicePathFromHandle error.");
    return Status;
	}

	DevicePath = FileDevicePath(LoadedImage->DeviceHandle, NOVA_BOOTPATH);
	if(DevicePath == NULL)
	{
    eLog(L"FileDevicePath error.");
    return Status;
	}

	iLog(L"Start Load Nova Image.");
	Status= gBS->LoadImage(FALSE, ImageHandle, DevicePath, NULL, 0, &ChildImageHandle);
	if(EFI_ERROR(Status))
	{
    eLog(L"Load Nova Image error.Error-code:%r.",Status);
    return Status;
	} 

	//屏幕模式设置为800 * 600
	Status = InitScreen(&ScreenMode,&Graphic);
	if(EFI_ERROR(Status))
	{
    eLog(L"Set Screen to 800*600 error.Error-code:%r.",Status);
    return Status;
	}
  
	Status = gBS->StartImage(ChildImageHandle, NULL, NULL);
	if(EFI_ERROR(Status))
	{
    eLog(L"Start Nova failed.Error-code:%r.",Status);
    return Status;
	}
  
	return Status;
}

EFI_STATUS
	EFIAPI
	UefiAppMain ( IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE  *SystemTable )
{
	EFI_STATUS	Status;
	BLKIO_ARRAY BlkIoArray; 
	UINT32 ret = 0xffff;
	EFI_GUID gBlockIoProtocol    = EFI_BLOCK_IO_PROTOCOL_GUID;
	UINT32 operate_status = INIT; //
	CHAR16 * TempFileName = NULL;
	UINT64 FileSize = 0;
	UINTN	BlockIoCount = 0;
  
	EFI_TEXT_STRING			ConoutOutput = gST->ConOut->OutputString;
	EFI_TEXT_STRING			StdErrOutput = gST->StdErr->OutputString;
	UINT16					EnterNetcloneFlag = 0;
	EFI_FILE_PROTOCOL		*FileRootDir = NULL;
	EFI_TIME				Time;
	EFI_TIME_CAPABILITIES	Temp;
	CHAR16					TimeBuffer[30];

	EFI_BLOCK_IO * pBlkIo = NULL;
	UINT16 ModuleConfig = 0;
	UINT32 PartTabType =0;
	UINT8 IsFromDefaultInstallProcess = 0;
	UINT8 IsInProbation = 0;

	Status = iLog(L"================Program Start====================");
	if(EFI_ERROR(Status))
	{
    DeleteLog();	
    return Status;
	}

	gST->ConOut->OutputString = OutStringLog;
	gST->StdErr->OutputString = OutStringLog;
  
  
  return Status;
}
