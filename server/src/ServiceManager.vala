/*
*   Manage all services
*/
class ServiceManager : GLib.Object {

    // Service for commands
    private CommandService _commandService;

    // Logger
    private Logger _log = Logger.GetInstance();

    // Process errors
    private void OnError (Error e) {
        _log.Error (e);
    }

    public ServiceManager () {
        _commandService = new CommandService ();
        _commandService.OnError.connect (OnError);
    }

    // Start all services
    public void Start () {        
        _commandService.Start ();
        new MainLoop ().run ();
    }
}