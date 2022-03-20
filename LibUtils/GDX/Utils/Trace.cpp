
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Framework.h"

#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdarg.h>

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Trace.h"

namespace GDX
{
    Trace* trace = new Trace;

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Trace::Init(int flags)
    {
        m_traceMode = flags;

        if (m_traceMode & LOG_FILE)
        {
            // TODO: Currently this is not working
            InitLogfile("C:/Development/Documents/LogFiles/logfile.txt");
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Trace::Dbg(const char * const dbgString, ...)
    {
        if (m_traceMode & (LOG_CONSOLE | LOG_FILE))
        {
            if (dbgString != nullptr)
            {
                va_list argList;
                char buffer[256];

                va_start(argList, dbgString);
                vsprintf_s(buffer, dbgString, argList);
                va_end(argList);

                Output(buffer, "DEBUG");
            }
        }
    }
    
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Trace::Err(const char * const dbgString, ...)
    {
        if (m_traceMode & (LOG_CONSOLE | LOG_FILE))
        {
            if (dbgString != nullptr)
            {
                va_list argList;
                va_start(argList, dbgString);

                char buffer[256];

                vsprintf_s(buffer, dbgString, argList);

                Output(buffer, "ERROR");
            }
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Trace::ScreenDbg(const char* dbgString, Vec2Int vec2, ...)
    {
        if (m_traceMode & LOG_SCREEN)
        {
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Trace::Output(const char* text, const char* tag)
    {
        if (m_traceMode & (LOG_CONSOLE | LOG_FILE))
        {
            std::string msg = tag;
            msg += "    [ ";
            msg += text;
            msg += " ]\n";

            OutputDebugStringA(msg.c_str());

            if (m_traceMode & LOG_FILE)
            {
                // TODO:
            }
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    char* Trace::StrippedFileName(const char* file)
    {
        char tmpstr[256];

        sprintf_s(tmpstr, "%s", file);

        int end = 255;
        int start;

        for (start = end; tmpstr[start - 1] != '\\'; start--)
        {
            //if (tmpstr[start] == '/')
            //{
            //    break;
            //}
        }

        int length = (end - start);

        for (int i = 0; i < length; i++)
        {
            m_strippedFilename[i] = tmpstr[start + i];
        }
        
        return m_strippedFilename;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Trace::Line(int linenum)
    {
        if (m_traceMode & (LOG_CONSOLE | LOG_FILE))
        {
            Dbg("Line: %d", linenum);
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Trace::FileLine(const char * const file, int linenum)
    {
        if (m_traceMode & (LOG_CONSOLE | LOG_FILE))
        {
            Dbg("File/Line: %s::%d", StrippedFileName(file), linenum);
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Trace::FileFunc(const char * const file, const char * const func)
    {
        if (m_traceMode & (LOG_CONSOLE | LOG_FILE))
        {
            Dbg("File/Func: %s::%s", StrippedFileName(file), func);
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Trace::FuncLine(const char* const func, int line)
    {
        if (m_traceMode & (LOG_CONSOLE | LOG_FILE))
        {
            Dbg("Func/Line: %s::%d", func, line);
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Trace::Func(const char* const func)
    {
        if (m_traceMode & (LOG_CONSOLE | LOG_FILE))
        {
            Dbg("Func: %s", func);
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Trace::Divider()
    {
        if (m_traceMode & (LOG_CONSOLE | LOG_FILE))
        {
            Dbg("--------------------------------------------------");
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Trace::InitLogfile(const char* filename)
    {
        if (m_traceMode & LOG_FILE)
        {
            strcpy_s(m_logfile, filename);

            FILE *fpLogfile;

            if (fopen_s(&fpLogfile, m_logfile, "W+") != 0)
            {
                if (fpLogfile != nullptr)
                {
                    fclose(fpLogfile);
                }
            }
        }
    }
}

