#include "mAbout.hpp"

mImage::mImage(wxWindow *parent, wxWindowID id,
		const wxPoint &pos, const wxSize &size,
		long style, const wxString &name) :
		wxPanel(parent, id, pos, size, style, name) {}

BEGIN_EVENT_TABLE(mImage, wxPanel)
EVT_PAINT(mImage::OnPaint)
END_EVENT_TABLE()

void mImage::OnPaint(wxPaintEvent &WXUNUSED(event)) {
	wxPaintDC dc(this);

	if (_bitmap != NULL && _bitmap->IsOk())
		dc.DrawBitmap(*_bitmap, wxPoint(0, 0), false);
}

void mImage::SetBitmap(wxBitmap *bmp) {
	_bitmap = bmp;
}

mAbout::mAbout(wxBitmap *bmp, wxWindow *parent, const wxString &title, int id,
		wxPoint pos, wxSize size,
		int style) :
		wxDialog(parent, id, title, pos, size, style) {
	_image = new mImage(this, wxID_ANY);
	_image->SetBitmap(bmp);
}