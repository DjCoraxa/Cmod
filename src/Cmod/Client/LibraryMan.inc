static bool isExpCoreLoaded;
static bool isClassCoreLoaded;

methodmap LibraryMan {
  property bool isExpCoreLoaded {
    public get() {
      return isExpCoreLoaded;
    }
  }

  property bool isClassCoreLoaded {
    public get() {
      return isClassCoreLoaded;
    }
  }

  public void onLoadLibrary(const char[] library) {
    if (StrEqual(library, "Cmod_ExpCore"))
      isExpCoreLoaded = true;
    else if (StrEqual(library, "Cmod_ClassCore"))
      isClassCoreLoaded = true;
  }
};
