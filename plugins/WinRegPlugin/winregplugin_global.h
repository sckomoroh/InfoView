#ifndef WINREGPLUGIN_GLOBAL_H
#define WINREGPLUGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef WINREGPLUGIN_LIB
# define PLUGIN_EXPORT Q_DECL_EXPORT
#else
# define PLUGIN_EXPORT Q_DECL_IMPORT
#endif

#endif // WINREGPLUGIN_GLOBAL_H
