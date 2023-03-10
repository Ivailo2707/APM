export default class Player {
    constructor(canvas) {
        this.canvas = canvas;
        this.x = this.canvas.width/2.2;
        this.y = 937;
        this.width = 60;
        this.height = 120;
        this.image = new Image();
        this.image.src = "Images/Game_Images/player_sprite.png";
    }
    draw(ctx){
        ctx.clearRect(0, 0, this.canvas.width, this.canvas.height);
        ctx.drawImage(this.image,this.x,this.y,this.width,this.height);
    }
}