const input = document.querySelector('.input')
const btn = document.querySelector('.btn')
const result  = document.querySelector('.result')

btn.addEventListener('click', mostraMeteo);
async function mostraMeteo() {
    let cityEnter = input.value;

    if (cityEnter === "") {
        console.log("Campo vuoto");
    } else {
        // const dataClean = {
        //     name: cityEnter,
        //     main: {
        //         temp: 21.5
        //     },
        //     weather: [
        //         { description: "cielo sereno" }
        //     ]
        // };
        const url = "";
        
        const jsonResponse = await fetch(`https://api.openweathermap.org/data/2.5/weather?q=${cityEnter}&appid=2f4c89c3a592289c8c4880846f14d054&units=metric`);
        const dataClean = await jsonResponse.json();
        
        console.log(dataClean);

        // ORA: passiamo i dati al DIV 'result'
        // Proviamo a scrivere solo il nome della città per ora
        // Uniamo tutto in un unico blocco HTML
        result.innerHTML = `
            <h2>Meteo di ${dataClean.name}</h2>
            <p>Temperatura: ${dataClean.main.temp}°C</p>
            <p>Condizioni: ${dataClean.weather[0].description}</p>
        `;
    }
}