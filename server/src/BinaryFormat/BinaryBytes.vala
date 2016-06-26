// Bytes or string
class BinaryBytes : BinaryType {        

    private uint8[] _data;

    public BinaryBytes() {        
    }

    public BinaryBytes.WithBytes (uint8[] data) {
        Set (data);
    }

    public void Set (uint8[] data) {
        _data = data;
    }

    public uint8[] Get () {
        return _data;
    }

    // Return byte array as string
    public string AsString () {
        return (string)_data;
    }
}