export default class Npc {
    constructor(canvas) {
        this.canvas = canvas;
        this.x = 1500;  
        this.y = this.canvas.height/2.2;
        this.width = 140;
        this.height = 200;
        this.image = new Image();
        this.image.src = "";
    }
    draw(ctx){
        ctx.clearRect(0, 0, this.canvas.width, this.canvas.height);
        ctx.drawImage(this.image, this.x, this.y, this.width, this.height);
    }
}