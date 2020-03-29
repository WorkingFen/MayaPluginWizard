#ifndef _$safeprojectname$Cmd
#define _$safeprojectname$Cmd
//
// Copyright (C) $username$
// 
// File: $safeprojectname$Cmd.h
//
// MEL Command: $safeprojectname$
//
// Author: Maya Plug-in Wizard 2.0 Reimplemented
//

#include <maya/MPxCommand.h>

class MArgList;

class $safeprojectname$ : public MPxCommand {
private:
    // Store the data you will need to undo the command here

public:
    $safeprojectname$();
	virtual ~$safeprojectname$();

	MStatus doIt(const MArgList&);
	MStatus redoIt();
	MStatus undoIt();
	bool isUndoable() const;

	static void* creator();
};

#endif
