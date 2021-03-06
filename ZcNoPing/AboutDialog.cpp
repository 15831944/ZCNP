#include "stdafx.h"
#include "AboutDialog.h"
#include "resource.h"
#include "MessageBoxOK.h"
#include <ShellAPI.h>
#include <openssl/crypto.h>
using namespace DuiLib;

void AboutDialog::Notify(DuiLib::TNotifyUI & msg)
{
	if (msg.sType == TEXT("click"))
	{
		if (msg.pSender->GetName() == TEXT("ok"))
		{
			Close();
		}
		else if (msg.pSender->GetName() == TEXT("viewlinc"))
		{
			MessageBoxOK::Show(m_hWnd, TEXT("DirectUI License"), TEXT("DirectUI - UI Library\n\nWritten by Bjarke Viksoe(bjarke@viksoe.dk)\n\
Copyright(c) 2006 - 2007 Bjarke Viksoe.\n\n\
This code may be used in compiled form in any way you desire.These\n\
source files may be redistributed by any means PROVIDING it is\n\
not sold for profit without the authors written consent, and\n\
providing that this notice and the authors name is included.\n\
This file is provided \"as is\" with no expressed or implied warranty.\n\
The author accepts no liability if it causes any damage to you or your\n\
computer whatsoever.It's free, so don't hassle me about it.\n\
Beware of bugs."), 700, 450);
			MessageBoxOK::Show(m_hWnd, TEXT("DuiLib License"), TEXT("Copyright (c) 2010-2011, duilib develop team(https://github.com/duilib/duilib).All rights reserved.\n\nRedistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met.\n\nRedistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.\n\nRedistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.\n\nTHIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."), 700, 750);
			ShellExecute(GetHWND(), TEXT("open"), TEXT("http://www.gnu.org/licenses/gpl-3.0.en.html"), NULL, NULL, SW_SHOWMAXIMIZED);
		}
	}
	__super::Notify(msg);
}

LRESULT AboutDialog::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return __super::HandleMessage(uMsg, wParam, lParam);
}

DuiLib::CDuiString AboutDialog::GetSkinFile()
{
	TCHAR szBuf[MAX_PATH] = { 0 };
	_stprintf_s(szBuf, MAX_PATH - 1, _T("%d"), IDR_XMLABOUT);
	return szBuf;
}

void AboutDialog::InitWindow()
{
	tstring openssl_version;
#ifdef UNICODE
	const char* c_ver = OpenSSL_version(OPENSSL_VERSION);
	int len = MultiByteToWideChar(CP_ACP, 0, c_ver, -1, NULL, 0);
	wchar_t* wc_ver = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, c_ver, -1, wc_ver, len);
	openssl_version = wc_ver;
	delete[] wc_ver;
#else
	openssl_version = OpenSSL_version(OPENSSL_VERSION);
#endif
	CTextUI* Text = static_cast<CTextUI*>(m_PaintManager.FindControl(TEXT("openssl_ver")));
	Text->SetText((TEXT("  OpenSSL Version: ") + openssl_version).c_str());
}

DuiLib::UILIB_RESOURCETYPE AboutDialog::GetResourceType() const
{
	return UILIB_RESOURCE;
}
