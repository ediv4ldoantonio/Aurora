#include "Aurora/Scene/Scene.h"

namespace Aurora
{

    Scene::Scene()
    {
    }

    Entity Scene::CreateEntity()
    {

        Entity entity(
            m_NextEntityID++,
            this);

        return entity;
    }

    void Scene::DestroyEntity(
        Entity entity)
    {
    }

}