class Logger {
    private static Logger _instance;

    private Logger () {

    }

    public static Logger GetInstance () {
        if (_instance == null) {
            _instance = new Logger ();
        }

        return _instance;
    }

    public void Info (string message) {
        stderr.printf (message + "\n");
    }

    public void Error (Error e) {
        stderr.printf (e.message + "\n");
    }
}