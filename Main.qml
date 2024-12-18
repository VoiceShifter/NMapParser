import QtQuick
import com.Analyzer

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Scan Viewer")
    Rectangle
    {
        id: _Background
        color: "#BCCCDC"
        anchors.fill: parent
    }
    Analyzer
    {
        id: _Analyzer
    }


    ListView
    {
        id: _List
        anchors.horizontalCenter: _Background.horizontalCenter
        anchors.bottom: _Background.bottom
        anchors.fill: parent
        model: _Analyzer.pLines
        spacing: -1
        width: parent.width
        height: parent.height
        delegate: Rectangle
        {
            id: _Delegated
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            height: 30
            border.width: 1
            border.color: "black"
            Text {
                id: _Text
                text: qsTr(modelData)
                font.pointSize: 14
            }
        }
    }

}
