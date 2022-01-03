var members;
function readTextFile1(file)
{
    var rawFile = new XMLHttpRequest();
    rawFile.open("GET", file, false);
    rawFile.onreadystatechange = function ()
    {
        if(rawFile.readyState === 4)
        {
            if(rawFile.status === 200 || rawFile.status == 0)
            {
               members = rawFile.responseText;
               
            }
        }
    }
    rawFile.send(null);
}

readTextFile1("members.txt");

let arr = members.split('\n');
var tabl = document.querySelector("tbody");

for (let i = 0; i < arr.length(); i++){
    let username = arr[i].split("#;");
    var line = tabl.insertRow();
    var cell = line.insertCell();
    cell.setAttribute("class", "rank");
    var beb = document.createTextNode(i + 1);
    cell.appendChild(beb);
    var cell = line.insertCell();
    cell.setAttribute("class", "participant");
    var beb = document.createTextNode(username[0]);
    cell.appendChild(beb);
    for (let i = 0; i < 11; i++){
        var cell = line.insertCell();
        cell.setAttribute("class", "task");
        var beb = document.createTextNode("100");
        cell.appendChild(beb);
    }
}