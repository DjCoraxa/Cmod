static ConVar cvarMaxLvl;
static ConVar cvarLvlRatio;

static bool isExpCoreLoaded;

methodmap ClientData __nullable__ {
  public ClientData() {
    cvarMaxLvl = CreateConVar("cmodclient_maxlvl", "100", "Max client lvl");
    cvarLvlRatio = CreateConVar("cmodclient_lvlratio", "35", "Client lvl ratio");
  }

  property ConVar cvarMaxLvl {
    public get() {
      return cvarMaxLvl;
    }
  }

  property ConVar cvarLvlRatio {
    public get() {
      return cvarLvlRatio;
    }
  }

  property bool isExpCoreLoaded {
    public get() {
      return isExpCoreLoaded;
    }
  }
}
