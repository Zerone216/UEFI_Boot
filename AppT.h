#ifndef		_APPT_H_
#define		_APPT_H_

#include <Library\DevicePathLib.h>
#include <Guid\Gpt.h>

#include ".\baselib\common.h"
#include ".\baselib\fileopt.h"
#include ".\baselib\diskrw.h"
#include ".\baselib\scanfs.h"
#include ".\baselib\buffer.h"
#include ".\prokernel\arith.h"

#include ".\guilib\GUILib.h"
#include ".\mainfunc\common\mainfunc_common.h"
#include ".\mainfunc\install\install.h"
#include ".\mainfunc\bootsel\bootsel.h"
#include ".\mainfunc\admin\admin.h"
#include ".\mainfunc\partop\partop.h"

#include ".\hdsplit\HDSplit.h"
#include ".\hdsplit\HardDiskInclude.h"
#include ".\mainfunc\para_struct\para_drv.h"
#include ".\mainfunc\hookblkio\hkblkio.h"
//#include ".\bootvar\setupfile.h"
//#include ".\bootvar\variable.h"
#include ".\mainfunc\probation\probation.h"

#define INIT 0xff00 //初始化
#define INSTALL 0xff01 //安装
#define DEFAULT_INSTALL 0xff02 //默认安装
#define CUSTOM_INSTALL 0xff03 //自定义安装
#define SYSTEM_SELECT 0xff04 //系统选择
#define SYSTEM_SETTING 0xff05 //系统设置
#define ENTER_SYSTEM 0xff06 //进入系统
#define UNINSTALL 0xff07 //卸载保护
#define EXIT 0xffff    //退出EDU返回

#define NOVA_BOOT_PATH L"\\NOVA\\grubx64.efi" //NOVA loader

#pragma pack(1)

#pragma pack()

#endif

