
/**
 * Copyright (C) 2016, Canonical Ltd.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 *
 * Author: Justin McPherson <justin.mcpherson@canonical.com>
 *
 */

#ifndef REACTMODULEMETHOD_H
#define REACTMODULEMETHOD_H

#include <functional>

#include <QPointer>
#include <QMetaMethod>


class ReactBridge;


class ReactModuleMethod
{
public:
  typedef std::function<QObject* (QVariantList&)> ObjectFunction;

  ReactModuleMethod(const QMetaMethod& metaMethod, const ObjectFunction& objectFunction);
  ~ReactModuleMethod();

  QString name() const;
  QString type() const;

  void invokeWithBridge(ReactBridge* bridge, const QVariantList& args);

private:
  ObjectFunction m_objectFunction;
  QMetaMethod m_metaMethod;
};


#endif // REACTMODULEMETHOD_H
