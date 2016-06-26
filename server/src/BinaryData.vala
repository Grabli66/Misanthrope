// For binary manipulation
class BinaryData {
    private uint8[] _data;

    // Simple constructor
    public BinaryData () {
        _data = {};
    }

    // Constructor with array initialization
    public BinaryData.WithArray (uint8[] data) {
        _data = data;
    }

    public int Size () {
        return _data.length;
    }

    public void LTrim (uint len) {        
        _data = _data[len:_data.length];
    }

    public void AddU8 (uint8 data) {
        _data += data;
    }

    public void AddU16 (ushort data) {
        var len = _data.length;
        _data.resize (len + 2);
        _data[len] = (uint8)(data >> 8);
        _data[len + 1] = (uint8)(data & 0xFF);
    }

    public void AddU32 (uint data) {
        
    }

    public void AddArray (uint8[] data) {
        var len = _data.length;
        _data.resize (len + data.length);
        Posix.memcpy (&_data[len], &data[0], data.length);
    }

    public uint8 GetU8 (uint index) {
        return _data[index];
    }

    public ushort GetU16 (uint index) {
        ushort res = (_data[index] << 8) + _data[index + 1]; 
        return res;
    }

    public uint GetU32 (uint index) {
        uint res = (_data[index] << 24) + 
                   (_data[index + 1] << 16) +
                   (_data[index + 2] << 8) +
                   (_data[index + 3]);
        return res;
    }

    public uint8[] GetArray (uint index, uint len) {
        return _data[index:len];
    }

    public uint8[] ToArray() {
        return _data;
    }
}