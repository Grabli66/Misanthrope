// Array
class BinaryArray : BinaryType {    
    private Gee.ArrayList<BinaryType> _data;

    public BinaryArray () {
        _data = new Gee.ArrayList<BinaryType>();
    }

    public void Add (BinaryType data) {
        _data.add (data);
    }

    public BinaryType Get (int index) {
        return _data.@get (index);        
    }
}