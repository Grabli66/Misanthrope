/*
*   For serialization and deserialization   
*/
class BinaryDeserializer {

    // Read data length
    private static int ReadLength (BinaryData data, ref int index) {        
        int res = 0;
        uint8 len = 0;
        do {
            len = data.GetU8 (index);
            res = (res << 8) + len;
            index++;
        } while (len == 0xFF);
        
        return res;
    }

    // Read array from binary data
    private static BinaryArray ReadArray (BinaryData data, ref int index) {
        var len = ReadLength (data, ref index);
        var res = new BinaryArray ();
        for (int i = 0; i < len; i++) {
            var tp = ReadType(data, ref index);
            res.Add (tp);
        }
        return res;
    }

    // Read bytes from binary data
    private static BinaryBytes ReadBytes (BinaryData data, ref int index) {        
        var len = ReadLength (data, ref index);
        var arr = data.GetArray (index, len);
        index += len;
        return new BinaryBytes.WithBytes (arr);
    }

    // Read byte from binary data
    private static BinaryU8 ReadByte (BinaryData data, ref int index) {        
        var dat = data.GetU8 (index);
        index++;
        return new BinaryU8.WithU8 (dat);
    }

    // Read type from binary data
    private static BinaryType ReadType (BinaryData data, ref int index) {
        var dataType = data.GetU8 (index);
        index++;
        switch (dataType) {
            case BinaryType.ARRAY_TYPE:
                return ReadArray (data, ref index);
            case BinaryType.BYTES_TYPE:
                return ReadBytes (data, ref index);
            case BinaryType.U8_TYPE:
                return ReadByte (data, ref index);
        }

        throw new DeserError.WrongType ("Unknown type");
    }


    // Deserialize data
    public static async BinaryType[] Deserialize (uint8[] data) {
        var binaryData = new BinaryData.WithArray (data);
        
        var index = 0;
        var dataList = new Gee.ArrayList<BinaryType> ();

        do {                    
            var tp = ReadType (binaryData, ref index);                        
            if (tp == null) break;
            dataList.add (tp);            
                        
        } while (index < data.length);

        var rs = dataList.to_array ();                
        return rs;
    }
}