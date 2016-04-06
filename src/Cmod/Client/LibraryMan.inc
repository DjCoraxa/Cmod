static bool isExpCoreLoaded;

methodmap LibraryMan {
  property bool isExpCoreLoaded {
    public get() {
      return isExpCoreLoaded;
    }
  }

  public void onLoadLibrary(const char[] library) {
    if (StrEqual(library, "Cmod_ExpCore"))
      isExpCoreLoaded = true;
  }
};
