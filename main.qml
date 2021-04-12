/*
    Copyright (C) 2021  Carlos Enrique Duarte Ortiz (carlosduarte.1@hotmail.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

import QtQuick 2.12
import QtQuick.Controls 2.5
import UserObject 1.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property int currentIndex: 0

    Component.onCompleted: {
        displayUser(currentIndex);
    }

    ColumnLayout {
        width: parent.width
        anchors.centerIn: parent

        RowLayout {
            Text {
                text: "ID"
            }

            TextField {
                Layout.fillWidth: true
                id: idTxt
            }
        }

        RowLayout {
            Text {
                text: "Name"
            }

            TextField {
                Layout.fillWidth: true
                id: nameTxt
            }
        }

        RowLayout {
            Text {
                text: "Lastname"
            }

            TextField {
                Layout.fillWidth: true
                id: lastnameTxt
            }
        }

        RowLayout {
            Text {
                text: "Genre"
            }

            TextField {
                Layout.fillWidth: true
                id: genreTxt
            }
        }

        RowLayout {
            Text {
                text: "Birthyear"
            }

            TextField {
                Layout.fillWidth: true
                id: birthyearTxt
            }
        }

        RowLayout {
            Text {
                text: "Email"
            }

            TextField {
                Layout.fillWidth: true
                id: emailTxt
            }
        }

        RowLayout {
            Text {
                text: "Passphrase"
            }

            TextField {
                Layout.fillWidth: true
                id: passprhaseTxt
            }
        }
    }

    function displayUser(index) {
        idTxt.text = users[index].id;
        nameTxt.text = users[index].name;
        lastnameTxt.text = users[index].lastname;
        genreTxt.text = users[index].genre;
        birthyearTxt.text = users[index].birthyear;
        emailTxt.text = users[index].email;
        passprhaseTxt.text = users[index].passphrase;
    }

    function advanceIndex() {
        if (currentIndex == users.length - 1) {
            currentIndex = 0;
        } else {
            currentIndex += 1;
        }
    }

    Button {
        anchors.bottom: parent.bottom
        text: "Next"
        onClicked: {
            advanceIndex();
            displayUser(currentIndex);
        }
    }
}
