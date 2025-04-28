document.addEventListener('DOMContentLoaded', function () {

    document.querySelector('#submit').addEventListener('click', function (event) {
        let name = document.querySelector('#name');
        let alert = document.querySelector('#show-name');
        alert.innerHTML = `hello, ${name.value}`;
        alert.classList.remove('d-none');
        event.preventDefault();
    })
});

