#include "mAbout.hpp"

mImage::mImage(wxWindow *parent, wxWindowID id,
		const wxPoint &pos, const wxSize &size,
		long style, const wxString &name) :
		wxPanel(parent, id, pos, size, style, name) {}

mImage::~mImage() {
	delete _bitmap;
}

BEGIN_EVENT_TABLE(mImage, wxPanel)
EVT_PAINT(mImage::OnPaint)
END_EVENT_TABLE()

void mImage::OnPaint(wxPaintEvent &WXUNUSED(event)) {
	wxPaintDC dc(this);

	if (_bitmap != NULL && _bitmap->IsOk())
		dc.DrawBitmap(*_bitmap, wxPoint(0, 0), true);
}

void mImage::SetBitmap(wxBitmap *bmp) {
	_bitmap = bmp;
}

mAbout::mAbout(wxBitmap *bmp, wxWindow *parent, const wxString &title, int id,
		wxPoint pos, wxSize size, int style) :
		wxDialog(parent, id, title, pos, size, style) {

	wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
	_image = new mImage(this, wxID_ANY);
	_image->SetBitmap(bmp);
	hbox->Add(_image, wxSizerFlags().Proportion(1).Expand().Border(wxALL, 8));

	wxStaticText *label = new wxStaticText(this, -1, _("Macroroni and Keys"));
	wxFont font = wxFont(wxFontInfo(16).Bold());
	label->SetFont(font);
	vbox->Add(label, wxSizerFlags().Proportion(0).Border(wxLEFT | wxRIGHT, 8));
	label = new wxStaticText(this, -1, wxString::Format(("Version: %s"), _VERSION_STRING));
	vbox->Add(label, wxSizerFlags().Proportion(0).Center());
	label = new wxStaticText(this, -1, _("A Cross-Platform Text Expander"));
	vbox->Add(label, wxSizerFlags().Proportion(0).Center());
	hbox->Add(vbox, wxSizerFlags().Proportion(1).Center().Border(wxUP, 8));

	vbox = new wxBoxSizer(wxVERTICAL);
	vbox->Add(hbox, wxSizerFlags().Proportion(1).Expand().Border(wxUP, 8));

	label = new wxStaticText(this, -1, _("(C) 2020 - David Hertenstein {hlfstr}"));
	vbox->Add(label, wxSizerFlags().Proportion(0).Center());

	hbox = new wxBoxSizer(wxHORIZONTAL);
	wxButton *close = new wxButton(this, 10, _("Close"));
	hbox->Add(close, wxSizerFlags().Proportion(0).Border(wxALL, 8));
	vbox->Add(hbox, wxSizerFlags().Proportion(0).Right().Border(wxALL, 8));

	SetSizer(vbox);
	Center();

	ShowModal();
}

BEGIN_EVENT_TABLE(mAbout, wxDialog)
EVT_BUTTON(10, mAbout::OnClose)
END_EVENT_TABLE()

mAbout::~mAbout() {
	delete _image;
}

void mAbout::OnClose(wxCommandEvent &WXUNUSED(event)) {
	Close();
	Destroy();
}