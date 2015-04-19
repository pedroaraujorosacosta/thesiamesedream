
#ifndef __Application_h_
#define __Application_h_

#include <Terrain/OgreTerrain.h>
#include <Terrain/OgreTerrainGroup.h>
#include "BaseApplication.h"

#define MAX_PLANTS 2

class Submarine;

class Application : public BaseApplication
{
private:
	Ogre::TerrainGlobalOptions* mTerrainGlobals;
	Ogre::TerrainGroup* mTerrainGroup;
	OgreBites::Label* mInfoLabel;
	OgreBites::Slider* mDiffuseColorRSlider;
	OgreBites::Slider* mDiffuseColorGSlider;
	OgreBites::Slider* mDiffuseColorBSlider;
	bool mTerrainsImported;

	// Keep our objects here
	Submarine*		sub;
	Ogre::Vector2	cameraVelocity; // TODO: remove this when project is integrated
	Ogre::Real		selectVelocity; // TODO: remove this when project is integrated
	Ogre::int32		selection;		// TODO: remove this when project is integrated
	Ogre::int32		oldSelection;	// TODO: remove this when project is integrated
	bool			isSelectMoving; // TODO: remove this when project is integrated
	enum SystemType { FRACTAL_PLANT, PYTHAGORAS_TREE };
	struct Plant_t
	{
		Ogre::SceneNode* plantNode;
		Ogre::Vector3	 plantLocation;
		Ogre::int32		 numGenerations;
		Ogre::Real		 maxHeight;
	} plants[MAX_PLANTS];

	void defineTerrain(long x, long y);
	void initBlendMaps(Ogre::Terrain* terrain);
	void configureTerrainDefaults(Ogre::Light* light);
public:
	Application(void);
	virtual ~Application(void);

	// Sdk Tray listeners
	virtual void sliderMoved(OgreBites::Slider* slider);
protected:
	virtual void createScene(void);
	virtual void createFrameListener(void);
	virtual void destroyScene(void);
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);

	void createPlant(const std::string& filename, Plant_t& plant, SystemType type);

	// IO Listeners
	virtual bool mouseMoved(const OIS::MouseEvent& evt);
	virtual bool mousePressed(const OIS::MouseEvent& evt, OIS::MouseButtonID id);
	virtual bool mouseReleased(const OIS::MouseEvent& evt, OIS::MouseButtonID id);
	virtual bool keyPressed(const OIS::KeyEvent &arg);
	virtual bool keyReleased(const OIS::KeyEvent &arg);
};

#endif