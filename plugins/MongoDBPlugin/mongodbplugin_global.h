#ifndef MONGODBPLUGIN_GLOBAL_H
#define MONGODBPLUGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef MONGODBPLUGIN_LIB
# define PLUGIN_EXPORT Q_DECL_EXPORT
#else
# define PLUGIN_EXPORT Q_DECL_IMPORT
#endif

#endif // MONGODBPLUGIN_GLOBAL_H
