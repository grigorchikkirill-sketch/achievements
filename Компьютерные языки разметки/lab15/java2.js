document.querySelector('input[type="button"]').addEventListener('click', function () {
    const checkboxes = document.querySelectorAll('.checkbox');
    const footer = document.getElementById('footer');
    footer.innerHTML = '';
    for (let i = 0; i < checkboxes.length; i++) {
        if (checkboxes[i].checked) {
            const li = document.createElement('li');
            li.textContent = checkboxes[i].value;
            footer.appendChild(li);
        }
    }
    let text = document.querySelectorAll('.text')

    for (let i = 0; i < text.length; i++) {
        if (text[i] != null) {
            let list = document.createElement("li");
            list.innerHTML = text[i].value;
            document.getElementById('footer').append(list);
        }
    }

    const selects = document.querySelectorAll('select');
    selects.forEach(select => {
        const selectedOption = select.options[select.selectedIndex];
        const li = document.createElement('li');
        li.textContent = selectedOption.text;
        footer.appendChild(li);
    });
})

