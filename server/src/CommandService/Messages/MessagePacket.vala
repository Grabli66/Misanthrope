/*
*   Base Message
*/
abstract class MessagePacket {
    public const uint8 REGISTER = 0;

    public abstract void Deserialize (BinaryType[] data);
    public abstract BinaryType[] Serialize ();
}