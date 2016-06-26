
/*
*   Message for user registration
*   [ 'user_id', 'password hash' ]
*/
class MessageRegister : MessagePacket {
    private const int USER_NAME = 0;
    private const int PASSWORD = 1;

    public string UserName;
    public string Password;

    public override void Deserialize (BinaryType[] data) {
        var arr = data[1] as BinaryArray;
        var userName = arr.Get (USER_NAME) as BinaryBytes;
        var password = arr.Get (PASSWORD) as BinaryBytes;

        if ((userName == null) || (password == null)) throw new DeserError.WrongData ("Wrong Data");
        UserName = userName.AsString ();
        Password = password.AsString ();       
    }

    public override BinaryType[] Serialize () {
        return null;
    }
}