using Gda;

class Database {
    public const string DATABASE_NAME = "";

    private static Database _instance;    

    private Gda.Connection _connection;

    private Database () {
        Open ();
    }

    public void Open () {
        var needCreate = false;
        if (!FileUtils.test (DATABASE_NAME, FileTest.EXISTS)) needCreate = true;
        _connection = Connection.open_from_string("SQLite", "DB_DIR=.;DB_NAME=serverdata.db", null, Gda.ConnectionOptions.NONE);

        if (needCreate) {
            _connection.execute_non_select_command("CREATE TABLE user (name string PRIMARY KEY, functions string, security_number integer)");
            _connection.update_meta_store(null);
        }
    }

    public static void Init () {
        GetInstance ().Open ();
    }

    public static Database GetInstance () {
        if (_instance == null) {
            _instance = new Database ();
        }

        return _instance;
    }
}