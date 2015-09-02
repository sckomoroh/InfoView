#ifndef Q_AMAZON_LIB_GLOBAL_H
#define Q_AMAZON_LIB_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef Q_AMAZON_LIB_LIB
# define Q_AMAZON_LIB_EXPORT Q_DECL_EXPORT
#else
# define Q_AMAZON_LIB_EXPORT Q_DECL_IMPORT
#endif

#endif // Q_AMAZON_LIB_GLOBAL_H
