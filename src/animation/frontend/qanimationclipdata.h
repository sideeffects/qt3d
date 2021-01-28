/****************************************************************************
**
** Copyright (C) 2016 Klaralvdalens Datakonsult AB (KDAB).
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QT3DANIMATION_QANIMATIONCLIPDATA_H
#define QT3DANIMATION_QANIMATIONCLIPDATA_H

#include <QtCore/qmetatype.h>
#include <QtCore/qscopedpointer.h>
#include <QtCore/qstring.h>
#include <Qt3DAnimation/qt3danimation_global.h>
#include <Qt3DAnimation/qchannel.h>

QT_BEGIN_NAMESPACE

namespace Qt3DAnimation {

class QAnimationClipDataPrivate;
class QAnimationClipData;

bool Q_3DANIMATIONSHARED_EXPORT operator==(const QAnimationClipData &lhs, const QAnimationClipData &rhs) noexcept;
bool Q_3DANIMATIONSHARED_EXPORT operator!=(const QAnimationClipData &lhs, const QAnimationClipData &rhs) noexcept;

class Q_3DANIMATIONSHARED_EXPORT QAnimationClipData
{
public:
    QAnimationClipData();
    QAnimationClipData(const QAnimationClipData &);
    QAnimationClipData &operator=(const QAnimationClipData &);
    ~QAnimationClipData();

    void setName(const QString &name);
    QString name() const;

    int channelCount() const;
    void appendChannel(const QChannel &c);
    void insertChannel(int index, const QChannel &c);
    void removeChannel(int index);
    void clearChannels();

    bool isValid() const noexcept;

    // Iterator API
    typedef const QChannel *const_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    const_iterator begin()  const noexcept;
    const_iterator cbegin() const noexcept { return begin(); }
    const_iterator end()    const noexcept;
    const_iterator cend()   const noexcept { return end(); }
    const_reverse_iterator rbegin()  const noexcept { return const_reverse_iterator(end()); }
    const_reverse_iterator crbegin() const noexcept { return rbegin(); }
    const_reverse_iterator rend()    const noexcept { return const_reverse_iterator(begin()); }
    const_reverse_iterator crend()   const noexcept { return rend(); }

    friend bool Q_3DANIMATIONSHARED_EXPORT operator==(const QAnimationClipData &,
                                                      const QAnimationClipData &) noexcept;
    friend bool Q_3DANIMATIONSHARED_EXPORT operator!=(const QAnimationClipData &,
                                                      const QAnimationClipData &) noexcept;

private:
    QScopedPointer<QAnimationClipDataPrivate> d;
};

} // namespace Qt3DAnimation

QT_END_NAMESPACE

Q_DECLARE_METATYPE(Qt3DAnimation::QAnimationClipData)

#endif // QT3DANIMATION_QANIMATIONCLIPDATA_H
