const char page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width">
  <link rel="stylesheet" href="https://rawgit.com/Ryanhu1015/NTP-clock/master/webpage.css" type="text/css" />
</head>
<body>

<center>
    <form method='get' action = 'timeSet'>
        <br><h1><font color='#FFFFFF'>AppWorks NTP clock</font></h1><br>
        <h5><font color='#FFFFFF'>made by Ryan</font></h5>

        <p><font color='#FFFFFF'>HOURS</font></p>
        <input type='text', id='textbox1', name = 'msg1'><br><br>

        <p><font color='#FFFFFF'>MINUTES</font></p>
        <input type = 'text', id='textbox2', name = 'msg2'><br><br>

        <p><font color='#FFFFFF'>SECONDS</font></p>
        <input type = 'text', id='textbox3', name = 'msg3'><br><br>

        <input type='submit', value = 'setting', onclick='getNumber()'><br><br>
    </form>

    <form method='get' action = 'NTP'><input type = 'submit', value = 'NTP1'></form>
    <form method='get' action = 'NTP2'><input type = 'submit', value = 'NTP2'></form>
    <form method='get' action = 'NTP3'><input type = 'submit', value = 'NTP3'></form><br><br>


    <form method = 'get' action = 'ColorPicker'>
    <input type="submit" value="SetColor">
    <input type="hidden" name="r" id="r"/>
    <input type="hidden" name="g" id="g"/>
    <input type="hidden" name="b" id="b"/>
    <div class="color-picker">
            <div class="cont ">
                <div class="transparent">
                    <div class="color-view"></div>
                </div>
                <div class="clearfix"></div>
                <div class="hue">
                    <div class="bg"></div>
                    <div class="range"><input type="range" min="0" max="360" value="33"></div>
                </div>
                <div class="apperance">
                    <div class="transparent"></div>
                    <div class="bg"></div>
                    <div class="range"><input type="range" min="0" max="100" value="100" step="1"></div>
                </div>
                <div class="color-codes">
                    <table>
                        <tr>
                            <td class="hsl" style="display: none">
                                hsla(33, 100%, 50%, 1)
                            </td>
                        </tr>
                        <tr>
                            <td class="rgb" name = 'color'>
                                rgb(255, 140, 0)
                            </td>
                        </tr>
                        <tr>
                            <td class="hex" style="display: none">
                                #ff8c00
                            </td>
                        </tr>
                    </table>
                </div>
            </div>
        </div>
</center>
</form>

    <script src="https://code.jquery.com/jquery-3.2.1.min.js"
      integrity="sha256-hwg4gsxgFZhOsEEamdOYGBf13FyQuiTwlAQgxVSNgt4="
      crossorigin="anonymous"></script>
    <script type="text/javascript" src="https://rawgit.com/Ryanhu1015/NTP-clock/master/webpage.js"></script>
</body>
</html>
)=====";
