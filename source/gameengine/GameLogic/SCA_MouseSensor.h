/**
 * Senses mouse events
 *
 * $Id$
 *
 * ***** BEGIN GPL/BL DUAL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version. The Blender
 * Foundation also sells licenses for use in proprietary software under
 * the Blender License.  See http://www.blender.org/BL/ for information
 * about this.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * The Original Code is Copyright (C) 2001-2002 by NaN Holding BV.
 * All rights reserved.
 *
 * The Original Code is: all of this file.
 *
 * Contributor(s): none yet.
 *
 * ***** END GPL/BL DUAL LICENSE BLOCK *****
 */

#ifndef __KX_MOUSESENSOR
#define __KX_MOUSESENSOR

#include "SCA_ISensor.h"
#include "BoolValue.h"
#include "SCA_IInputDevice.h"

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

class SCA_MouseSensor : public SCA_ISensor
{
	Py_Header;
	class SCA_MouseManager*	m_pMouseMgr;
	
	/**
	 * Use SCA_IInputDevice values to encode the mouse mode for now.
	 */
	short int m_mousemode;
	/**
	 * Triggermode true means all mouse events trigger. Useful mainly
	 * for button presses.
	 */
	bool m_triggermode;
	/**
	 * Remember the last state update 
	 */
	int m_val;

	SCA_IInputDevice::KX_EnumInputs m_hotkey;
	
	/**
	 * valid x coordinate
	 */
	short m_x;

	/**
	 * valid y coordinate
	 */
	short m_y;
	
 public:
	/**
	 * Allowable modes for the trigger status of the mouse sensor.
	 */
	enum KX_MOUSESENSORMODE {
		KX_MOUSESENSORMODE_NODEF = 0,
		KX_MOUSESENSORMODE_LEFTBUTTON,
		KX_MOUSESENSORMODE_MIDDLEBUTTON,
		KX_MOUSESENSORMODE_RIGHTBUTTON,
		KX_MOUSESENSORMODE_POSITION,
		KX_MOUSESENSORMODE_POSITIONX,
		KX_MOUSESENSORMODE_POSITIONY,
		KX_MOUSESENSORMODE_MOVEMENT,
		KX_MOUSESENSORMODE_MAX
	};

	bool isValid(KX_MOUSESENSORMODE);
	
	SCA_MouseSensor(class SCA_MouseManager* keybdmgr,
					int startx,int starty,
				   short int mousemode,
				   SCA_IObject* gameobj,
				   PyTypeObject* T=&Type );

	virtual ~SCA_MouseSensor();
	virtual CValue* GetReplica();
	virtual bool Evaluate(CValue* event);

	virtual bool IsPositiveTrigger();
	short int GetModeKey();
	SCA_IInputDevice::KX_EnumInputs GetHotKey();
	void setX(short x);
	void setY(short y);
	
	/* --------------------------------------------------------------------- */
	/* Python interface ---------------------------------------------------- */
	/* --------------------------------------------------------------------- */

	virtual PyObject*  _getattr(char *attr);

	/* read x-coordinate */
	KX_PYMETHOD_DOC(SCA_MouseSensor,GetXPosition);
	/* read y-coordinate */
	KX_PYMETHOD_DOC(SCA_MouseSensor,GetYPosition);

};

#endif //__KX_MOUSESENSOR

