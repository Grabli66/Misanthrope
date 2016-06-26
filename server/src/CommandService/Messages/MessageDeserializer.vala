class MessageDeserializer : GLib.Object { 

    // Deserialize data
    public static async MessagePacket Deserialize (BinaryType[] data) {
        if (data.length < 2) throw new DeserError.WrongData ("Wrong data");        
        var number = data[0] as BinaryNumber;
        if (number == null) throw new DeserError.WrongType ("Must be a number");
        var messageType = number.AsInt32 ();

        MessagePacket res = null;

        switch (messageType) {
            case MessagePacket.REGISTER:
                res = new MessageRegister ();
                res.Deserialize (data);
                break;
            default:
                break;
        }

        return res;
    }
}