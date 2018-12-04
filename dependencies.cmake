#  (The MIT License)
#
#  Copyright (c) 2016 Mohammad S. Babaei
#
#  Permission is hereby granted, free of charge, to any person obtaining a copy
#  of this software and associated documentation files (the "Software"), to deal
#  in the Software without restriction, including without limitation the rights
#  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#  copies of the Software, and to permit persons to whom the Software is
#  furnished to do so, subject to the following conditions:
#
#  The above copyright notice and this permission notice shall be included in
#  all copies or substantial portions of the Software.
#
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
#  THE SOFTWARE.


SET ( Boost_FIND_REQUIRED TRUE )
SET ( Boost_USE_MULTITHREADED ON )
SET ( Boost_USE_STATIC_LIBS OFF )
SET ( Boost_USE_STATIC_RUNTIME OFF )
SET ( PGSQL_FIND_REQUIRED TRUE )
SET ( PISTACHE_FIND_REQUIRED TRUE )
SET ( PQXX_FIND_REQUIRED TRUE )
SET ( Threads_FIND_REQUIRED TRUE )

IF ( NOT WIN32 )
    SET ( THREADS_PREFER_PTHREAD_FLAG TRUE )
ENDIF (  )


### Boost ###
FIND_PACKAGE (Boost 1.55.0
    COMPONENTS
        date_time filesystem log log_setup regex system thread
    )
INCLUDE_DIRECTORIES ( SYSTEM ${Boost_INCLUDE_DIRS} )


### pgSQL ###
FIND_PACKAGE ( pgSQL )
INCLUDE_DIRECTORIES ( SYSTEM ${PGSQL_INCLUDE_DIR} )


### Pistache ###
FIND_PACKAGE ( Pistache )
INCLUDE_DIRECTORIES ( SYSTEM ${PISTACHE_INCLUDE_DIR} )


### pqxx ###
FIND_PACKAGE ( pqxx )
INCLUDE_DIRECTORIES ( SYSTEM ${PQXX_INCLUDE_DIR} )


### Threads ###
FIND_PACKAGE ( Threads )
IF ( NOT Threads_FOUND )
    IF ( Threads_FIND_REQUIRED )
        MESSAGE ( FATAL_ERROR "Could not find Threads" )
    ENDIF (  )
ENDIF (  )
