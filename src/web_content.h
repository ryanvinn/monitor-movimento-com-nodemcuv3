#ifndef WEB_CONTENT_H
#define WEB_CONTENT_H

/**
 * @file web_content.h
 * @brief Conteúdo HTML para interface web do sistema de alarme
 * 
 * Contém a página HTML principal com estilos CSS embutidos
 * e placeholders para conteúdo dinâmico
 */

/**
 * @brief Página HTML principal do sistema de alarme
 *
 * Página web responsiva com:
 * - Exibição do status do alarme
 * - Botão de controle do sistema
 * - Estilos CSS embutidos
 *
 * @note Armazenado na memória PROGMEM para economizar RAM
 * @note Utiliza placeholders para conteúdo dinâmico:
 *       - %ALARM_STATUS% - Texto do status atual
 *       - %BUTTON_COLOR% - Cor do botão (verde/vermelho)
 *       - %BUTTON_TEXT% - Texto do botão (Ativar/Desativar)
 */
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

