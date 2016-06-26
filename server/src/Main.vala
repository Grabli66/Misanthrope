void main() {
    Database.Init ();
    var serviceManager = new ServiceManager ();
    serviceManager.Start ();       
}