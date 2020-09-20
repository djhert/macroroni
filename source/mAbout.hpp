#ifndef _mABOUT_HPP_
#define _mABOUT_HPP_

#include <wx/wx.h>

#include "version.h"

class mImage : public wxPanel {
public:
	mImage(wxWindow *parent, wxWindowID id = wxID_ANY,
			const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize,
			long style = wxTAB_TRAVERSAL, const wxString &name = wxT("mImage"));
	~mImage();

	void OnPaint(wxPaintEvent &event);
	void SetBitmap(wxBitmap *bmp);

private:
	DECLARE_EVENT_TABLE()

	wxBitmap *_bitmap;
};

class mAbout : public wxDialog {
public:
	mAbout(wxBitmap *bmp, wxWindow *parent, const wxString &title, int id = -1,
			wxPoint pos = wxDefaultPosition, wxSize size = wxSize(400, 275),
			int style = wxDEFAULT_DIALOG_STYLE);
	~mAbout();

	void OnClose(wxCommandEvent &event);

protected:
	mImage *_image;

private:
	DECLARE_EVENT_TABLE()
};

#endif