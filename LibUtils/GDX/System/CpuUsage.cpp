//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "CpuUsage.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

namespace GDX
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    CpuUsage::CpuUsage()
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    CpuUsage::~CpuUsage()
    {
        Shutdown();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void CpuUsage::Initialise()
    {
        PDH_STATUS status;

        // Initialize the flag indicating whether this object can read the system cpu usage or not.
        m_canReadCPU = true;

        // Create a query object to poll cpu usage.
        status = PdhOpenQuery(NULL, 0, &m_queryHandle);
        
        if(status != ERROR_SUCCESS)
        {
            m_canReadCPU = false;
        }

        // Set query object to poll all cpus in the system.
        status = PdhAddCounter(m_queryHandle, TEXT("\\Processor(_Total)\\% processor time"), 0, &m_counterHandle);

        if(status != ERROR_SUCCESS)
        {
            m_canReadCPU = false;
        }

        m_lastSampleTime = GetTickCount(); 

        m_cpuUsage = 0;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void CpuUsage::Shutdown()
    {
        if( m_canReadCPU )
        {
            PdhCloseQuery( m_queryHandle );

            m_canReadCPU = false;
            m_queryHandle = 0;
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void CpuUsage::Update()
    {
        PDH_FMT_COUNTERVALUE value; 

        if(m_canReadCPU)
        {
            if((m_lastSampleTime + 1000) < GetTickCount())
            {
                m_lastSampleTime = GetTickCount(); 

                PdhCollectQueryData(m_queryHandle);

                PdhGetFormattedCounterValue(m_counterHandle, PDH_FMT_LONG, NULL, &value);

                m_cpuUsage = value.longValue;
            }
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    int CpuUsage::GetUsage()
    {
        int usage;

        if(m_canReadCPU)
        {
            usage = (int)m_cpuUsage;
        }
        else
        {
            usage = 0;
        }

        return( usage );
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    unsigned long CpuUsage::GetTickCount()
    {
        return 0;
    }
}