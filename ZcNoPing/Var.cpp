#include "stdafx.h"
#include <map>
#include "PasswordData.h"

using namespace std;

extern const map<const tstring, const PasswordData> LicenceCodeList{
	{TEXT("964312"),PasswordData(TEXT(" �Գ�û��Ʒ"))},
	{TEXT("541632"),PasswordData(TEXT(" ���û��Ʒ"))},
	{TEXT("493789"),PasswordData(TEXT("       Ʒ"),750)},
	{TEXT("392849"),PasswordData(TEXT("      ��Ʒ"))},
	{TEXT("938498"),PasswordData(TEXT("     ZCNP"))},
	{TEXT("409148"),PasswordData(TEXT("     JGNP")) }
};

tstring LicenceCode;