#ifndef __GDX_CPUUSAGE_H
#define __GDX_CPUUSAGE_H

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#pragma comment(lib, "pdh.lib")

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include <pdh.h>

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

namespace GDX
{
    class CpuUsage
    {
    public:
        CpuUsage();
        ~CpuUsage();

        void Initialise();
        void Shutdown();
        void Update();

        int GetUsage();

    private:
        unsigned long GetTickCount();

        bool          m_canReadCPU;
        HQUERY        m_queryHandle;
        HCOUNTER      m_counterHandle;
        unsigned long m_lastSampleTime;
        long          m_cpuUsage;
    };
}

#endif // __GDX_CPUUSAGE_H


