#include "Player/ChessServer.h"
#include <iostream>
// #include "httplib.h"

void ChessServer::make_move() {
  std::cout << "Starting server\n";
  // httplib::Server svr;
  // svr.Get("/move/:move", [](const httplib::Request& req, httplib::Response& res) {
  //   std::string move_to_make = "";
  //   auto made_move = req.path_params.at("move");
  //   res.set_content(move_to_make, "text/plain");
  // });
  // svr.listen("localhost", port);
}