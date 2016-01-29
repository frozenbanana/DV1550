#if defined(WIN32)
  #include <windows.h>
#elif defined(linux)
  #include <unistd.h>
#else
#endif


int millisleep(unsigned ms)
{
#if defined(WIN32)
    SetLastError(0);
      Sleep(ms);
        return GetLastError() ?-1 :0;
#elif defined(linux)
          return usleep(1000 * ms);
#else
#error ("no milli sleep available for platform")
            return -1;
#endif
}
