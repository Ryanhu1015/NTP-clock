$(document).ready(function () {
    "use strict";
    var hueBg = $(".color-picker .hue .bg"),
        i,
        h = 33,
        s = 100,
        l = 50,
        a = 1;
    for (i = 0; i <= 360; i += 1) {
        hueBg.append("<span style='background:hsla(" + i + ", " + s + "%, " + l + "%, " + a + ");'></span>");
    }
    $(".color-picker .hue .range input[type=range]").change(function () {
        h = $(this).val();
        var hue = "hsla(" + h + ", " + s + "%, " + l + "%, " + a + ")",
            rgb = $("body").css("background-color"),
            hex_16_bytes = rgb.split("(")[1].split(")")[0].split(", "),
            hex = [];
        hex[0] = parseInt(hex_16_bytes[0]).toString(16);
        hex[1] = parseInt(hex_16_bytes[1]).toString(16);
        hex[2] = parseInt(hex_16_bytes[2]).toString(16);
        if (hex[0].length < 2) {
            hex[0] = "0" + hex[0];
        }
        if (hex[1].length < 2) {
            hex[1] = "0" + hex[1];
        }
        if (hex[2].length < 2) {
            hex[2] = "0" + hex[2];
        }
        $(".color-codes .hex").text("#" + hex.join(""))
        $(".color-codes .hsl").text(hue);
        $(".color-codes .rgb").text(rgb);
        $("body").css({
            background : hue
        });
        
        $(".color-picker .apperance .bg").css({
            background: hue,
            background: "-o-linear-gradient(left,  rgba(0,0,0,0) 0%, " + hue + " 100%)",
            background: "-moz-linear-gradient(left,  rgba(0,0,0,0) 0%, " + hue + " 100%)",
            background: "-webkit-linear-gradient(left,  rgba(0,0,0,0) 0%, " + hue + " 100%)",
            background: "linear-gradient(to right,  rgba(0,0,0,0) 0%, " + hue + " 100%)"
        });
    });
    $(".color-picker .hue .range input[type=range]").mousemove(function () {
        h = $(this).val();
        var hue = "hsla(" + h + ", " + s + "%, " + l + "%, " + a + ")",
            rgb = $("body").css("background-color"),
            hex_16_bytes = rgb.split("(")[1].split(")")[0].split(", "),
            hex = [];
            console.log(hex_16_bytes);
        hex[0] = parseInt(hex_16_bytes[0]).toString(16);
        hex[1] = parseInt(hex_16_bytes[1]).toString(16);
        hex[2] = parseInt(hex_16_bytes[2]).toString(16);
        if (hex[0].length < 2) {
            hex[0] = "0" + hex[0];
        }
        if (hex[1].length < 2) {
            hex[1] = "0" + hex[1];
        }
        if (hex[2].length < 2) {
            hex[2] = "0" + hex[2];
        }
        $(".color-codes .hex").text("#" + hex.join(""))
        $(".color-codes .hsl").text(hue);
        $(".color-codes .rgb").text(rgb);
        console.log(rgb);
        function getRGB(){
            var red = rgb,
                green,
                blue; 
        }
        $("body").css({
            background : hue
        });
        $(".color-picker .apperance .bg").css({
            background: hue,
            background: "-o-linear-gradient(left,  rgba(0,0,0,0) 0%, " + hue + " 100%)",
            background: "-moz-linear-gradient(left,  rgba(0,0,0,0) 0%, " + hue + " 100%)",
            background: "-webkit-linear-gradient(left,  rgba(0,0,0,0) 0%, " + hue + " 100%)",
            background: "linear-gradient(to right,  rgba(0,0,0,0) 0%, " + hue + " 100%)"
        });
    });
    
    $(".color-picker .apperance .range input[type=range]").change(function () {
        if ($(this).val() <= 9){
            a = "0.0" + $(this).val();
        } else if ($(this).val() >= 100) {
            a = "1";
        } else {
            a = "0." + $(this).val();
        }
        var hue = "hsla(" + h + ", " + s + "%, " + l + "%, " + a + ")",
            rgb = $("body").css("background-color"),
            hex_16_bytes = rgb.split("(")[1].split(")")[0].split(", "),
            hex = [];
        hex[0] = parseInt(hex_16_bytes[0]).toString(16);
        hex[1] = parseInt(hex_16_bytes[1]).toString(16);
        hex[2] = parseInt(hex_16_bytes[2]).toString(16);
        if (hex[0].length < 2) {
            hex[0] = "0" + hex[0];
        }
        if (hex[1].length < 2) {
            hex[1] = "0" + hex[1];
        }
        if (hex[2].length < 2) {
            hex[2] = "0" + hex[2];
        }
        $(".color-codes .hex").text("#" + hex.join(""))
        $(".color-codes .hsl").text(hue);
        $(".color-codes .rgb").text(rgb);
        $("body").css({
            background : hue
        });
    });
    $(".color-picker .apperance .range input[type=range]").mousemove(function () {
        if ($(this).val() <= 9){
            a = "0.0" + $(this).val();
        } else if ($(this).val() >= 100) {
            a = "1";
        } else {
            a = "0." + $(this).val();
        }
        var hue = "hsla(" + h + ", " + s + "%, " + l + "%, " + a + ")",
            rgb = $("body").css("background-color"),
            hex_16_bytes = rgb.split("(")[1].split(")")[0].split(", "),
            hex = [];
        hex[0] = parseInt(hex_16_bytes[0]).toString(16);
        hex[1] = parseInt(hex_16_bytes[1]).toString(16);
        hex[2] = parseInt(hex_16_bytes[2]).toString(16);
        if (hex[0].length < 2) {
            hex[0] = "0" + hex[0];
        }
        if (hex[1].length < 2) {
            hex[1] = "0" + hex[1];
        }
        if (hex[2].length < 2) {
            hex[2] = "0" + hex[2];
        }
        $(".color-codes .hex").text("#" + hex.join(""))
        $(".color-codes .hsl").text(hue);
        $(".color-codes .rgb").text(rgb);
        $("body").css({
            background : hue
        });
    });
});