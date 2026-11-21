#include <boost/asio.hpp>
#include <boost/filesystem.hpp>
#include <zlib.h>
#include <bzlib.h>
#include <pybind11/pybind11.h>
#include <curl/curl.h>

void test_curl()
{
  CURL* curl = curl_easy_init();

  if(curl)
  {
    curl_easy_setopt(curl, CURLOPT_URL, "https://scapix.com");
//  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    CURLcode res = curl_easy_perform(curl);

    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

    curl_easy_cleanup(curl);
  }
}

int main2()
{
	auto r1 = gzwrite(0, 0, 0);
	auto r2 = BZ2_bzCompressInit(0, 0, 0, 0);

	boost::filesystem::path p("hello");

	test_curl();

	return 0;
}
