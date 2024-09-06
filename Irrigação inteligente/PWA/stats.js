// stats.js
window.onload = function() {
    var ctx1 = document.getElementById('humidityChart').getContext('2d');
    var humidityChart = new Chart(ctx1, {
        type: 'pie',
        data: {
            labels: ['Planta 1', 'Planta 2', 'Planta 3'],
            datasets: [{
                data: [12, 19, 3],
                backgroundColor: ['rgba(75, 192, 192, 0.2)', 'rgba(153, 102, 255, 0.2)', 'rgba(255, 159, 64, 0.2)'],
                borderColor: ['rgba(75, 192, 192, 1)', 'rgba(153, 102, 255, 1)', 'rgba(255, 159, 64, 1)'],
                borderWidth: 1
            }]
        },
        options: {
            responsive: true,
            plugins: {
                legend: {
                    position: 'top',
                },
                title: {
                    display: true,
                    text: 'Umidade das Plantas'
                }
            }
        },
    });

    var ctx2 = document.getElementById('wateringChart').getContext('2d');
    var wateringChart = new Chart(ctx2, {
        type: 'pie',
        data: {
            labels: ['Regadas', 'Não Regadas'],
            datasets: [{
                data: [3, 2],
                backgroundColor: ['rgba(75, 192, 192, 0.2)', 'rgba(255, 99, 132, 0.2)'],
                borderColor: ['rgba(75, 192, 192, 1)', 'rgba(255, 99, 132, 1)'],
                borderWidth: 1
            }]
        },
        options: {
            responsive: true,
            plugins: {
                legend: {
                    position: 'top',
                },
                title: {
                    display: true,
                    text: 'Plantas Regadas'
                }
            }
        },
    });
}
