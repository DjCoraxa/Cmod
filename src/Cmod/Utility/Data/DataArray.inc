methodmap DataArray __nullable__ < Handle {
  public DataArray(int blocksize = 1, int startsize = 0) {
    return as<DataArray>(new ArrayList(blocksize, startsize));
  }

  property int length {
    public native get() = GetArraySize;
  }

  public native any getValue(int index, int block = 0, bool asChar = false) = GetArrayCell;

  public native int getString(int index, char[] buffer, int maxlength) = GetArrayString;

  public native int getArray(int index, any[] buffer, int size = -1) = GetArrayArray;

  public native void erase(int index) = RemoveFromArray;

  public native bool resize(int newSize) = ResizeArray;

  public native void setValueUnsafe(int index, any value, int block = 0, bool asChar = false) = SetArrayCell;

  public native int setStringUnsafe(int index, const char[] value) = SetArrayString;

  public native int setArrayUnsafe(int index, const any[] values, int size = -1) = SetArrayArray;

  public native int findValue(any item, int block = 0) = FindValueInArray;

  public native int findString(const char[] item) = FindStringInArray;

  public void setValue(int index, any value, int block = 0) {
    if (index >= this.length)
      this.resize(index + RESIZE_BACKUP);

    this.setValueUnsafe(index, value, block);
  }

  public void setString(int index, const char[] value) {
    if (index >= this.length)
      this.resize(index + RESIZE_BACKUP);

    this.setStringUnsafe(index, value);
  }

  public void setArray(int index, const any[] values, int size = -1) {
    if (index >= this.length)
      this.resize(index + RESIZE_BACKUP);

    this.setArrayUnsafe(index, values, size);
  }

  public void resizeAndSetValue(int newSize, any value, int block = 1) {
    int length = this.length;

    this.resize(newSize);

    for (int index = length; index < newSize; ++index)
      for (int i = 0; i < block; i++)
        this.setValue(index, value, i);  
  }
};
