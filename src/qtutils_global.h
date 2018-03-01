#ifndef QTUTILS_GLOBAL_H
#define QTUTILS_GLOBAL_H

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
    #if defined(QTUTILS_LIB)
        #define QTUTILS_EXPORT Q_DECL_EXPORT
    #else
        #define QTUTILS_EXPORT Q_DECL_IMPORT
    #endif //QTUTILS_LIB
#else
    #define QTUTILS_EXPORT
#endif //BUILD_STATIC

#endif //QTUTILS_GLOBAL_H
