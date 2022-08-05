set(CMAKE_CXX_STANDARD 17)

set(HTMLCXX_SOURCES
    ParserSax.cc
	ParserDom.cc
	Extensions.cc
	CharsetConverter.cc
	Uri.cc
	Node.cc
	utils.cc)

set(HTMLCXX_PUBLIC_HEADERS
    ParserSax.h ParserSax.inl
    ParserDom.h
    Node.h
    Uri.h
    CharsetConverter.h
    Extensions.h
    htmlcxx_export.h)

find_package(Iconv REQUIRED)

add_library(htmlcxx SHARED ${HTMLCXX_SOURCES})
target_link_libraries(htmlcxx PRIVATE Iconv::Iconv)
set_target_properties(htmlcxx PROPERTIES PUBLIC_HEADER "${HTMLCXX_PUBLIC_HEADERS}")

install(TARGETS htmlcxx
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        PUBLIC_HEADER DESTINATION include/htmlcxx/html)
