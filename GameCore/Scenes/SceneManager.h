#ifndef __SCENEMANAGER_H
#define __SCENEMANAGER_H

#include <memory>
#include <unordered_map>

#include <SFML/Graphics.hpp>
#include "SceneBase.h"

namespace Game
{
	class SceneManager
	{
	public:
		SceneManager();
		~SceneManager();

		void Update(float deltaTime);
		unsigned int Add(std::shared_ptr<SceneBase> scene);
		void SwitchToScene(unsigned int id);
		void RemoveScene(unsigned int id);

	private:
		std::unordered_map<unsigned int, std::shared_ptr<SceneBase>> m_scenes;
		std::shared_ptr<SceneBase>  m_currentScene;
		unsigned int                m_insertedSceneID;
	};
}

#endif // __SCENEMANAGER_H
