import QtQuick
import QtQuick.Controls
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
    TextField
    {
        id: _SearchBar
        z: 2
        anchors.right: parent.right
        anchors.rightMargin: 20
        width: 160
        height: 30
        font.pointSize: 14
        placeholderText: "Enter threat level"
        horizontalAlignment: TextInput.AlignHCenter
        Keys.onReturnPressed:
        {
            _Analyzer.mFilter(_SearchBar.text)
            _SearchBar.clear()
        }
    }
    Rectangle
    {
        id: _Accept
        z: 2
        width: _SearchBar.width / 2 - 5
        anchors.right: _SearchBar.right
        anchors.top: _SearchBar.bottom
        anchors.topMargin: 5
        color: "green"
        height: _SearchBar.height
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                console.log("green")
                _Analyzer.mFilter(_SearchBar.text)
                _SearchBar.clear()
            }
        }
    }

    Rectangle
    {
        id: _Clear
        z: 2
        width: _SearchBar.width / 2 - 5
        anchors.left: _SearchBar.left
        anchors.top: _SearchBar.bottom
        anchors.topMargin: 5
        color: "red"
        height: _SearchBar.height
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                console.log("red")
                _Analyzer.mReset()
                _SearchBar.clear()
            }
        }
    }

    ListView
    {
        id: _List
        z: 1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.top: _Accept.bottom
        anchors.topMargin: 5
        model: _Analyzer.pLines
        spacing: -1
        width: parent.width
        height: parent.height - parent.height / 8
        delegate: Rectangle
        {
            id: _Delegated
            width: maximumWidth
            anchors.horizontalCenter: _List.horizontalCenter
            height: 30
            border.width: 1
            border.color: "black"
            TextEdit {

                id: _Text
                readOnly: true
                onLinkActivated: Qt.openUrlExternally("google.com")
                text: qsTr(modelData)
                font.pointSize: 14
            }
        }
    }

}
