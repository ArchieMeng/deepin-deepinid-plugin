/*
 * Copyright (C) 2019 ~ 2019 Deepin Technology Co., Ltd.
 *
 * Author:     justforlxz <justforlxz@outlook.com>
 *
 * Maintainer: justforlxz <justforlxz@outlook.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "interface/namespace.h"
#include <QWidget>
#include <QLabel>
#include <QSvgRenderer>

class QVBoxLayout;

class PicLabel:public QLabel
{
    Q_OBJECT
public:
    explicit PicLabel(QWidget *parent = nullptr);

    void SetImage(const QString &imgurl);
protected:
    void resizeEvent(QResizeEvent *event) override;
private:
    QSvgRenderer *m_svgrender;
};

class LoginPage : public QWidget
{
    Q_OBJECT
public:
    explicit LoginPage(QWidget *parent = nullptr);

private:
    /**
     * @brief getAgreementHttp  返回协议 0 为使用协议 1为 隐私协议
     * @return
     */
    QStringList getAgreementHttp();

public Q_SLOTS:
    void onLinkActivated(const QString link);

Q_SIGNALS:
    void requestLoginUser() const;

private:
    QVBoxLayout *m_mainLayout;
};
