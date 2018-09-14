/**
 *Copyright (c) 2018 ilaocai
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

import QtQuick 2.2
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Window {
    id: root
    width: 400
    height: 400

    visible: true

    title: qsTr("下载测试")

    ColumnLayout {
        spacing: 10
        
        anchors.fill: parent
        anchors.margins: 10
        
        TextField {
            id: url
            placeholderText: qsTr("下载地址")
            implicitWidth: 350
            objectName: "textfield"
        }

        ProgressBar {
            id: progress
            objectName: "progress"
            maximumValue: 100
        }

        Button {
            id: button
            text: "开始下载"
            objectName: "button"
        }

        Label {
            id: line
            objectName: "line"
        }
        
        Label {
            id: finish
            objectName: "finish"
            
            font.pixelSize: 30
            color: "green"
            
        }
    }

}
