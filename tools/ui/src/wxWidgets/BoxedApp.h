#ifndef __BOXED_APP_H__
#define __BOXED_APP_H__

class BoxedContainer;

class BoxedApp {
public:
    bool Load(BoxedContainer* container, const wxString& iniFilepath);

    const wxString& GetName() {return this->name;}
    const wxString& GetPath() {return this->path;}

    void Launch(bool showConsole);
    wxIcon* CreateIcon(int size);
    BoxedContainer* GetContainer() {return this->container;}
    bool IsLink() { return link.Length()>0;}
    bool SaveApp();
    void Remove();

private:
    friend class BoxedContainer;
    friend class BoxedAppOptionsDialog;

    wxString name;
    wxString path;
    wxString icon;
    wxString link;
    wxString cmd;

    // Boxedwine command line options
    wxString resolution;
    int bpp;
    bool fullScreen;
    wxString glExt;
    int scale;
    int scaleQuality;

    BoxedContainer* container;
    wxString iniFilePath;
};

#endif