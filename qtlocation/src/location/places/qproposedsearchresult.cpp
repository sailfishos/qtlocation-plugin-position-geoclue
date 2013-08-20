/****************************************************************************
**
** Copyright (C) 2013 Aaron McCarthy <mccarthy.aaron@gmail.com>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtLocation module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qproposedsearchresult.h"
#include "qproposedsearchresult_p.h"

QT_BEGIN_NAMESPACE

QProposedSearchResultPrivate::QProposedSearchResultPrivate()
{
}

QProposedSearchResultPrivate::QProposedSearchResultPrivate(const QProposedSearchResultPrivate &other)
:   QPlaceSearchResultPrivate(other), searchRequest(other.searchRequest)
{
}

QProposedSearchResultPrivate::~QProposedSearchResultPrivate()
{
}

bool QProposedSearchResultPrivate::compare(const QPlaceSearchResultPrivate *other) const
{
    const QProposedSearchResultPrivate *od = static_cast<const QProposedSearchResultPrivate *>(other);
    return QPlaceSearchResultPrivate::compare(other) && searchRequest == od->searchRequest;
}

/*!
    \class QProposedSearchResult
    \inmodule QtLocation
    \ingroup QtLocation-places
    \ingroup QtLocation-places-data
    \since Qt Location 5.2

    \brief The QProposedSearchResult class represents a search result containing a proposed search.

    \sa QPlaceSearchResult
*/

/*!
    Constructs a new proposed search result.
*/
QProposedSearchResult::QProposedSearchResult()
:   QPlaceSearchResult(new QProposedSearchResultPrivate)
{
}

/*!
    \fn QProposedSearchResult::QProposedSearchResult(const QPlaceSearchRequest &other)

    Contructs a copy of \a other if possible, otherwise constructs a default proposed search
    result.
*/
Q_IMPLEMENT_SEARCHRESULT_COPY_CTOR(QProposedSearchResult)

Q_IMPLEMENT_SEARCHRESULT_D_FUNC(QProposedSearchResult)

/*!
    Destroys the proposed search result.
*/
QProposedSearchResult::~QProposedSearchResult()
{
}

/*!
    Returns a place search request that can be used to perform an additional proposed search.
*/
QPlaceSearchRequest QProposedSearchResult::searchRequest() const
{
    Q_D(const QProposedSearchResult);
    return d->searchRequest;
}

/*!
    Sets the proposed search request to \a request.
*/
void QProposedSearchResult::setSearchRequest(const QPlaceSearchRequest &request)
{
    Q_D(QProposedSearchResult);
    d->searchRequest = request;
}

QT_END_NAMESPACE
