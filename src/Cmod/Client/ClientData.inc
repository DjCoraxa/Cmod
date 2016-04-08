static ConVar cvarMaxLvl;
static ConVar cvarLvlRatio;
static DataArray statsPtsArray[ClientPts_Count];
static DataArray clientAllPtsArray;

methodmap ClientData __nullable__ {
  public ClientData() {
    cvarMaxLvl = CreateConVar("cmodclient_maxlvl", "100", "Max client lvl");
    cvarLvlRatio = CreateConVar("cmodclient_lvlratio", "35", "Client lvl ratio");
    
    for (int type = 0; type < view_as<int>(ClientPts_Count); ++type)
      statsPtsArray[type] = new DataArray(MAXPLAYERS + 1);

    clientAllPtsArray = new DataArray(MAXPLAYERS + 1);
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

  property DataArray clientAllPtsArray {
    public get() {
      return clientAllPtsArray;
    }
  }

  public DataArray getStatsPtsArray(ClientPtsType type) {
    return statsPtsArray[type];
  }
}
