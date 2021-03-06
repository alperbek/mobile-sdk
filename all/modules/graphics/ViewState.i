#ifndef _VIEWSTATE_I
#define _VIEWSTATE_I

#pragma SWIG nowarn=325

%module ViewState

!proxy_imports(carto::ViewState, core.MapPos, core.ScreenPos, core.MapVec, components.Options, projections.Projection)

%{
#include "graphics/ViewState.h"	
#include <cglib/mat.h>
%}

%include <cartoswig.i>

%import "core/MapPos.i"
%import "core/MapVec.i"
%import "core/ScreenPos.i"
%import "components/Options.i"

!value_type(carto::ViewState, graphics.ViewState)

%ignore carto::ViewState::getCameraPos;
%ignore carto::ViewState::getFocusPos;
%ignore carto::ViewState::getUpVec;
%ignore carto::ViewState::getFrustum;

%attribute(carto::ViewState, float, Rotation, getRotation)
%attribute(carto::ViewState, float, Zoom, getZoom)
%attribute(carto::ViewState, float, Tilt, getTilt)
%attribute(carto::ViewState, float, Zoom0Distance, getZoom0Distance)
%attribute(carto::ViewState, int, FOVY, getFOVY)
%attribute(carto::ViewState, float, Near, getNear)
%attribute(carto::ViewState, float, Far, getFar)
%attribute(carto::ViewState, bool, CameraChanged, isCameraChanged)
%attribute(carto::ViewState, int, Width, getWidth)
%attribute(carto::ViewState, int, Height, getHeight)
%attribute(carto::ViewState, int, ScreenWidth, getScreenWidth)
%attribute(carto::ViewState, int, ScreenHeight, getScreenHeight)
%attribute(carto::ViewState, float, DPI, getDPI)
%attribute(carto::ViewState, float, DPToPX, getDPToPX)
%attribute(carto::ViewState, float, UnitToDPCoef, getUnitToDPCoef)
%attribute(carto::ViewState, float, UnitToPXCoef, getUnitToPXCoef)
%attribute(carto::ViewState, float, AspectRatio, getAspectRatio)
%ignore carto::ViewState::ViewState;
%ignore carto::ViewState::RotationState;
%ignore carto::ViewState::getMinZoom;
%ignore carto::ViewState::getHalfWidth;
%ignore carto::ViewState::getHalfHeight;
%ignore carto::ViewState::getTanHalfFOVY;
%ignore carto::ViewState::getHalfFOVY;
%ignore carto::ViewState::getNormalizedResolution;
%ignore carto::ViewState::getTanHalfFOVX;
%ignore carto::ViewState::getCosHalfFOVY;
%ignore carto::ViewState::getCosHalfFOVXY;
%ignore carto::ViewState::setCameraPos;
%ignore carto::ViewState::setFocusPos;
%ignore carto::ViewState::setUpVec;
%ignore carto::ViewState::setRotation;
%ignore carto::ViewState::setTilt;
%ignore carto::ViewState::setZoom;
%ignore carto::ViewState::cameraChanged;
%ignore carto::ViewState::get2PowZoom;
%ignore carto::ViewState::getRotationState;
%ignore carto::ViewState::getProjectionSurface;
%ignore carto::ViewState::getProjectionMat;
%ignore carto::ViewState::getModelviewMat;
%ignore carto::ViewState::getModelviewProjectionMat;
%ignore carto::ViewState::getRTELocalMat;
%ignore carto::ViewState::getRTEModelviewMat;
%ignore carto::ViewState::getRTEModelviewProjectionMat;
%ignore carto::ViewState::getRTESkyProjectionMat;
%ignore carto::ViewState::setScreenSize;
%ignore carto::ViewState::clampZoom;
%ignore carto::ViewState::clampFocusPos;
%ignore carto::ViewState::getFocusPosNormal;
%ignore carto::ViewState::isSkyVisible;
%ignore carto::ViewState::calculateViewState;
%ignore carto::ViewState::worldToScreen;
%ignore carto::ViewState::screenToWorld;
%ignore carto::ViewState::estimateWorldPixelMeasure;
%ignore carto::ViewState::getHorizontalLayerOffsetDir;
%ignore carto::ViewState::setHorizontalLayerOffsetDir;
!standard_equals(carto::ViewState);

%include "graphics/ViewState.h"

#endif
