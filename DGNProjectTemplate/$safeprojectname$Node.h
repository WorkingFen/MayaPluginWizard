#ifndef _$safeprojectname$Node
#define _$safeprojectname$Node
//
// Copyright (C) $year$ $username$
// 
// File: $safeprojectname$Node.h
//
// Dependency Graph Node: $safeprojectname$
//
// Author: Maya Plug-in Wizard 2.0 Reimplemented
//

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MTypeId.h> 

 
class $safeprojectname$ : public MPxNode {
public:
    $safeprojectname$();
	virtual ~$safeprojectname$(); 

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);

	static void* creator();
	static MStatus initialize();

	/* There needs to be a MObject handle declared for each attribute that
	the node will have.  These handles are needed for getting and setting
	the values later. */
	static MObject input;		                // Example input attribute
	static MObject output;		                // Example output attribute

	/* The typeid is a unique 32bit identifier that describes this node.
	It is used to save and retrieve nodes of this type from the binary
	file format.  If it is not unique, it will cause file IO problems. */
	static MTypeId id;
};

#endif
