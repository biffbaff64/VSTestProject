#ifndef __MESSAGE_MANAGER
#define __MESSAGE_MANAGER

namespace Game
{
	class MessageManager
	{
	public:
		MessageManager()
			:
			m_isEnabled(false)
		{
		}
		~MessageManager() = default;

		bool m_isEnabled;
	};
}

#endif // __MESSAGE_MANAGER

