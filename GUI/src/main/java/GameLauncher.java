import controller.Controller;
import model.Loop;
import view.MainWindow;

public class GameLauncher {
    public static void main(String[] args) {
        MainWindow mainWindow = new MainWindow(new Controller());
        new Loop().start();
    }
}
