function scrollDown() {
    const marketing = document.querySelector("#marketing_section");
    marketing.scrollIntoView({ behavior: "smooth" });
}

var lastY = window.pageYOffset;

function scroll_navbar() {
  var currY = window.pageYOffset;
  if (lastY > currY) {
    document.getElementById("navbar").style.top = "0px";
  }
  else {
    document.getElementById("navbar").style.top = "-4rem";
  }
  lastY = currY;
}
