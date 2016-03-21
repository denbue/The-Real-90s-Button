// ==UserScript==
// @name        90s Button
// @namespace   90sbutton
// @include     *the90sbutton.com/*
// @version     1
// @grant       none
// ==/UserScript==

// CSS
function addGlobalStyle(css) {
    var head, style;
    head = document.getElementsByTagName('head')[0];
    if (!head) { return; }
    style = document.createElement('style');
    style.type = 'text/css';
    style.innerHTML = css;
    head.appendChild(style);
}

addGlobalStyle('.news, .credits, tr.bottom { display: none !important; } .video-wrapper {  }');

// load hotkey plugin
var script = document.createElement("script");
script.src = "https://raw.github.com/jeresig/jquery.hotkeys/master/jquery.hotkeys.js";
document.getElementsByTagName("head")[0].appendChild(script);

// bind hotkey and do the action
$(document).on('keyup', null, 'n', function(){
    console.log('next');
    $('.button-container a.button').click();
});  