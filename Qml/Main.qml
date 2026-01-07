import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Rectangle {
    id: root
    height: 800
    width: 800
    color: isDarkMode ? "#3D3D3D" : "#F5F5F7"

    ColumnLayout {
        id: verticalLayout
        anchors.fill: parent

        Item {
            id: topFiller
            Layout.fillHeight: true
        }

        Label {
            id: title
            Layout.alignment: Qt.AlignCenter
            text: {
                return isDarkMode ? "Good Night World" : "Hello World"
            }
            font.pixelSize: 28
            font.weight: Font.ExtraBold
            color: root.getTextColor()
        }

        Image {
            id: image
            Layout.alignment: Qt.AlignCenter
            source: "qrc:/images/globe.png"
            sourceSize.width: 250
            sourceSize.height: 250
            fillMode: Image.PreserveAspectFit
        }

        Label {
            id: subtitle
            Layout.alignment: Qt.AlignCenter
            text: "Est. 2026"
            font.pixelSize: 11
            font.weight: Font.Normal
            color: root.getTextColor()
        }

        Item {
            id: bottomFiller
            Layout.fillHeight: true
        }
    }

    function getTextColor() {
        return isDarkMode ? "white" : "black"
    }
}
