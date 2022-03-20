#ifndef __TRACE_H
#define __TRACE_H

#include "GDX/Maths/Vec2.h"

namespace GDX
{
	#define LOG_NOTHING     1
	#define LOG_CONSOLE     2
	#define LOG_FILE        4
	#define LOG_SCREEN		8
	#define LOG_APPEND      16

	class Trace
	{
	public:
		enum class LogType
		{
			LOG_NONE,
			LOG_DEBUG,
			LOG_WARNING,
			LOG_ERROR
		};

		Trace() = default;
		virtual ~Trace() = default;

		void Init(int flags);
		void Dbg(const char* dbgString, ...);
		void Err(const char* dbgString, ...);
		void ScreenDbg(const char * dbgString, Vec2Int vec2, ...);
		void Line(int linenum = 0);
		void FileLine(const char* file = "", int linenum = 0);
		void FileFunc(const char* file = "", const char* func = "");
		void FuncLine(const char* func = "", int line = 0);
		void Func(const char* func = "");
		void Divider();

		int m_traceMode = LOG_NOTHING;

	private:
		void Output(const char* text, const char* tag);
		char* StrippedFileName(const char* file);

		void InitLogfile(const char *filename);

		char m_strippedFilename[256] = { '\0' };
		char m_logfile[256] = { '\0' };
	};

	extern Trace* trace;

	#define TraceLine()         GDX::trace->Line(__LINE__)
	#define TraceFunc()         GDX::trace->Func(__func__)
	#define TraceFileLine()     GDX::trace->FileLine(__FILE__, __LINE__)
	#define TraceFileFunc()     GDX::trace->FileFunc(__FILE__ , __func__)
	#define TraceFuncLine()     GDX::trace->FuncLine(__func__ , __LINE__)
}

#endif // __TRACE_H

