/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the documentation of the Qt Toolkit.
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

#include <QtWidgets>

QString tr(const char *text)
{
    return QApplication::translate(text, text);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextEdit *editor = new QTextEdit();

    QTextCursor cursor(editor->textCursor());
    cursor.movePosition(QTextCursor::Start); 

    QTextCharFormat plainFormat(cursor.charFormat());

    QTextCharFormat headingFormat = plainFormat;
    headingFormat.setFontWeight(QFont::Bold);
    headingFormat.setFontPointSize(16);

    QTextCharFormat emphasisFormat = plainFormat;
    emphasisFormat.setFontItalic(true);

    QTextCharFormat qtFormat = plainFormat;
    qtFormat.setForeground(QColor("#990000"));

    QTextCharFormat underlineFormat = plainFormat;
    underlineFormat.setFontUnderline(true);

//! [0]
    cursor.insertText(tr("Character formats"),
                      headingFormat);

    cursor.insertBlock();

    cursor.insertText(tr("Text can be displayed in a variety of "
                                  "different character formats. "), plainFormat);
    cursor.insertText(tr("We can emphasize text by "));
    cursor.insertText(tr("making it italic"), emphasisFormat);
//! [0]
    cursor.insertText(tr(", give it a "), plainFormat);
    cursor.insertText(tr("different color "), qtFormat);
    cursor.insertText(tr("to the default text color, "), plainFormat);
    cursor.insertText(tr("underline it"), underlineFormat);
    cursor.insertText(tr(", and use many other effects."), plainFormat);

    editor->setWindowTitle(tr("Text Document Character Formats"));
    editor->resize(320, 480);
    editor->show();
    return app.exec();
}