#ifndef __LOG
#define __LOG

#include <iostream>

struct LogStream {
    std::ostream &o;
    bool log, fail;

    LogStream(std::ostream &o, const char *file, int line, bool log, bool fail)
    : o(o), log(log), fail(fail) {
#ifndef NDEBUG
        if (log) o << "[" << file << ":" << line << "]\t";
#endif
    }

    ~LogStream() {
#ifndef NDEBUG
        if (log) o << std::endl;
#endif
        if (fail) abort();
    }

    template <typename T>
    const LogStream &operator <<(T x) const {
#ifndef NDEBUG
        if (log) o << x;
#endif
        return *this;
    }
};

#define LOG_TO(x, log, fail) LogStream(x, __FILE__, __LINE__, log, fail)

#ifndef DEFAULT_LOG
#define DEFAULT_LOG std::cerr
#endif

#define LOG         LOG_TO(DEFAULT_LOG, true, false)
#define LOG_IF(x)   ({ bool __log = (x) ? true : false; LOG_TO(DEFAULT_LOG, __log, false); })
#define FAIL        LOG_TO(DEFAULT_LOG, true, true)

#define CHECK(x)    ({ bool __fail = (x) ? false : true; LOG_TO(DEFAULT_LOG, __fail, __fail); })
#define CHECK_EQ(x, y) CHECK((x) == (y))
#define CHECK_NQ(x, y) CHECK((x) != (y))

#ifndef NDEBUG
#define CHECK_GL()  ({ GLenum err = glGetError(); CHECK_EQ(err, GL_NO_ERROR) << "gl error: " << err; })
#else
#define CHECK_GL()
#endif

#endif
