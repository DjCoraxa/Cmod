static DataArray fwdPrepareArray;
static DataArray fwdStartArray;
static DataArray fwdStopArray;

methodmap SkillCFGData __nullable__ {
  public SkillCFGData() {
    fwdPrepareArray = new DataArray();
    fwdStartArray = new DataArray();
    fwdStopArray = new DataArray();
  }

  property DataArray fwdPrepareArray {
    public get() {
      return fwdPrepareArray;
    }
  }

  property DataArray fwdStartArray {
    public get() {
      return fwdStartArray;
    }
  }

  property DataArray fwdStopArray {
    public get() {
      return fwdStopArray;
    }
  }
};
