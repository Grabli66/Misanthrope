using Gee;

enum WorkState {
    HEADER,
    DATA
}

// Command packet
// [PackNum] [DataLen] [Data]
class CommandPacket {
    public uint8 PackNum;
    public uint DataLen;
    public uint8[] Data;
}

// Session for socket
class SocketSession {
    public SocketConnection Connection;    
    public BinaryData Data;
    public WorkState State;
    public CommandPacket ProcessPacket;

    public SocketSession(SocketConnection conn) {
        Connection = conn;
        Data = new BinaryData ();
        State = WorkState.HEADER;
        ProcessPacket = new CommandPacket ();
    }    
}

/*
*   Service for commands from clients
*/
class CommandService : GLib.Object {
    public const int HEADER_SIZE = 5;
    public const int BUFFER_SIZE = 8192;
    
    // Socket server
    private SocketService _socketService;

    // Logger
    private Logger _log = Logger.GetInstance();
    
    // Sessions
    private HashMap<SocketConnection, SocketSession> _sessions = new HashMap<SocketConnection, SocketSession>();

    // Signal on error
    public signal void OnError (Error e);

    // Process incoming connection
    private bool onIncomingConnection (SocketConnection conn) {
        _log.Info ("Connection");  
        ProcessRequest.begin (conn);      
        return true;
    }

    // Process data from client
    private async void ProcessRequest (SocketConnection conn) {
        try {
            var dis = new DataInputStream (conn.input_stream);
            uint8[] buffer = new uint8[BUFFER_SIZE];
            ssize_t size = 0;

            // Gets session
            SocketSession session = _sessions.@get (conn);
            if (session == null) {
                session = new SocketSession (conn);
                _sessions.@set (conn, session);
            }

            do {
                size = yield dis.read_async (buffer);
                if  (size == 0) break; // if size == 0 connection reset
                session.Data.AddArray (buffer[0:size]);
                yield ProcessData (session);
            } while (size > 0);
        } catch (Error e) {
            OnError (e);
        }
    }

    // Process data 
    private async void ProcessData (SocketSession session) {
        if (session.State == WorkState.HEADER) {
            if (session.Data.Size () < HEADER_SIZE) return;
            session.ProcessPacket.PackNum = session.Data.GetU8 (0);
            session.ProcessPacket.DataLen = session.Data.GetU32 (1);                              
            _log.Info (session.ProcessPacket.DataLen.to_string ());
            session.State = WorkState.DATA;
        }
        
        if (session.State == WorkState.DATA) {
            if (session.Data.Size () >= session.ProcessPacket.DataLen - HEADER_SIZE) {
                var len = session.ProcessPacket.DataLen + HEADER_SIZE;
                session.ProcessPacket.Data = session.Data.GetArray (HEADER_SIZE, len);
                session.Data.LTrim (len);                
                // Process data packet
                yield ProcessPacket (session);
                // Process next data buffer
                yield ProcessData (session);
            }
        }
    }

    // Process data packet
    private async void ProcessPacket (SocketSession session) {
        session.State = WorkState.HEADER;     
        var data = yield BinaryDeserializer.Deserialize (session.ProcessPacket.Data);        
        var packet = yield MessageDeserializer.Deserialize (data);
        yield MessageProcessor.ProcessMessage (packet);
    }    

    public CommandService () {
    }    

    // Start seervice
    public void Start () {
        try {
            _socketService = new SocketService();
            _socketService.add_inet_port (65200, null);
            _socketService.incoming.connect (onIncomingConnection);
            _socketService.start ();
        } catch (Error e) {
            OnError (e);
        }
    }
}