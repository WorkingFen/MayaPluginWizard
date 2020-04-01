//
// Copyright (C) $year$ $username$
// 
// File: $safeprojectname$Cmd.cpp
//
// MEL Command: $safeprojectname$
//
// Author: Maya Plug-in Wizard 2.0 Reimplemented
//

// Includes everything needed to register a simple MEL command with Maya.
#include <maya/MSimple.h>

/* Use helper macro to register a command with Maya.  It creates and
registers a command that does not support undo or redo.  The 
created class derives off of MPxCommand. */
DeclareSimpleCommand($safeprojectname$, "$username$", "[!output MAYA_VERSION]");

/**
*	Description:
*		implements the MEL $safeprojectname$ command.
*
*	Arguments:
*		args - the argument list that was passes to the command from MEL
*
*	Return Value:
*		MS::kSuccess - command succeeded
*		MS::kFailure - command failed (returning this value will cause the 
*                     MEL script that is being run to terminate unless the
*                     error is caught using a "catch" statement.
**/
MStatus $safeprojectname$::doIt(const MArgList& args) {
	MStatus stat = MS::kSuccess;

	/* Since this class is derived off of MPxCommand, you can use the 
	inherited methods to return values and set error messages */
	setResult("$safeprojectname$ command executed!\n");

	return stat;
}
