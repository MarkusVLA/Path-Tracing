//
// Created by Aleksi Lassila on 5.11.2023.
//

#include "scene.h"

void Scene::AddObject(std::shared_ptr<Object::Object> object) {
    objects_.push_back(object);
}

void Scene::RemoveObject(std::shared_ptr<Object::Object> object) {
    objects_.erase(std::remove(objects_.begin(), objects_.end(), object), objects_.end());
}

std::vector<std::shared_ptr<Object::Object>> Scene::GetObjects() const {
    return objects_;
}

std::ostream &operator<<(std::ostream &os, const Scene &scene) {
    os << "Scene objects:" << std::endl;

    for (auto &object: scene.objects_) {
        os << *object << std::endl;
    }

    return os;
}

Camera Scene::GetCamera() const {
    return camera_;
}
