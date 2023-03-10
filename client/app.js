const express = require('express');
const path = require('path')
  
const app = express();
app.use(express.static(__dirname));

const PORT = 3000;
  
app.listen(PORT, (error) =>{
    if(!error)
        console.log("Server is Successfully Running, and App is listening on port "+ PORT)
    else 
        console.log("Error occurred, server can't start", error);
    }
);

app.get('/',function(req,res) {
    res.sendFile(path.join(__dirname+'/Homepage/Homepage.html'));
  });