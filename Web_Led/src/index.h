#include <Arduino.h>

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>

<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Sterowanie LED</title>

  <style>
    body { 
      font-family: Arial, sans-serif; 
      text-align: center; 
      margin-top: 50px;
      background-color: #f4f4f4;
    }
    h1 { 
      color: #333; 
    }
    .button {
      display: inline-block; 
      padding: 15px 25px; 
      font-size: 24px;
      cursor: pointer; 
      text-decoration: none; 
      outline: none;
      color: #fff; 
      background-color: #4CAF50;
      border: none; 
      border-radius: 15px;
      box-shadow: 0 9px #999;
      margin: 10px;
    }
    .button:active { 
      background-color: #3e8e41; 
      box-shadow: 0 5px #666; 
      transform: translateY(4px);
    }
    .off { 
      background-color: #f44336; 
    }
    .off:active {
      background-color: #d32f2f;
    }
  </style>

</head>

<body>
  <h1>Tryb Access Point</h1>
  <p>Kliknij przycisk, aby zmienic stan diody</p>
  <br>
  <a href="/led/on">
    <button class="button">WLACZ LED</button>
  </a>
  <a href="/led/off">
    <button class="button off">WYLACZ LED</button>
  </a>
</body>

</html>
)rawliteral";