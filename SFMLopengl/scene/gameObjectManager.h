#include "../commonTypeDefs.h"
class GameObject;

class gameObjectManager {
public:

	///
	/// \brief Destructor
	///
    ~gameObjectManager();

    ///
    /// \brief Constructor
    ///
	gameObjectManager();

    ///
    /// \brief Create gameObject with name and component list as parameter
    /// \param GameObject name as std::string
    /// \param Component-list as std::string ie. "gocVisualSphere, gocAI, gocTransform"
    ///
    void createGameObject(go_type_name _GOName, goc_type_name _GOCList);

    ///
    /// \brief Create empty GameObject
    /// \param GameObject name
    ///
    void createGameObject(go_type_name _GOName);

    ///
    /// \brief Clear all GameObjects from the database
    ///
    void clearGameObjects();

    ///
    /// \brief Get GameObject pointer from GameObjectMap
    /// \param GameObject name
    ///
    void getGameObjectByName(go_type_name _GOName);

    ///
    /// \brief Get GameObject pointer from GameObjectMap
    /// \param GameObject Id as unsigned long int
    ///
    void getGameObjectById(go_type_id _GOId);

private:
    // Returns next free id for gameObject
    const go_type_id getNextFreeId();

    // Map containing all created gameObjects
    GameObject_map gameObjectMap_;

    go_type_id nextFreeId_;
};
