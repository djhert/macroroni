#ifndef _mAPP_HPP_
#define _mAPP_HPP_

#include <wx/cmdline.h>
#include <wx/filefn.h>
#include <wx/log.h>
#include <wx/utils.h>
#include <wx/wx.h>

#include "mStorage.hpp"
#include "mTray.hpp"
#include "mWindow.hpp"

#include "version.h"

class makTray;
class makWindow;
class mApp : public wxApp {
public:
	~mApp() = default;

	bool OnInit() override;
#ifndef __WXMSW__
	void OnInitCmdLine(wxCmdLineParser &parser) override;
	bool OnCmdLineParsed(wxCmdLineParser &parser) override;
#endif
	void Quit();

	static mApp *App();

	makTray *Tray;
#ifdef __WXOSX__
	makTray *Dock;
#endif

	makWindow *MainWin;

	makStore Storage;

private:
	static mApp *_instance;

	wxString _file;
};

#ifndef __WXMSW__
static const wxCmdLineEntryDesc cmdLineDesc[] = {
	{ wxCMD_LINE_SWITCH, "h", "help", "show this help message",
			wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP },
	{ wxCMD_LINE_OPTION, "f", "file", "specify a file to load (defaults to ~/.mak)",
			wxCMD_LINE_VAL_STRING },
	wxCMD_LINE_DESC_END
};
#endif

#endif