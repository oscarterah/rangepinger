import Felgo 3.0
import QtQuick 2.12
import QtQuick.Layouts 1.1
import io.qt.examples.pingloop 1.0

App {

    NavigationStack {

        Page {
//            title: qsTr("Pinger")

    ColumnLayout{
        anchors.fill: parent
        spacing: 7
        ListView{
            anchors.verticalCenter: parent.verticalCenter
            id : mListView
            model : myModel
            delegate: Rectangle{

                width : parent.width
                height: textId.implicitHeight+30
                color: "white"
                border.color: "green"
                radius: 10

                Text {
                    width : parent.width
                    height: parent.height
                    id : textId
                    anchors.centerIn: parent
                    text : modelData
                    font.pointSize: 13
                    wrapMode: Text.WordWrap
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
            }
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }

        GridLayout{

            anchors.horizontalCenter: parent.horizontalCenter

            AppTextField{
                id: textEditf
                width: dp(250)
                placeholderText: "if"
                text: Wrapper.userinput_i_f
                onTextChanged: Wrapper.userinput_i_f = text
            }
            AppTextField{
                id: textEdit
                width: dp(250)
                placeholderText: "i"
                text: Wrapper.userinput_i
                onTextChanged: Wrapper.userinput_i = text
            }

            AppTextField{
                id: textEdit2f
                width: dp(250)
                placeholderText: "jf"

                text: Wrapper.userinput_j_f
                onTextChanged: Wrapper.userinput_j_f = text
            }
            AppTextField{
                id: textEdit2
                width: dp(250)
                placeholderText: "j"

                text: Wrapper.userinput_j
                onTextChanged: Wrapper.userinput_j = text
            }

            AppTextField{
                id: textEdit3f
                width: dp(250)
                placeholderText: "kf"

                text: Wrapper.userinput_k_f
                onTextChanged: Wrapper.userinput_k_f = text
            }
            AppTextField{
                id: textEdit3
                width: dp(250)
                placeholderText: "k"

                text: Wrapper.userinput_k
                onTextChanged: Wrapper.userinput_k = text
            }

        }
        GridLayout{
            anchors.bottom: parent.bottom
            AppButton{
                id: button1
                text: "Start"
                onClicked:{
                    Wrapper.startCppTask()
                }
            }
            AppButton{
                id: button2
                text: "Stop"
                onClicked: button2.text = "todo"
                    }
                }
         }
     }
}
