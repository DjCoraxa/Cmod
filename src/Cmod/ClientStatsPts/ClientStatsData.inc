static DataArray statsPtsArray[ClientPts_Count];
static DataArray clientAllPtsArray;
static int clientFreePts[MAXPLAYERS + 1] = {0, ...};

methodmap ClientStatsData __nullable__ {
  public ClientStatsData() {
    for (int type = 0; type < view_as<int>(ClientPts_Count); ++type)
      statsPtsArray[type] = new DataArray(MAXPLAYERS + 1);

    clientAllPtsArray - new DataArray(MAXPLAYERS + 1);
  }

  property DataArray clientAllPtsArray {
    public get() {
      return clientAllPtsArray;
    }
  }

  public DataArray getStatsPtsArray(ClientPtsType type) {
    return statsPtsArray[type];
  }

  public int getClientFreePts(int client) {
    return clientFreePts[client];
  }

  public void setClientFreePts(int client, int value) {
    clientFreePts[client] = value;
  }
};
