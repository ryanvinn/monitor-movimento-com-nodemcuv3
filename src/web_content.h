#ifndef WEB_CONTENT_H
#define WEB_CONTENT_H

const char MAIN_PAGE[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
    <title>Sistema de Alarme</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            text-align: center;
            margin: 50px;
        }
        .alarm-button {
            padding: 15px 30px;
            font-size: 18px;
            border: none;
            border-radius: 5px;
            color: white;
            cursor: pointer;
            margin: 20px;
        }
        .status {
            font-size: 24px;
            margin: 20px;
        }
    </style>
</head>
<body>
    <h1>Sistema de Alarme</h1>
    <div class="status">
        Status: %ALARM_STATUS%
    </div>
    <form action="/toggle" method="POST">
        <button class="alarm-button" style="background-color:%BUTTON_COLOR%">
            %BUTTON_TEXT%
        </button>
    </form>
</body>
</html>
)=====";

#endif

