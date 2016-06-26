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
        _connection = Connection.open_from_string("SQLite", "DB_DIR=.;DB_NAME=serverdata", null, Gda.ConnectionOptions.NONE);

        if (needCreate) {
            _connection.execute_non_select_command("DROP table IF EXISTS test");            
            _connection.execute_non_select_command("CREATE TABLE test (description string, notes string)");
            _connection.execute_non_select_command("INSERT INTO test (description, notes) VALUES (\"Test description 1\", \"Some notes\")");
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