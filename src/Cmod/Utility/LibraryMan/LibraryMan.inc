enum CmodLibType {
  CmodLib_Unknown = -1,
  CmodLib_ClassCore = 0,
  CmodLib_ExpCore,
  CmodLib_ItemCore,
  CmodLib_SkillCore,
  CmodLib_StatsCore,
  CmodLib_WeaponCore,
  CmodLib_PreparedSkill,
  CmodLib_Client,
  CmodLib_Request,
  CmodLib_Count
};

static char libName[][] = {
  "Cmod_ClassCore",
  "Cmod_ExpCore",
  "Cmod_ItemCore",
  "Cmod_SkillCore",
  "Cmod_StatsCore",
  "Cmod_WeaponCore",
  "Cmod_PreparedSkill",
  "Cmod_Client",
  "Cmod_Request"
};

static bool isLoaded[CmodLib_Count];

methodmap LibraryMan {
  public bool isLoaded(CmodLibType library) {
    return isLoaded[library];
  }

  public CmodLibType onLibraryAdded(const char[] library) {
    for (CmodLibType i = view_as<CmodLibType>(0); i < CmodLib_Count; ++i) {
      if (StrEqual(library, libName[i])) {
        isLoaded[i] = true;
        return i;
      }
    }
    return CmodLib_Unknown;
  }
}
