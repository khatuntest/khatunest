
let title ;
document.addEventListener('DOMContentLoaded', function()  {
     title  = document.getElementById('title');
});
let list_of_squares = [];

function process(num1 , num2 , num3 ){
    title.innerHTML= `${list_of_squares[num1]} Winner`;
    document.getElementById('item' + num1).style.background = ' rgb(228, 221, 226)';
    document.getElementById('item' + num2).style.background = ' rgb(228, 221, 226)';
    document.getElementById('item' + num3).style.background=' rgb(228, 221, 226)';
    setInterval(function(){title.innerHTML += '.'} , 1000);
    setTimeout(function(){ location.reload();},4000);
}
function win(){
    for (let i= 1 ; i<10 ; ++i){
        list_of_squares[i]= document.getElementById('item' + i).innerHTML; 
    }

    if (list_of_squares[1] == list_of_squares[2] && list_of_squares[2] == list_of_squares[3] && list_of_squares[1] != ''){
        process(1,2,3);
    }
    else if (list_of_squares[4] == list_of_squares[5] && list_of_squares[5] == list_of_squares[6] && list_of_squares[4] != ''){
        process(4,5,6);
    }
    else if (list_of_squares[7] == list_of_squares[8] && list_of_squares[8] == list_of_squares[9] && list_of_squares[7] != ''){
        process(7,8,9);
    }
    else if (list_of_squares[1] == list_of_squares[4] && list_of_squares[4]== list_of_squares[7] && list_of_squares[1] != ''){
       process(1,4,7);
    }
    else if (list_of_squares[2] == list_of_squares[5] && list_of_squares[5] == list_of_squares[8] && list_of_squares[2] != ''){
      process(2,5,8);
    }
    else if (list_of_squares[3] == list_of_squares[6] && list_of_squares[6] == list_of_squares[9] && list_of_squares[6] != ''){
       process(3,6,9);
    }
    else if (list_of_squares[1] == list_of_squares[5] && list_of_squares[5] == list_of_squares[9] && list_of_squares[1] != ''){
       process(1,5,9);
    }
    else if (list_of_squares[3] == list_of_squares[5] && list_of_squares[5] == list_of_squares[7] && list_of_squares[7] != ''){
        process(3,5,7);
    }
}

let turn ='x';
function Game (id){
    let item= document.getElementById(id);
    if(turn == 'x' && item.innerHTML == ''){
        item.innerHTML ='x';
        turn = 'o';
        title.innerHTML = 'o';
    }
    else if (turn == 'o' && item.innerHTML == ''){
        item.innerHTML ='o';
        turn = 'x';
        title.innerHTML = 'x';
    }
    win();
}
