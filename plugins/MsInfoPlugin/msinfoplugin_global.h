#ifndef MSINFOPLUGIN_GLOBAL_H
#define MSINFOPLUGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef MSINFOPLUGIN_LIB
# define PLUGIN_EXPORT Q_DECL_EXPORT
#else
# define PLUGIN_EXPORT Q_DECL_IMPORT
#endif

#endif // MSINFOPLUGIN_GLOBAL_H
