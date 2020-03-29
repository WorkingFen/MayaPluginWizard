//
// Copyright (C) $year$ $username$ 
// 
// File: $safeprojectname$Main.cpp
//
// Author: Maya Plug-in Wizard 2.0 Reimplemented
//

#include <maya/MFnPlugin.h>

/**
*	Description:
*		this method is called when the plug-in is loaded into Maya.  It 
*		registers all of the services that this plug-in provides with 
*		Maya.
*
*	Arguments:
*		obj - a handle to the plug-in object (use MFnPlugin to access it)
**/
MStatus initializePlugin(MObject obj) { 
	MStatus status;
	MFnPlugin plugin(obj, "username", "MAYA_VERSION", "Any");

	// Add plug-in feature registration here

	return status;
}

/**
*	Description:
*		this method is called when the plug-in is unloaded from Maya. It 
*		deregisters all of the services that it was providing.
*
*	Arguments:
*		obj - a handle to the plug-in object (use MFnPlugin to access it)
**/
MStatus uninitializePlugin(MObject obj) {
	MStatus status;
	MFnPlugin plugin(obj);

	// Add plug-in feature deregistration here

	return status;
}
