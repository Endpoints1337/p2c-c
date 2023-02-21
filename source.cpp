#include <iostream>
#include <curl/curl.h>

int main() {
    // Initialize cURL
    CURL* curl = curl_easy_init();

    // Set the URL to download
    std::string url = "https://example.com/file.zip";
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    curl_easy_setopt(curl, CURLOPT_USERAGENT, "P2C CRYPTO");

    // Set the SSL/TLS options to verify the server's certificate
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);

    // Set the output file for the download
    FILE* file = fopen("file.zip", "wb"); // example please keep in mind if you need help comment or contact me via email.
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    // Perform the download
    CURLcode result = curl_easy_perform(curl);

    // Check for errors
    if (result != CURLE_OK) {
        std::cerr << "Error: " << curl_easy_strerror(result) << std::endl;
    }

    // Clean up
    fclose(file);
    curl_easy_cleanup(curl);

    return 0;
}
