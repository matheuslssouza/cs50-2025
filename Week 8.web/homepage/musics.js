document.addEventListener('DOMContentLoaded', () => {

    let musics = [];

    document.querySelector('#music-submit').addEventListener('click', () => {

        let music = document.querySelector('.form-music').value;

        musics.push(music);

        let table = document.querySelector('#table-musics');

        table.innerHTML = "";

        for (insert in musics){
            table.innerHTML += `<li class ="list-group-item">${musics[insert]}</li>`;
        }

    })

});
