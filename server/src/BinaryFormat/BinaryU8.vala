// Byte
class BinaryU8 : BinaryNumber {
    private uint8 _data;

    public BinaryU8() {        
    }

    public BinaryU8.WithU8 (uint8 data) {
        Set (data);
    }

    public void Set (uint8 data) {
        _data = data;
    }

    public uint8 Get () {
        return _data;
    }

    public override int AsInt32 () {
        return _data;
    }
}