#include "game/piece/piece.h"
#include "gui/chessWindow.h"
#include <gtkmm.h>

int main(int argc, char *argv[]) {
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "com.github.aviraj55.chess");

  ChessWindow window;
  app->run(window);
}
