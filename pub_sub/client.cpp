/* Publish-subscribe pattern for ZMQ in a weather update app.*/

#include <zmq.hpp>
#include <iostream>
#include <sstream>

int main(int argc, char* argv[]) {
    zmq::context_t context(1);

    // Socket to talk to server
    std::cout << "Collecting updates from weather server ..." << "\n";
    zmq::socket_t subscriber(context, zmq::socket_type::sub);
    subscriber.connect("tcp://localhost:5556");

    // Subscribe to zipcode, default is NYC, 10001
    const char* filter = (argc > 1)? argv[1]: "10001";
    subscriber.set(zmq::sockopt::subscribe, filter);

    // Process 100 updates
    int update_nbr;
    long total_temp = 0;
    for (update_nbr = 0; update_nbr < 100; update_nbr++) {
        zmq::message_t update;
        int zipcode, temperature, relhumidity;

        auto retval = subscriber.recv(update, zmq::recv_flags::none);

        std::istringstream iss(static_cast<char*>(update.data()));
        
        iss >> zipcode >> temperature >> relhumidity;
        
        total_temp += temperature;
    }
    std::cout << "Average temperature for zipcode '" << filter
              << "' was " << (int)(total_temp / update_nbr) << "F\n";
    return 0;
}
