import Player from "./player.js";

const canvas = document.getElementById("game");
const ctx = canvas.getContext("2d");

canvas.width = 1900;
canvas.height = 927;
const player = new Player(canvas);


function game() {
    player.draw(ctx);
}

setInterval(game, 1000 / 60);
