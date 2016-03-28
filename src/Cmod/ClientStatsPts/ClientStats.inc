static ClientStatsData data;

methodmap ClientStats {
  property int freePts {
    public get() {
      return data.getClientFreePts(this);
    }

    public set(int value) {
      data.setClientFreePts(this, value);
    }
  }

  public int getPts(StatsID statsID, ClientPtsType type) {
    return data.getStatsPtsArray(type).getValue(statsID, this);
  }

  public void setPts(StatsID statsID, ClientPtsType type, int value) {
    data.getStatsPtsArray(type).setValue(statsID, value, this);
  }

  public int getAllPts(StatsID statsID) {
    return data.clientAllPtsArray.getValue(statsID, this);
  }

  public int setAllPts(StatsID statsID, int value) {
    data.clientAllPtsArray.setValue(statsID, value, this);
  }

  public int calculateAllPts(StatsID statsID) {
    int pts = 0;
    for (ClientPtsType type = 0; type < ClientPts_Count; ++type)
      pts += this.getPts(statsID, type);

    return this.setAllPts(statsID, pts);
  }

  public bool spendPts(StatsID statsID, int pts) {
    if (0 > pts > this.freePts)
      return false;

    this.freePts -= pts;
    this.setPts(statsID, ClientPts_General, this.getPts(statsID, ClientPts_General) + pts);
    this.calculateAllPts(statsID);

    return true;
  }
}
