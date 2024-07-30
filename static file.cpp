void handleClient(int clientSocket) {
    char buffer[1024] = {0};
    read(clientSocket, buffer, 1024);
    std::string request(buffer);

    // Parse the request (assuming a simple GET request)
    size_t pos = request.find("GET");
    if (pos == std::string::npos) {
        close(clientSocket);
        return;
    }

    pos = request.find(" ", pos + 4);
    if (pos == std::string::npos) {
        close(clientSocket);
        return;
    }

    size_t pos2 = request.find(" ", pos + 1);
    std::string filePath = request.substr(pos + 1, pos2 - pos - 1);
    if (filePath == "/") {
        filePath = "/index.html";  // Default file
    }

    // Open the file and read its contents
    std::ifstream file("www" + filePath);  // Assuming "www" is the root directory
    if (!file.is_open()) {
        std::string notFound = "HTTP/1.1 404 Not Found\r\n\r\n";
        send(clientSocket, notFound.c_str(), notFound.size(), 0);
    } else {
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        std::string response = "HTTP/1.1 200 OK\r\nContent-Length: " + std::to_string(content.size()) + "\r\n\r\n" + content;
        send(clientSocket, response.c_str(), response.size(), 0);
    }

    close(clientSocket);
}
