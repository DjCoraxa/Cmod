static bool isExpCoreLoaded;
static bool isClassCoreLoaded;
static bool isItemCoreLoaded;

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

  property bool isItemCoreLoaded {
    public get() {
      return isItemCoreLoaded;
    }
  }

  public void onLoadLibrary(const char[] library) {
    if (StrEqual(library, "Cmod_ExpCore"))
      isExpCoreLoaded = true;
    else if (StrEqual(library, "Cmod_ClassCore"))
      isClassCoreLoaded = true;
    else if (StrEqual(library, "Cmod_ItemCore"))
      isItemCoreLoaded = true;
  }
};
